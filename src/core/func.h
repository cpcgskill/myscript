#ifndef MYSCRIPTFUNC
#define MYSCRIPTFUNC
#include "./basetype.h"
#include "./null.h"
namespace myscript {
	class Func :public BaseType
	{
	public:
		myscript_definition_ID(3);
		BaseType __doIt__(BaseType args, BaseType keyargs);
	};
}
#endif

