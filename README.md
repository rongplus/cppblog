CppBlog - A blog to introduce c++ program.
===================================

gRPC is a modern, open source, high-performance remote procedure call (RPC) framework that can run anywhere. gRPC enables client and server applications to communicate transparently, and simplifies the building of connected systems.

<table>
  <tr>
    <td><b>Homepage:</b></td>
    <td><a href="https://rongplus.github.io/">Cpp Blog</a></td>
  </tr>
  <tr>
    <td><b>Mailing List:</b></td>
    <td><a href=""> </a></td>
  </tr>
</table>

[![Join the chat at https://gitter.im/grpc/grpc](https://badges.gitter.im/grpc/grpc.svg)](https://wechat.im/grpc/grpc?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

# To start using Cpp Blog

To maximize usability, gRPC supports the standard method for adding dependencies to a user's chosen language (if there is one).
In most languages, the gRPC runtime comes as a package available in a user's language package manager.

For instructions on how to use the language-specific gRPC runtime for a project, please refer to these documents

 * [C++](cpp): follow the instructions under the `src/cpp` directory
 * [gtest](googletest): NuGet package `Grpc`
 * [boost](boost): pub package `grpc`
 * [stl](stl): Use JARs from Maven Central Repository
 * [Linux](linux): `go get google.golang.org/grpc`
 * [Windows](windows): Use JARs from Maven Central Repository
 * [Qt](qt): `npm install grpc`
 * [openCV](src/objective-c): Add `gRPC-ProtoRPC` dependency to podspec
 * [openGL](src/php): `pecl install grpc`
 * [Python](src/python/grpcio): `pip install grpcio`


Per-language quickstart guides and tutorials can be found in the [documentation section  ](https://google.ca/). Code examples are available in the [examples](examples) directory.

# To start developing gRPC

Contributions are welcome!

Please read [How to contribute](CONTRIBUTING.md) which will guide you through the entire workflow of how to build the source code, how to run the tests, and how to contribute changes to
the gRPC codebase.
The "How to contribute" document also contains info on how the contribution process works and contains best practices for creating contributions.

# Troubleshooting

Sometimes things go wrong. Please check out the [Troubleshooting guide](TROUBLESHOOTING.md) if you are experiencing issues .

# Performance 

See the [Performance dashboard](https://performancard=5652536396611584) for performance numbers of master branch daily builds.

# Concepts

# About This Repository

This repository contains source code for gRPC libraries implemented in multiple languages written on top of a shared C core library [src/core](src/core).

Libraries in different languages may be in various states of development. We are seeking contributions for all of these libraries:

| Language                | Source                              |
|-------------------------|-------------------------------------|
| Shared C [core library] | [src/core](src/core)                |
| C++                     | [src/cpp](src/cpp)                  |
| Ruby                    | [src/ruby](src/ruby)                |
| Python                  | [src/python](src/python)            |
| PHP                     | [src/php](src/php)                  |
| C# (core library based) | [src/csharp](src/csharp)            |
| Objective-C             | [src/objective-c](src/objective-c)  |

