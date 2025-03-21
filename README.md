# engine3d-audio

## Overview
This is the wrapper around miniaudio for engine3d. Wrapper that can also be used for standalone applications.

## To Contributors

Before contributing to engine3d-audio. Please fork this repository.

## Building engine3d-audio

You only need to build this project once using `conan create` command.

```
conan build . -b missing
```

Then you can build using `conan build` afterwards.

```bash
conan build .
```

## Running engine3d-audio demo

To run and test the example audio file, run the demo application like the following below:

```bash
./build/Release/demo/demo Resources/BabyElephantWalk60.wav
```
