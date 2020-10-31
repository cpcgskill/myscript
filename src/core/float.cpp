#include "./float.h"
namespace myscript {
	Float::Float(int v) { this->v = v; }
	Float::Float(size v) { this->v = v; }
	Float::Float(float v) { this->v = v; }
	Float::Float(double v) { this->v = v; }

	BaseType Float::__add__(BaseType &o) { return static_cast<Float>(this->v + static_cast<Float*>(&o)->v); }
	BaseType Float::__les__(BaseType &o) { return static_cast<Float>(this->v - static_cast<Float*>(&o)->v); }
	BaseType Float::__mul__(BaseType &o) { return static_cast<Float>(this->v * static_cast<Float*>(&o)->v); }
	BaseType Float::__div__(BaseType &o) { return static_cast<Float>(this->v / static_cast<Float*>(&o)->v); }

}