#include "Win32.h"
#include "MDX.h"
#include "GameState.h"
//========================================
namespace Jade
	{
	Win32::Win32()
		{
		this->MessageLoop = 1;
		}

	int Win32::Init(HINSTANCE hInst,HINSTANCE hPrev,LPSTR lpszCmdParam,int nCmdshow)
		{
		this->hInst = hInst;
		this->hPrev = hPrev;
		this->lpszCmdParam = lpszCmdParam;
		this->nCmdshow = nCmdshow;
		this->szAppName = "Generic Game SDK Window";

		wc.style=CS_DBLCLKS;
		wc.lpfnWndProc=this->WndFunc;
		wc.cbClsExtra=0;
		wc.cbWndExtra=0;
		wc.hInstance=hInst;
		wc.hIcon=LoadIcon(NULL,IDI_APPLICATION);
		wc.hCursor=LoadCursor(NULL,IDC_ARROW);
		wc.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);
		wc.lpszMenuName=NULL;
		wc.lpszClassName=szAppName.c_str();

		RegisterClass(&wc);

		hwnd=CreateWindowEx(
			//		WS_EX_TOPMOST,
			0,
			szAppName.c_str(),
			"Direct X",
			//		WS_VISIBLE|WS_POPUP,
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			SCRW,SCRH,
			NULL,NULL,hInst,
			NULL);

		if(!hwnd)return FALSE;

		ShowWindow(hwnd,nCmdshow);
		UpdateWindow(hwnd);
		SetFocus(hwnd);
		if(FULLSCREEN){
			ShowCursor(FALSE);
			}else{
				RECT rc={0,0,SCRW,SCRH};
				AdjustWindowRect(&rc,WS_OVERLAPPEDWINDOW,FALSE);
				SetWindowPos(hwnd,NULL,0,0,rc.right-rc.left,rc.bottom-rc.top,SWP_SHOWWINDOW|SWP_NOMOVE|SWP_NOZORDER);
			}
if(Jade::GameState::GetInstance()->DebugMode == true)
		Jade::Debug::GetInstance()->Add("Win32の初期化完了");

		return 0;
		}

	void Win32::Run()
		{
		if(Jade::GameState::GetInstance()->DebugMode == true)
		Jade::Debug::GetInstance()->Add("メッセージループの起動");
		//--------
		while(this->MessageLoop){
			if(PeekMessage(&msg,NULL,0,0,PM_NOREMOVE))
				{
				if(!GetMessage(&msg,NULL,0,0))
					break;
				TranslateMessage(&msg);
				DispatchMessage(&msg);
				}else{
					
					Jade::MDX::GetInstance()->DrawFrame();
					
					
				}
			}
		//---------
		}


	LRESULT APIENTRY Win32::WndFunc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
		{
		switch(msg){
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	case WM_KEYDOWN:
		switch(wParam){
	case VK_ESCAPE:
		PostQuitMessage(0);
		return 0;
			}
		return 0;

			}
		return DefWindowProc(hwnd,msg,wParam,lParam);

		}
	}
