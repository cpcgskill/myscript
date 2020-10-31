#ifndef MYSCRIPTCOREH
#define MYSCRIPTCOREH
#include "../core/basetype.h"
namespace myscript {
	enum TolenType
	{
		DATA,
		END,
		CR
	}; 

	class Token
	{
	public:
		Token();
		~Token();
		Char naem;
		BaseType(*tokenbuild)(Token& self);
		Token * self;
	private:

	};
	typedef BaseType(*tokenbuildfunc)(Token& self);
}
#endif // !MYSCRIPTCOREH
