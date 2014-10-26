#include<cstdio>
#include<fstream>
#include<string>
#include<cstring>
#include<iostream>

using namespace std;


const int Maxsize = 1000;    //���ֵΪ1000

/***************************************/
/* ����߱���                        */
/***************************************/ 
struct ArcNode              
{            
        int adjvex;         //�ڽӵ���
		int distance;       //Ȩֵ
		ArcNode*next;       //ָ����ָ��߱����һ�����
};

/***************************************/
/* ����߱���                        */
/***************************************/ 
struct VertexNode           
{
    string vertex;             //�����򣬴�Ŷ�����Ϣ
    int count;
	ArcNode*firstedge;      //ָ����ָ��߱��е�һ�����
};

/***********************************************/
/* declaration of haghSpeddRail class          */
/***********************************************/
class highSpeedRail
{
public:
         highSpeedRail(int , int );        
         //highSpeedRail(string );                                 //for file input
         ~highSpeedRail(){};                                                //��������
		 bool isExisted(string );                                 //վ��station�Ƿ����
		 int getIndex(string );                                                 //���վ�������
         void addStation(string );                                              //����һ��վ̨
		 void addRailWay(string ,string ,int );                                              //����һ��������·
         void getDistance(string ,string );                         // get shortest distance from station1 to station2 

private:
	    VertexNode adjlist[Maxsize];                //���վ��������
		int staNum;                              //������վ����
		int railWay;                             //����������·��
};

/***********************************************************/
/* Construction function to build a network                */
/* with n station and e edges                              */
/***********************************************************/                      
highSpeedRail::highSpeedRail(int n, int e)
{
   //ifstream in("rail.txt");    //���վ����Ϣ��txt�ļ�
   //ofstream out("rail.txt");    
   string station;              //վ����
   staNum = 0;                  //
   railWay = e; 
   /*if(in)                    //�������rail.txt�ļ�
   {  */
       for(int i = 0; i< n ; i++)   //���붥����Ϣ����վ����Ϣ����ʼ��վ���
	   {  
		   cout<<"\n�������"<<staNum+1<<"��վ������ƣ�"<<endl;
	       cin>>station;
           while(isExisted(station))//���ڸ�վ��ʱ
		   {
		     cout<<"��վ̨�Ѵ��ڣ�����������:"<<endl;
			 cin>>station;
		   }
		   //out<<station<<endl;                  //��վ̨�������ļ�
           adjlist[i].vertex = station;
           adjlist[i].firstedge = NULL;
           adjlist[i].count = 0;
           staNum ++;
	  }
   
       for(int k = 0; k < e ; k++)    //�ӵ�һ��վ�㿪ʼ���������ͨ��վ��
	   {  
	        string station1,station2;
			int cost;
			//������·�����ӵ���վ̨i,j
			cout<<endl<<"��������վ̨�����ֺ�վ̨֮��ľ���(��λ��km)"<<endl;
	        cin>>station1;
		    cin>>station2;
			cin>>cost; 
			if(isExisted(station1) && isExisted(station2)) 
            {
			   ArcNode *s =new ArcNode;
			   int i = getIndex(station2);
       	       s->adjvex =i;                     //����һ���µı߱��㣬���µ���·
               s->distance=cost;
			   s->next = NULL;                 
			   int j = getIndex(station1);
	           s->next = adjlist[j].firstedge;   //�������뵽��j���߱�ı�ͷ
	           adjlist[j].firstedge = s;  
	           adjlist[j].count ++;
			}
			else
				cout<<"վ̨��������"<<endl;
	   }
   
      /* 
	   in.close();
	   out.close();
   }
   else 
   {
	   cout<<"������rail.txt�ļ�"<<endl;
   }*/
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
	cout << "Fail in getting index!" << endl;
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
	//�����ɾ��վ�㣬���ﲻҪ��ôд������ 
	adjlist[staNum].vertex = station;
    adjlist[staNum].firstedge = NULL;
    staNum ++;
}

/******************************************************/
/* This is a program to add a Railway                 */ 
/******************************************************/
void highSpeedRail::addRailWay(string station1,string station2,int cost)
{
	
	if(!isExisted(station1) || !isExisted(station2)) 
    {
		cout<<"վ̨��������"<<endl;
		return ;
	}
	ArcNode *s =new ArcNode;
	
	int i = getIndex(station2);
  	s->adjvex =i;                     //����һ���µı߱��㣬���µ���·
    s->distance=cost;                 
	
	int j = getIndex(station1);
	s->next = adjlist[j].firstedge;   //�������뵽��j���߱�ı�ͷ
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
	
	while(sum < staNum)//sum = staNum, all node is known,�����ɾ��վ�㣬���ﲻҪ��ôд 
	{
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

		for(int i = 0 ;i < adjlist[s].count; i++,tmp = tmp->next)// update the distance
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
		cout << endl << station1 << " �� " << station2 <<"�ľ���Ϊ" << dis[b] << " km." << endl; 
	}
	else
	{
		cout << endl << "����" << station1 << " �޷����� " << station2 <<endl; 
	}
	
}
int main()
{
   highSpeedRail hsr(5,5);
   hsr.getDistance("guangzhou","beijing");
   return 0;
}
