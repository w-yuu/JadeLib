/*===========================================
DirecrX�̈����N���X�̍Œ���̊Ԑڊ��N���X
Singleton�p�^�[�����̗p���Ă���B
�`��₻�̑�����ɕK�v�ȃf�[�^��ێ����Ă���B
/==========================================*/
#ifndef _BASEMODEL_
#define _BASEMODEL_


#include <stdio.h> 
#include <iostream>
#include <d3dx9.h>
//===========================================
namespace Jade
	{
	class BaseModel
		{
		public:
			BaseModel();
			virtual ~BaseModel();

			void ModelLine();


		protected:
			float x, y, z , x2, y2 , z2;

			
			D3DXVECTOR2 LineX[2];
				

			ID3DXLine*				Line_axis;


		};
	}
//===========================================
#endif