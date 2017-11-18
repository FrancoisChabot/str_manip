#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "str_manip/join.h"
#include "str_manip/split.h"

#include <string>
#include <vector>

TEST_CASE("Join a vector of strings", "[split_string]") {
  std::vector<std::string> src = {"aa", "bb", "cc"};

  auto joined = slt::join(src.begin(), src.end(), std::string_view(":"));

  std::string joined_as_string(joined.begin(), joined.end());

  REQUIRE(joined_as_string == "aa:bb:cc");
}

TEST_CASE("Join with longer delimiter", "[split_string]") {
  std::vector<std::string> src = {"aa", "bb", "cc"};

  auto joined = slt::join(src.begin(), src.end(), std::string_view("+++"));

  std::string joined_as_string(joined.begin(), joined.end());

  REQUIRE(joined_as_string == "aa+++bb+++cc");
}

TEST_CASE("Join with empty delimiter", "[split_string]") {
  std::vector<std::string> src = {"aa", "bb", "cc"};

  auto joined = slt::join(src.begin(), src.end(), std::string_view(""));

  std::string joined_as_string(joined.begin(), joined.end());

  REQUIRE(joined_as_string == "aabbcc");
}

TEST_CASE("Join with empty strings", "[split_string]") {
  std::vector<std::string> src = {"", "", ""};

  auto joined = slt::join(src.begin(), src.end(), std::string_view(":"));

  std::string joined_as_string(joined.begin(), joined.end());

  REQUIRE(joined_as_string == "::");
}

TEST_CASE("Join an empty range", "[split_string]") {
  std::vector<std::string> src;

  auto joined = slt::join(src.begin(), src.end(), std::string_view(":"));

  std::string joined_as_string(joined.begin(), joined.end());

  REQUIRE(joined_as_string == "");
}

TEST_CASE("Join an empty range of empties with empty delimiter",
          "[split_string]") {
  std::vector<std::string> src = {"", "", ""};

  auto joined = slt::join(src.begin(), src.end(), std::string_view(""));

  std::string joined_as_string(joined.begin(), joined.end());

  REQUIRE(joined_as_string == "");
}

TEST_CASE("Mixed empties with data", "[split_string]") {
  std::vector<std::string> src = {"", "a", "", "", "b", ""};

  auto joined = slt::join(src.begin(), src.end(), std::string_view("-"));

  std::string joined_as_string(joined.begin(), joined.end());

  REQUIRE(joined_as_string == "-a---b-");
}

TEST_CASE("Mixed empties with data no delim", "[split_string]") {
  std::vector<std::string> src = {"", "a", "", "", "b", ""};

  auto joined = slt::join(src.begin(), src.end(), std::string_view(""));

  std::string joined_as_string(joined.begin(), joined.end());

  REQUIRE(joined_as_string == "ab");
}

TEST_CASE("Join collection of string views", "[split_string]") {
  std::string data = "ab";
  std::vector<std::string_view> src = {data, data, data};

  auto joined = slt::join(src.begin(), src.end(), std::string_view(":"));

  std::string joined_as_string(joined.begin(), joined.end());

  REQUIRE(joined_as_string == "ab:ab:ab");
}

TEST_CASE("Split and rejoin", "[split_string]") {
  std::string data = "a-b-c-d";
  auto split = slt::split(std::string_view(data), std::string_view("-"));

  auto rejoined = slt::join(split.begin(), split.end(), std::string_view("+"));

  std::string joined_as_string(rejoined.begin(), rejoined.end());

  REQUIRE(joined_as_string == "a+b+c+d");
}