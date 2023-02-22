#include <wheel/format/format.hpp>

#include <wheel/string/string_comparison.hpp>

#include <wheel/test/test_framework.hpp>

#include <format/util/arg.hpp>

TEST_SUITE(FormatUnit) {
  TEST(FormatStringWithoutArguments) {
    wheel::StringView expected_string{"format string without arguments"};

    wheel::String string = wheel::Format("format string without arguments");

    ASSERT_TRUE(Equal(string, expected_string));
  }

  TEST(FormatStringWithInts) {
    wheel::StringView expected_string{"-1 2 -3 4"};

    auto string = wheel::Format("{} {} {} {}",
                                 static_cast<wheel::Int8>(-1),
                                 static_cast<wheel::Int16>(2),
                                 static_cast<wheel::Int32>(-3),
                                 static_cast<wheel::Int64>(4));

    ASSERT_TRUE(Equal(string, expected_string));
  }

  TEST(FormatStringWithUints) {
    wheel::StringView expected_string{"15 26 37 48"};

    wheel::String string = wheel::Format("{} {} {} {}",
                                           static_cast<wheel::Uint8>(15),
                                           static_cast<wheel::Uint16>(26),
                                           static_cast<wheel::Uint32>(37),
                                           static_cast<wheel::Uint64>(48));

    ASSERT_TRUE(Equal(string, expected_string));
  }

  TEST(FormatStringWithCustomArg) {
    wheel::StringView expected_string{"custom argument and string with 15"};

    wheel::String string = wheel::Format("{} and {} with {}", Arg{}, "string", 15);

    ASSERT_TRUE(Equal(string, expected_string));
  }
}