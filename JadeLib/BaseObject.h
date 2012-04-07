/*===========================================
DirecrXの扱うクラスの最低限の間接基底クラス
Singletonパターンを採用している。
描画やその他制御に必要なデータを保持している。
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