Build files
```
cd CPU_emulator
```
```
mkdir build
cd build
cmake ..
cmake --build .
```
Tests result (in "build" dir)
```
cd test
ctest
cd ..
```

Web-interface of tests coverage (download lcov: sudo apt install lcov) ((coverage result file: build/out/index.html))
```
lcov -c -d . -o main_coverage.info
genhtml main_coverage.info --output-directory out
```

