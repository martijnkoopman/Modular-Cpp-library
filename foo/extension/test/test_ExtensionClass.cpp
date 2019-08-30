#include <foo/ExtensionClass.hpp>

int main()
{
	// Validate that ExtensionClass::number() returns 2
	foo::ExtensionClass extObject;
	return (extObject.number() == 2 ? 0 : 1);
	// Return 0 if expected, 1 otherwise
}