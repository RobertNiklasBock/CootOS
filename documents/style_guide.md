# Coding Style Guide

## Namespaces
Namespaces are implemented as prefixes for function names, struct names and method names. They are written in snake case and have the following schema: `ns_subns_subsubns_[...]__` the double-underscore ends the prefix.


## Functions
A function name is written in lower camel case. There is no predefined schema, but an example would be `roundToNearestOddNumber`. 

Arguments for functions are always sorted based on there direction of information flow. The order is: `[in], [inout], [out]`.

A function in a namepspace would look like this: `util_math__roundToNearstOddNumber`.


## Structs
A struct name is written in upper camel case. There is no predefined schma, but an example would be `BufferedMessage`. 

Struct types are named as their associated struct, but a `_t` suffix is appended. The type for out example struct would be `BufferedMessage_t`.

When prepended with a namespace, it could look like this: `comm_msg__BufferedMessage` or `comm_msg__BufferedMessage_t`.


## Methods
Methods are functions designed to work on a specific instance of a struct. They are named in lower camel case and prefixed by the corresponding structs name. 

Example: `BufferedMessage__getType`. Also the pointer to the corresponding struct **must** be the first argument to this function.

With namespacing, it would look like this: `comm_msg__BufferedMessage__getType`.


## Header Files
Each header file is guarded by the following directives:
```C
#pragma once
#define NASP(name) ns_subns_subsubns__##name

/* content */

#undef NASP
```

