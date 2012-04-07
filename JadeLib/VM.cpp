#include "VM.h"
#include "stdafx.h"
#include "GameState.h"
#include "MDX.h"
#include "Win32.h"
#include "Object.h"
#include "SystemView.h"


//#include <boost/any.hpp>
using namespace std;
//using namespace Jade;
int WINAPI WinMain(HINSTANCE hInst,HINSTANCE hPrev,
				   LPSTR lpszCmdParam,int nCmdshow)
	{

		//Jade::GameState::GetInstance()->DebugMode = true;


	Jade::Win32::GetInstance()->Init( hInst,hPrev,lpszCmdParam,nCmdshow);
	Jade::MDX::GetInstance()->Init();
	Jade::VM::GetInstance()->Init();



//実体
	Jade::Object obj;
	Jade::SystemView sy;

	Jade::Object* o = &obj;
	Jade::SystemView* s = &sy;



	//オブジェクト
	Jade::MDX::GetInstance()->DataStack.push_back(o);

	

	Jade::MDX::GetInstance()->DataStack.push_back(s);


	/*Jade::MDX::GetInstance()->DataStack.erase(Jade::MDX::GetInstance()->DataStackIt=Jade::MDX::GetInstance()->DataStack.begin() +1);
	Jade::MDX::GetInstance()->DataStack.erase(Jade::MDX::GetInstance()->DataStackIt=Jade::MDX::GetInstance()->DataStack.begin() +1);*/


	


	Jade::Win32::GetInstance()->Run();




	return 0;
	}

namespace Jade
	{

	VM::VM()
		{
		}
	VM::~VM()
		{

		}


	bool VM::Init(void)
		{
		if( ScriptInit() == true)
			{
			return true;
			}
		else
			{
			return false;
			}
		}

	bool VM::ScriptInit()
		{
		//using namespace xtal;
		////--------------------------Xtal関連------------------------------


		////エラー報告変数
		//int error = 0;
		//try{
		//	CStdioStdStreamLib cstd_std_stream_lib; // stdin, stdout, stderrはCの標準ライブラリを使う
		//	WinThreadLib win_thread_lib; // Windowsのスレッドを使う
		//	WinFilesystemLib win_filesystem_lib; // Windowsのファイルシステムを使う 
		//	SJISChCodeLib sjis_ch_code_lib; // SJISを使う


		//	// 環境依存である機能についてどれを使うかを設定
		//	Setting setting; 
		//	setting.thread_lib = &win_thread_lib;
		//	setting.std_stream_lib = &cstd_std_stream_lib;
		//	setting.filesystem_lib = &win_filesystem_lib;
		//	setting.ch_code_lib = &sjis_ch_code_lib;

		//	// ここで指定したthread_libなどのポインタが示す先のオブジェクトは、
		//	// uninitializeを呼び出すまで存在している必要があります。

		//	// Xtalを初期化

		//	initialize(setting);

		//	// エラーメッセージをバインド
		//	bind_error_message();

		//	// ここでスクリプトの実行を行う
		//		{
		//		xtal::CodePtr pCode;
		//		// ファイルのコンパイル
		//		//pCode = xtal::compile_file("test.xtal");
		//		//if (pCode)    // コンパイルに失敗したときはxtal::nullが返る
		//		//    pCode->call();
		//		// 上は下と同義
		//		xtal::load("System/Script/Main.xtal");//ゲームのエントリーポイント。ここにxtalファイルを指定して処理していく。
		//		Jade::Debug::GetInstance()->Add("Xtalエントリーファイルのロード開始");

		//		// libオブジェクトからfuncTestオブジェクトを取り出す
		//		xtal::AnyPtr f = xtal::lib()->member(Xid(funcTest));    // intern化した文字列
		//		// xtal::AnyPtr f = xtal::lib()->member("funcTest"));   // 文字列リテラルも渡せる
		//		// funcTestオブジェクトを実行する
		//		xtal::AnyPtr ret = f->call();    // 10が入ったxtal::AnyPtrが返る
		//		std::cout << ret->to_s()->c_str() << std::endl;    // "10\n"が出力されます

		//		}

		//		// 例外を捕捉
		//		XTAL_CATCH_EXCEPT(e){
		//			Jade::Debug::GetInstance()->Add("code:901 Xtalエントリーファイルのロード失敗",Jade::Debug::GetInstance()->ERROR_LL);
		//			MessageBox(NULL,"初期化エラー code:901","",MB_OK);//error code 901 Xtalの初期化エラー
		//			stderr_stream()->println(e);

		//			error = 1;//初期化エラーとして本体に報告
		//			}

		//		// Xtalを破棄
		//		uninitialize();
		//	}

		//catch( const char* str )  // 例外をキャッチする
		//	{
		//	Jade::Debug::GetInstance()->Add("code:102 不明なエラー",Jade::Debug::GetInstance()->ERROR_LL);
		//	MessageBox(NULL,"重大な内部エラー code:102","ERROR",MB_OK | MB_ICONSTOP);
		//	error = 1;
		//	}
		//if(error == 1) return false;//初期化時にエラーがあった場合、１を返す。本体はこれを確認し、実行するか判断する。
		//return true;
			return false;
		}





	void VM::CreateObject( string Data,int Option )
		{

		}


	}