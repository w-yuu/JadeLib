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



//����
	Jade::Object obj;
	Jade::SystemView sy;

	Jade::Object* o = &obj;
	Jade::SystemView* s = &sy;



	//�I�u�W�F�N�g
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
		////--------------------------Xtal�֘A------------------------------


		////�G���[�񍐕ϐ�
		//int error = 0;
		//try{
		//	CStdioStdStreamLib cstd_std_stream_lib; // stdin, stdout, stderr��C�̕W�����C�u�������g��
		//	WinThreadLib win_thread_lib; // Windows�̃X���b�h���g��
		//	WinFilesystemLib win_filesystem_lib; // Windows�̃t�@�C���V�X�e�����g�� 
		//	SJISChCodeLib sjis_ch_code_lib; // SJIS���g��


		//	// ���ˑ��ł���@�\�ɂ��Ăǂ���g������ݒ�
		//	Setting setting; 
		//	setting.thread_lib = &win_thread_lib;
		//	setting.std_stream_lib = &cstd_std_stream_lib;
		//	setting.filesystem_lib = &win_filesystem_lib;
		//	setting.ch_code_lib = &sjis_ch_code_lib;

		//	// �����Ŏw�肵��thread_lib�Ȃǂ̃|�C���^��������̃I�u�W�F�N�g�́A
		//	// uninitialize���Ăяo���܂ő��݂��Ă���K�v������܂��B

		//	// Xtal��������

		//	initialize(setting);

		//	// �G���[���b�Z�[�W���o�C���h
		//	bind_error_message();

		//	// �����ŃX�N���v�g�̎��s���s��
		//		{
		//		xtal::CodePtr pCode;
		//		// �t�@�C���̃R���p�C��
		//		//pCode = xtal::compile_file("test.xtal");
		//		//if (pCode)    // �R���p�C���Ɏ��s�����Ƃ���xtal::null���Ԃ�
		//		//    pCode->call();
		//		// ��͉��Ɠ��`
		//		xtal::load("System/Script/Main.xtal");//�Q�[���̃G���g���[�|�C���g�B������xtal�t�@�C�����w�肵�ď������Ă����B
		//		Jade::Debug::GetInstance()->Add("Xtal�G���g���[�t�@�C���̃��[�h�J�n");

		//		// lib�I�u�W�F�N�g����funcTest�I�u�W�F�N�g�����o��
		//		xtal::AnyPtr f = xtal::lib()->member(Xid(funcTest));    // intern������������
		//		// xtal::AnyPtr f = xtal::lib()->member("funcTest"));   // �����񃊃e�������n����
		//		// funcTest�I�u�W�F�N�g�����s����
		//		xtal::AnyPtr ret = f->call();    // 10��������xtal::AnyPtr���Ԃ�
		//		std::cout << ret->to_s()->c_str() << std::endl;    // "10\n"���o�͂���܂�

		//		}

		//		// ��O��ߑ�
		//		XTAL_CATCH_EXCEPT(e){
		//			Jade::Debug::GetInstance()->Add("code:901 Xtal�G���g���[�t�@�C���̃��[�h���s",Jade::Debug::GetInstance()->ERROR_LL);
		//			MessageBox(NULL,"�������G���[ code:901","",MB_OK);//error code 901 Xtal�̏������G���[
		//			stderr_stream()->println(e);

		//			error = 1;//�������G���[�Ƃ��Ė{�̂ɕ�
		//			}

		//		// Xtal��j��
		//		uninitialize();
		//	}

		//catch( const char* str )  // ��O���L���b�`����
		//	{
		//	Jade::Debug::GetInstance()->Add("code:102 �s���ȃG���[",Jade::Debug::GetInstance()->ERROR_LL);
		//	MessageBox(NULL,"�d��ȓ����G���[ code:102","ERROR",MB_OK | MB_ICONSTOP);
		//	error = 1;
		//	}
		//if(error == 1) return false;//���������ɃG���[���������ꍇ�A�P��Ԃ��B�{�̂͂�����m�F���A���s���邩���f����B
		//return true;
			return false;
		}





	void VM::CreateObject( string Data,int Option )
		{

		}


	}