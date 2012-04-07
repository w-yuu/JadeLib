#include "GameState.h"

//========================================
namespace Jade
	{

	GameState::GameState()
		{
		this->DebugMode = false;
		StartTime = time((time_t *)0);
		TimeObject = localtime(&StartTime);
		
		if(Jade::GameState::GetInstance()->DebugMode == true)
		Jade::Debug::GetInstance()->Add("GameState‚Ì‰Šú‰»Š®—¹");
		}

	bool GameState::SetFPS(int FPS)
		{
		return true;
		}
	

	int GameState::GetFPS()
		{
		return GameState::FPS;
		}

	
	int GameState::GetErrorProcessTime()
		{
		DeffTime =  time((time_t *)0);
		NowTimeObject = localtime(&DeffTime);
		return DeffTime - StartTime;
		}


	}