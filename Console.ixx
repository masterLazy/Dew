export module Dew:Console;
import :Object;
import :ConsoleColor;

import <cstdio>;
using namespace std;

namespace Dew {
	/*
	* 控制台 IO
	*/
	class _Console : public Object {
	public:
		/* 输出 */
		const _Console& Write(const String& str) const { wprintf(L"%s", wstring(str).c_str()); return *this; }
		const _Console& WriteLine() const { wprintf(L"\n"); return *this; }
		const _Console& WriteLine(const String& str) const { return Write(str).WriteLine(); }
		/* 泛型输出 */
		template<CanToString T> const _Console& Write(const T& obj) const { return Write(Dew::ToString(obj)); }
		template<CanToString T> const _Console& WriteLine(const T& obj) const { return WriteLine(Dew::ToString(obj)); }
		/* 颜色输出 */
		const _Console& Write(const String& str, _Color color) const { return Write(color.Code).Write(str).Write(ConsoleColor.Default.Code); }
		const _Console& WriteLine(const String& str, _Color color) const { return Write(color.Code).Write(str).Write(ConsoleColor.Default.Code).WriteLine(); }
		template<CanToString T> const _Console& Write(const T& obj, _Color color) const { return Write(Dew::ToString(obj), color); }
		template<CanToString T> const _Console& WriteLine(const T& obj, _Color color) const { return WriteLine(Dew::ToString(obj), color); }
	};
	export const _Console Console;
}