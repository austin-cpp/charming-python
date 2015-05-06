# Charming Python

Integrating programming languages can be a challenge. From differences in fundamental types to ownership semantics, it is easy to get lost in the boundary between C++ and Python. This presentation will guide its audience through using a handful of tools, making it easier to add some Python zen into C++ or reuse a battle-tested C++ library in Python.

## Instructions

### Build Environment

In order to capture all build requirements, the demo uses [Docker](http://docker.com), an open-source application container engine, proviomge environment isolation without the overhead of a VM.  Windows and OSX user may wish to use [boot2docker](http://boot2docker.io/).

A `Makefile` in the base directory is used to orchestrate the build process, but one can run the individual docker commands manually if Make is not available on the host machine.  The default target will build and test evertything.

### The `sample` Application

The sample application for which Python bindings are generated is located in the `sample` directory.  It is a small application aimed to capture functionality one may encounter when integrating between the languages.  With the same application being wrapped, one can compare how the tools compare at wrapping certain functionality.

### The `examples` Directory

The `examples` directory contains a subdirectory for each tool being demonstrated.  Each directory will contain non-geneated assets needed during the building process.  The `Makefile` within each directory will contain all instructions on how to generate and compile bindings.

Artifacts placed within the `build` directory are development artifacts not needed when distributing the bindings.  On the other hand, all artifacts needed to be distributed with the bindings are placed within the `dist` directory.  For instance, `build/swig` will contain generated code not needed on the final platform, while `dist/swig` will contain all files one would need to distribute.

### Building Tool From Source

Instructions for building the tools from source can be found in the Dockerfiles:

* Python 2.7: `tools/python/2.7/Dockerfile`
* Boost.Python 1.57.0: `examples/boost_python/dockerfiles/Dockerfile`
* SWIG 3.0.5: `examples/boost_python/dockerfiles/Dockerfile`

## Presentation

To see the slides, open `slides/index.html` in a browser.


## License

Boost licensed.  See LICENSE_1_0.txt.

Copyright (C) 2015 Tanner Sansbury
