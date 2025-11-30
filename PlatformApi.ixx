export module Dew:PlatformApi;

import <string>;
using namespace std;

import <Windows.h>;

namespace Dew {
	/**
	* 平台特定的 API
	*/
	class _PlatformApi {
	public:
		/* string (UTF-8) -> wstring */
		wstring ToWstr(const string& str) const {
			int len = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.size(), nullptr, 0);
			auto buf = new wchar_t[len];
			MultiByteToWideChar(CP_UTF8, 0, str.c_str(), (int)str.size(), buf, len);
			wstring res(buf, len);
			delete[] buf;
			return res;
		}
		/* wstring -> string (UTF-8) */
		string ToStr(const wstring& wstr) const {
			int len = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), (int)wstr.size(), nullptr, 0, NULL, NULL);
			auto buf = new char[len];
			WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), (int)wstr.size(), buf, len, NULL, NULL);
			string res(buf, len);
			delete[] buf;
			return res;
		}
	};
	export const _PlatformApi PlatformApi;
}