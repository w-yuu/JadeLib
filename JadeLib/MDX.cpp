#include "MDX.h"
#include "GameState.h"
#include "SystemView.h"

//========================================
namespace Jade
	{
	MDX::MDX()
		{
		this->DataStack.reserve(1000);
		DataStackIt = DataStack.begin();
		}

	int MDX::Init()
		{

		//---------------------DirectX Graphics関連-----------------------

		// Direct3D オブジェクトを作成
		lpD3D = Direct3DCreate9(D3D_SDK_VERSION);
		if (!lpD3D)
			{
			// オブジェクト作成失敗
			MessageBox(NULL,"Direct3D の作成に失敗しました。","ERROR",MB_OK | MB_ICONSTOP);
			// 終了する
			return 0;
			}
		// 使用するアダプタ番号
		adapter = 0;

		// ウインドウの作成が完了したので、Direct3D を初期化する
		ZeroMemory(&d3dpp,sizeof(D3DPRESENT_PARAMETERS));
		// Direct3D 初期化パラメータの設定
		if (FULLSCREEN)
			{
			// フルスクリーン : ほとんどのアダプタでサポートされているフォーマットを使用
			//		d3dpp.BackBufferFormat = D3DFMT_R5G6B5;
			d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
			}
		else
			{
			// ウインドウ : 現在の画面モードを使用
			D3DDISPLAYMODE disp;
			// 現在の画面モードを取得
			lpD3D->GetAdapterDisplayMode(adapter,&disp);
			d3dpp.BackBufferFormat = disp.Format;


			}
		// 表示領域サイズの設定
		d3dpp.BackBufferWidth = SCRW;
		d3dpp.BackBufferHeight = SCRH;
		d3dpp.SwapEffect = D3DSWAPEFFECT_FLIP;

		if (!FULLSCREEN)
			{
			// ウインドウモード
			d3dpp.Windowed = 1;
			}

		// Z バッファの自動作成
		d3dpp.EnableAutoDepthStencil = 1;
		d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

		//ﾊﾞｯｸﾊﾞｯﾌｧをﾛｯｸ可能にする(GetDCも可能になる)
		d3dpp.Flags=D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;

		// デバイスの作成 - T&L HAL
		if (FAILED(lpD3D->CreateDevice(adapter,D3DDEVTYPE_HAL,Jade::Win32::GetInstance()->hwnd,D3DCREATE_HARDWARE_VERTEXPROCESSING,&d3dpp,&lpD3DDevice)))
			{
			// 失敗したので HAL で試行
			if (FAILED(lpD3D->CreateDevice(adapter,D3DDEVTYPE_HAL,Jade::Win32::GetInstance()->hwnd,D3DCREATE_SOFTWARE_VERTEXPROCESSING,&d3dpp,&lpD3DDevice)))
				{
				// 失敗したので REF で試行
				if (FAILED(lpD3D->CreateDevice(adapter,D3DDEVTYPE_REF,Jade::Win32::GetInstance()->hwnd,D3DCREATE_SOFTWARE_VERTEXPROCESSING,&d3dpp,&lpD3DDevice)))
					{
					// 結局失敗した
					MessageBox(NULL,"DirectX9が初期化できません。\n未対応のパソコンと思われます。","ERROR",MB_OK | MB_ICONSTOP);
					lpD3D->Release();
					// 終了する
					return 0;
					}
				}
			}

		// レンダリング・ステートを設定
		// Z バッファ有効化->前後関係の計算を正確にしてくれる
		lpD3DDevice->SetRenderState(D3DRS_ZENABLE,D3DZB_TRUE);
		lpD3DDevice->SetRenderState(D3DRS_ZWRITEENABLE,TRUE);

		// アルファブレンディング有効化
		lpD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE,TRUE);

		// アルファブレンディング方法を設定
		lpD3DDevice->SetRenderState(D3DRS_SRCBLEND,D3DBLEND_SRCALPHA);
		lpD3DDevice->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_INVSRCALPHA);

		// レンダリング時のアルファ値の計算方法の設定
		lpD3DDevice->SetTextureStageState(0,D3DTSS_ALPHAOP,D3DTOP_MODULATE);
		// テクスチャの色を使用
		lpD3DDevice->SetTextureStageState(0,D3DTSS_ALPHAARG1,D3DTA_TEXTURE);
		// 頂点の色を使用
		lpD3DDevice->SetTextureStageState(0,D3DTSS_ALPHAARG2,D3DTA_DIFFUSE);
		// レンダリング時の色の計算方法の設定
		lpD3DDevice->SetTextureStageState(0,D3DTSS_COLOROP,D3DTOP_MODULATE);

		//裏面カリング
		lpD3DDevice->SetRenderState(D3DRS_CULLMODE,D3DCULL_NONE);

		// フィルタ設定
		lpD3DDevice->SetSamplerState(0,D3DSAMP_MIPFILTER,D3DTEXF_LINEAR);
		lpD3DDevice->SetSamplerState(0,D3DSAMP_MINFILTER,D3DTEXF_LINEAR);
		lpD3DDevice->SetSamplerState(0,D3DSAMP_MAGFILTER,D3DTEXF_LINEAR);

		// ライト
		lpD3DDevice->SetRenderState(D3DRS_LIGHTING,FALSE);

		lpD3DDevice->GetBackBuffer(0,0,D3DBACKBUFFER_TYPE_MONO,&lpBackbuffer);

		// 頂点フォーマットの設定
		lpD3DDevice->SetFVF(FVF_VERTEX);

		timeBeginPeriod(1);

		if(Jade::GameState::GetInstance()->DebugMode == true)
		Jade::Debug::GetInstance()->Add("MDXの初期化完了");	
		return 0;
		}


	void MDX::DestMDX()
		{
		timeBeginPeriod(1);
		if(Jade::GameState::GetInstance()->DebugMode == true)
		Jade::Debug::GetInstance()->Add("MDXのDestMDXが呼ばれた",Jade::Debug::GetInstance()->EVENT);
		}


	void MDX::DrawFrame()
		{
		// 描画開始
		lpD3DDevice->BeginScene();

		// バックバッファと Z バッファをクリア
		lpD3DDevice->Clear(0,NULL,D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,D3DCOLOR_XRGB(0,0,255),1.0f,0);

		//D3DXMATRIX mView,mProj;

		//// 視点行列の設定
		//D3DXMatrixLookAtLH(&mView,
		//	&D3DXVECTOR3(0,0,-5),
		//	&D3DXVECTOR3(0,0,0),
		//	&D3DXVECTOR3(0.0f, 1.0f, 0.0f)
		//	);

		//// 投影行列の設定
		//D3DXMatrixPerspectiveFovLH(&mProj, D3DXToRadian(60), 4.0f/3.0f, 1.0f, 1000.0f);

		////行列設定
		//lpD3DDevice->SetTransform(D3DTS_VIEW, &mView);
		//lpD3DDevice->SetTransform(D3DTS_PROJECTION, &mProj);

		////ここに記入------------------------------------------------------------------


		//static D3DXVECTOR3 pos = D3DXVECTOR3( 0.0f,0.0f,0.0f);//移動の為の変数

		//D3DXMATRIX mRot;//回転専用の行列
		//D3DXMATRIX mWorld;//掛け合わされた行列
		//D3DXMATRIX mTrans;//行列の為の変数
		//D3DXMATRIX mScal;
		//D3DXMatrixScaling( &mScal , 2.0f , 2.0f , 2.0f );

		//VERTEX v[4];

		//v[0].Pos = D3DXVECTOR3( -50 ,  30 , 0 );
		//v[1].Pos = D3DXVECTOR3(  50 ,  30 , 0 );
		//v[2].Pos = D3DXVECTOR3(  50 , -30 , 0 );
		//v[3].Pos = D3DXVECTOR3( -50 , -30 , 0 );

		//v[0].Color = D3DCOLOR_ARGB( 255 , 100 , 5  ,   0);
		//v[1].Color = D3DCOLOR_ARGB( 255 , 0   , 5  , 100);
		//v[2].Color = D3DCOLOR_ARGB( 255 , 50  , 100,   0);
		/*v[3].Color = D3DCOLOR_ARGB( 255 , 20  , 20 ,  50);*/

		//static float Rot = 0.0f;//回転の制御
		//Rot+=4;//回転を増やす



		//D3DXMatrixRotationY( &mRot , D3DXToRadian( Rot ) );
		//if( Rot >= 360 ) Rot = 0;//360度以上になったら0にする。
		//static float x = 0.1f;

	/*	if( GetAsyncKeyState(VK_RIGHT) & 0x8000)
			{
			pos.x += x;

			}

		if( GetAsyncKeyState(VK_LEFT) & 0x8000)
			{
			pos.x -= x;

			}
		if( GetAsyncKeyState(VK_DOWN) & 0x8000)
			{
			pos.y -= x;

			}
		if( GetAsyncKeyState(VK_UP) & 0x8000)
			{
			pos.y += x;

			}*/



		//D3DXMatrixTranslation( &mTrans , pos.x , pos.y , pos.z );

		//mWorld =mScal * mRot * mTrans;

		//lpD3DDevice->SetTransform( D3DTS_WORLD ,  &mWorld );

		//lpD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN,2,v,sizeof(VERTEX) );

		

		
			//======================================================================================
		

		/*
		型実行なんだけど、publicにしたらBaseObjectじゃなくてもメソッド呼び出しできるんじゃない？
		static_cast<Object>みたいに強引にキャストすればできるｗ
		*/
		
		
		for(this->DataStackIt = this->DataStack.begin(); DataStackIt != DataStack.end() ; DataStackIt++ )  // 末尾要素まで
				{
			
				//オブジェクト固有のメソッド及びフィールドを扱いたい場合はキャストする事
				std::type_info const & info = typeid(*(*DataStackIt)) ;  // 実行時型情報を取得
				if( info == typeid( Object ) )
					{
					(*DataStackIt)->Draw();//描画
					if(Jade::GameState::GetInstance()->DebugMode == true)
					Jade::Debug::GetInstance()->Add("MDX EndDraw");
					}

				else if( info == typeid( SystemView ) )
					{
					(*DataStackIt)->SetView();//描画
					
					if(Jade::GameState::GetInstance()->DebugMode == true)
					Jade::Debug::GetInstance()->Add("MDX EndViewDraw");
					
					}
				else
				{
					if(Jade::GameState::GetInstance()->DebugMode == true)
					Jade::Debug::GetInstance()->Add("型情報判定失敗");
				}


				              
				}
			//======================================================================================
		

		
			
		//RenderProc();
		// 描画終了
		lpD3DDevice->EndScene();

		// バックバッファをプライマリバッファにコピー
		if (FAILED(lpD3DDevice->Present(NULL,NULL,NULL,NULL)))
			{
			lpD3DDevice->Reset(&d3dpp);
			}



		}

	}
