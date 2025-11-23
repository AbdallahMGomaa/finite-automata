# DFA Abstract Data Type
---

## 🧩 Build Instructions

This project uses **CMake** as its build system.  
Follow the steps below to build and run the project.

### 1. first create a build directory

```bash
mkdir build
cd build
```

### 2. build the project
```bash
cmake ..
make
```
### 3. run the DFA executable
```bash
./test_DFA
```

### 3. run the NFA_to_DFA executable
```bash
./NFA_to_DFA
```

### (Optional) run using gnu g++
```bash
g++ test_DFA.cpp Alphabet.cpp BST.cpp DFA.cpp State.cpp -o test_DFA
```
