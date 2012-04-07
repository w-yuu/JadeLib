/*===========================================
DirecrXの扱うクラスの最低限の間接基底クラス
Singletonパターンを採用している。
描画やその他制御に必要なデータを保持している。
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