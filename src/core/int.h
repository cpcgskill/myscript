#ifndef MYSCRIPTINT
#define MYSCRIPTINT
#include "./basetype.h"
namespace myscript {
	class Int :public BaseType
	{
	public:
		myscript_definition_ID(1);
		int v;
		Int(int v);
		Int(size v);
		Int(float v);
		Int(double v);


		BaseType __add__(BaseType &o);
		BaseType __les__(BaseType &o);
		BaseType __mul__(BaseType &o);
		BaseType __div__(BaseType &o);

	private:
		
	};
}


#endif