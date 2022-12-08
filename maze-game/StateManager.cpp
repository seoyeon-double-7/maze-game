#include "StateManager.h"
#include "State.h"

/* ȭ����ȯ�� ���� */

namespace edy {
	namespace core {
		StateManager::StateManager()
		{
			mWindow.create(sf::VideoMode(600, 600), "Maze Game", sf::Style::Close | sf::Style::Titlebar);
			mFont.loadFromFile("font/neodgm.ttf");
			mPack.Font = &mFont;
			mPack.Manager = this;
			mPack.Window = &mWindow;
		}
		StateManager::~StateManager()
		{
			popTop(mStates.size());
			clearStacks();
		}

		// ���ÿ��� �ֻ��� ������Ʈ�� ����
		void StateManager::popTop(int amount)
		{
			amount = std::min(amount, static_cast<int>(mStates.size()));
			for (int i = 0; i < amount; ++i)
			{
				mClear.push(mStates.top());
				mStates.pop();
			}
		}


		// �������� ������Ʈ��(���û�����-amount) ��(����)
		void StateManager::leaveBottom(int amount)
		{
			popTop(mStates.size() - amount);
		}


		// ���� ���� ������Ʈ�� Ǫ����
		void StateManager::pushTop(State* state)
		{
			mStates.push(state);
		}


		// �ֻ�ܿ� �ִ� run �Լ��� ����
		void StateManager::gameRun()
		{
			while (!mStates.empty())
			{
				mStates.top()->run(mPack);
				clearStacks();
			}
		}

		// ���ÿ� �ִ� ��� ������Ʈ ����
		void StateManager::clearStacks()
		{
			while (!mClear.empty())
			{
				delete mClear.top();
				mClear.pop();
			}
		}
	}
}