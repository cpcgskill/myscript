#include "./int.h"
namespace myscript {
	namespace object {
		Int::Int(int v) { this->v = v; }
		Int::Int(size v) { this->v = v; }
		Int::Int(float v) { this->v = v; }
		Int::Int(double v) { this->v = v; }

		BaseType Int::__add__(BaseType& o) {
			return static_cast<Int>(this->v + static_cast<Int*>(&o)->v);
		}
		BaseType Int::__les__(BaseType& o) { return static_cast<Int>(this->v - static_cast<Int*>(&o)->v); }
		BaseType Int::__mul__(BaseType& o) { return static_cast<Int>(this->v * static_cast<Int*>(&o)->v); }
		BaseType Int::__div__(BaseType& o) { return static_cast<Int>(this->v / static_cast<Int*>(&o)->v); }
		//type_id Int::__typeid__() {
		//	return 1;
		//}
	}
}