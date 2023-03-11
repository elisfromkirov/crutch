#include <wheels/format/format.hpp>

#include <wheels/test/test_framework.hpp>

#include <format/util/arg.hpp>

TEST_SUITE(FormatUnit) {
  TEST(FormatStringWithoutArguments) {
    wheels::StringView expected_string{"format string without arguments"};

    wheels::String string = wheels::Format("format string without arguments");

    ASSERT_EQ(string, expected_string);
  }

  TEST(FormatStringWithInts) {
    wheels::StringView expected_string{"-1 2 -3 4"};

    auto string = wheels::Format("{} {} {} {}",
                                 static_cast<Int8>(-1),
                                 static_cast<Int16>(2),
                                 static_cast<Int32>(-3),
                                 static_cast<Int64>(4));

    ASSERT_EQ(string, expected_string);
  }

  TEST(FormatStringWithUints) {
    wheels::StringView expected_string{"15 26 37 48"};

    wheels::String string = wheels::Format("{} {} {} {}",
                                           static_cast<Uint8>(15),
                                           static_cast<Uint16>(26),
                                           static_cast<Uint32>(37),
                                           static_cast<Uint64>(48));

    ASSERT_EQ(string, expected_string);
  }

  TEST(FormatStringWithCustomArg) {
    wheels::StringView expected_string{"custom argument and string with 15"};

    wheels::String string = wheels::Format("{} and {} with {}", Arg{}, "string", 15);

    ASSERT_EQ(string, expected_string);
  }
}