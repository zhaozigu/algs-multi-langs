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
