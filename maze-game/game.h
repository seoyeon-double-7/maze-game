#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <string.h>


#define back Color(96,58,18)	// 미로 색 정의

using namespace std;
using namespace sf;

class mazeGame {
private:
	RenderWindow window;

	Vector2i player;
	Texture playerTex;
	Sprite playerSprite;

	Vector2i door;
	Texture doorTex;
	Sprite doorSprite;

	Vector2i opponent;
	Texture opponentTex;
	Sprite opponentSprite;

	int gameMap[15 * 15];
	RectangleShape displayRects[15 * 15];

public:
	mazeGame();	// 생성자
	void Intro();	// 인트로 (게임 시작, 게임룰, 랭킹)
	void GameSet();	// 게임 준비
	void GameStart();	//게임 시작
	void Rank();
};