#include <wheels/vector/vector.hpp>

#include <wheels/test/test_framework.hpp>

#include <random>

TEST_SUITE(VectorUnit) {
  TEST(Iterator) {
    wheels::Vector<int> vector{};

    wheels::SizeType num_values{12};
    int values[] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
    };

    for (wheels::SizeType i = 0; i < num_values; ++i) {
      vector.PushBack(values[i]);
    }

    wheels::SizeType i = 0;
    for (auto iterator = vector.Begin(); iterator != vector.End(); ++iterator) {
      ASSERT_EQ(*iterator, values[i++]);
    }
    i = 0;
    for (auto const_iterator = vector.ConstBegin(); const_iterator != vector.ConstEnd(); ++const_iterator) {
      ASSERT_EQ(*const_iterator, values[i++]);
    }
  }

  TEST(RandomAccess) {
    wheels::Vector<int> vector{};

    wheels::SizeType num_values{12};
    int values[] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
    };

    for (wheels::SizeType i = 0; i < num_values; ++i) {
      vector.PushBack(values[i]);
    }

    auto iterator = vector.Begin() + 4;
    ASSERT_EQ(*iterator, 5);

    auto const_iterator = vector.ConstBegin() + 8;
    ASSERT_EQ(*const_iterator, 9);
  }

  TEST(At) {
    wheels::Vector<int> vector{};
    const wheels::Vector<int>& ref = vector;

    wheels::SizeType num_values{12};
    int values[] = {
        1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12
    };

    for (wheels::SizeType i = 0; i < num_values; ++i) {
      vector.PushBack(values[i]);
    }

    for (wheels::SizeType i = 0; i < num_values; ++i) {
      ASSERT_EQ(vector[i], values[i]);
      ASSERT_EQ(vector.At(i), values[i]);
    }
    for (wheels::SizeType i = 0; i < num_values; ++i) {
      ASSERT_EQ(ref[i], values[i]);
      ASSERT_EQ(ref.At(i), values[i]);
    }
  }

  TEST(IsEmpty) {
    wheels::Vector<int> vector{};

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
    wheels::Vector<int> vector{};

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
    wheels::Vector<int> vector{};
    const wheels::Vector<int>& ref = vector;

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
    wheels::Vector<int> vector{};
    const wheels::Vector<int>& ref = vector;

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
    wheels::Vector<int> vector{};

    std::mt19937 gen{42};

    constexpr wheels::SizeType kIterations{4};
    for (wheels::SizeType iteration = 0; iteration < kIterations; ++iteration) {
      int value{static_cast<int>(gen())};
      vector.PushBack(value);
      ASSERT_EQ(vector.Back(), value);
    }
    ASSERT_EQ(vector.Size(), kIterations);
  }

  TEST(PushBackWithReserve) {
    wheels::Vector<int> vector{};

    std::mt19937 gen{42};

    constexpr wheels::SizeType kIterations{12};
    for (wheels::SizeType iteration = 0; iteration < kIterations; ++iteration) {
      int value{static_cast<int>(gen())};
      vector.PushBack(value);
      ASSERT_EQ(vector.Back(), value);
    }
    ASSERT_EQ(vector.Size(), kIterations);
  }

  TEST(PushBackWithReserves) {
    wheels::Vector<int> vector{};

    std::mt19937 gen{42};

    constexpr wheels::SizeType kIterations{36};
    for (wheels::SizeType iteration = 0; iteration < kIterations; ++iteration) {
      int value{static_cast<int>(gen())};
      vector.PushBack(value);
      ASSERT_EQ(vector.Back(), value);
    }
    ASSERT_EQ(vector.Size(), kIterations);
  }

  TEST(CopyOnly) {
    wheels::Vector<wheels::CopyOnly> vector{};

    std::mt19937 gen{42};

    constexpr wheels::SizeType kIterations{36};
    for (wheels::SizeType iteration = 0; iteration < kIterations; ++iteration) {
      int value{static_cast<int>(gen())};
      vector.EmplaceBack(value);
      ASSERT_EQ(vector.Back().value, value);
    }
  }

  TEST(MoveOnly) {
    wheels::Vector<wheels::MoveOnly> vector{};

    std::mt19937 gen{42};

    constexpr wheels::SizeType kIterations{36};
    for (wheels::SizeType iteration = 0; iteration < kIterations; ++iteration) {
      int value{static_cast<int>(gen())};
      vector.EmplaceBack(value);
      ASSERT_EQ(vector.Back().value, value);
    }
  }
}