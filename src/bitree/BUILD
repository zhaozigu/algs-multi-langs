# 二叉树
cc_library(
  name = "bitree",
  copts = ["-g", "-Wall", "-O3"],
  hdrs = ["bitree.h", "traverse.h"],
  srcs = ["bitree.c", "traverse.c"],
  deps = [
    "//src/list:list",
  ]
)

# 二叉搜索树（AVL）
cc_library(
  name = "bistree",
  copts = ["-g", "-Wall", "-O3"],
  hdrs = ["bistree.h"],
  srcs = ["bistree.c"],
  deps = [
    ":bitree"
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

cc_binary(
  name = "bistree_main",
  srcs = ["bistree_main.c"],
  copts = ["-g", "-Wall", "-O3"],
  deps = [
    ":bitree",
    ":bistree"
  ],
)

