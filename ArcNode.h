#include<cstdio>
#include<fstream>
#include<string>
#include<cstring>
#include<iostream>
#include "windows.h"
using namespace std;
/***************************************/
/* ����߱���                        */
/***************************************/ 
struct ArcNode              
{            
        int adjvex;         //�ڽӵ���
		int distance;       //Ȩֵ
		ArcNode*next;       //ָ����ָ��߱����һ�����
};
