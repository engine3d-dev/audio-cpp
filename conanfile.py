from conan import ConanFile
from conan.tools.cmake import CMakeToolchain, CMake, cmake_layout, CMakeDeps
from conan.tools.scm import Git
from conan.tools.files import copy
import os

class AudioRecipe(ConanFile):
    name = "engine-audio"
    version = "1.0"
    package_type = "library"
    license = "Apache-2.0"
    homepage = "https://github.com/engine3d-dev/engine3d-audio"

    # Binary configuration
    settings = "os", "compiler", "build_type", "arch"
    options = {"shared": [True, False], "fPIC": [True, False]}
    default_options = {"shared": False, "fPIC": True}
    exports_sources = "CMakeLists.txt", "src/CMakeLists.txt"

    def build_requirements(self):
        self.tool_requires("make/4.4.1")
        self.tool_requires("cmake/3.27.1")
        self.tool_requires("engine3d-cmake-utils/3.0")
    
    def requirements(self):
        self.requires("miniaudio/1.0")
    
    # This is how exporting the sources work
    def export_sources(self):
        copy(self,"CMakeLists.txt", self.recipe_folder, self.export_sources_folder)
        copy(self,"*.hpp", self.recipe_folder, self.export_sources_folder)
        copy(self,"*.h", self.recipe_folder, self.export_sources_folder)
        copy(self,"*.cpp", self.recipe_folder, self.export_sources_folder)

    def layout(self):
        cmake_layout(self)
    
    def generate(self):
        deps = CMakeDeps(self)
        deps.generate()

        tc = CMakeToolchain(self, generator="Unix Makefiles")
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.verbose = True
        cmake.configure()
        cmake.build()
    
    def package(self):
        copy(self, "LICENSE", src=self.source_folder, dst=os.path.join(self.package_folder, "licenses"))
        copy(self, pattern="*.h", src=os.path.join(self.source_folder, "engine-audio"), dst=os.path.join(self.package_folder, "engine-audio"))
        copy(self, pattern="*.hpp", src=os.path.join(self.source_folder, "engine-audio"), dst=os.path.join(self.package_folder, "engine-audio"))
        copy(self, pattern="*.a", src=self.build_folder, dst=os.path.join(self.package_folder, "lib"), keep_path=False)
        copy(self, pattern="*.so", src=self.build_folder, dst=os.path.join(self.package_folder, "lib"), keep_path=False)
        copy(self, pattern="*.lib", src=self.build_folder, dst=os.path.join(self.package_folder, "lib"), keep_path=False)
        copy(self, pattern="*.dll", src=self.build_folder, dst=os.path.join(self.package_folder, "bin"), keep_path=False)
        copy(self, pattern="*.dylib", src=self.build_folder, dst=os.path.join(self.package_folder, "lib"), keep_path=False)
        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.set_property("cmake_target_name", "engine-audio::engine-audio")
        self.cpp_info.libs = ["engine-audio"]
        self.cpp_info.includedirs = ['./', './engine-audio']
