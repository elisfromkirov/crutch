#pragma once

#include <wheels/utility/source_location.hpp>

#define HERE() ::wheels::SourceLocation{__FILE__, __LINE__, __func__}