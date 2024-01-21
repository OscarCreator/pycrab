# pycrab

A simple `c` library with bindings to python via `cython`.

## Build
This will build the `c` source and the `cython` to a shared object.
```
make CMAKE_BUILD_TYPE=RelWithDebInfo
```

## Test
This will run the test's with `pytest`
```
make test
```
