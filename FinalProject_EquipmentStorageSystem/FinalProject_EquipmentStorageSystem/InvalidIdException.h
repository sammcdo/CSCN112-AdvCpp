#pragma once

#include <stdexcept>

class InvalidIdException : public std::runtime_error {
public:
	InvalidIdException() : std::runtime_error{ "The item provided has an ID that is already in use." } {
	}
};