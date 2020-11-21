cc_library(
  name = "bitree",
  copts = ["-g", "-Wall", "-O3"],
  hdrs = ["bitree.h"],
  srcs = ["bitree.c"],
)

cc_binary(
  name = "bitree_main",
  srcs = ["bitree_main.c"],
  copts = ["-g", "-Wall", "-O3"],
  deps = [
    ":bitree",
  ],
)
