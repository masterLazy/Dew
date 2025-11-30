export module Dew:String;
import :PlatformApi;

import <string>;
import <codecvt>;
import <functional>;
using namespace std;

namespace Dew {
	/*
	* 字符串 (包装 wstring)
	*/
	export class String {
		wstring _data;
		class Length {
		public:
			const String& owner;
			operator size_t() const { return owner._data.size(); }
		};
	public:
		/* 兼容 */
		String() = default;
		String(const String&) = default;
		String(const wchar_t* wstr) : _data(wstr) {}
		String(const wstring& wstr) : _data(wstr) {}
		String(wstring&& wstr) : _data(move(wstr)) {}
		operator wstring() const { return _data; }
		operator wstring_view() const { return _data; }

		/* 运算符重载 */
		String& operator=(String&&) = default;
		wchar_t& operator[](size_t index) { return _data[index]; }
		const wchar_t& operator[](size_t index) const { return _data[index]; }
		bool operator==(const String& another) const { return _data == another._data; }
		String operator+(const String& another) const { return _data + another._data; }
		String& operator+=(const String& another) { _data += another._data; return *this; }

		/* 假装继承了 Object */
		const String& ToString() const { return *this; }
		bool Equals(const String& another) const { return *this == another; }

		/* 属性 & 字段 */
		Length Length{ *this };
		const static String Empty;

		/* 方法 */
		String Concat(const String& another) const { return *this + another; }
		static String Concat(const String& a, const String& b) { return a + b; }
		bool Contains(wchar_t ch) { return find(_data.begin(), _data.end(), ch) != _data.end(); }
		bool Contains(const String& another) { return _data.find(another) != string::npos; }
	};
	/* 兼容 */
	export String ToString(int x) { return to_wstring(x); }
	export String ToString(unsigned x) { return to_wstring(x); }
	export String ToString(long x) { return to_wstring(x); }
	export String ToString(unsigned long x) { return to_wstring(x); }
	export String ToString(long long x) { return to_wstring(x); }
	export String ToString(unsigned long long x) { return to_wstring(x); }
	export String ToString(float x) { return to_wstring(x); }
	export String ToString(double x) { return to_wstring(x); }
	export String ToString(long double x) { return to_wstring(x); }
	/* 扩展 */
	export String ToString(const wchar_t* wstr) { return wstr; }
	export String ToString(bool x) { return x ? L"True" : L"False"; }
	/* 和 string 转换 (不推荐) */
	export String ToString(const char* str) { return PlatformApi.ToWstr(str); }
	export String ToString(const string& str) { return PlatformApi.ToWstr(str); }

	/* 泛型 */
	template<typename T> concept CanToString = requires(const T & obj) { { ToString(obj) } -> std::convertible_to<String>; };
}