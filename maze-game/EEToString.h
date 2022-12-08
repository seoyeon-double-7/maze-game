#ifndef EE_TOSTRING_H_INCLUDED
#define EE_TOSTRING_H_INCLUDED
#include <sstream>

// �ؽ�Ʈ�� ��Ʈ���� ��ȯ���ִ� ���

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