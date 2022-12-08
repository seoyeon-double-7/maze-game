#ifndef EE_QUITSTATE_H_INCLUDED
#define EE_QUITSTATE_H_INCLUDED
#include "State.h"
#include "StateManager.h"
#include <string>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Window/Event.hpp>

/* ���� ���� ������ */

namespace edy {
	namespace state {
		class QuitState : public core::State
		{
		public:
			virtual void run(core::PointerPack& pack)
			{

				// �ؽ�Ʈ ����

				sf::Text text("Game Over", *pack.Font);
				sf::Text text2("Enter to go menu", *pack.Font);

				text.setPosition(100, 100);
				text2.setPosition(100, 150);


				sf::Event eve;
				while (1)
				{
					while (pack.Window->pollEvent(eve))
					{
						// ���� ���� ȭ�鿡�� ���͸� ġ�� �������� ���ư�
						if (eve.type == sf::Event::KeyPressed && eve.key.code == sf::Keyboard::Enter)
						{
							pack.Manager->leaveBottom(1);
							return;
						}
					}

					// �ؽ�Ʈ ���
					pack.Window->clear();
					pack.Window->draw(text);
					pack.Window->draw(text2);
					pack.Window->display();
				}
			}
		};
	}
}
#endif