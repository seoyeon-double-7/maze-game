#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

#define back Color(96,58,18)	// �̷� �� ����

using namespace std;
using namespace sf;

class mazeGame {
private:
	RenderWindow window;
	//Color back;
public:
	mazeGame();	// ������

	void Intro();	// ��Ʈ�� (���� ����, ���ӷ�, ��ŷ)
	void GameSet();	// ���� �غ�
	void GameStart();	//���� ����
	void Rank();
};