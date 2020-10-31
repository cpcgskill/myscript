
#include "../core/basetype.h"
namespace myscript {
	namespace object {
		class NullType : public BaseType
		{
		public:
			myscript_definition_ID(0);
		};
		static NullType Null;
		static NullType Nullb;
	}
}


