/*===========================================
�Q�[�����̓������Ď���������f�o�b�O�p�N���X
Singleton�p�^�[�����̗p���Ă���B
�f�o�b�O��񂪗~�����N���X�͏�ɕ񍐂��邱�ƁB
/==========================================*/
#ifndef _DEBUG_
#define _DEBUG_


#include "stdafx.h"

//�f�[�^�`���p




//===========================================
namespace Jade
	{
	class Debug
		{
		public:
			Debug();
			
			//�s���ȃ��\�b�h
			bool Clear();

			//�G���[��ʐM���ȂǁA�����������t�@�C���ɋL�q���܂��B
			bool Add(std::string Data,int DataType = 9  , std::string FileName = "Debug.txt");
			

			//���̃N���X�𗘗p����ꍇ�́A���̃��\�b�h����Ă��������B
			static Debug* GetInstance(void)
			{
				static Debug ThisInstance;
				return &ThisInstance;
			}
			

			//�f�[�^�^�C�v�\
				enum { ERROR_S = 0 , ERROR_M , ERROR_L , ERROR_LL , VERSION , NETWORK , STREAM , CRACK , OTHERS , EVENT };
		private:
			//�f�[�^�^�C�v�\�̕ۑ�
			std::string MapData[10];

	
		
			
		};
	}
//===========================================
#endif

//
//int Error_S		= ERROR_S;
//			int Error_M		= ERROR_M;
//			int Error_L		= ERROR_L;
//			int Error_LL	= ERROR_LL;
//
//			int Version		= VERSION;
//			int Network		= NETWORK;
//			int File		= FILE;
//			int Crack		= CRACK;
//			int Except		= EXCEPT;