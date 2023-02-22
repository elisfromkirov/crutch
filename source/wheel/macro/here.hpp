#pragma once

#include <wheel/utility/source_location.hpp>

#define HERE() ::wheel::SourceLocation{__FILE__, __LINE__, __func__}