#ifndef MYSCRIPTLEX
#define MYSCRIPTLEX
#include "../core/basetype.h"
#include "../core/error.h"
#include <list>
namespace myscript {
	namespace lex {
		// 记号类型
		enum class MarkType {
			_ERRROR,
			Null,// 空
			INT,// 整形
			FLOAT,// 浮点型
			ADD,// 加
			LES,// 减
			MUL,// 乘
			DIV,// 除
			IF,// 如果
			ELIF,// 否则-如果
			ELSE// 否则
		};
		// 记号
		struct Mark {
			size len = 0;
			MarkType type = MarkType::_ERRROR;
			// 在创建函数中别动这个
			Char* start = nullptr;
		};

		typedef list<Mark> MarkList;

		static const Mark null_mark;
		/*class GetMark
		{
		public:
			GetMark();
			~GetMark();
			unsigned int line;
			char* name;
			MarkType type;
			BaseObject(*tokenbuild)(Token& self);
		private:

		};
		typedef BaseObject(*tokenbuildfunc)(Token& self);*/
		// 获得记号函数 如果失败返回nullptr
		typedef Mark (*getmarkfunc)(Char* s);

		// 词法分析
		class Lex
		{
		public:
			Lex(getmarkfunc* funcs);
			Lex(const getmarkfunc* funcs);
			~Lex();
			MarkList run(Char * code);
			MarkList run(const Char* code);
		private:
			getmarkfunc* funcs;
			size len;
		};
		static Mark add_mark = { 1, MarkType::ADD };
		static Mark les_mark = { 1, MarkType::LES };
		static Mark mul_mark = { 1, MarkType::MUL };
		static Mark div_mark = { 1, MarkType::DIV };
		static Mark if_mark = { 2, MarkType::IF };
		static Mark elif_mark = { 4, MarkType::ELIF };
		static Mark else_mark = { 4, MarkType::ELSE };


		Mark Add(Char* s);
		Mark Les(Char* s);
		Mark Mul(Char* s);
		Mark Div(Char* s);

		Mark Int(Char* s);
		Mark Float(Char* s);

		Mark If(Char* s);
		Mark Elif(Char* s);
		Mark Else(Char* s);


		static const lex::getmarkfunc funcs[] = {
			lex::Add,
			lex::Les,
			lex::Mul,
			lex::Div,
			lex::Int,
			lex::Float,
			lex::If,
			lex::Elif,
			lex::Else,
			nullptr };

	}
}
#endif