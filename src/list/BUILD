cc_library(
  name = "list",
  copts = ["-g", "-Wall", "-O3"],
  hdrs = ["list.h"],
  srcs = ["list.c"],
)

cc_binary(
  name = "list_main",
  srcs = ["list_main.c"],
  copts = ["-g", "-Wall", "-O3"],
  deps = [
    ":list",
  ],
)
