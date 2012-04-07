/*==========================================================
DirecrX�̏�Ԃ�E�B���h�E���Ǘ�����N���X
Singleton�p�^�[�����̗p���Ă���B
���̃C���X�^���X�ɕ`��o�^����ɂ�Object�N���X
�̔h���ł��邱�Ƃ����߂��Ă���B
/==========================================================*/
#ifndef _MDX_
#define _MDX_

//#include "stdafx.h"

#include <time.h>
#include "Win32.h"
#include <vector>
#include "Object.h"
#include "BaseObject.h"
#define	FULLSCREEN	0		// �t���X�N���[������ 1 �ɂ���
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
			//�R���X�g���N�^
			MDX();
			void DestMDX();
			


			//������
			int					Init();

			LPDIRECT3D9				lpD3D;				// Direct3D�C���^�[�t�F�C�X
			LPDIRECT3DDEVICE9		lpD3DDevice;		// Direct3DDevice�C���^�[�t�F�C�X
			LPDIRECT3DSURFACE9		lpBackbuffer;		
			D3DPRESENT_PARAMETERS	d3dpp;
			int						adapter;

			vector<BaseObject*>	DataStack;
			vector<BaseObject*>::iterator DataStackIt;

			


			//DirectX�̗v�f�ɃA�N�Z�X����֐� 
			static MDX* GetInstance(void)
				{
				static MDX ThisInstance;
				return &ThisInstance;
				}


			//�ꎞ�I
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