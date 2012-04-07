/*===========================================
ファイルの入出力やインスタンスの管理、
描画の実行、その他、常に動作し続けるループの制御。
ObjectクラスはDraw,SystemViewクラスはSetView,それ以外はUserの
メソッドが自動で実行される。（実際の処理はMDXクラス、、というかMDXにこの説明を移した方がよくね?）
ゲーム上のインスタンス（キャラクター、アイテム）などはこのVM上で
インスタンス生成する事。これによりどこでキャラを制御しているのかが明確になる。
またVM上で生成されたインスタンスはメモリリークを起こさない
ことが保証される。（自動デストラクタ）
シングルトンクラスではない。
/==========================================*/


#ifndef _VM_
#define _VM_

#include<windows.h>
#include<stdio.h>
#include<d3dx9.h>
#include<time.h>
#include<string>

//今回は使用しない
////Xtalのインクルード-----------
//#include <xtal.h>
//#include <xtal_macro.h> // Xidなど便利なマクロが定義されている
//
//#include <xtal_lib/xtal_cstdiostream.h>	// CStdioStdStreamLibのため
//#include <xtal_lib/xtal_winthread.h>		// WinThreadLibのため
//#include <xtal_lib/xtal_winfilesystem.h>	// WinFilesystemLibのため
//#include <xtal_lib/xtal_chcode.h>			// SJISChCodeLibのため
//#include <xtal_lib/xtal_errormessage.h>	// bind_error_message()のため
//
//
////========================================


//======================================
namespace Jade
	{
	class VM//インスタンスの管理を行う
		{
		public:
			VM();
			~VM();
			bool Init(void);
			bool ScriptInit(void);
			void CreateObject(std::string Data,int Option);

			static VM* GetInstance(void)
				{
				static VM ThisInstance;
				
				return &ThisInstance;
				}


			
			

		private:
			
			
		};
	}
//======================================
#endif