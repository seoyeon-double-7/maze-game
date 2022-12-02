#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace std;
using namespace sf;

class mazeGame {
private:
	// ������
	RenderWindow app;
	
	// ���� ��
	int gameMap[15*15];
	RectangleShape displayRects[15 * 15];

	int fullSet[2000];
	int openSet[100];

	//�� ����
	bool updatePath;
	int orderedSet[100];
	int path[100];
	int pathSize = 0;
	int pathPos = 0;

	//�÷��̾�
	Vector2i player;
	Texture playerTex;
	Sprite playerSprite;

	// ��
	Vector2i opponent;
	Texture opponentTex;
	Sprite opponentSprite;

	int neighbors[4];

	// ����
	Texture coinTex;
	Sprite coins[1];

	int numCoins = 0;
	int score = 0;	// ���� ����

	// ���� ����
	Color Maze;
	Color Background;



public:
	mazeGame();	// ������

	void Intro();	// ��Ʈ�� (���� ����, ���ӷ�, ��ŷ)
	void GameSet();	// ���� �غ�
	void GameStart();	//���� ����
	void Rank();
};