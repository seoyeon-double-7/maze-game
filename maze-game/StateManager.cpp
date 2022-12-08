#include "StateManager.h"
#include "State.h"

/* 화면전환을 관리 */

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

		// 스택에서 최상위 스테이트를 제거
		void StateManager::popTop(int amount)
		{
			amount = std::min(amount, static_cast<int>(mStates.size()));
			for (int i = 0; i < amount; ++i)
			{
				mClear.push(mStates.top());
				mStates.pop();
			}
		}


		// 지정해준 스테이트를(스택사이즈-amount) 팝(제거)
		void StateManager::leaveBottom(int amount)
		{
			popTop(mStates.size() - amount);
		}


		// 스택 위로 스테이트를 푸시함
		void StateManager::pushTop(State* state)
		{
			mStates.push(state);
		}


		// 최상단에 있는 run 함수를 실행
		void StateManager::gameRun()
		{
			while (!mStates.empty())
			{
				mStates.top()->run(mPack);
				clearStacks();
			}
		}

		// 스택에 있는 모든 스테이트 제거
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