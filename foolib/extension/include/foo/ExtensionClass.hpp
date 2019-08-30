#ifndef FOO_EXTENSIONCLASS_H
#define FOO_EXTENSIONCLASS_H

#include "FooExport.hpp"

namespace foo {

	class FOO_EXPORT ExtensionClass
	{
	public:
		ExtensionClass() = default;

		int number() const;
	};
}

#endif