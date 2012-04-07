/*===========================================
DirecrXの扱うクラスの最低限の間接基底クラス
Singletonパターンを採用している。
描画やその他制御に必要なデータを保持している。
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
			BaseDirectX();//コンストラクタ
			virtual ~BaseDirectX();//デストラクタ
			
		protected:

			unsigned int SerialNumber;//オブジェクト固有の番号
			bool CullMode;//  ?


			// 頂点フォーマット
			struct VERTEX
				{
				D3DXVECTOR3 Pos;
				D3DCOLOR Color;
				D3DXVECTOR2 Tex;
				};

			vector<VERTEX> Vertex;//頂点データ
			vector<VERTEX>::iterator VertexIt;//頂点イテレータ 

			//インスタンスの情報を初期化（描画前に必ず1回呼ぶこと）
			void Initialize();

			





		private:


		};
	}
//===========================================
#endif