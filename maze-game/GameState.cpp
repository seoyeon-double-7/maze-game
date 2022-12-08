#include "GameState.h"
#include "EEToString.h"
#include <SFML/Window/Event.hpp>
#include "StateManager.h"
#include "ScoreState.h"
#include "QuitState.h"
#include <iostream>

using namespace std;
using namespace sf;

/* ���� �÷��� ������ */

namespace edy {
	namespace state {

		// ���ھ�� mPack�� �ʱ�ȭ
		GameState::GameState() :mScore(0), mPack(0x0)
		{
			// �÷��̾� ����
			player = Vector2i(13, 13);
			playerTex.loadFromFile("img/player.png");
			playerSprite.setTexture(playerTex);
			playerSprite.setPosition(player.x * 40.f, player.y * 40.f);

			// ������ ����
			door = Vector2i(1, 13);
			doorTex.loadFromFile("img/star.png");
			doorSprite.setTexture(doorTex);
			doorSprite.setPosition(door.x * 40.f, player.y * 40.f);

			// �� ����
			opponent = Vector2i(1, 1);
			opponentTex.loadFromFile("img/enemy.png");
			opponentSprite.setTexture(opponentTex);
			opponentSprite.setPosition(opponent.x * 40.f, opponent.y * 40.f);

			// ���ӿ��� Ȯ�� ����, ���� ���� �ʱ�ȭ
			playing = 1;
			mScore = 0;
		}

		void GameState::run(core::PointerPack& pack)
		{
			
			//�̷� �迭 ����
			int gameMap[15 * 15];


			// ���� ����
			if (!mPack)
			{
				mPack = &pack;

				score.setFont(*pack.Font);
				score.setString("Score:0");
				score.setCharacterSize(32);
				score.setPosition(80.f, 500.f);
			}

			sf::Event seve;
			pac::PacEvent peve;

			//rand �Լ��� ���� �� �ʱ�ȭ �ϱ�
			srand(sin(time(nullptr)) * 1000);

			// ���� �ð��� ������� ����
			int frameCount = 0;
			int moveTimer = 1000;

			// �÷��̾��� ��θ� Ȯ���ϴ� ����
			bool updatePath = true;
			int orderedSet[15 * 15];
			int path[100] = { 0 };
			int pathSize = 0;
			int pathPos = 0;


			// �̷� �迭�� ���� �簢������ ��ġ, ������ ����
			for (int i = 0; i < 15; i++) {
				for (int j = 0; j < 15; j++) {
					displayRects[i + j * 15].setPosition(i * 40.f, j * 40.f);
					displayRects[i + j * 15].setSize(Vector2f(40.f, 40.f));


					/* 
					* 
					�÷��̾��� ��ǥ���� ���� ��ǥ���� ���� ������
					�̷� ��ġ�� �÷��̾�� �� ��ġ�� ��ġ�� �ʰ� ��
					rand() �Լ��� ����Ͽ� �� ���ට���� �̷ι迭�� �޶����� ��.
					
					 */
					if (!(i == opponent.x && j == opponent.y) && !(i == player.x && j == player.y) && !(i == door.x && j == door.y)) {
						if (rand() / (float)RAND_MAX < 0.22f || i == 0 || j == 0 || i == 14 || j == 14) {
							gameMap[i + j * 15] = 1;
						}
					}
				}
			}


		
			while (playing)
			{
				while (pack.Window->pollEvent(seve))
				{
					if (seve.type == sf::Event::Closed)
					{
						pack.Manager->popTop(100);
						return;
					}

					// Ű������ �Է¿� ���� �÷��̾��� ��ǥ���� ����
					if (seve.type == sf::Event::KeyPressed)
					{
						switch (seve.key.code)
						{
						case sf::Keyboard::Up:
							if (gameMap[player.x + (player.y - 1) * 15] != 1) player.y -= 1;
							break;
						case sf::Keyboard::Down:
							if (gameMap[player.x + (player.y + 1) * 15] != 1) player.y += 1;
							break;
						case sf::Keyboard::Left:
							if (gameMap[(player.x - 1) + player.y * 15] != 1) player.x -= 1;
							break;
						case sf::Keyboard::Right:
							if (gameMap[(player.x + 1) + player.y * 15] != 1) player.x += 1;
							break;
						}
					}

					updatePath = true;
					pathSize = 0;
					pathPos = 0;
					playerSprite.setPosition(player.x * 40.f, player.y * 40.f);
				}


				/*for (int i = 0; i < 15 * 15; i++) {
					pack.Window->draw(displayRects[i]);
				}*/

				// A* �˰��� (�ִ� ��� Ž��)
				// ���� ��忡�� ��ǥ �������� �ִ� ��θ� ����


				if (updatePath == true) {
					int counter = 0;

					int fullSet[2000];
					int fullSetSize = 0;

					int openSet[100];
					int openSetSize = 2;
					openSet[0] = player.x + player.y * 15;
					openSet[1] = counter;

					int currentIndex = player.x + player.y * 15;	// ���� �÷��̾��� ��ġ

					while (currentIndex != opponent.x + opponent.y * 15) {
						currentIndex = openSet[0];
						counter = openSet[1] + 1;
						int neighbors[4];	

						// �̿� �迭
						neighbors[0] = currentIndex - 1;
						neighbors[1] = currentIndex + 1;
						neighbors[2] = currentIndex - 15;
						neighbors[3] = currentIndex + 15;

						for (int i = 0; i < 8; i += 2) {
							bool alreadyExists = false;

							for (int j = 0; j < fullSetSize; j += 2) {
								if (neighbors[i / 2] == fullSet[j]) {
									alreadyExists = true;
									break;
								}
							}

							if (alreadyExists == false) {
								if (gameMap[(neighbors[i / 2])] != 1) {
									fullSet[fullSetSize] = neighbors[i / 2];
									fullSet[fullSetSize + 1] = counter;
									fullSetSize += 2;

									openSet[openSetSize] = (neighbors[i / 2]);
									openSet[openSetSize + 1] = counter;
									openSetSize += 2;
								}
								else {
									fullSet[fullSetSize] = neighbors[i / 2];
									fullSet[fullSetSize + 1] = 100000;
									fullSetSize += 2;
								}
							}
						}

						for (int i = 0; i < openSetSize; i++) {
							openSet[i] = openSet[i + 2];
						}

						openSetSize -= 2;
					}

					for (int i = 0; i < 15 * 15; i++) {
						orderedSet[i] = 100000;
					}

					for (int i = 0; i < fullSetSize; i += 2) {
						orderedSet[fullSet[i]] = fullSet[i + 1];
					}

					orderedSet[player.x + player.y * 15] = 0;

					int pathIndex = opponent.x + opponent.y * 15;

					while (pathIndex != player.x + player.y * 15) {
						int neighbors[4];

						neighbors[0] = pathIndex - 1;
						neighbors[1] = pathIndex + 1;
						neighbors[2] = pathIndex - 15;
						neighbors[3] = pathIndex + 15;

						int lowest[2]{ 0, 100000 };
						for (int i = 0; i < 4; i++) {
							if (orderedSet[neighbors[i]] < lowest[1]) {
								lowest[0] = i;
								lowest[1] = orderedSet[neighbors[i]];
							}
						}

						pathIndex = neighbors[lowest[0]];

						path[pathSize] = pathIndex;

						pathSize += 1;
					}

					updatePath = false;
				}

				// ���� �����϶����� ī��Ʈ�� ����
				if (frameCount % moveTimer == 0) {
					opponent.x = path[pathPos] % 15;
					opponent.y = floor(path[pathPos] / 15);
					opponentSprite.setPosition(opponent.x * 40.f, opponent.y * 40.f);
					pathPos += 1;

					if (moveTimer >= 250) {
						moveTimer = 1000 - floor(frameCount / 1000) * 4;
					}
				}

				frameCount++;

				// �������� �ð��� �־���
				mScore = frameCount / 600;
				cout << mScore << endl;

				// ������ ȭ�鿡 ���
				score.setString("Score:" + sup::toString(mScore) + "s");


				// �÷��̾ ���� ������ ��ŷ �������� ��ȯ
				if (player == door) {
					pack.Manager->pushTop(new ScoreState(mScore));
					break;
				}

				// �÷��̾�� ���� �浹���� �� ���� ���� �������� ��ȯ

				if (player == opponent) {
					pack.Manager->pushTop(new QuitState());
					break;
				}

				pack.Window->clear();

				pack.Window->draw(score);
				pack.Window->draw(playerSprite);
				pack.Window->draw(opponentSprite);
				pack.Window->draw(doorSprite);

				pack.Window->display();
			}
		}
	}
}