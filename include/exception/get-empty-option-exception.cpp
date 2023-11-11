#pragma once
#include <string>

class GetEmptyOptionException : public std::exception {
private:
	std::string msg;
public:
	GetEmptyOptionException(std::string option) {
		msg = "The option: " + option + " is empty";
	}

	const char* what() const noexcept {
		return msg.c_str();
	}
};
