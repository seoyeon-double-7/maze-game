#ifndef EE_SCORESTATE_H_INCLUDED
#define EE_SCORESTATE_H_INCLUDED
#include "State.h"
#include <SFML/Graphics/Text.hpp>

namespace edy {
	namespace state {
		class ScoreState : public core::State
		{
		public:
			
			ScoreState(int score);
			virtual ~ScoreState();
			virtual void run(core::PointerPack& pack);
		
		private:
			//랭킹페이지에 사용될 변수

			// 랭킹 점수를 저장할 컨테이너
			std::vector<sf::Text> mLines;

			int mWritingTo, mScore;
			std::string mWritingLine;

		};
	}
}
#endif