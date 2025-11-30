export module Dew:ConsoleColor;
import :Object;

import <iostream>;
using namespace std;

namespace Dew {
	/*
	* ¿ØÖÆÌ¨ÑÕÉ«
	*/
	class _Color : public Object {
		String _name, _code;
		class Code {
		public:
			const _Color& owner;
			operator String() const { return owner._code; }
		};
	public:
		_Color(const String& name, const String& code) : _name(name), _code(code) {}
		String ToString() { return _name; }
		Code Code{ *this };
	};
	class _ConsoleColor : public Object {
	public:
		_Color Black{ L"Black",L"\033[30m" };
		_Color Red{ L"Red",L"\033[31m" };
		_Color Green{ L"Green",L"\033[32m" };
		_Color Yellow{ L"Yellow",L"\033[33m" };
		_Color Blue{ L"Blue",L"\033[34m" };
		_Color Magenta{ L"Magenta",L"\033[35m" };
		_Color Cyan{ L"Cyan",L"\033[36m" };
		_Color White{ L"White",L"\033[37m" };
		_Color Default{ L"Default",L"\033[39m" };
	};
	export const _ConsoleColor ConsoleColor;
}