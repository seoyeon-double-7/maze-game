#include "MenuState.h"
#include "PacEvent.h"
#include "StateManager.h"
#include <SFML/Window/Event.hpp>
#include "ScoreState.h"
#include "GameState.h"


/* �޴� ������ */

namespace edy {
	namespace state {
		void MenuState::run(core::PointerPack& pack)
		{

			// �޴� ���� �ҷ���
			MenuBackground.loadFromFile("img/menuImg.png");
			MenuBg.setTexture(MenuBackground);
			MenuBg.setPosition(0, 0);

			Event eve;
			while (true)
			{
				while (pack.Window->pollEvent(eve))
				{
					// �÷��̾ Q�� �Է��ϸ� ���� ���ÿ��� ������ (����)
					if (eve.type == Event::Closed || (eve.type == Event::KeyPressed && eve.key.code == Keyboard::Q))
					{
						pack.Manager->popTop(100);
						return;
					}
					else if (eve.type == Event::KeyPressed)
					{
						// �÷��̾ S�� ������ ���� ������Ʈ�� Ǫ�� ����
						if (eve.key.code == Keyboard::S)
						{
							pack.Manager->pushTop(new GameState());
							return;
						}

						// �÷��̾ R�� ������ ���ھ� ������Ʈ�� Ǫ������
						if (eve.key.code == Keyboard::R)
						{
							pack.Manager->pushTop(new ScoreState(-1));
							return;
						}

					}
				}


				// ��� Ŭ���� �� �� ���ȭ�� �׷��ֱ�
				pack.Window->clear();
				pack.Window->draw(MenuBg);
				pack.Window->display();
			}
		}
	}
}