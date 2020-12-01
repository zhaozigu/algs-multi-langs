cc_library(
  name = "qsort",
  copts = ["-g", "-Wall", "-O3"],
  hdrs = ["sort.h"],
  srcs = ["qksort.c"],
)

cc_binary(
  name = "qsort_main",
  srcs = ["qsort_main.c"],
  copts = ["-g", "-Wall", "-O3"],
  deps = [
    ":qsort",
  ],
)

# 三行代码实现快速排序
py_test(
  name = "qsort_functional_python",
  srcs = [
    "qsort_functional.py",
  ],
  main = "qsort_functional.py"
)
