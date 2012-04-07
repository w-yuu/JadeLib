#include "SystemView.h"
#include "MDX.h"
#include "GameState.h"
//========================================

#define MDX Jade::MDX::GetInstance()->
namespace Jade
	{
	SystemView::SystemView()
		{
		Lie		= D3DXVECTOR3(0,0,-5);
		Gaze	= D3DXVECTOR3(0,0,0);
		Sky		= D3DXVECTOR3(0.0f, 1.0f, 0.0f);
		if(Jade::GameState::GetInstance()->DebugMode == true)
		Jade::Debug::GetInstance()->Add("SystemViewClass Create");
		}

	SystemView::~SystemView()
		{
		if(Jade::GameState::GetInstance()->DebugMode == true)
		Jade::Debug::GetInstance()->Add("SystemViewClass Destructor");
		}


	void SystemView::Draw()
	{
	}


	void SystemView::SetView()//オブジェクトのViewを設定する
		{


		// 視点行列の設定
		D3DXMatrixLookAtLH(&mView,
			&Lie,
			&Gaze,
			&Sky
			);

		// 投影行列の設定
		D3DXMatrixPerspectiveFovLH(&mProj, D3DXToRadian(60), 4.0f/3.0f, 1.0f, 1000.0f);

		//行列設定
		MDX lpD3DDevice->SetTransform(D3DTS_VIEW, &mView);
		MDX lpD3DDevice->SetTransform(D3DTS_PROJECTION, &mProj);
		
		//ここに記入------------------------------------------------------------------


		static D3DXVECTOR3 pos = D3DXVECTOR3( 0.0f,0.0f,0.0f);//移動の為の変数

		D3DXMATRIX mRot;//回転専用の行列
		D3DXMATRIX mWorld;//掛け合わされた行列
		D3DXMATRIX mTrans;//行列の為の変数
		D3DXMATRIX mScal;
		D3DXMatrixScaling( &mScal , 2.0f , 2.0f , 2.0f );


		static float Rot = 0.0f;//回転の制御
		Rot+=4;//回転を増やす



		D3DXMatrixRotationY( &mRot , D3DXToRadian( Rot ) );
		if( Rot >= 360 ) Rot = 0;//360度以上になったら0にする。
		static float x = 0.1f;





		D3DXMatrixTranslation( &mTrans , pos.x , pos.y , pos.z );

		mWorld =mScal * mRot * mTrans;

		MDX lpD3DDevice->SetTransform( D3DTS_WORLD ,  &mWorld );
		}



	}