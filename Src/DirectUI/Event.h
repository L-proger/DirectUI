#ifndef Event_h__
#define Event_h__

#include <functional>
#include <vector>
#include <type_traits>

template<class... Args>
class Event {
public:
	typedef std::function<void(Args...)> handler_t;

	void invoke(Args... args){
		std::vector<handler_t> handlersCopy = _handlers;
		for (auto handler : handlersCopy){
			handler(std::forward<Args>(args)...);
		}
	}

	void operator ()(Args... args) {
		invoke(std::forward<Args>(args)...);
	}

	Event& operator += (handler_t f){
		_handlers.push_back(f);
		return *this;
	}

	Event& operator -= (handler_t f){
		for (auto handler = _handlers.begin(); handler != _handlers.end(); ++handler){
			if ((*handler).target<void(Args...)>() == f.target<void(Args...)>()){
				_handlers.erase(handler);
				break;
			}
		}
		return *this;
	}
private:
	std::vector<handler_t> _handlers;
};
#endif // Event_h__
