load("//:junit5.bzl", "java_junit5_test")

java_binary(
  name = "AlgsDrawExample",
  srcs = [
    "AlgsDrawExample.java"
  ],
  deps = [
    "//third_party:algs4"
  ]
)

java_library(
  name = "myadd_java",
  srcs = ["MyAdd.java"],
)

java_junit5_test(
    name = "MyAddTests_Java",
    srcs = glob([
      "MyAddTests.java",
    ]),
    test_package = "alpha",
    deps = [
      ":myadd_java"
    ]
)

py_test(
  name = "MyAddTests_Python",
  srcs = [
    "myaddtests.py",
    "myadd.py",
  ],
  main = "myaddtests.py"
)

cc_library(
  name = "myadd_cc",
  hdrs = ["myadd.hpp"],
  srcs = ["myadd.cpp"]
)

cc_test(
  name = "MyAddTests_Cpp",
  srcs = ["AddTests.cc"],
  deps = [
    ":myadd_cc",
    "@com_google_googletest//:gtest_main",
  ]
)

cc_test(
  name = "fib_benchmark",
  srcs = ["fib_benchmark.cc"],
  deps = [
    "@com_google_benchmark//:benchmark_main",
  ]
)