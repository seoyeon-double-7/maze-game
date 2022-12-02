#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace std;
using namespace sf;

class mazeGame {
private:
	// 윈도우
	RenderWindow app;
	
	// 게임 맵
	int gameMap[15*15];
	RectangleShape displayRects[15 * 15];

	int fullSet[2000];
	int openSet[100];

	//길 변수
	bool updatePath;
	int orderedSet[100];
	int path[100];
	int pathSize = 0;
	int pathPos = 0;

	//플레이어
	Vector2i player;
	Texture playerTex;
	Sprite playerSprite;

	// 적
	Vector2i opponent;
	Texture opponentTex;
	Sprite opponentSprite;

	int neighbors[4];

	// 코인
	Texture coinTex;
	Sprite coins[1];

	int numCoins = 0;
	int score = 0;	// 코인 점수

	// 색깔 변수
	Color Maze;
	Color Background;



public:
	mazeGame();	// 생성자

	void Intro();	// 인트로 (게임 시작, 게임룰, 랭킹)
	void GameSet();	// 게임 준비
	void GameStart();	//게임 시작
	void Rank();
};