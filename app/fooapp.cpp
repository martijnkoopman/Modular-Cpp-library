#include <iostream>

#include <foo/CoreClass.hpp>
#include <foo/ExtensionClass.hpp>

int main(int argc, char *argv[])
{
	foo::CoreClass coreObject;
	std::cout << "Core number: " << coreObject.number() << std::endl;

	foo::ExtensionClass extObject;
	std::cout << "Extension number: " << extObject.number() << std::endl;

	return 0;
}