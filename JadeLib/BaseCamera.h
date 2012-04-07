/*===========================================
DirecrXの扱うクラスの最低限の間接基底クラス
Singletonパターンを採用している。
描画やその他制御に必要なデータを保持している。
/==========================================*/
#ifndef _BASECAMERA_
#define _BASECAMERA_


#include <stdio.h> 
#include<iostream>
#include<d3dx9.h>
//===========================================
namespace Jade
	{
	class BaseCamera
		{
		public:
			BaseCamera();
			virtual ~BaseCamera();
			

		


		private:
			

		};
	}
//===========================================
#endif