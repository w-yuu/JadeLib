/*===========================================
DirecrXの扱うクラスの最低限の間接基底クラス
Singletonパターンを採用している。
描画やその他制御に必要なデータを保持している。
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