#ifndef MYSCRIPTFLOAT
#define MYSCRIPTFLOAT
#include "../core/basetype.h"
namespace myscript {
	namespace object {
		class Float :public BaseType
		{
		public:
			myscript_definition_ID(2);
			float v;
			Float(int v);
			Float(size v);
			Float(float v);
			Float(double v);


			
			virtual BaseType __add__(BaseType& o);
			virtual BaseType __les__(BaseType& o);
			virtual BaseType __mul__(BaseType& o);
			virtual BaseType __div__(BaseType& o);
		private:

		};
	}
}


#endif