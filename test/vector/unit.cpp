#include "crutch/vector/vector.hpp"

#include "crutch/test/test_framework.hpp"

#include <random>
#include <exception>

TEST_SUITE(VectorUnit) {
  TEST(Iterator) {
    crutch::Vector<int> vector{};
    const crutch::Vector<int>& ref = vector;

    crutch::SizeType num_values{12};
    int values[] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
    };

    for (crutch::SizeType i = 0; i < num_values; ++i) {
      vector.PushBack(values[i]);
    }

    crutch::SizeType i = 0;
    for (auto iterator = vector.Begin(); iterator != vector.End(); ++iterator) {
      ASSERT_EQ(*iterator, values[i++]);
    }
    i = 0;
    for (auto iterator = ref.ConstBegin(); iterator != ref.ConstEnd(); ++iterator) {
      ASSERT_EQ(*iterator, values[i++]);
    }
  }

  TEST(At) {
    crutch::Vector<int> vector{};
    const crutch::Vector<int>& ref = vector;

    crutch::SizeType num_values{12};
    int values[] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
    };

    for (crutch::SizeType i = 0; i < num_values; ++i) {
      vector.PushBack(values[i]);
    }

    for (crutch::SizeType i = 0; i < num_values; ++i) {
      ASSERT_EQ(vector[i], values[i]);
      ASSERT_EQ(vector.At(i), values[i]);
    }
    for (crutch::SizeType i = 0; i < num_values; ++i) {
      ASSERT_EQ(ref[i], values[i]);
      ASSERT_EQ(ref.At(i), values[i]);
    }
  }

  TEST(IsEmpty) {
    crutch::Vector<int> vector{};

    ASSERT_TRUE(vector.IsEmpty());

    vector.PushBack(1);
    ASSERT_FALSE(vector.IsEmpty());

    vector.PushBack(1);
    ASSERT_FALSE(vector.IsEmpty());

    vector.PushBack(1);
    ASSERT_FALSE(vector.IsEmpty());

    vector.PopBack();
    ASSERT_FALSE(vector.IsEmpty());

    vector.PopBack();
    ASSERT_FALSE(vector.IsEmpty());

    vector.PopBack();
    ASSERT_TRUE(vector.IsEmpty());
  }

  TEST(Size) {
    crutch::Vector<int> vector{};

    vector.PushBack(1);
    ASSERT_EQ(vector.Size(), 1);

    vector.PushBack(1);
    ASSERT_EQ(vector.Size(), 2);

    vector.PushBack(1);
    ASSERT_EQ(vector.Size(), 3);

    vector.PopBack();
    ASSERT_EQ(vector.Size(), 2);

    vector.PopBack();
    ASSERT_EQ(vector.Size(), 1);
  }

  TEST(PushBack) {
    crutch::Vector<int> vector{};
    const crutch::Vector<int>& ref = vector;

    vector.PushBack(1);
    ASSERT_EQ(vector.Back(), 1);
    ASSERT_EQ(ref.Back(), 1);

    vector.PushBack(2);
    ASSERT_EQ(vector.Back(), 2);
    ASSERT_EQ(ref.Back(), 2);

    vector.PushBack(3);
    ASSERT_EQ(vector.Back(), 3);
    ASSERT_EQ(ref.Back(), 3);
  }

  TEST(PopBack) {
    crutch::Vector<int> vector{};
    const crutch::Vector<int>& ref = vector;

    vector.PushBack(1);
    ASSERT_EQ(vector.Back(), 1);
    ASSERT_EQ(ref.Back(), 1);

    vector.PushBack(2);
    ASSERT_EQ(vector.Back(), 2);
    ASSERT_EQ(ref.Back(), 2);

    vector.PushBack(3);
    ASSERT_EQ(vector.Back(), 3);
    ASSERT_EQ(ref.Back(), 3);

    vector.PopBack();
    ASSERT_EQ(vector.Back(), 2);
    ASSERT_EQ(ref.Back(), 2);

    vector.PopBack();
    ASSERT_EQ(vector.Back(), 1);
    ASSERT_EQ(ref.Back(), 1);
  }

  TEST(PushBackWithoutReserve) {
    crutch::Vector<int> vector{};

    std::mt19937 gen{42};

    constexpr crutch::SizeType kIterations{4};
    for (crutch::SizeType iteration = 0; iteration < kIterations; ++iteration) {
      int value{static_cast<int>(gen())};
      vector.PushBack(value);
      ASSERT_EQ(vector.Back(), value);
    }
    ASSERT_EQ(vector.Size(), kIterations);
  }

  TEST(PushBackWithReserve) {
    crutch::Vector<int> vector{};

    std::mt19937 gen{42};

    constexpr crutch::SizeType kIterations{12};
    for (crutch::SizeType iteration = 0; iteration < kIterations; ++iteration) {
      int value{static_cast<int>(gen())};
      vector.PushBack(value);
      ASSERT_EQ(vector.Back(), value);
    }
    ASSERT_EQ(vector.Size(), kIterations);
  }

  TEST(PushBackWithReserves) {
    crutch::Vector<int> vector{};

    std::mt19937 gen{42};

    constexpr crutch::SizeType kIterations{36};
    for (crutch::SizeType iteration = 0; iteration < kIterations; ++iteration) {
      int value{static_cast<int>(gen())};
      vector.PushBack(value);
      ASSERT_EQ(vector.Back(), value);
    }
    ASSERT_EQ(vector.Size(), kIterations);
  }

  TEST(CopyOnly) {
    crutch::Vector<crutch::CopyOnly> vector{};

    std::mt19937 gen{42};

    constexpr crutch::SizeType kIterations{36};
    for (crutch::SizeType iteration = 0; iteration < kIterations; ++iteration) {
      int value{static_cast<int>(gen())};
      vector.EmplaceBack(value);
      ASSERT_EQ(vector.Back().value, value);
    }
  }

  TEST(MoveOnly) {
    crutch::Vector<crutch::MoveOnly> vector{};

    std::mt19937 gen{42};

    constexpr crutch::SizeType kIterations{36};
    for (crutch::SizeType iteration = 0; iteration < kIterations; ++iteration) {
      int value{static_cast<int>(gen())};
      vector.EmplaceBack(value);
      ASSERT_EQ(vector.Back().value, value);
    }
  }
}