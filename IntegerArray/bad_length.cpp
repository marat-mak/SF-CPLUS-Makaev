#include"bad_length.h"

const char* BadLength::what() const noexcept
{
	return "ERROR: Zero Length!";
}