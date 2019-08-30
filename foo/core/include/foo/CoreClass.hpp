#ifndef FOO_CORECLASS_H
#define FOO_CORECLASS_H

#include "FooExport.hpp"

namespace foo {

	class FOO_EXPORT CoreClass
	{
	public:
		CoreClass() = default;

		int number() const;
	};
}

#endif