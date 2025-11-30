export module Dew:Event;
import :Object;

import <functional>;
import <vector>;
using namespace std;

namespace Dew {
	/*
	* 事件 (未完善)
	*/
	export template<typename... Args> class Event : public Object {
		using Handler = std::function<void(Args...)>;
		std::vector<Handler> handlers;
	public:
		void operator+=(Handler handler) {
			handlers.push_back(handler);
		}
		void Invoke(Args... args) {
			for (auto& handler : handlers) {
				if (handler) handler(args...);
			}
		}
	};
	/*
	* 事件参数
	*/
	export class EventArgs : public Object {
	public:
		const static EventArgs Empty;
	};
}