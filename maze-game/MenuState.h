#ifndef EE_MENUSTATE_H_INCLUDED
#define EE_MENUSTATE_H_INCLUDED
#include "State.h"
#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

namespace edy {
	namespace state {
		class MenuState : public core::State
		{
		public:
			virtual void run(core::PointerPack& pack);
		private:

			// �޴� ����ȭ�� ����
			Texture MenuBackground;
			Sprite MenuBg;



		};
	}
}
#endif