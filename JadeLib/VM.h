/*===========================================
�t�@�C���̓��o�͂�C���X�^���X�̊Ǘ��A
�`��̎��s�A���̑��A��ɓ��삵�����郋�[�v�̐���B
Object�N���X��Draw,SystemView�N���X��SetView,����ȊO��User��
���\�b�h�������Ŏ��s�����B�i���ۂ̏�����MDX�N���X�A�A�Ƃ�����MDX�ɂ��̐������ڂ��������悭��?�j
�Q�[����̃C���X�^���X�i�L�����N�^�[�A�A�C�e���j�Ȃǂ͂���VM���
�C���X�^���X�������鎖�B����ɂ��ǂ��ŃL�����𐧌䂵�Ă���̂������m�ɂȂ�B
�܂�VM��Ő������ꂽ�C���X�^���X�̓��������[�N���N�����Ȃ�
���Ƃ��ۏ؂����B�i�����f�X�g���N�^�j
�V���O���g���N���X�ł͂Ȃ��B
/==========================================*/


#ifndef _VM_
#define _VM_

#include<windows.h>
#include<stdio.h>
#include<d3dx9.h>
#include<time.h>
#include<string>

//����͎g�p���Ȃ�
////Xtal�̃C���N���[�h-----------
//#include <xtal.h>
//#include <xtal_macro.h> // Xid�ȂǕ֗��ȃ}�N������`����Ă���
//
//#include <xtal_lib/xtal_cstdiostream.h>	// CStdioStdStreamLib�̂���
//#include <xtal_lib/xtal_winthread.h>		// WinThreadLib�̂���
//#include <xtal_lib/xtal_winfilesystem.h>	// WinFilesystemLib�̂���
//#include <xtal_lib/xtal_chcode.h>			// SJISChCodeLib�̂���
//#include <xtal_lib/xtal_errormessage.h>	// bind_error_message()�̂���
//
//
////========================================


//======================================
namespace Jade
	{
	class VM//�C���X�^���X�̊Ǘ����s��
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