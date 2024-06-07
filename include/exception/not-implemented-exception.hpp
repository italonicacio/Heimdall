#pragma once
#include <string>
#include <stdexcept>

class NotImplementedException : public std::logic_error {
public:
	NotImplementedException(std::string& function)
		: std::logic_error{ function + " not implemented!" } {}
};
