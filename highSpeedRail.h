#include<stdio.h>
#include<fstream.h>

#ifndef HSRAIL
#define HSRAIL

#include "VertexNode"

const int Maxsize = 1000;    //最大值为1000

class highSpeedRail
{
   public：
         void highSpeedRail(int array[],int n, int e);        //构造函数，建立一个有n个站点，e条线路的高铁网络图
         ~highSpeedRail();                                          //析构函数
		 bool isExisted(string station);                                      //站点station是否存在
         void addStation();                                              //增加一个站台
		 void addRailWay();                                              //增加一条高铁线路
         

   private:
	    VertexNode adjlist[Maxsize];                //存放站点表的数组
		int staNum;                              //高铁网站点数
		int railWay;                             //高铁网中线路数
}

void highSpeedRail::highSpeedRail(string array[],int n, int e)
{  
   ifstream in("rail.txt");    //存放站点信息的txt文件
   string station;              //站点名
     
   if(in)                    //如果存在rail.txt文件
   {
       for(int i = 0; i< n ; i++)   //输入顶点信息，即站点信息，初始化站点表
	   {  
		   cout<<"\n请输入第">>staNum+i+1>>"个站点的名称："<<endl;
	       cin>>station;
           while(isExited(station))
		   {
		     cout<<"该站台已存在，请重新输入:"<<endl;
			 cin>>station;
		   }
		   in<<station<<endl;                  //将站台名存入文件
           adjlist[i].vertex = station;
           adjlist[i].firstedge = NULL;
	  }
   
       for(int k = 0; k < e ; k++)    //从第一个站点开始添加与其连通的站点
	   {  
	        string i,j;
			//输入线路所连接的两站台i,j
			cout<<"输入两个站台的名字："<<endl;
	        cin>>i;
		    cin>>j; 
			if(isExisten(i)&&isExisten(j)) 
            {
			   ArcNode s = new ArcNode;           
       	       s->adjvex =j;                     //建立一个新的边表结点，即新的线路
		       cout<<"\n请输入站台"<<i<<"和站台"<<j<<"之间的距离："<<endl;
               cin>>cost;
               s->distance=cost;                 //站点x与y之间的距离为n
	           s->next = adjlist[i].firstedge;   //将结点插入到第i个边表的表头
			}
			else
				cout<<'站台名不存在'<<endl
	   }
   
       staNum = n;
       railWay = e;
   }
   else 
   {
	   cout<<"不存在rail.txt文件"<<endl;
   }

 
bool highSpeedRail::isExisted(string station)
{
    ifstream in("rail.txt");
	string temp;
	for(int i = 0;i<staNum;i++)
	{
	   temp=in.getline();
	   if(temp == station)
	      break;
	}
	if(temp == station)
		return 0;
	else 
		return -1;
}


void highSpeedRail::addStation()
{
   string station;
   cout<<"请输入添加的站台："<<endl;
   cin>>station;
   while(isExited(station))
   {
		     cout<<"该站台已存在，请重新输入:"<<endl;
			 cin>>station;
   }
	in<<station<<endl;                  //将站台名存入文件
    adjlist[i].vertex = station;
    adjlist[i].firstedge = NULL;
	  
}


void highSpeedRail::addRailWay()
{
    string i,j;
	//输入线路所连接的两站台i,j
	cout<<"输入两个站台的名字："<<endl;
	cin>>i;
	cin>>j; 
	if(isExisten(i)&&isExisten(j)) 
     {
		ArcNode s = new ArcNode;           
       	s->adjvex =j;                     //建立一个新的边表结点，即新的线路
		cout<<"\n请输入站台"<<i<<"和站台"<<j<<"之间的距离："<<endl;
        cin>>cost;
        s->distance=cost;                 //站点x与y之间的距离为n
	    s->next = adjlist[i].firstedge;   //将结点插入到第i个边表的表头

	}
	else
	     cout<<'站台名不存在'<<endl
	 
}

}
