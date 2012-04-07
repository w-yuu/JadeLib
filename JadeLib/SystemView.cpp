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


	void SystemView::SetView()//�I�u�W�F�N�g��View��ݒ肷��
		{


		// ���_�s��̐ݒ�
		D3DXMatrixLookAtLH(&mView,
			&Lie,
			&Gaze,
			&Sky
			);

		// ���e�s��̐ݒ�
		D3DXMatrixPerspectiveFovLH(&mProj, D3DXToRadian(60), 4.0f/3.0f, 1.0f, 1000.0f);

		//�s��ݒ�
		MDX lpD3DDevice->SetTransform(D3DTS_VIEW, &mView);
		MDX lpD3DDevice->SetTransform(D3DTS_PROJECTION, &mProj);
		
		//�����ɋL��------------------------------------------------------------------


		static D3DXVECTOR3 pos = D3DXVECTOR3( 0.0f,0.0f,0.0f);//�ړ��ׂ̈̕ϐ�

		D3DXMATRIX mRot;//��]��p�̍s��
		D3DXMATRIX mWorld;//�|�����킳�ꂽ�s��
		D3DXMATRIX mTrans;//�s��ׂ̈̕ϐ�
		D3DXMATRIX mScal;
		D3DXMatrixScaling( &mScal , 2.0f , 2.0f , 2.0f );


		static float Rot = 0.0f;//��]�̐���
		Rot+=4;//��]�𑝂₷



		D3DXMatrixRotationY( &mRot , D3DXToRadian( Rot ) );
		if( Rot >= 360 ) Rot = 0;//360�x�ȏ�ɂȂ�����0�ɂ���B
		static float x = 0.1f;





		D3DXMatrixTranslation( &mTrans , pos.x , pos.y , pos.z );

		mWorld =mScal * mRot * mTrans;

		MDX lpD3DDevice->SetTransform( D3DTS_WORLD ,  &mWorld );
		}



	}