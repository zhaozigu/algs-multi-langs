workspace(name = "algs_multi_langs")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Google Test
http_archive(
  name = "com_google_googletest",
  urls = ["https://github.com/google/googletest/archive/release-1.10.0.zip"],
  strip_prefix = "googletest-release-1.10.0",
  sha256 = "94c634d499558a76fa649edb13721dce6e98fb1e7018dfaeba3cd7a083945e91",
)

# Python Rules
http_archive(
  name = "rules_python",
  url = "https://github.com/bazelbuild/rules_python/releases/download/0.1.0/rules_python-0.1.0.tar.gz",
  sha256 = "b6d46438523a3ec0f3cead544190ee13223a52f6a6765a29eae7b7cc24cc83a0",
)

# JUnit 5
load(":junit5.bzl", "junit_jupiter_java_repositories", "junit_platform_java_repositories")

JUNIT_JUPITER_VERSION = "5.7.0"

JUNIT_PLATFORM_VERSION = "1.7.0"

junit_jupiter_java_repositories(
    version = JUNIT_JUPITER_VERSION,
)

junit_platform_java_repositories(
    version = JUNIT_PLATFORM_VERSION,
)

# Google Benchmark
http_archive(
  name = "com_google_benchmark",
  urls = ["https://github.com/google/benchmark/archive/refs/tags/v1.6.0.zip"],
  strip_prefix = "benchmark-1.6.0",
  sha256 = "3da225763533aa179af8438e994842be5ca72e4a7fed4d7976dc66c8c4502f58",
)
