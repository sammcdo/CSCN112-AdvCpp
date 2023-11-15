#pragma once

#include "NegativeNumberException.h"

template <class T>
class Rectangle {

	template <typename T>
	friend std::ostream& operator<<(std::ostream& output, Rectangle<T>& r);

public:
	Rectangle() {
		length = 0;
		width = 0;
	}
	~Rectangle () {}

	T getWidth() {
		return width;
	}
	T getLength() {
		return length;
	}

	void setLength(T height) {
		if (height < 0) {
			throw NegativeNumberException();
		}
		this->length = height;
	}

	void setWidth(T width) {
		if (width < 0) {
			throw NegativeNumberException();
		}
		this->width = width;
	}
private:
	T length;
	T width;
};

template <typename T>
std::ostream& operator<<(std::ostream& output, Rectangle<T>& r) {
	output << "Length = " << r.getLength() << std::endl;
	output << "Width = " << r.getWidth() << std::endl;
	return output;
}