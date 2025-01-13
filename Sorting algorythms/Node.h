#pragma once

#include <iostream>
#include <string>
#include <sstream>

template <typename T>

struct Node {
	T value;

	Node(const T& v) : value(v){}

	Node() : value() {}

	T get() {
		return value;
	}

	void set(T input) {
		value = input;
	}

	std::string str() const {
		std::ostringstream oss;
		oss << value;
		return oss.str();
	}

	bool operator==(const Node& other) const { 
		return value == other.value; 
	}
	bool operator!=(const Node& other) const {
		return !(*this == other);
	}
	bool operator<(const Node& other) const { 
		return value < other.value; 
	}
	bool operator>(const Node& other) const { 
		return value > other.value; 
	}

	Node(const Node& other) : value(other.value) {}

	Node& operator=(const Node& other) {
		if (this != &other) {
			value = other.value;
		}
		return *this;
	}

	Node(Node&& other) noexcept : value(std::move(other.value)) {}

	Node& operator=(Node&& other) noexcept {
		if (this != &other) {
			value = std::move(other.value);
		}
		return *this;
	}
};