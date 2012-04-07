/*==========================================================
DirecrXの状態やウィンドウを管理するクラス
Singletonパターンを採用している。
このインスタンスに描画登録するにはObjectクラス
の派生であることが決められている。
/==========================================================*/
#ifndef _MDX_
#define _MDX_

//#include "stdafx.h"

#include <time.h>
#include "Win32.h"
#include <vector>
#include "Object.h"
#include "BaseObject.h"
#define	FULLSCREEN	0		// フルスクリーン時に 1 にする
#define	SCRW		640		// Width
#define	SCRH		480		// Heigh
#define	FVF_VERTEX (D3DFVF_XYZ | D3DFVF_DIFFUSE | D3DFVF_TEX1)

using namespace std;
//===========================================
namespace Jade
	{
	class MDX
		{
		public:
			//コンストラクタ
			MDX();
			void DestMDX();
			


			//初期化
			int					Init();

			LPDIRECT3D9				lpD3D;				// Direct3Dインターフェイス
			LPDIRECT3DDEVICE9		lpD3DDevice;		// Direct3DDeviceインターフェイス
			LPDIRECT3DSURFACE9		lpBackbuffer;		
			D3DPRESENT_PARAMETERS	d3dpp;
			int						adapter;

			vector<BaseObject*>	DataStack;
			vector<BaseObject*>::iterator DataStackIt;

			


			//DirectXの要素にアクセスする関数 
			static MDX* GetInstance(void)
				{
				static MDX ThisInstance;
				return &ThisInstance;
				}


			//一時的
			struct VERTEX
				{
				D3DXVECTOR3 Pos;
				D3DCOLOR Color;
				D3DXVECTOR2 Tex;
				};

		
			void DrawFrame();

		private:






		};
	}
//===========================================
#endif