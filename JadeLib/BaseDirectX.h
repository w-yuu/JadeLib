/*===========================================
DirecrX�̈����N���X�̍Œ���̊Ԑڊ��N���X
Singleton�p�^�[�����̗p���Ă���B
�`��₻�̑�����ɕK�v�ȃf�[�^��ێ����Ă���B
/==========================================*/
#ifndef _BASEDIRECTX_
#define _BASEDIRECTX_

#include <stdio.h> 
#include<iostream>
#include<d3dx9.h>

#include <vector>
using namespace std;
//===========================================
namespace Jade
	{
	class BaseDirectX
		{
		public:
			BaseDirectX();//�R���X�g���N�^
			virtual ~BaseDirectX();//�f�X�g���N�^
			
		protected:

			unsigned int SerialNumber;//�I�u�W�F�N�g�ŗL�̔ԍ�
			bool CullMode;//  ?


			// ���_�t�H�[�}�b�g
			struct VERTEX
				{
				D3DXVECTOR3 Pos;
				D3DCOLOR Color;
				D3DXVECTOR2 Tex;
				};

			vector<VERTEX> Vertex;//���_�f�[�^
			vector<VERTEX>::iterator VertexIt;//���_�C�e���[�^ 

			//�C���X�^���X�̏����������i�`��O�ɕK��1��ĂԂ��Ɓj
			void Initialize();

			





		private:


		};
	}
//===========================================
#endif