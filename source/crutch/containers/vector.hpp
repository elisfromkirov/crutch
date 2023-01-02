#pragma once

#include "crutch/allocators/new_allocator.hpp"
#include "crutch/core/assert.hpp"
#include "crutch/core/types.hpp"

#include "crutch/containers/detail/vector_base.hpp"

namespace crutch {

/**
 * @brief Sequential container that encapsulates dynamically growing arrays.
 */
template <typename Type, typename Allocator = NewAllocator<Type>>
class Vector : protected detail::VectorBase<Type, Allocator> {
 public:
  static_assert(!::std::is_reference<Type>::value,
                "Reference types are not supported");

 public:
  /**
   * @brief Default capacity value.
   */
  static constexpr SizeType kDefaultCapacity{8};

  /**
   * @brief Growth factor value.
   */
  static constexpr SizeType kCapacityGrowthFactor{2};

 public:
  /**
   * @breif Constructs empty vector with default capacity.
   */
   Vector();

  /**
   * @brief Returns reference to element specified by index.
   *
   * @return Reference to element specified by index.
   *
   * @warning If code is compiled in debug mode then method has an assertion
   * that checks that given index is less than size of vector.
   * @warning If code is compiled in release mode then method's behaviour
   * is undefined if given index is not less than size of vector.
   */
  Type& operator[](SizeType index) noexcept;

  /**
   * @brief Returns const reference to element specified by index.
   *
   * @return Const reference to element specified by index.
   *
   * @warning If code is compiled in debug mode then method has an assertion
   * that checks that given index is less than size of vector.
   * @warning If code is compiled in release mode then method's behaviour
   * is undefined if given index is not less than size of vector.
   */
  const Type& operator[](SizeType index) const noexcept;

  /**
   * @brief Returns reference to element specified by index.
   *
   * @return Reference to element specified by index.
   *
   * @warning If code is compiled in debug mode then method has an assertion
   * that checks that given index is less than size of vector.
   * @warning If code is compiled in release mode then method's behaviour
   * is undefined if given index is not less than size of vector.
   */
  Type& At(SizeType index) noexcept;

  /**
   * @brief Returns reference to element specified by index.
   *
   * @return Reference to element specified by index.
   *
   * @warning If code is compiled in debug mode then method has an assertion
   * that checks that given index is less than size of vector.
   * @warning If code is compiled in release mode then method's behaviour
   * is undefined if given index is not less than size of vector.
   */
  const Type& At(SizeType index) const noexcept;

  /**
   * @brief Returns reference to last element of vector.
   *
   * @return Reference to last element of vector.
   *
   * @warning If code is compiled in debug mode then method has an assertion
   * that checks that vector is not empty.
   * @warning If code is compiled in release mode then method's behaviour is
   * undefined if vector is empty.
   */
  Type& Back() noexcept;

  /**
   * @brief Returns const reference to last element of vector.
   *
   * @return Const reference to last element of vector.
   *
   * @warning If code is compiled in debug mode then method has an assertion
   * that checks that vector is not empty.
   * @warning If code is compiled in release mode then method's behaviour is
   * undefined if vector is empty.
   */
  const Type& Back() const noexcept;

  /**
   * @brief Returns pointer to internal buffer.
   *
   * @return Pointer to internal buffer.
   */
  Type* Data() noexcept;

  /**
   * @brief Returns const pointer to internal buffer.
   *
   * @return Const pointer to internal buffer.
   */
  const Type* Data() const noexcept;

  /**
   * @brief Checks whether vector is empty.
   *
   * @return True if vector is empty, otherwise false.
   */
  [[nodiscard]] bool IsEmpty() const noexcept;

  /**
   * @brief Returns number of vector elements.
   *
   * @return Number of vector elements.
   */
  [[nodiscard]] SizeType Size() const noexcept;

  /**
   * @brief Returns maximal number of vector elements that can contained in
   * vector without reallocations.
   *
   * @return Maximal number of vector elements that can contained in
   * vector without reallocations.
   */
  [[nodiscard]] SizeType Capacity() const noexcept;

  /**
   * @brief Increase capacity vector storage to given value.
   *
   * @warning If code is compiled in debug mode then method has an assertion
   * that checks that given capacity is greater than capacity of vector.
   * @warning If code is compiled in release mode then method's behaviour
   * is undefined if given capacity is not greater than capacity of vector.
   */
  void Reserve(SizeType capacity);

  /**
   * @brief Copies given element to end of vector.
   */
  void PushBack(const Type& value);

  /**
   * @brief Moves given element to end of vector.
   */
  void PushBack(Type&& value);

  /**
   * @brief Construct new element at end of vector from given arguments.
   */
  template <typename... ArgTypes>
  void EmplaceBack(ArgTypes&&... args);

  /**
   * @brief Removes last element of vector.
   *
   * @warning If code is compiled in debug mode then method has an assertion
   * that checks that vector is not empty.
   * @warning If code is compiled in release mode then method's behaviour is
   * undefined if vector is empty.
   */
  void PopBack() noexcept;
};

}  // namespace crutch

#define VECTOR_IMPL
#include <crutch/containers/vector.ipp>
#undef VECTOR_IMPL