#include "Object.h"
#include "MDX.h"
#include "GameState.h"
//========================================
namespace Jade
	{

	Object::Object()
		{
			if(Jade::GameState::GetInstance()->DebugMode == true)
		Jade::Debug::GetInstance()->Add("ObjectClass Create");
		}

	Object::~Object()
		{
			if(Jade::GameState::GetInstance()->DebugMode == true)
		Jade::Debug::GetInstance()->Add("ObjectClass Destructor");
		}

	void Object::SetView()
	{
	}
	void Object::Draw()
		{
		VERTEX v[4];
		
			v[0].Pos = D3DXVECTOR3( -1 ,  1 , 0 );
			v[1].Pos = D3DXVECTOR3(  1 ,  1 , 0 );
			v[2].Pos = D3DXVECTOR3(  1 , -1 , 0 );
			v[3].Pos = D3DXVECTOR3( -1 , -1 , 0 );

			v[0].Color = D3DCOLOR_ARGB( 255 , 100 ,200  ,   0);
			v[0].Color = D3DCOLOR_ARGB( 255 , 0 , 43  ,   0);
			v[1].Color = D3DCOLOR_ARGB( 255 , 0   , 5  , 100);
			v[2].Color = D3DCOLOR_ARGB( 255 , 50  , 100,   0);
			v[3].Color = D3DCOLOR_ARGB( 255 , 200  , 20 ,  50);
			

			Jade::MDX::GetInstance()->lpD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLEFAN,2,v,sizeof(VERTEX) );
			
			if(Jade::GameState::GetInstance()->DebugMode == true)
			Jade::Debug::GetInstance()->Add("Object Draw");
		}


	void Object::DrawControlMode()
		{

		}



	}