#pragma once

#include <stdexcept>

class NegativeNumberException : public std::runtime_error {
public:
	NegativeNumberException() : std::runtime_error{ "The number you have entered is a negative number." } {
	}
};