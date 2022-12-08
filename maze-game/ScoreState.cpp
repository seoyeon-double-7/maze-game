#include "ScoreState.h"
#include "StateManager.h"
#include <fstream>
#include <sstream>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
#include "EEToString.h"
#include <iostream>

/* ��ŷ ������ */

using namespace std;

namespace edy {
	namespace state {

		// ������� �ʱ�ȭ
		ScoreState::ScoreState(int score) :mWritingTo(-1), mScore(score)
		{

			// ���Ͽ� 10�� ���� ����
			mLines.resize(10);	

			// ��ŷ ���� ��������
			ifstream file("High.txt");

			// ������ �ӽ� ������ �Լ�
			int tmpscores[10] = { 0, };

			// ���� ����
			for (int i = 0; i < 10; ++i)//wypelniamy liste
			{

				// ��ŷ ���Ͽ� �ִ� ���� ������ ����
				mLines[i].setCharacterSize(20);

				// ���Ͽ��� tmpscores�� i��° ������ temp�� �־���
				string temp;
				file >> temp;
				file >> tmpscores[i];

				// ���� �ڿ� s �ٿ��ֱ�(��)
				mLines[i].setString(temp + " " + sup::toString(tmpscores[i])+"s");
			}


			// �ٽ� ���� �������ֱ�
			for (int i = 0; i < 10; ++i)
			{
				if (tmpscores[i] < mScore && mWritingTo < 0)
				{
					sf::Text temp;
					temp.setCharacterSize(20);
					temp.setString(" " + sup::toString(mScore));
					mWritingTo = i;
					mLines.insert(mLines.begin() + i, temp);
				}
			}

			mLines.resize(10);

			//���� ���� ����
			for (int i = 0; i < 10; ++i)
			{
				mLines[i].setPosition(240.f, 180.f + i * 30);
				mLines[i].setFillColor(sf::Color::Black);
				mLines[i].setCharacterSize(30);

			}

		}

		// ���� �ݾ��ֱ�
		ScoreState::~ScoreState()
		{
			std::ofstream file("High.txt");
			for (int i = 0; i < 10; ++i)
			{
				file << mLines[i].getString().operator std::string() << std::endl;
			}
		}


		void ScoreState::run(core::PointerPack& pack)
		{
			// ��ŷ�������� �׷��� �ؽ�Ʈ�� �� ����

			Text Rank;
			Rank.setFont(*pack.Font);
			Rank.setString("RANK");
			Rank.setPosition(230.f, 30);
			Rank.setOutlineColor(sf::Color::Black);
			Rank.setOutlineThickness(5);
			Rank.setCharacterSize(80);

			RectangleShape line;
			line.setSize(Vector2f(350, 5));
			line.setPosition(130.f, 140);
			line.setFillColor(Color::Black);

			RectangleShape line2;
			line2.setSize(Vector2f(350, 5));
			line2.setPosition(130.f, 140 + 370);
			line2.setFillColor(Color::Black);

			RectangleShape line3;
			line3.setSize(Vector2f(5, 373));
			line3.setPosition(129, 139);
			line3.setFillColor(Color::Black);

			RectangleShape line4;
			line4.setSize(Vector2f(5, 373));
			line4.setPosition(129 + 348, 140);
			line4.setFillColor(Color::Black);



			for (int i = 0; i < 10; ++i)
			{
				mLines[i].setFont(*pack.Font);
			}
			sf::Event eve;
			while (1)
			{
				while (pack.Window->pollEvent(eve))
				{
					
			
					if (eve.type == sf::Event::Closed)
					{
						pack.Manager->leaveBottom(1);
						return;
					}

					// ����Ű ������ ���� �������� ��ȯ
					if (eve.type == sf::Event::KeyPressed && eve.key.code == sf::Keyboard::Return)
					{
						if (mWritingTo >= 0)
						{
							mWritingTo = -1;
						}
						else
						{
							pack.Manager->leaveBottom(1);
							return;
						}
					}
					if (eve.type == sf::Event::KeyPressed && eve.key.code == sf::Keyboard::BackSpace)
					{
						if (!mWritingLine.empty())
						{
							mWritingLine.erase(--mWritingLine.end());
							mLines[mWritingTo].setString(mWritingLine + sup::toString(mScore));
						}
					}
					if (eve.type == sf::Event::TextEntered && eve.text.unicode > 31 && eve.text.unicode < 127 && eve.text.unicode != ' ')
					{
						if (mWritingTo >= 0)
						{
							mWritingLine += static_cast<char>(eve.text.unicode);
							mLines[mWritingTo].setString(mWritingLine + " " + sup::toString(mScore));
						}
					}
				}
				pack.Window->clear(Color(192, 225, 240));
				for (int i = 0; i < 10; ++i) pack.Window->draw(mLines[i]);

				pack.Window->draw(Rank);
				pack.Window->draw(line);
				pack.Window->draw(line2);
				pack.Window->draw(line3);
				pack.Window->draw(line4);

				pack.Window->display();
			}
		}
	}
}