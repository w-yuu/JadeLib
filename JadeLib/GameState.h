/*===========================================
�Q�[����Ԃ�ύX������m�F�ł���B
Singleton�p�^�[�����̗p���Ă���B
/==========================================*/
#ifndef _GAMESTATE_
#define _GAMESTATE_

#include "stdafx.h"

#include "Debug.h"
#include <time.h>

//===========================================
namespace Jade
	{
	class GameState
		{
		public:
			struct tm *TimeObject;

			GameState();
			bool SetFPS(int FPS);
			int  GetFPS(void);
			int GetErrorProcessTime();
			bool FileLoad(void);
			
			bool DebugMode;

			static GameState* GetInstance(void)
				{
				static GameState ThisInstance;
				


				return &ThisInstance;
				}


		private:
			
			
			
			int FPS;
			time_t StartTime;
			time_t DeffTime;
			
			struct tm *NowTimeObject;

		};
	}
//===========================================
#endif