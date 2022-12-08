#ifndef EE_GAMESTATE_H_INCLUDED
#define EE_GAMESTATE_H_INCLUDED
#include "State.h"
#include "PacEngine.h"
#include <SFML/Graphics/RenderTexture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics.hpp>


namespace edy {
	namespace core {
		class PointerPack;
	}
	namespace state {
		class GameState : public core::State
		{
		public:
			GameState();
			virtual void run(core::PointerPack& pack);

		private:

			// ȭ�鿡 ���� ǥ�� ����
			sf::Text score;	

			// �÷��� ������ �ƴ��� Ȯ�� ����
			bool playing;

			core::PointerPack* mPack;
			
			int mScore;
			
			//pac::PacEngine mEngine;


			/* ���� ���� */

			// �÷��̾� (��ǥ, �ؽ���, ��������Ʈ)
			sf::Vector2i player;
			sf::Texture playerTex;
			sf::Sprite playerSprite;

			// ������ (��ǥ, �ؽ���, ��������Ʈ)
			sf::Vector2i door;
			sf::Texture doorTex;
			sf::Sprite doorSprite;

			// ��(���̷���) (��ǥ, �ؽ���, ��������Ʈ)
			sf::Vector2i opponent;
			sf::Texture opponentTex;
			sf::Sprite opponentSprite;


			sf::RectangleShape displayRects[15 * 15];
		};
	}
}
#endif