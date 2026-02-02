## Environment Setup (macOS Apple Silicon)

This project is written in C/C++ and uses OpenMP to perform parallel computations.  
The following instructions describe how to configure the development environment on macOS systems with Apple Silicon processors (M1/M2).

---

### Requirements
- macOS (Apple Silicon)
- Homebrew
- Terminal access

---

### Install the C/C++ Compiler

On macOS, the C/C++ compiler is provided through Xcode Command Line Tools.


```xcode-select --install```


### Verify the Compiler Installation
```gcc --version```

Note: On macOS, the gcc command points to clang, which is expected behavior.


### Install OpenMP
OpenMP support on macOS is enabled using the libomp library.

```brew install libomp```

### Verify OpenMP Installation
```brew list | grep libomp```

If libomp appears in the output, OpenMP is correctly installed.

### Compilation with OpenMP

To compile a C program with OpenMP support on macOS Apple Silicon, use the following command:

```clang -Xpreprocessor -fopenmp main.c -I/opt/homebrew/opt/libomp/include -L/opt/homebrew/opt/libomp/lib -lomp -o main```

### Execution
```./main```

#### Notes
- OpenMP is not enabled by default on macOS.
- The libomp library is required to support parallel execution.
- The OpenMP loops in this project are safe for parallel execution since each iteration operates on independent data.