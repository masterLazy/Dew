export module Dew:Object;
import :String;

import <string>;
import <typeinfo>;
using namespace std;

namespace Dew {
	/*
	* 超级基类
	*/
	export class Object {
	public:
		bool operator==(const Object& another) const { return this == &another; }
		/* 可重写的方法 */
		virtual String ToString() const { return Dew::ToString(typeid(*this).name()); }
		virtual bool Equals(const Object& another) const { return *this == another; }
	};
	/* 泛型 */
	template<typename T> concept HasToString = requires(const T & obj) { { obj.ToString() } -> std::convertible_to<String>; };
	export template<HasToString T> String ToString(const T& obj) { return obj.ToString(); }
}