#include "./lex.h"
namespace myscript {
	namespace lex {
		Lex::Lex(getmarkfunc* funcs) {
			len = 0;
			while (funcs[len] != nullptr)
			{
				len++;
			}
			this->funcs = funcs;
		}
		Lex::Lex(const getmarkfunc* funcs)
		{
			len = 0;
			while (funcs[len] != nullptr)
			{
				len++;
			}
			this->funcs = new getmarkfunc[len];
			for (size i = 0; i < len; i++) {
				this->funcs[i] = funcs[i];
			}

		}

		Lex::~Lex()
		{
			delete[] this->funcs;
		}

		void Lex::run(Char* code) {
			// 最后生成的Mark对象列表
			list<Mark> marks;
			/*marks.push_back();*/
			// 保存一个ptr
			Char* ptr = code;
			// 临时的marks数组
			Mark * test_marks = new Mark [this->len];
			//array<Mark*> test_marks;
			while ((* ptr) != L'\0')
			{
				if (*ptr != L' '){
					// 生成结果
					for (size i = 0; i < this->len; i++) {
						test_marks[i] = this->funcs[i](ptr);
						//test_marks[i]->start = ptr;
					}
					// 判断结果是否未空{nullptr，。。}如果不为空则使用长的结果
					Mark this_mark = null_mark;
					for (size i = 0; i < this->len; i++) {
						// 是否不为空
						if (test_marks[i].type != MarkType::_ERRROR) {
							if (this_mark.len < test_marks[i].len) {
								//delete this_mark;
								this_mark = test_marks[i];
							}
						}
					}
					if (this_mark.type == MarkType::_ERRROR) {
						throw Error(lexical_error, L"lexical error");
					}
					this_mark.start = ptr;
					marks.push_back(this_mark);
					ptr += this_mark.len;

				}
				else {
					ptr++;
				}
			}
			delete[] test_marks;
			//for (auto i : marks) {
			//	delete i;
			//}
//#ifdef  DEBUG
//			printf
//#endif //  DEBUG

		}
		void Lex::run(const Char* code) {
			this->run((Char *) code);
		}

		Mark Int(Char* s) {
			size id = 0;
			while (true)
			{
				if (s[id] == L'0'|| s[id] == L'1'|| s[id] == L'2' || s[id] == L'3' || s[id] == L'4' || s[id] == L'5' || s[id] == L'6' || s[id] == L'7' || s[id] == L'8' || s[id] == L'9') {
					id++;
				}
				else {
					if (id > 0) {
						Mark mark;
						mark.type = MarkType::INT;
						mark.len = id;
						return mark;
					}
					else {
						return null_mark;
					}
					
				}
			}
			return null_mark;
		}
		Mark Float(Char* s) {
			size id = 0;
			//if (s[id] == L'0' || s[id] == L'1' || s[id] == L'2' || s[id] == L'3' || s[id] == L'4' || s[id] == L'5' || s[id] == L'6' || s[id] == L'7' || s[id] == L'8' || s[id] == L'9') {
			//	id++;
			//}
			while (true)
			{
				if (s[id] == L'0' || s[id] == L'1' || s[id] == L'2' || s[id] == L'3' || s[id] == L'4' || s[id] == L'5' || s[id] == L'6' || s[id] == L'7' || s[id] == L'8' || s[id] == L'9' || s[id] == L'.') {
					id++;
				}
				else {
					if (id > 1) {
						Mark mark;
						mark.type = MarkType::INT;
						mark.len = id;
						return mark;
					}
					else {
						return null_mark;
					}

				}
			}
			return null_mark;
		}
		Mark Add(Char* s) { if (s[0] == L'+') { return add_mark; }return null_mark; }
		Mark Les(Char* s) { if (s[0] == L'-') { return les_mark; }return null_mark; }
		Mark Mul(Char* s) { if (s[0] == L'*') { return mul_mark; }return null_mark; }
		Mark Div(Char* s) { if (s[0] == L'/') { return div_mark; }return null_mark; }
	}
}
