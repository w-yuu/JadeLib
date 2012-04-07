/*===========================================
DirecrX�̈����N���X�̍Œ���̊Ԑڊ��N���X
Singleton�p�^�[�����̗p���Ă���B
�`��₻�̑�����ɕK�v�ȃf�[�^��ێ����Ă���B
/==========================================*/
#ifndef _SYSTEMVIEW_
#define _SYSTEMVIEW_


#include <stdio.h> 
#include <iostream>
#include <d3dx9.h>
#include "baseObject.h"
//===========================================
namespace Jade
	{
	class SystemView : public BaseObject
		{
		public:
			
			SystemView();
			virtual ~SystemView();

			void Draw();
			void SetView();


		protected:
		D3DXMATRIX mView,mProj;
		D3DXVECTOR3 Lie,Gaze,Sky;

		};
	}
//===========================================
#endif