/*===========================================
DirecrX�̏�Ԃ�E�B���h�E���Ǘ�����N���X
Singleton�p�^�[�����̗p���Ă���B
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
			//�R���X�g���N�^

			HINSTANCE hInst;
			HINSTANCE hPrev;
			LPSTR lpszCmdParam;
			int nCmdshow;

			MSG msg;
			HWND hwnd;
			WNDCLASS wc;
			string szAppName;
			//���b�Z�[�W���[�v�𔲂���ꍇ��0�ɂ��Ă�������
			int MessageLoop;

			Win32();
			static LRESULT APIENTRY WndFunc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);


			//������
			int Init(HINSTANCE hInst,HINSTANCE hPrev,LPSTR lpszCmdParam,int nCmdshow);

			static Win32* GetInstance(void)
				{
				static Win32 ThisInstance;
				return &ThisInstance;
				}

			//���b�Z�[�W���[�v
			void Run();


		private:
			



		};
	}
//===========================================
#endif