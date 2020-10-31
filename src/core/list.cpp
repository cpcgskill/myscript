#include "./list.h"
#include "./null.h"
namespace myscript {
	List::List(){
		o = list<BaseType>(0);
	}
	List::List(size len) {
		o = list<BaseType>(len);
	}
	BaseType List::append(BaseType &v) {
		o.push_back(v);
		return Null;
	}
}