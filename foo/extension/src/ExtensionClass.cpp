#include "foo/ExtensionClass.hpp"
#include "foo/CoreClass.hpp"

namespace foo {

	int ExtensionClass::number() const
	{
		CoreClass coreObject;
		return coreObject.number() + 1;
	}
}
