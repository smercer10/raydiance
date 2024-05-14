# raydiance

raydiance generates a path-traced PPM render from a JSON scene description.

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](https://github.com/smercer10/raydiance/blob/main/LICENSE)
[![GitHub Actions Workflow Status](https://img.shields.io/github/actions/workflow/status/smercer10/raydiance/ci.yml?label=CI)](https://github.com/smercer10/raydiance/actions/workflows/ci.yml)

## Current Features

- Configurable camera
- Fixed lighting
- Spherical objects
- Lambertian, metal and dielectric materials
- Anti-aliasing
- Depth of field

## Usage

```bash
raydiance -s <path to scene config file> [-o <output image name>]
```

A path to a scene configuration file is required, but the output image name is optional and defaults to `img`.
Notably, the image name does not require a file extension, as the `ppm` extension is automatically appended during
runtime.

## Example

### PPM Render (Converted to JPEG)

![img-28-02-2024-21-54-04.jpeg](example%2Fimg-28-02-2024-21-54-04.jpeg)

### JSON Scene Description

```json
{
  "lookFrom": {
    "x": -5.5,
    "y": 2.5,
    "z": 9.5
  },
  "lookAt": {
    "x": -4.0,
    "y": 1.0,
    "z": 0.0
  },
  "samplesPerPixel": 500,
  "maxDepth": 50,
  "imgWidth": 1200,
  "defocusAngle": 1.2,
  "focusDistance": 8.0,
  "fieldOfView": 60.0,
  "spheres": [
    {
      "centre": {
        "x": 0.0,
        "y": -1000.0,
        "z": -1.0
      },
      "radius": 1000.0,
      "material": {
        "type": "lambertian",
        "colour": {
          "r": 0.2,
          "g": 0.5,
          "b": 0.0
        }
      }
    },
    {
      "centre": {
        "x": -4,
        "y": 2.0,
        "z": -0.5
      },
      "radius": 2.0,
      "material": {
        "type": "lambertian",
        "colour": {
          "r": 0.2,
          "g": 0.2,
          "b": 0.8
        }
      }
    },
    {
      "centre": {
        "x": -8.0,
        "y": 1.5,
        "z": 0.0
      },
      "radius": 1.5,
      "material": {
        "type": "dielectric",
        "refIdx": 1.5
      }
    },
    {
      "centre": {
        "x": -8.0,
        "y": 1.5,
        "z": 0.0
      },
      "radius": -1.5,
      "material": {
        "type": "dielectric",
        "refIdx": 1.5
      }
    },
    {
      "centre": {
        "x": -3.0,
        "y": 1.25,
        "z": 5.0
      },
      "radius": 1.25,
      "material": {
        "type": "metal",
        "colour": {
          "r": 0.7,
          "g": 0.1,
          "b": 0.1
        },
        "fuzz": 0.2
      }
    },
    {
      "centre": {
        "x": -6.0,
        "y": 0.75,
        "z": 4.0
      },
      "radius": 0.75,
      "material": {
        "type": "metal",
        "colour": {
          "r": 0.7,
          "g": 0.6,
          "b": 0.5
        },
        "fuzz": 0.0
      }
    }
  ]
}
```

## Configuration Options

- `aspectRatio`: The aspect ratio of the output image. It expects a double and the default value is `16.0 / 9.0`.
- `lookFrom`: The position of the camera.
  It is an object with `x`, `y`, and `z` properties.
  Each property expects a double and the default values are `x: 0.0`, `y: 0.0`, `z: 0.0`.
- `lookAt`: The point the camera is looking at.
  It is an object with `x`, `y`, and `z` properties.
  Each property expects a double and the default values are `x: 0.0`, `y: 0.0`, `z: 1.0`.
- `cameraUp`: The up vector for the camera.
  It is an object with `x`, `y`, and `z` properties.
  Each property expects a double and the default values are `x: 0.0`, `y: 1.0`, `z: 0.0`.
- `samplesPerPixel`: The number of ray samples per pixel. It expects an integer and the default value is `10`.
- `maxDepth`: The maximum number of bounces for a ray. It expects an integer and the default value is `10`.
- `imgWidth`: The pixel width of the output image. It expects an integer and the default value is `400`.
- `defocusAngle`: The defocus angle for the camera (higher value = greater bokeh).
  It expects a double and the default value is `0.0`.
- `focusDistance`: The focus distance for the camera. It expects a double and the default value is `1.0`.
- `fieldOfView`: The field of view for the camera. It expects a double and the default value is `45.0`.
- `spheres`: An array of sphere objects in the scene. Each sphere object has the following properties:
    - `centre`: The centre of the sphere.
      It is an object with `x`, `y`, and `z` properties.
      Each property expects a double and there are no default values.
    - `radius`: The radius of the sphere. It expects a double and there are no default values.
    - `material`: The material of the sphere.
      It is an object with a `type` property, which is a string that can
      be `"lambertian"`, `"metal"`, or `"dielectric"`.
      Depending on the `type`, it may also have other properties
      like `colour` (an object with `r`, `g`, and `b` properties, each a double) and `refIdx` or `fuzz` (both doubles).
      There are no default values for the `material` object.

## Build Locally

### Prerequisites

- C++17 compiler (tested with GCC and Clang)
- CMake 3.14+
- Clang-Format (optional)
- Clang-Tidy (optional)

### Steps

1. Clone the project:

```bash
  git clone https://github.com/smercer10/raydiance.git
```

2. Navigate to the project directory:

```bash
  cd raydiance
```

3. Generate the build files:

```bash
  cmake -S . -B build
```

4. Build the project:

```bash
  cmake --build build
```

## Running Tests

The project utilises the GoogleTest framework with CTest.

To execute the testcases, run the following command from the project root:

```bash
  cmake --build build --target test
```

## Contributing

Contributions are always welcome!

See [open issues](https://github.com/smercer10/raydiance/issues) for ways to get started.

## Acknowledgements

The core ray tracing logic is based on the brilliant [Ray Tracing in One Weekend Book Series](https://raytracing.github.io).
