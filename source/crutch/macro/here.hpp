#pragma once

#include <crutch/utility/source_location.hpp>

#define HERE() ::crutch::SourceLocation{__FILE__, __LINE__, __func__}