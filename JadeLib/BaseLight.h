/*===========================================
DirecrXの扱うクラスの最低限の間接基底クラス
Singletonパターンを採用している。
描画やその他制御に必要なデータを保持している。
/==========================================*/
#ifndef _BASELIGHT_
#define _BASELIGHT_

#include <stdio.h> 
#include<iostream>
#include<d3dx9.h>
//===========================================
namespace Jade
	{
	class BaseLight
		{
		public:
			BaseLight();
			virtual ~BaseLight();


		private:
		

		};
	}
//===========================================
#endif