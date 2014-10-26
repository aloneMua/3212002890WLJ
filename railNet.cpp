#include<stdio.h>
#include<fstream>
#include<string>
#include<iostream>
using namespace std;


const int Maxsize = 1000;    //最大值为1000

/***************************************/
/* 定义边表结点                        */
/***************************************/ 
struct ArcNode              
{            
        int adjvex;         //邻接点域
		int distance;       //权值
		ArcNode*next;       //指针域，指向边表的下一个结点
};

/***************************************/
/* 定义边表顶点                        */
/***************************************/ 
struct VertexNode           
{
    string vertex;             //数据域，存放顶点信息
	ArcNode*firstedge;      //指针域，指向边表中第一个结点
};

/***********************************************/
/* declaration of haghSpeddRail class          */
/***********************************************/
class highSpeedRail
{
public:
         highSpeedRail(int , int );        
         highSpeedRail(string );//for file input
         ~highSpeedRail();                                                //析构函数
		 bool isExisted(string );                                 //站点station是否存在
		 int getIndex(string );                                                 //获得站点的索引
         void addStation();                                              //增加一个站台
		 void addRailWay();                                              //增加一条高铁线路
         

private:
	    VertexNode adjlist[Maxsize];                //存放站点表的数组
		int staNum;                              //高铁网站点数
		int railWay;                             //高铁网中线路数
};

/***********************************************************/
/* Construction function to build a network                */
/* with n station and e edges                              */
/***********************************************************/                      
highSpeedRail::highSpeedRail(int n, int e)
{  
   //ifstream in("rail.txt");    //存放站点信息的txt文件
   //ofstream out("rail.txt");    
   string station;              //站点名
     
   //if(in)                    //如果存在rail.txt文件
   {
       for(int i = 0; i< n ; i++)   //输入顶点信息，即站点信息，初始化站点表
	   {  
		   cout<<"\n请输入第"<<staNum+i+1<<"个站点的名称："<<endl;
	       cin>>station;
           while(isExisted(station))//存在该站点时
		   {
		     cout<<"该站台已存在，请重新输入:"<<endl;
			 cin>>station;
		   }
		   //out<<station<<endl;                  //将站台名存入文件
           adjlist[i].vertex = station;
           adjlist[i].firstedge = NULL;
	  }
   
       for(int k = 0; k < e ; k++)    //从第一个站点开始添加与其连通的站点
	   {  
	        string station1,station2;
			int cost;
			//输入线路所连接的两站台i,j
			cout<<"输入两个站台的名字和站台之间的距离"<<endl;
	        cin>>station1;
		    cin>>station2;
			cin>>cost; 
			if(isExisted(station1)&&isExisted(station2)) 
            {
			   ArcNode *s =new ArcNode;
			   int i = getIndex(station2);
       	       s->adjvex =i;                     //建立一个新的边表结点，即新的线路
               s->distance=cost;                 
			   int j = getIndex(station1);
	           s->next = adjlist[j].firstedge;   //将结点插入到第j个边表的表头
	           adjlist[j].firstedge = s;  
			}
			else
				cout<<"站台名不存在"<<endl;
	   }
   
       staNum = n;
       railWay = e;
	  // in.close();
	  // out.close();
   }
   else 
   {
	   cout<<"不存在rail.txt文件"<<endl;
   }
}
/*bool highSpeedRail::isExisted(string station)
{
    ifstream in("rail.txt");
	string line;
	string temp;
	if(in)
	{
	    for(int i = 0;i<staNum;i++)
		{
	        temp=getline(in,line);
	        if(temp == station)
	                break;
		}
	    if(temp == station)
		    return 0;
	    else 
		    return -1;
	}
	else
		cout<<"没有该文件"<<endl;
}*/


void main(){
   
}
