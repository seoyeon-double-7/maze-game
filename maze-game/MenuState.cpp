#include "MenuState.h"
#include "PacEvent.h"
#include "StateManager.h"
#include <SFML/Window/Event.hpp>
#include "ScoreState.h"
#include "GameState.h"


/* 메뉴 페이지 */

namespace edy {
	namespace state {
		void MenuState::run(core::PointerPack& pack)
		{

			// 메뉴 파일 불러옴
			MenuBackground.loadFromFile("img/menuImg.png");
			MenuBg.setTexture(MenuBackground);
			MenuBg.setPosition(0, 0);

			Event eve;
			while (true)
			{
				while (pack.Window->pollEvent(eve))
				{
					// 플레이어가 Q를 입력하면 현재 스택에서 팝해줌 (제거)
					if (eve.type == Event::Closed || (eve.type == Event::KeyPressed && eve.key.code == Keyboard::Q))
					{
						pack.Manager->popTop(100);
						return;
					}
					else if (eve.type == Event::KeyPressed)
					{
						// 플레이어가 S를 누르면 게임 스테이트를 푸시 해줌
						if (eve.key.code == Keyboard::S)
						{
							pack.Manager->pushTop(new GameState());
							return;
						}

						// 플레이어가 R을 누르면 스코얼 스테이트를 푸시해줌
						if (eve.key.code == Keyboard::R)
						{
							pack.Manager->pushTop(new ScoreState(-1));
							return;
						}

					}
				}


				// 배경 클리어 한 후 배경화면 그려주기
				pack.Window->clear();
				pack.Window->draw(MenuBg);
				pack.Window->display();
			}
		}
	}
}