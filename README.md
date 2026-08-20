# libhttp

`libhttp` is a minimalistic C++ library for implementing HTTP communication
with a small, modular, and protocol-oriented API.

The project is intended to provide the fundamental building blocks required
to work with HTTP without forcing higher-level application code to depend on
a large or monolithic networking framework.

## Purpose

The purpose of `libhttp` is to provide a focused HTTP implementation that
separates HTTP concepts from the underlying transport and allows the
different protocol versions to share common HTTP abstractions.

The library is intended to cover the HTTP protocol family while keeping its
public API small and its internal components independently usable.

## Design

The library is organized around several layers.

### Core

The core layer contains the fundamental HTTP types shared by the different
protocol versions.

This includes:

- HTTP requests and responses
- HTTP methods
- HTTP status codes
- HTTP headers
- HTTP message bodies
- URI representation
- Common HTTP types and errors

These components should remain independent of any particular network
transport or HTTP protocol version.

### HTTP/1

The HTTP/1 implementation provides the components required to represent,
parse, serialize, and manage HTTP/1 connections.

The HTTP/1 layer is responsible for protocol-specific behavior while using
the common types provided by the core layer.

### HTTP/2

The HTTP/2 implementation provides the protocol primitives required for
HTTP/2 communication.

This includes concepts such as:

- Frames
- Streams
- HPACK header compression
- HTTP/2 connections
- HTTP/2 protocol state

### HTTP/3

The HTTP/3 implementation provides the protocol primitives required for
HTTP/3 communication.

HTTP/3 is separated from the HTTP/1 and HTTP/2 implementations because it
uses QUIC as its transport rather than TCP.

The HTTP/3 layer includes protocol, stream, and QPACK-related components.

### Transport

The transport layer provides abstractions for the underlying network
connections used by the HTTP implementations.

The initial transport model includes:

- TCP
- TLS
- QUIC

Keeping transport separate from the HTTP protocol layers allows protocol
implementations to operate independently from the details of the underlying
network connection.

## Client API

The client layer provides higher-level functionality for applications that
need to initiate HTTP requests.

It is intended to build on top of the core, protocol, and transport layers
rather than duplicate their functionality.

## Goals

The primary goals of `libhttp` are:

- Provide a minimal HTTP API for C++ applications.
- Keep HTTP message types independent from network transports.
- Separate protocol versions into independent components.
- Provide reusable protocol primitives rather than one large abstraction.
- Keep the public API understandable and predictable.
- Allow the implementation to evolve without coupling unrelated layers.
- Provide a foundation that can support HTTP/1, HTTP/2, and HTTP/3.

## Non-Goals

`libhttp` is not intended to be a complete web framework.

It does not aim to provide application-level functionality such as routing,
templating, REST frameworks, web application middleware, or server-side
application logic.

Those concerns should remain outside of the HTTP protocol library.

## Project Status

`libhttp` is in early development.

The current repository represents the beginning of the project and the API,
architecture, and protocol implementations are expected to evolve as
development progresses.

Until the project reaches a stable stage, interfaces should be considered
experimental and may change without preserving backward compatibility.

## License

See `LICENSE` for licensing information.
