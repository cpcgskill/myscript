#ifndef MYSCRIPTBASEOBJECTH
#define MYSCRIPTBASEOBJECTH
#define DEBUG
#include <typeinfo>
namespace myscript {
	using namespace std;
	typedef wchar_t Char;
	typedef char Byte;
	typedef unsigned int size;
	typedef const unsigned long int type_id;
	//class TypeId
	//{
	//public:
	//	static type_id BaseObject;
	//	static type_id Int;
	//	static type_id Float;
	//	static type_id String;
	//	static type_id Null;
	//private:

	//};
#define myscript_definition_ID(id) virtual type_id __id__() { return ID; }static type_id ID = id
#define myscript_object_ID(obj) obj.__id__()
#define myscript_type_ID(typ) typ::ID
#define myscript_isinstance(obj, cls) (myscript_ObjectTypeId(obj) == myscript_TypeId(cls))
#define myscript_Rttl(obj)	(* (int*)*(int*)&obj)
	typedef type_id (*idfunc)();
	class BaseType
	{
	public:
		myscript_definition_ID(-1);
		BaseType();
		virtual ~BaseType();
		virtual BaseType __getattr__(Char* name);
		virtual bool __setattr__(Char* key, BaseType &val);
		virtual BaseType __doIt__(BaseType &args, BaseType &keyargs);
		virtual BaseType __add__(BaseType &o);
		virtual BaseType __les__(BaseType &o);
		virtual BaseType __mul__(BaseType &o);
		virtual BaseType __div__(BaseType &o);

		//const void* static_value = &value;
		//const TypeData* static_data = &base_data;

		
	private:

	};
}

#endif // !MYSCRIPTBASEOBJECTH
