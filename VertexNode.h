#include<cstdio>
#include<fstream>
#include<string>
#include<cstring>
#include<iostream>
#include "windows.h"

#include "ArcNode.h"
using namespace std;
/***************************************/
/* 定义边表顶点                        */
/***************************************/ 
struct VertexNode           
{
    string vertex;             //数据域，存放顶点信息
    int count;               //数据域，存放边表大小 
	ArcNode*firstedge;      //指针域，指向边表中第一个结点
};