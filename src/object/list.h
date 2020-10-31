#ifndef MYSCRIPTLIST
#define MYSCRIPTLIST
#include <list>
#include "../core/basetype.h"
namespace myscript {
	namespace object {
		class List :public BaseType
		{
		public:
			List();
			List(size len);
			BaseType append(BaseType& v);
		private:
			list<BaseType> o;
		};
	}
}
#endif
