#include <wheels/format/format.hpp>

#include <wheels/string/string_comparison.hpp>

#include <wheels/test/test_framework.hpp>

#include <format/util/arg.hpp>

TEST_SUITE(FormatUnit) {
  TEST(FormatStringWithoutArguments) {
    wheels::StringView expected_string{"format string without arguments"};

    wheels::String string = wheels::Format("format string without arguments");

    ASSERT_TRUE(Equal(string, expected_string));
  }

  TEST(FormatStringWithInts) {
    wheels::StringView expected_string{"-1 2 -3 4"};

    auto string = wheels::Format("{} {} {} {}",
                                 static_cast<wheels::Int8>(-1),
                                 static_cast<wheels::Int16>(2),
                                 static_cast<wheels::Int32>(-3),
                                 static_cast<wheels::Int64>(4));

    ASSERT_TRUE(Equal(string, expected_string));
  }

  TEST(FormatStringWithUints) {
    wheels::StringView expected_string{"15 26 37 48"};

    wheels::String string = wheels::Format("{} {} {} {}",
                                           static_cast<wheels::Uint8>(15),
                                           static_cast<wheels::Uint16>(26),
                                           static_cast<wheels::Uint32>(37),
                                           static_cast<wheels::Uint64>(48));

    ASSERT_TRUE(Equal(string, expected_string));
  }

  TEST(FormatStringWithCustomArg) {
    wheels::StringView expected_string{"custom argument and string with 15"};

    wheels::String string = wheels::Format("{} and {} with {}", Arg{}, "string", 15);

    ASSERT_TRUE(Equal(string, expected_string));
  }
}