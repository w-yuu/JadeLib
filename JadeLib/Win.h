/*===========================================
JadeLib���Ǘ����鉼�z�}�V��
�Q�[���̃C���X�^���X�Ǘ����s���B
/==========================================*/
#ifndef _WIN_
#define _WIN_

#include<windows.h>
#include<stdio.h>
#include<d3dx9.h>
#include<time.h>
#include"Debug.h"



//======================================
namespace Jade
	{
	class Windows
		{
		public:
			
			Windows();
			static Windows* GetInstance(void)
				{
				static Windows ThisInstance;
				


				return &ThisInstance;
				}
			
			

		private:
		
			
		};
	}
//======================================
#endif