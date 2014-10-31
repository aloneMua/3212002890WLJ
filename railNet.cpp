/*************************************************************/
/*建立高铁网                    120804班  3212002890   文林静*/
/*************************************************************/
#include<cstdio>
#include<fstream>
#include<string>
#include<cstring>
#include<iostream>
#include "windows.h"
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
    int count;               //数据域，存放边表大小 
	ArcNode*firstedge;      //指针域，指向边表中第一个结点
};

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

//菜单功能
void menu();
void menu1(highSpeedRail);
void menu2(highSpeedRail);
void menu3(highSpeedRail);

/***********************************************************/
/* This is a function to build a highSpeedRail instance    */
/* and display a menu to make operations                   */
/* on highSpeedRail instance for users for convenience.    */
/***********************************************************/   
void menu()
{
	//初始化
    highSpeedRail hsr("station.txt","rail.txt"); //
	int no; 
	system("cls");//清屏 
	//string string1, string2;
	cout<<"                    欢迎进入高铁管理系统"<<endl;
	cout<<endl<<endl<<"1、增加站台"<<endl;
	cout<<endl<<"2、增加线路"<<endl;
	cout<<endl<<"3、站点最短距离查询"<<endl;
	cout<<endl<<"4、清空所有数据"<<endl;
	cout<<endl<<"5、退出系统"<<endl;
	cout<<endl<<endl<<endl<<"请输入要进行的操作编号："<<endl;
	
	while(1)
	{
	//cin>>no,no!=5
	system("cls");//清屏 
	//string string1, string2;
	cout<<"                        欢迎进入高铁管理系统"<<endl;
	cout<<endl<<endl<<"1、增加站台"<<endl;
	cout<<endl<<"2、增加线路"<<endl;
	cout<<endl<<"3、站点最短距离查询"<<endl;
	cout<<endl<<"4、清空所有数据"<<endl;
	cout<<endl<<"5、退出系统"<<endl;
	cout<<endl<<endl<<endl<<"请输入要进行的操作编号："<<endl;
	cin>>no;
	if(no == 1)
	{
		menu1(hsr);
		
	}
	else if(no == 2)
	{
		menu2(hsr);
		
	}
	else if(no == 3)
	{
		menu3(hsr);
		
	}
	else if(no == 4)
	{
		if(hsr.clear())
		    cout <<"清空成功！"<<endl;
		else 
		    cout<<"清空失败！"<<endl;
	}
    else if(no == 5) break;
    }
}

void menu1(highSpeedRail hsr)
{
	string string1;
	char bo;
	system("cls");//清屏 
	cout<<endl<<"请输入要添加的站台名称："<<endl;
	cin>>string1;
	hsr.addStation(string1);
	
	while(1)
	{
		cout<<"是否继续添加？是（Y）/否（N）"<<endl;
		cin >> bo;
	    if(tolower(bo) == 'y')
	    {
	    	cout<<endl<<"请输入要添加的站台名称："<<endl;
			cin>>string1;
         	hsr.addStation(string1);
         	continue;
	    }
	    if(tolower(bo) == 'n')
	    {
		    break;
	    }
	    else
	    {
    		cout<<"输入错误！"<<endl;
	        continue;
	    }
    }
    return;
}

void menu2(highSpeedRail hsr)
{
	string string1,string2;
	char bo;
	int di;
	system("cls");//清屏 
	cout<<endl<<"请输入要添加的线路的出发站点名、目的站点名和站点间距离："<<endl;
	cout<<"出发站点：";
    cin>>string1;
    cout<<endl<<"目标站点：";
    cin>>string2;
    cout<<endl<<"站点间距离：";
    cin>>di;   
	hsr.addRailWay(string1,string2,di);
	
	while(1)
	{
		cout<<"是否继续添加？是（Y）/否（N）"<<endl;
		cin >> bo;
	    if(tolower(bo) == 'y')
	    {
           	cout<<endl<<"请输入要添加的线路的出发站点名、目的站点名和站点间距离："<<endl;
        	cout<<"出发站点：";
            cin>>string1;
            cout<<endl<<"目标站点：";
            cin>>string2;
            cout<<endl<<"站点间距离：";
            cin>>di;   
          	hsr.addRailWay(string1,string2,di);
         	continue;
	    }
	    if(tolower(bo) == 'n')
	    {
		     break;
	    }
	    else
	    {
    		cout<<"输入错误！"<<endl;
	        continue;
	    }
    }
    return;
}


void menu3(highSpeedRail hsr)
{
	string string1,string2;
	char bo;
	
	system("cls");//清屏 
	cout<<endl<<"请输入要查询的出发站点名和目的站点名："<<endl;
	cout<<"出发站点：";
    cin>>string1;
    cout<<endl<<"目标站点：";
    cin>>string2;
  
	hsr.getDistance(string1,string2);
	
	while(1)
	{
		cout<<"是否继续查询？是（Y）/否（N）"<<endl;
		cin >> bo;
	    if(tolower(bo) == 'y')
	    {
           		cout<<endl<<"请输入要查询的出发站点名和目的站点名："<<endl;
             	cout<<"出发站点：";
                cin>>string1;
                cout<<endl<<"目标站点：";
                cin>>string2;  
               	hsr.getDistance(string1,string2);
             	continue;
	    }
	    if(tolower(bo) == 'n')
	    {
		    break;
	    }
	    else
	    {
    		cout<<"输入错误！"<<endl;
	        continue;
	    }
    }
    return;
}

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
	return true;
}

int main()
{

	menu();
   return 0;
}
