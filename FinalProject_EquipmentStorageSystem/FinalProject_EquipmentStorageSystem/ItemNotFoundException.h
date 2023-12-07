#pragma once

#include <stdexcept>

class ItemNotFoundException : public std::runtime_error {
public:
	ItemNotFoundException() : std::runtime_error{ "The item was not found in the units inventory" } {
	}
};