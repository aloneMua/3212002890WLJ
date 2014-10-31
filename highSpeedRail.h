#include<cstdio>
#include<fstream>
#include<string>
#include<cstring>
#include<iostream>
#include "windows.h"

#include "VertexNode.h"
using namespace std;

const int Maxsize = 1000;    //最大值为1000


/***********************************************/
/*                  高铁网类                   */
/***********************************************/
class highSpeedRail
{
public:
         highSpeedRail(string,string);                            //构造函数      
         ~highSpeedRail(){};                                      //析构函数
		 bool isExisted(string );                                 //站点station是否存在
		 int getIndex(string );                                   //获得站点的索引
         void addStation(string );                                //增加一个站台
		 void addRailWay(string ,string ,int );                   //增加一条高铁线路
         void getDistance(string ,string );                       // 获得station1 到 station2  的最短路径
         bool clear();

private:
	    VertexNode adjlist[Maxsize];             //存放站点表的数组
		int staNum;                              //高铁网站点数
		int railWay;                             //高铁网中线路数
		string  stationFile;
        string  railFile;		
};

/***********************************************************/
/*               构造函数，构建一个高铁网                  */ 
/***********************************************************/   
highSpeedRail::highSpeedRail(string s,string r)
{

   ifstream infile;
   stationFile = s;
   railFile = r; 
   infile.open(stationFile.c_str(),ios::in);//打开stationFile文件

   if (!infile.is_open())
   {
       cout<<"\nCannot open input file!\n"<<endl;
       exit(1);
   }

   //输入顶点信息，即站点信息，初始化站点表
   string station;              //站点名   
   staNum = 0;
       while(infile>>station)
	   {  
	       
           if(isExisted(station))//存在该站点时
		   {
		       cout<<station<<" 站台已存在，输入文件内容错误！"<<endl;
			   exit(1);
		   }

           adjlist[staNum].vertex = station;        //将站台存入
           adjlist[staNum].firstedge = NULL;        //无可达站台
           adjlist[staNum].count = 0;               
           
           staNum ++;
	  }
	  infile.close();
	  
	  //录入铁路线路 
	  ifstream infiler;
	  infiler.open(railFile.c_str(),ios::in);
      if (!infiler.is_open())
      {
           cout<<"\nCannot open input file!\n"<<endl;
           exit(1);
      }
       
	   railWay = 0;
       string station1,station2;
	   int cost;
	   while(infiler>>station1>>station2>>cost)  
	   {  
			if(isExisted(station1) && isExisted(station2))      //当station1 和 station2 存在时
            {
			   ArcNode *s =new ArcNode;            //建立一个新的边表结点，即新的线路
			   int i = getIndex(station2);         //获得station2 的索引
       	       s->adjvex =i;                    
               s->distance=cost;
			   s->next = NULL;                 
			   int j = getIndex(station1);         //获得staion1 的索引
	           s->next = adjlist[j].firstedge;     //将结点插入到第j个边表的表头
	           adjlist[j].firstedge = s;  
	           adjlist[j].count ++;
			}
			else if(isExisted(station1))
			{
				cout<<station2<<" 站台名不存在，输入文件内容错误！"<<endl;
				exit(1);
			}
			else if(isExisted(station2))
			{
				cout<<station1<<" 站台名不存在，输入文件内容错误！"<<endl;
				exit(1);
			}
			else 
			{
				cout<<station1 <<"和"<< " "<<station2<<" 站台名均不存在，输入文件内容错误！"<<endl;
				exit(1);
			}
			railWay ++;				
	   }
   
   	   infiler.close();

}


/*****************************************************/
/*                 判断是否存在站台station           */
/*****************************************************/
bool highSpeedRail::isExisted(string station)
{  
	for(int i = 0;i<staNum;i++)	
	    if(adjlist[i].vertex == station)
	        return 1;
    
	return 0;		//if fail ,return 0
}

/******************************************************/
/*                  获得站台station的索引             */ 
/******************************************************/
int highSpeedRail::getIndex(string station)
{
	for(int i = 0; i < staNum; i ++)
	    if(adjlist[i].vertex == station)
	        return i;
	
	// 未获得该站台索引
	//cout << "Fail in getting index! Station "<< station << " do not existed！" << endl;
	return -1;
	
}

/******************************************************/
/*                   添加一个站台                     */ 
/******************************************************/
void highSpeedRail::addStation(string station)
{
	if(isExisted(station))
	{
	    cout<<"Error! This station is already existed!"<<endl;
	    return ;
	}
	ofstream outfile;
	outfile.open(stationFile.c_str(),ios::app);

	adjlist[staNum].vertex = station;
    adjlist[staNum].firstedge = NULL;
    staNum ++;
    outfile<<station<<endl;
    outfile.close();
}

/******************************************************/
/*                    添加一条线路                    */ 
/******************************************************/
void highSpeedRail::addRailWay(string station1,string station2,int cost)
{
	
	if(!isExisted(station1) || !isExisted(station2)) 
    {
		if(isExisted(station1))
		{
			cout<<station2<<" 站台名不存在，输入错误！"<<endl;
			
		}
		else if(isExisted(station2))
		{
			cout<<station1<<" 站台名不存在，输入错误！"<<endl;
				
		}
		else 
		{
			cout<<station1 << " "<<station2<<" 站台名不存在，输入错误！"<<endl;
			
		}			
		return ;
	}

	int e = getIndex(station2);//线路终点end ，获得索引
	int b = getIndex(station1);//线路起点begin，获得索引
	
	//如果线路已存在
	ArcNode *tmp;
	tmp = adjlist[b].firstedge;
	for(int j = 0 ;j < adjlist[b].count; j++,tmp = tmp->next)
	{
		if(e == tmp->adjvex)
	       //if(cost >= tmp->distance )
		   {
		      cout<<"此线路已经存在！"<<endl;
		      return;
		   }
	}
	
	//线路不存在
	ofstream outfile;
	outfile.open(railFile.c_str(),ios::app);
	
	ArcNode *s =new ArcNode;

  	s->adjvex =e;                     //建立一个新的边表结点，即新的线路
    s->distance=cost;                 
		
	s->next = adjlist[b].firstedge;   //将结点插入到第j个边表的表头
	adjlist[b].firstedge = s;  
	railWay ++;	
		
	outfile<<station1<<" "<<station2<<" "<<cost<<endl;
    outfile.close();
}

/******************************************************/
/*     站台station1 和 站台station2 之间的最短距离    */ 
/*                      dijkstra                      */
/******************************************************/
void highSpeedRail::getDistance(string station1, string station2)
{
	int a, b;           //起点，终点
	//站台不存在
	if(!isExisted(station1) || !isExisted(station2)) 
    {
		if(isExisted(station1))
		{
			cout<<station2<<" 站台名不存在，输入错误！"<<endl;
			
		}
		else if(isExisted(station2))
		{
			cout<<station1<<" 站台名不存在，输入错误！"<<endl;
				
		}
		else 
		{
			cout<<station1 << " "<<station2<<" 站台名不存在，输入错误！"<<endl;
			
		}			
		return ;
	}
	//站台存在
	a = getIndex(station1);
	b = getIndex(station2);
	
	//dijkstra	
	bool known[Maxsize]; //表示一个顶点是否被探知，存放为0，1
	int dis[Maxsize];    //存储距离
	int sum = 0;         //已被探知的顶点数
	
	//初始化一片连续的内存空间，初始化将known[]置为0，sizeof(known)为known[]长度
	memset(known,0,sizeof(known));
	//初始化一片连续的内存空间，初始化将dis[]置为无穷大，sizeof(dis)为dis[]长度
	memset(dis,0x3f,sizeof(dis));		
	dis[a] = 0;
	
	ArcNode *tmp;
	int s,t,v;         //
	
	while(sum < staNum)//sum = staNum,所有的结点都被探知过，结束
	{
		s = 0;
		while(known[s])//此处s的值只是临时的过渡，作为比较的结点，无具体意义，当known[s]==1，即被探知过，s++
		{
			s++;
		}
		
		for(int i = 0; i < staNum ; i++)//寻找known[]中没有被探知的最短距离结点s
		{
			if(known[i] == 0 && dis[i] < dis[s] ) //i是一个没有被探知过的点，且dis[i]距离更短
			{
			    s = i;
			}
		}
		known[s] = 1; 
		tmp = adjlist[s].firstedge;

		for(int j = 0 ;j < adjlist[s].count; j++,tmp = tmp->next)//更新距离
		{
			
			t = tmp->adjvex;              
			v = tmp->distance;
			if(dis[t] > dis[s] + v && known[t] == 0)
			{
				dis[t] = dis[s] + v;
			}
			
		}
		
		sum++;
	}
	if(dis[b] != 0x3f3f3f3f)
	{
		cout << endl << station1 << " 到 " << station2 <<" 的距离为 " << dis[b] << " km." << endl; 
	}
	else
	{
		cout << endl << "错误！" << station1 << " 无法到达 " << station2 <<endl; 
	}	
}

bool highSpeedRail::clear()
{
	remove("station.txt");
	remove("rail.txt");
	staNum = 0;
	railWay = 0;
	return true;
}