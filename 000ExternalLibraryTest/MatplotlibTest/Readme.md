build sequence

환경변수 설정 필요 (Matplotlib)

환경변수 명 = MATPLOTLIB
값(matplotlib 위치) = C:\DevSoft\matplotlib-cpp-master\matplotlib-cpp-master 

make makefile
'''
mkdir build
cd build
cmake ..
'''


build

```
cmake --build . --config Release
```


오류 발생 시  Snaity Checks 확인 후 주석 처리 필요함.
// Sanity checks; comment them out or change the numpy type below if you're compiling on a platform where they don't apply


// static_assert(sizeof(long long) == 8);
// template <> struct select_npy_type<long long> { const static NPY_TYPES type = NPY_INT64; };
// static_assert(sizeof(unsigned long long) == 8);
// template <> struct select_npy_type<unsigned long long> { const static NPY_TYPES type = NPY_UINT64; };
