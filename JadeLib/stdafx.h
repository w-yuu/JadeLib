/*===================================================================
頻繁にインクルードするヘッダーをまとめる。
通常はこのヘッダーをインクルードする事。（Baseクラスはインクルードしないこと）
===================================================================*/


#pragma once


#pragma warning(disable:4996) //localtime warning		localtime_sに変更することを推奨
#pragma warning(disable:4244) //fopen warning			fopen_sに変更することを推奨

//スタンダードなヘッダー
#include <stdio.h> 
#include<iostream>
#include<d3dx9.h>






