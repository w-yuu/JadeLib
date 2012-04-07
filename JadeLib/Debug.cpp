#include "Debug.h"
#include "GameState.h"
//========================================
//#pragma warning(disable:4996)
namespace Jade
	{

	//コンストラクタ
	Debug::Debug()
		{
		this->MapData[0] = "Error_S";
		this->MapData[1] = "Error_M";
		this->MapData[2] = "Error_L";
		this->MapData[3] = "Error_LL";
		this->MapData[4] = "Version";
		this->MapData[5] = "NetWork";
		this->MapData[6] = "Stream";
		this->MapData[7] = "Crack";
		this->MapData[8] = "Others";
		this->MapData[9] = "Event";

		//肥大化を防ぐため、ローカルデバッグファイルを空にする。
		FILE *fp = NULL;
		fp = fopen("Debug.txt", "w");
		if (fp == NULL) 
			{
			printf("LocalDebugFile(Debug.txt) ReadErorr\n");
			}
		else
			{
			//作成日を記述　エポック秒なので注意
			fprintf(fp,"Start to DebugGuard.\t%4d/%02d/%02d %02d:%02d:%02d\n\n",
				Jade::GameState::GetInstance()->TimeObject->tm_year+1900,
				Jade::GameState::GetInstance()->TimeObject->tm_mon+1,
				Jade::GameState::GetInstance()->TimeObject->tm_mday,
				Jade::GameState::GetInstance()->TimeObject->tm_hour,
				Jade::GameState::GetInstance()->TimeObject->tm_min,
				Jade::GameState::GetInstance()->TimeObject->tm_sec);
			fclose(fp);
			}
		}

	//ファイルにデバッグ情報を追加書き込み
	bool Debug::Add(std::string Data, int DataType ,std::string FileName  )
		{
		FILE *fp = NULL;
		fp = fopen(FileName.c_str(), "a");
		if (fp == NULL) 
			{
			printf("LocalDebugFile(Debug.txt) ReadErorr\n");
			return false;
			}

		//書込み
		fprintf(fp,"Time:%dsec\t Type:%s\t Data:%s\n",GameState::GetInstance()->GetErrorProcessTime(),this->MapData[DataType].c_str(),Data.c_str());			//nFIX 時間も表示するようにする
		fclose(fp);
		return true;
		}



	bool Debug::Clear()
		{
		return true;
		}




	}




