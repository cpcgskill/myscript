#include "./error.h"
namespace myscript {
	Error::Error(const Char* type, const Char* message) {
		size len = 0;
		while (type[len] != L'\0')
		{
			len++;
		}
		this->type = new Char[len];
		for (size i = 0; i < len; i++) {
			this->type[i] = type[i];
		}

		len = 0;
		while (message[len] != L'\0')
		{
			len++;
		}
		this->message = new Char[len];
		for (size i = 0; i < len; i++) {
			this->message[i] = message[i];
		}

	}
	Error::Error(Char* type, Char* message) {
		this->type = type;
		this->message;
	}
	Error::~Error() {
		delete[] this->type;
		delete[] this->message;
	}
}