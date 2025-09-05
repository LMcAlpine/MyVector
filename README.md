# MyVector
MyVector is a small C++ project that demonstrates how to implement a templated dynamic array from scratch.
It mirrors a subset of the functionality offered by std::vector and includes a GoogleTest-based suite for
verifying program behavior.

## Features
- Generic dynamic array of MyVector<T> that stores elements of any type and resizes automatically.

- Core operations

  - ```insert(item, index)```

  - ```remove(index)```

  - ```contains(item)```

  - ```indexOf(item)```

  - ```get(index)```
  - ```set(index, item)```

  - ```getSize()```

  - ```isEmpty()```

  - ```clear()```

  - ```print()```

- Automatic resizing where capacity begins at 16 and doubles when needed.

- Unit tests in MyVectorTest.cpp testing insertion, removal, resizing, lookup, and boundary cases using Google Test.

## Project Structure

```graphql
MyVector/
├─ CMakeLists.txt      # Build configuration (expects GoogleTest in a 'googletest' subdirectory)
├─ MyVector.h          # Class declaration and inline methods
├─ MyVector_impl.h     # Templated member-function definitions
└─ MyVectorTest.cpp    # Google Test suite
```
