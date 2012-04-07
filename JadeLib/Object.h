/*===========================================
JadeLib�ɊǗ����ė~�����N���X�̊Ԑڊ��N���X
��Ƀo�C�i���t�@�C���ȊO�̃I�u�W�F�N�g������
/==========================================*/
#ifndef _OBJECT_
#define _OBJECT_


#include"stdafx.h"


//BaseClass
#pragma once
#include "BaseCamera.h"
#include "BaseLight.h"
#include "BaseDirectX.h"
#include "BaseModel.h"
#include "BaseObject.h"


//===========================================
namespace Jade
	{
	class Object :  public Jade::BaseObject , Jade::BaseCamera , Jade::BaseDirectX , Jade::BaseLight , public Jade::BaseModel
		{
		public:
			Object();
			virtual ~Object();
			
			void Draw();
			void SetView();
			void DrawControlMode();

			

		private:
			
			
		};
	}
//===========================================
#endif