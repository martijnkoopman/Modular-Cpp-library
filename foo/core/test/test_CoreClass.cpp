#include <foo/CoreClass.hpp>

int main()
{
	// Validate that CoreClass::number() returns 1
	foo::CoreClass coreObject;
	return (coreObject.number() == 1 ? 0 : 1);
	// Return 0 if expected, 1 otherwise
}