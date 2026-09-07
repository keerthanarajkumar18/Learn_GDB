# GDB Assignment – Calculator # GDB Assignment Calculator and Expression Processing

## Overview

This assignment demonstrates debugging and troubleshooting of a C++ calculator application using **GDB**.

## Files

* `calculator.h` – Function declarations
* `calculator.cpp` – Calculator implementation
* `main.cpp` – Main program
* `README.md` – Assignment documentation

## Build

### Debug Build

```bash
g++ -g -O0 main.cpp calculator.cpp -o calculator_debug
```

### Release Build

```bash
g++ -O2 main.cpp calculator.cpp -o calculator_release
```

## Run with GDB

```bash
gdb -tui ./calculator_debug
```

Example:

```text
run 10 + 5
```

## GDB Topics Covered

* Breakpoints and conditional breakpoints
* `run`, `continue`, `step`, `next`, and `finish`
* `print`, `display`, `info locals`, and `info args`
* Call stack and stack-frame navigation
* Source-code navigation using `list`
* Watchpoints
* Logical and runtime errors
* Infinite-loop debugging
* Segmentation-fault debugging
* Multi-file debugging
* Logging vs interactive debugging

## Key Commands

```text
break
run
continue
step
next
finish
print
display
info locals
info args
backtrace
frame
list
watch
```

## Conclusion

The assignment provides hands-on practice with GDB to identify program errors, inspect execution state, trace function calls, and verify fixes.
