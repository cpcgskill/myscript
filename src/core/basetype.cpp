#include "../core/basetype.h"
#include "./error.h"
namespace myscript {
	//type_id TypeId::BaseObject = 0;
	//type_id TypeId::Int = 1;
	//type_id TypeId::Float = 2;
	//type_id TypeId::String = 3;
	//type_id TypeId::Null = 4;


	BaseType::BaseType() {}
	BaseType::~BaseType() {};
	BaseType BaseType::__getattr__(Char* name) { 
		throw Error(method_error, L"Method not implemented");
	}
	bool BaseType::__setattr__(Char* key, BaseType &val) {
		throw Error(method_error, L"Method not implemented");
	}
	BaseType BaseType::__doIt__(BaseType &args, BaseType &keyargs) { 
		throw Error(method_error, L"Method not implemented");
	}
	BaseType BaseType::__add__(BaseType &o) { 
		throw Error(method_error, L"Method not implemented");
	}
	BaseType BaseType::__les__(BaseType &o) { 
		throw Error(method_error, L"Method not implemented");
	}
	BaseType BaseType::__mul__(BaseType &o) { 
		throw Error(method_error, L"Method not implemented");
	}
	BaseType BaseType::__div__(BaseType &o) { 
		throw Error(method_error, L"Method not implemented");
	}
}