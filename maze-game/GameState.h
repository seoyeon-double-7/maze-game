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

			// 화면에 점수 표시 변수
			sf::Text score;	

			// 플레이 중인지 아닌지 확인 변수
			bool playing;

			core::PointerPack* mPack;
			
			int mScore;
			
			//pac::PacEngine mEngine;


			/* 게임 변수 */

			// 플레이어 (좌표, 텍스쳐, 스프라이트)
			sf::Vector2i player;
			sf::Texture playerTex;
			sf::Sprite playerSprite;

			// 도착지 (좌표, 텍스쳐, 스프라이트)
			sf::Vector2i door;
			sf::Texture doorTex;
			sf::Sprite doorSprite;

			// 적(바이러스) (좌표, 텍스쳐, 스프라이트)
			sf::Vector2i opponent;
			sf::Texture opponentTex;
			sf::Sprite opponentSprite;


			sf::RectangleShape displayRects[15 * 15];
		};
	}
}
#endif