#include<cstdio>
#include<fstream>
#include<string>
#include<cstring>
#include<iostream>
#include "windows.h"

#include "ArcNode.h"
using namespace std;
/***************************************/
/* ����߱���                        */
/***************************************/ 
struct VertexNode           
{
    string vertex;             //�����򣬴�Ŷ�����Ϣ
    int count;               //�����򣬴�ű߱��С 
	ArcNode*firstedge;      //ָ����ָ��߱��е�һ�����
};