
#include "./basetype.h"
namespace myscript {
	class NullType : public BaseType
	{
	public:
		myscript_definition_ID(0);
	};
	static NullType Null;
	static NullType Nullb;
}


