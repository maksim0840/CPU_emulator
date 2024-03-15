Open console in dir
```
cd CPU_emulator
```

Run programm (in "cpu_emulator" dir)
```
./main fib.txt
```

Build files
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

Download lcov to see test results
```
sudo apt install lcov
```

Create web-interface of tests coverage (in "build" dir)s
```
lcov -c -d . -o main_coverage.info
genhtml main_coverage.info --output-directory out
```

Coverage result (in "build" dir)
```
./out/index.html
```