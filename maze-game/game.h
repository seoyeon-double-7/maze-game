#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <string.h>


#define back Color(96,58,18)	// �̷� �� ����

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
	mazeGame();	// ������
	void Intro();	// ��Ʈ�� (���� ����, ���ӷ�, ��ŷ)
	void GameSet();	// ���� �غ�
	void GameStart();	//���� ����
	void Rank();
};