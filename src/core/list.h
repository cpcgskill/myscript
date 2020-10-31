#ifndef MYSCRIPTLIST
#define MYSCRIPTLIST
#include <list>
#include "./basetype.h"
namespace myscript {
	class List :public BaseType
	{
	public:
		List();
		List(size len);
		BaseType append(BaseType &v);
	private:
		list<BaseType> o;
	};
}
#endif
