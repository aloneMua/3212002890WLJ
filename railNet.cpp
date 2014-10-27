#include<cstdio>
#include<fstream>
#include<string>
#include<cstring>
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
    int count;               //数据域，存放边表大小 
	ArcNode*firstedge;      //指针域，指向边表中第一个结点
};

/***********************************************/
/* declaration of haghSpeddRail class          */
/***********************************************/
class highSpeedRail
{
public:
         highSpeedRail(string);                                 //for file input
		 highSpeedRail(int , int );                
         ~highSpeedRail(){};                                                //析构函数
		 bool isExisted(string );                                 //站点station是否存在
		 int getIndex(string );                                                 //获得站点的索引
         void addStation(string );                                              //增加一个站台
		 void addRailWay(string ,string ,int );                                              //增加一条高铁线路
         void getDistance(string ,string );                         // get shortest distance from station1 to station2 

private:
	    VertexNode adjlist[Maxsize];                //存放站点表的数组
		int staNum;                              //高铁网站点数
		int railWay;                             //高铁网中线路数
};

/***********************************************************/
/* Construction function to build a network                */
/* with n station and e edges, input from terminal         */
/***********************************************************/                      
highSpeedRail::highSpeedRail(int n, int e)
{
   
   string station;              //站点名
   staNum = 0;                  //
   railWay = e; 
   
       for(int i = 0; i< n ; i++)   //输入顶点信息，即站点信息，初始化站点表
	   {  
		   cout<<"\n请输入第"<<staNum+1<<"个站点的名称："<<endl;
	       cin>>station;
           while(isExisted(station))//存在该站点时
		   {
		     cout<<"该站台已存在，请重新输入:"<<endl;
			 cin>>station;
		   }
	
           adjlist[i].vertex = station;
           adjlist[i].firstedge = NULL;
           adjlist[i].count = 0;
           staNum ++;
	  }
   
       for(int k = 0; k < e ; k++)    //从第一个站点开始添加与其连通的站点
	   {  
	        string station1,station2;
			int cost;
			//输入线路所连接的两站台station1,station2
			cout<<endl<<"输入两个站台的名字和站台之间的距离(单位：km)"<<endl;
	        cin>>station1;
		    cin>>station2;
			cin>>cost; 
			while(!isExisted(station1) || !isExisted(station2)) 
			{
				if(isExisted(station1))
			    {
				    cout<<station2<<" 站台名不存在，请重新输入两个站台的名字和站台之间的距离(单位：km)："<<endl;
				    cin>>station1;
		            cin>>station2;
			        cin>>cost; 
			    }
			    else if(isExisted(station2))
			    {
				    cout<<station1<<" 站台名不存在，请重新输入两个站台的名字和站台之间的距离(单位：km)："<<endl;
				    cin>>station1;
		            cin>>station2;
		        	cin>>cost; 
			    }
			    else 
			    {
     				cout<<station1 << " "<<station2<<" 站台名不存在，请重新输入两个站台的名字和站台之间的距离(单位：km)："<<endl;
	    			cin>>station1;
        		    cin>>station2;
			        cin>>cost; 
		    	}	
			}
			
            //若输入正确 
			ArcNode *s =new ArcNode;
			int i = getIndex(station2);
       	    s->adjvex =i;                     //建立一个新的边表结点，即新的线路
            s->distance=cost;
			s->next = NULL;                 
			int j = getIndex(station1);
	        s->next = adjlist[j].firstedge;   //将结点插入到第j个边表的表头
	        adjlist[j].firstedge = s;  
	        adjlist[j].count ++;
			
	   }

}

/***********************************************************/
/* Construction function to build a network                */
/* with input from file                                    */
/***********************************************************/   
highSpeedRail::highSpeedRail(string g)
{

   ifstream infile;
   infile.open(g.c_str());
   if (infile == NULL)
   {
       cout<<"\nCannot open input file!\n"<<endl;
       exit(1);
   }
   int n; 
   infile>>n;

   infile>>railWay;

   string station;              //站点名
   staNum = 0;                  //
    
       for(int i = 0; i< n ; i++)   //输入顶点信息，即站点信息，初始化站点表
	   {  
	       infile>>station;
           if(isExisted(station))//存在该站点时
		   {
		       cout<<station<<" 站台已存在，输入文件内容错误！"<<endl;
			   exit(1);
		   }

           adjlist[i].vertex = station;

           adjlist[i].firstedge = NULL;
           adjlist[i].count = 0;
           
           staNum ++;
	  }

       for(int k = 0; k < railWay ; k++)    //从第一个站点开始添加与其连通的站点
	   {  
	        string station1,station2;
			int cost;

			infile>>station1;
			infile>>station2;
			infile>>cost;
		
			if(isExisted(station1) && isExisted(station2)) 
            {
			   ArcNode *s =new ArcNode;
			   int i = getIndex(station2);
       	       s->adjvex =i;                     //建立一个新的边表结点，即新的线路
               s->distance=cost;
			   s->next = NULL;                 
			   int j = getIndex(station1);
	           s->next = adjlist[j].firstedge;   //将结点插入到第j个边表的表头
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
				cout<<station1 << " "<<station2<<" 站台名不存在，输入文件内容错误！"<<endl;
				exit(1);
			}				
	   }
   
   	   infile.close();

}


/*****************************************************/
/* This is a program to determine whether station is */
/* existed.                                          */
/*****************************************************/
bool highSpeedRail::isExisted(string station)
{  
	for(int i = 0;i<staNum;i++)// determine if the station is existed	
	    if(adjlist[i].vertex == station)
	        return 1;
    
	return 0;		//if fail ,return 0
}

/******************************************************/
/* This is a program to get station's index           */ 
/******************************************************/
int highSpeedRail::getIndex(string station)
{
	for(int i = 0; i < staNum; i ++)// determine if the station is existed	
	    if(adjlist[i].vertex == station)
	        return i;
	
	// if do not get index successfully
	cout << "Fail in getting index! Station "<< station << " do not existed！" << endl;
	return -1;
	
}

/******************************************************/
/* This is a program to add a station to the list     */ 
/******************************************************/
void highSpeedRail::addStation(string station)
{
	if(isExisted(station))
	{
	    cout<<"Error! This station is already existed!"<<endl;
	    return ;
	}
	// no problem , add it
	//如果能删除站点，这里不要这么写！！！ 
	adjlist[staNum].vertex = station;
    adjlist[staNum].firstedge = NULL;
    staNum ++;
}

/******************************************************/
/* This is a function to add a Railway                */ 
/******************************************************/
void highSpeedRail::addRailWay(string station1,string station2,int cost)
{
	
	if(!isExisted(station1) || !isExisted(station2)) 
    {
		cout<<"站台名不存在"<<endl;
		return ;
	}
	ArcNode *s =new ArcNode;
	
	int i = getIndex(station2);
  	s->adjvex =i;                     //建立一个新的边表结点，即新的线路
    s->distance=cost;                 
	
	int j = getIndex(station1);
	s->next = adjlist[j].firstedge;   //将结点插入到第j个边表的表头
	adjlist[j].firstedge = s;  
	railWay ++;		
}

/******************************************************/
/* This is a program to compute the shortest distance */ 
/* between station1 and station2.                     */
/* Using dijkstra algorithm.                          */
/******************************************************/
void highSpeedRail::getDistance(string station1, string station2)
{
	int a, b;//source and destination	
	a = getIndex(station1);
	b = getIndex(station2);
	if(a == -1 || b == -1)
	{
		cout<<"Error! Station do not exist!"<<endl;
		return  ;
	}
	
	bool known[Maxsize]; //to indicate whether the shortest distance to a vertix is known 
	int dis[Maxsize];    //to store temporary shortest distance from station1 to a vertix
	int sum = 0;         //to determine whether  is time to stop
	//initialization
	memset(known,0,sizeof(known));
	memset(dis,0x3f,sizeof(dis));		
	dis[a] = 0;
	
	//dijkstra algorithm
	ArcNode *tmp;
	int s,t,v;
	
	while(sum < staNum)//sum = staNum, all node is known,如果能删除站点，这里不要这么写 
	{
		s = 0;
		while(known[s])
		{
			s++;
		}
		
		for(int i = 0; i < staNum ; i++)//find the smallest distance to the current graph
		{
			if(known[i] == 0 && dis[s] > dis[i] ) 
			{
			    s = i;
			}
		}
		known[s] = 1; 
		tmp = adjlist[s].firstedge;

		for(int j = 0 ;j < adjlist[s].count; j++,tmp = tmp->next)// update the distance
		{
			
			t = tmp->adjvex;
			v = tmp->distance;
			if(dis[t] > dis[s] + v)
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
int main()
{
   //highSpeedRail hsr(5,5);
   highSpeedRail hsr("input.txt"); 
   hsr.getDistance("广州","北京");
   string a ,b;
   cout<<"请输入想要查询的车站距离："<<endl;
   cout<<"出发站点：";
   cin>>a;
   cout<<endl<<"目标站点：";
   cin>>b;
   hsr.getDistance(a,b);
   return 0;
}
