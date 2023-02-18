#include <crutch/format/format.hpp>

#include <crutch/string/string_comparison.hpp>

#include <crutch/test/test_framework.hpp>

#include <format/util/arg.hpp>

TEST_SUITE(FormatUnit) {
  TEST(FormatStringWithoutArguments) {
    crutch::StringView expected_string{"format string without arguments"};

    crutch::String string = crutch::Format("format string without arguments");

    ASSERT_TRUE(Equal(string, expected_string));
  }

  TEST(FormatStringWithInts) {
    crutch::StringView expected_string{"-1 2 -3 4"};

    auto string = crutch::Format("{} {} {} {}",
                                 static_cast<crutch::Int8>(-1),
                                 static_cast<crutch::Int16>(2),
                                 static_cast<crutch::Int32>(-3),
                                 static_cast<crutch::Int64>(4));

    ASSERT_TRUE(Equal(string, expected_string));
  }

  TEST(FormatStringWithUints) {
    crutch::StringView expected_string{"15 26 37 48"};

    crutch::String string = crutch::Format("{} {} {} {}",
                                           static_cast<crutch::Uint8>(15),
                                           static_cast<crutch::Uint16>(26),
                                           static_cast<crutch::Uint32>(37),
                                           static_cast<crutch::Uint64>(48));

    ASSERT_TRUE(Equal(string, expected_string));
  }

  TEST(FormatStringWithCustomArg) {
    crutch::StringView expected_string{"custom argument and string with 15"};

    crutch::String string = crutch::Format("{} and {} with {}", Arg{}, "string", 15);

    ASSERT_TRUE(Equal(string, expected_string));
  }
}