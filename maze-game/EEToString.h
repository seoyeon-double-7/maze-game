#ifndef EE_TOSTRING_H_INCLUDED
#define EE_TOSTRING_H_INCLUDED
#include <sstream>

// 텍스트를 스트링을 변환해주는 기능

namespace edy{
	namespace sup{
		template<typename T> inline std::string toString(T targ)
		{
			std::ostringstream ss;
			ss<<targ;
			return ss.str();
		}
	}
}
#endif