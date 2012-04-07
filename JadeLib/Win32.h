/*===========================================
DirecrXの状態やウィンドウを管理するクラス
Singletonパターンを採用している。
/==========================================*/
#ifndef _WIN32_
#define _WIN32_

#include "stdafx.h"
#include "Debug.h"
#include <windows.h>
#include <string>
using namespace std;
//===========================================
namespace Jade
	{
	class Win32
		{
		public:
			//コンストラクタ

			HINSTANCE hInst;
			HINSTANCE hPrev;
			LPSTR lpszCmdParam;
			int nCmdshow;

			MSG msg;
			HWND hwnd;
			WNDCLASS wc;
			string szAppName;
			//メッセージループを抜ける場合は0にしてください
			int MessageLoop;

			Win32();
			static LRESULT APIENTRY WndFunc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);


			//初期化
			int Init(HINSTANCE hInst,HINSTANCE hPrev,LPSTR lpszCmdParam,int nCmdshow);

			static Win32* GetInstance(void)
				{
				static Win32 ThisInstance;
				return &ThisInstance;
				}

			//メッセージループ
			void Run();


		private:
			



		};
	}
//===========================================
#endif