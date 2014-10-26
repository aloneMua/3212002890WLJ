#ifndef VETTEXNODE
#define VETTEXNODE

#include "ArcNode.h"

struct VertexNode           //定义边表顶点
{
	string vertex;             //数据域，存放顶点信息
	ArcNode*firstedge;      //指针域，指向边表中第一个结点
};
#endif
