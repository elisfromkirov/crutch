#pragma once

namespace crutch {

/**
 * @brief Construct object of specified type at specified memory location from
 * given arguments.
 *
 * @param place Memory location where the object to be constructed is placed.
 * @param args Arguments for constructor.
 */
template <typename Type, typename... ArgTypes>
void ConstructAt(Type* place, ArgTypes&&... args);

/**
 * @brief Destroy object of specified type at specified memory location.
 *
 * @param place Memory location where the object to be destroyed is placed.
 */
template <typename Type>
void DestroyAt(Type* place) noexcept;

}  // namespace crutch

#define PLACEMENT_IMPL
#include <crutch/utiltiy/placement.ipp>
#undef PLACEMENT_IMPL