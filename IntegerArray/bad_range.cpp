#include"bad_range.h"

const char* BadRange::what() const noexcept
{
	return "ERROR: Out Of Range!";
}