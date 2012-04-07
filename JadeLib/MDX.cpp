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

		//---------------------DirectX Graphics�֘A-----------------------

		// Direct3D �I�u�W�F�N�g���쐬
		lpD3D = Direct3DCreate9(D3D_SDK_VERSION);
		if (!lpD3D)
			{
			// �I�u�W�F�N�g�쐬���s
			MessageBox(NULL,"Direct3D �̍쐬�Ɏ��s���܂����B","ERROR",MB_OK | MB_ICONSTOP);
			// �I������
			return 0;
			}
		// �g�p����A�_�v�^�ԍ�
		adapter = 0;

		// �E�C���h�E�̍쐬�����������̂ŁADirect3D ������������
		ZeroMemory(&d3dpp,sizeof(D3DPRESENT_PARAMETERS));
		// Direct3D �������p�����[�^�̐ݒ�
		if (FULLSCREEN)
			{
			// �t���X�N���[�� : �قƂ�ǂ̃A�_�v�^�ŃT�|�[�g����Ă���t�H�[�}�b�g���g�p
			//		d3dpp.BackBufferFormat = D3DFMT_R5G6B5;
			d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
			}
		else
			{
			// �E�C���h�E : ���݂̉�ʃ��[�h���g�p
			D3DDISPLAYMODE disp;
			// ���݂̉�ʃ��[�h���擾
			lpD3D->GetAdapterDisplayMode(adapter,&disp);
			d3dpp.BackBufferFormat = disp.Format;


			}
		// �\���̈�T�C�Y�̐ݒ�
		d3dpp.BackBufferWidth = SCRW;
		d3dpp.BackBufferHeight = SCRH;
		d3dpp.SwapEffect = D3DSWAPEFFECT_FLIP;

		if (!FULLSCREEN)
			{
			// �E�C���h�E���[�h
			d3dpp.Windowed = 1;
			}

		// Z �o�b�t�@�̎����쐬
		d3dpp.EnableAutoDepthStencil = 1;
		d3dpp.AutoDepthStencilFormat = D3DFMT_D16;

		//�ޯ��ޯ̧��ۯ��\�ɂ���(GetDC���\�ɂȂ�)
		d3dpp.Flags=D3DPRESENTFLAG_LOCKABLE_BACKBUFFER;

		// �f�o�C�X�̍쐬 - T&L HAL
		if (FAILED(lpD3D->CreateDevice(adapter,D3DDEVTYPE_HAL,Jade::Win32::GetInstance()->hwnd,D3DCREATE_HARDWARE_VERTEXPROCESSING,&d3dpp,&lpD3DDevice)))
			{
			// ���s�����̂� HAL �Ŏ��s
			if (FAILED(lpD3D->CreateDevice(adapter,D3DDEVTYPE_HAL,Jade::Win32::GetInstance()->hwnd,D3DCREATE_SOFTWARE_VERTEXPROCESSING,&d3dpp,&lpD3DDevice)))
				{
				// ���s�����̂� REF �Ŏ��s
				if (FAILED(lpD3D->CreateDevice(adapter,D3DDEVTYPE_REF,Jade::Win32::GetInstance()->hwnd,D3DCREATE_SOFTWARE_VERTEXPROCESSING,&d3dpp,&lpD3DDevice)))
					{
					// ���ǎ��s����
					MessageBox(NULL,"DirectX9���������ł��܂���B\n���Ή��̃p�\�R���Ǝv���܂��B","ERROR",MB_OK | MB_ICONSTOP);
					lpD3D->Release();
					// �I������
					return 0;
					}
				}
			}

		// �����_�����O�E�X�e�[�g��ݒ�
		// Z �o�b�t�@�L����->�O��֌W�̌v�Z�𐳊m�ɂ��Ă����
		lpD3DDevice->SetRenderState(D3DRS_ZENABLE,D3DZB_TRUE);
		lpD3DDevice->SetRenderState(D3DRS_ZWRITEENABLE,TRUE);

		// �A���t�@�u�����f�B���O�L����
		lpD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE,TRUE);

		// �A���t�@�u�����f�B���O���@��ݒ�
		lpD3DDevice->SetRenderState(D3DRS_SRCBLEND,D3DBLEND_SRCALPHA);
		lpD3DDevice->SetRenderState(D3DRS_DESTBLEND,D3DBLEND_INVSRCALPHA);

		// �����_�����O���̃A���t�@�l�̌v�Z���@�̐ݒ�
		lpD3DDevice->SetTextureStageState(0,D3DTSS_ALPHAOP,D3DTOP_MODULATE);
		// �e�N�X�`���̐F���g�p
		lpD3DDevice->SetTextureStageState(0,D3DTSS_ALPHAARG1,D3DTA_TEXTURE);
		// ���_�̐F���g�p
		lpD3DDevice->SetTextureStageState(0,D3DTSS_ALPHAARG2,D3DTA_DIFFUSE);
		// �����_�����O���̐F�̌v�Z���@�̐ݒ�
		lpD3DDevice->SetTextureStageState(0,D3DTSS_COLOROP,D3DTOP_MODULATE);

		//���ʃJ�����O
		lpD3DDevice->SetRenderState(D3DRS_CULLMODE,D3DCULL_NONE);

		// �t�B���^�ݒ�
		lpD3DDevice->SetSamplerState(0,D3DSAMP_MIPFILTER,D3DTEXF_LINEAR);
		lpD3DDevice->SetSamplerState(0,D3DSAMP_MINFILTER,D3DTEXF_LINEAR);
		lpD3DDevice->SetSamplerState(0,D3DSAMP_MAGFILTER,D3DTEXF_LINEAR);

		// ���C�g
		lpD3DDevice->SetRenderState(D3DRS_LIGHTING,FALSE);

		lpD3DDevice->GetBackBuffer(0,0,D3DBACKBUFFER_TYPE_MONO,&lpBackbuffer);

		// ���_�t�H�[�}�b�g�̐ݒ�
		lpD3DDevice->SetFVF(FVF_VERTEX);

		timeBeginPeriod(1);

		if(Jade::GameState::GetInstance()->DebugMode == true)
		Jade::Debug::GetInstance()->Add("MDX�̏���������");	
		return 0;
		}


	void MDX::DestMDX()
		{
		timeBeginPeriod(1);
		if(Jade::GameState::GetInstance()->DebugMode == true)
		Jade::Debug::GetInstance()->Add("MDX��DestMDX���Ă΂ꂽ",Jade::Debug::GetInstance()->EVENT);
		}


	void MDX::DrawFrame()
		{
		// �`��J�n
		lpD3DDevice->BeginScene();

		// �o�b�N�o�b�t�@�� Z �o�b�t�@���N���A
		lpD3DDevice->Clear(0,NULL,D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,D3DCOLOR_XRGB(0,0,255),1.0f,0);

		//D3DXMATRIX mView,mProj;

		//// ���_�s��̐ݒ�
		//D3DXMatrixLookAtLH(&mView,
		//	&D3DXVECTOR3(0,0,-5),
		//	&D3DXVECTOR3(0,0,0),
		//	&D3DXVECTOR3(0.0f, 1.0f, 0.0f)
		//	);

		//// ���e�s��̐ݒ�
		//D3DXMatrixPerspectiveFovLH(&mProj, D3DXToRadian(60), 4.0f/3.0f, 1.0f, 1000.0f);

		////�s��ݒ�
		//lpD3DDevice->SetTransform(D3DTS_VIEW, &mView);
		//lpD3DDevice->SetTransform(D3DTS_PROJECTION, &mProj);

		////�����ɋL��------------------------------------------------------------------


		//static D3DXVECTOR3 pos = D3DXVECTOR3( 0.0f,0.0f,0.0f);//�ړ��ׂ̈̕ϐ�

		//D3DXMATRIX mRot;//��]��p�̍s��
		//D3DXMATRIX mWorld;//�|�����킳�ꂽ�s��
		//D3DXMATRIX mTrans;//�s��ׂ̈̕ϐ�
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

		//static float Rot = 0.0f;//��]�̐���
		//Rot+=4;//��]�𑝂₷



		//D3DXMatrixRotationY( &mRot , D3DXToRadian( Rot ) );
		//if( Rot >= 360 ) Rot = 0;//360�x�ȏ�ɂȂ�����0�ɂ���B
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
		�^���s�Ȃ񂾂��ǁApublic�ɂ�����BaseObject����Ȃ��Ă����\�b�h�Ăяo���ł���񂶂�Ȃ��H
		static_cast<Object>�݂����ɋ����ɃL���X�g����΂ł��邗
		*/
		
		
		for(this->DataStackIt = this->DataStack.begin(); DataStackIt != DataStack.end() ; DataStackIt++ )  // �����v�f�܂�
				{
			
				//�I�u�W�F�N�g�ŗL�̃��\�b�h�y�уt�B�[���h�����������ꍇ�̓L���X�g���鎖
				std::type_info const & info = typeid(*(*DataStackIt)) ;  // ���s���^�����擾
				if( info == typeid( Object ) )
					{
					(*DataStackIt)->Draw();//�`��
					if(Jade::GameState::GetInstance()->DebugMode == true)
					Jade::Debug::GetInstance()->Add("MDX EndDraw");
					}

				else if( info == typeid( SystemView ) )
					{
					(*DataStackIt)->SetView();//�`��
					
					if(Jade::GameState::GetInstance()->DebugMode == true)
					Jade::Debug::GetInstance()->Add("MDX EndViewDraw");
					
					}
				else
				{
					if(Jade::GameState::GetInstance()->DebugMode == true)
					Jade::Debug::GetInstance()->Add("�^��񔻒莸�s");
				}


				              
				}
			//======================================================================================
		

		
			
		//RenderProc();
		// �`��I��
		lpD3DDevice->EndScene();

		// �o�b�N�o�b�t�@���v���C�}���o�b�t�@�ɃR�s�[
		if (FAILED(lpD3DDevice->Present(NULL,NULL,NULL,NULL)))
			{
			lpD3DDevice->Reset(&d3dpp);
			}



		}

	}
