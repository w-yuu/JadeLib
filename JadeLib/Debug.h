/*===========================================
ゲーム内の動向を監視する内部デバッグ用クラス
Singletonパターンを採用している。
デバッグ情報が欲しいクラスは常に報告すること。
/==========================================*/
#ifndef _DEBUG_
#define _DEBUG_


#include "stdafx.h"

//データ形式用




//===========================================
namespace Jade
	{
	class Debug
		{
		public:
			Debug();
			
			//不明なメソッド
			bool Clear();

			//エラーや通信情報など、発生事項をファイルに記述します。
			bool Add(std::string Data,int DataType = 9  , std::string FileName = "Debug.txt");
			

			//このクラスを利用する場合は、このメソッドを介してください。
			static Debug* GetInstance(void)
			{
				static Debug ThisInstance;
				return &ThisInstance;
			}
			

			//データタイプ表
				enum { ERROR_S = 0 , ERROR_M , ERROR_L , ERROR_LL , VERSION , NETWORK , STREAM , CRACK , OTHERS , EVENT };
		private:
			//データタイプ表の保存
			std::string MapData[10];

	
		
			
		};
	}
//===========================================
#endif

//
//int Error_S		= ERROR_S;
//			int Error_M		= ERROR_M;
//			int Error_L		= ERROR_L;
//			int Error_LL	= ERROR_LL;
//
//			int Version		= VERSION;
//			int Network		= NETWORK;
//			int File		= FILE;
//			int Crack		= CRACK;
//			int Except		= EXCEPT;