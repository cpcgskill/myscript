#ifndef MYSCRIPTERROR
#define MYSCRIPTERROR
#include "../core/basetype.h"
namespace myscript {
	class Error
	{
	public:
		Error(const Char* type, const Char* message);
		Error(Char* type, Char* message);
		~Error();
		Char* type;
		Char* message;
	private:

	};
	static const Char* func_error = L"Function error";
	static const Char* method_error = L"Method error";
	static const Char* string_error = L"String error";
	static const Char* lexical_error = L"Lexical error";
	// 
	//void raise(const Char* type, const Char* message) {
	//	Error err = { type, message };
	//	throw err;
	//}
	//void raise(Char* type, Char* message) {
	//	Error err = { type, message };
	//	throw err;
	//}
}
#endif