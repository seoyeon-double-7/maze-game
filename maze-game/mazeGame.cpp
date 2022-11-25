#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

int main()
{
	int x = 0, y = 0;

	Clock clock;	//��� �ð��� ������ �� �ִ� Clock ��ü ����
	Clock ai_timer;
	float interval = 0, delay1 = 4.0;
	int count = 0;

	const Time ai_time = seconds(0.5f);

	cout << "���� ����" << endl;

	// �ؽ���, ��������Ʈ
	Texture Tbackground, Tstart, Trule, Trank;
	Sprite background, start, rule, rankBtn;

	Texture rankScreen, ruleScreen, mapScreen;
	Sprite rank_screen, rule_screen, map_screen;



	// �̹��� ���� �б�
	Tbackground.loadFromFile("images/bg.png");
	Tstart.loadFromFile("images/startBtn.png");
	Trule.loadFromFile("images/ruleBtn.png");
	Trank.loadFromFile("images/rankBtn.png");
	rankScreen.loadFromFile("images/rankScreen.png");
	ruleScreen.loadFromFile("images/ruleScreen.png");
	mapScreen.loadFromFile("images/mapScreen.png");

	// Sprite ����
	background.setTexture(Tbackground);

	start.setTexture(Tstart);
	start.setPosition(100, 600);

	rule.setTexture(Trule);
	rule.setPosition(550, 590);

	rankBtn.setTexture(Trank);
	rankBtn.setPosition(1000, 600);

	rank_screen.setTexture(rankScreen);
	rule_screen.setTexture(ruleScreen);
	map_screen.setTexture(mapScreen);
	map_screen.setPosition(0, 0);

	// ȭ�� ũ��, ĸ�� �̸� ����
	RenderWindow app(VideoMode(1500, 900), "MazeGame");
	app.setFramerateLimit(60);	//������ ���� ����

	// �ʴ� 60 ������ ����
	app.setFramerateLimit(60);

	// SFML ���� ���� - ������ ���������� �ݺ�

	while (app.isOpen())
	{
		// �ʴ����� ����ð��� ����
		/*float time = clock.getElapsedTime().asSeconds();
		clock.restart();

		interval += time;*/

		Event event;
		// �̺�Ʈ ó��
		while (app.pollEvent(event)) {


			// ���α׷� ���� �̺�Ʈ ó��
			if (event.type == Event::EventType::Closed)
			{
				app.close();
				cout << "���� ����" << endl;
			}

			// ���콺 ��ư ���� �̺�Ʈ
			if (event.type == Event::MouseButtonPressed)
			{
				switch (event.key.code)
				{
				case Mouse::Left:
				{
					Vector2i pos = Mouse::getPosition(app);

					if (pos.x >= 155 && pos.x <= 500 && pos.y >= 614 && pos.y <= 720) {
						cout << "���� ���۹�ư ����" << endl;
						//app.clear();
						app.draw(map_screen);
					}
					else if (pos.x >= 576 && pos.x <= 946 && pos.y >= 628 && pos.y <= 728) {
						cout << "���� �����ư ����" << endl;
						//app.clear();
						app.draw(rule_screen);
					}
					else if (pos.x >= 1027 && pos.x <= 1401 && pos.y >= 630 && pos.y <= 732) {
						cout << "���� ��ŷ��ư ����" << endl;
						//app.clear();
						app.draw(rank_screen);
					}
					else {
						app.draw(background);
						app.draw(start);
						app.draw(rule);
						app.draw(rankBtn);
					}
				}
				}

			}
		}

		// ������ ��ũ���� ���
		app.display();

	}
	return 0;
}