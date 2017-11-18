#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <vector>
#include "str_manip/split.h"

TEST_CASE("Split a simple string", "[split_string]") {
  auto split = slt::split(std::string_view("aa:bb:c"), std::string_view(":"));

  auto begin = split.begin();
  auto end = split.end();

  REQUIRE(begin != end);
  REQUIRE(*begin++ == "aa");

  REQUIRE(begin != end);
  REQUIRE(*begin++ == "bb");

  REQUIRE(begin != end);
  REQUIRE(*begin++ == "c");

  REQUIRE(begin == end);
}

TEST_CASE("Split using a long delimiter", "[split_string]") {
  auto split =
      slt::split(std::string_view("aa::bb::c"), std::string_view("::"));

  auto begin = split.begin();
  auto end = split.end();

  REQUIRE(begin != end);
  REQUIRE(*begin++ == "aa");

  REQUIRE(begin != end);
  REQUIRE(*begin++ == "bb");

  REQUIRE(begin != end);
  REQUIRE(*begin++ == "c");

  REQUIRE(begin == end);
}

TEST_CASE("Split an empty string", "[split_string]") {
  auto split = slt::split(std::string_view(""), std::string_view(":"));

  auto begin = split.begin();
  auto end = split.end();

  REQUIRE(begin == end);
}

TEST_CASE("delimiter prefix", "[split_string]") {
  auto split = slt::split(std::string_view(":aa"), std::string_view(":"));

  std::vector<std::string_view> as_vec(split.begin(), split.end());

  REQUIRE(as_vec.size() == 2);
  REQUIRE(as_vec[0] == "");
  REQUIRE(as_vec[1] == "aa");
}

TEST_CASE("delimiter postfix", "[split_string]") {
  auto split = slt::split(std::string_view("aa:"), std::string_view(":"));

  std::vector<std::string_view> as_vec(split.begin(), split.end());

  REQUIRE(as_vec.size() == 2);
  REQUIRE(as_vec[0] == "aa");
  REQUIRE(as_vec[1] == "");
}

TEST_CASE("only a delim", "[split_string]") {
  auto split = slt::split(std::string_view(":"), std::string_view(":"));

  std::vector<std::string_view> as_vec(split.begin(), split.end());

  REQUIRE(as_vec.size() == 2);
  REQUIRE(as_vec[0] == "");
  REQUIRE(as_vec[1] == "");
}

TEST_CASE("delimiter not found", "[split_string]") {
  auto split = slt::split(std::string_view("aabbcc"), std::string_view(":"));

  std::vector<std::string_view> as_vec(split.begin(), split.end());

  REQUIRE(as_vec.size() == 1);
  REQUIRE(as_vec[0] == "aabbcc");
}

TEST_CASE("sequential delimiters", "[split_string]") {
  auto split = slt::split(std::string_view("aa:::bb"), std::string_view(":"));

  std::vector<std::string_view> as_vec(split.begin(), split.end());

  REQUIRE(as_vec.size() == 4);
  REQUIRE(as_vec[0] == "aa");
  REQUIRE(as_vec[1] == "");
  REQUIRE(as_vec[2] == "");
  REQUIRE(as_vec[3] == "bb");
}