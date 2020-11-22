cc_library(
  name = "bitree",
  copts = ["-g", "-Wall", "-O3"],
  hdrs = ["bitree.h", "traverse.h"],
  srcs = ["bitree.c", "traverse.c"],
  deps = [
    "//src/list:list",
  ]
)

cc_binary(
  name = "bitree_main",
  srcs = ["bitree_main.c"],
  copts = ["-g", "-Wall", "-O3"],
  deps = [
    ":bitree",
  ],
)
