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

			// 메뉴 바탕화면 구성
			Texture MenuBackground;
			Sprite MenuBg;



		};
	}
}
#endif