/*===========================================
DirecrX�̈����N���X�̍Œ���̊Ԑڊ��N���X
Singleton�p�^�[�����̗p���Ă���B
�`��₻�̑�����ɕK�v�ȃf�[�^��ێ����Ă���B
/==========================================*/
#ifndef _BASEOBJECT_
#define _BASEOBJECT_


#include <stdio.h> 
#include<iostream>
#include<d3dx9.h>
//===========================================
namespace Jade
	{
	class BaseObject
		{
		public:
			
			BaseObject();
			virtual ~BaseObject();

			virtual void Draw() = 0;
			virtual void SetView() = 0;



		protected:
	

		};
	}
//===========================================
#endif