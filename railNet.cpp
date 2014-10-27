#include<cstdio>
#include<fstream>
#include<string>
#include<cstring>
#include<iostream>
#include "windows.h"
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
    int count;               //�����򣬴�ű߱��С 
	ArcNode*firstedge;      //ָ����ָ��߱��е�һ�����
};

/***********************************************/
/* declaration of haghSpeddRail class          */
/***********************************************/
class highSpeedRail
{
public:
         highSpeedRail(string);                                 //for file input
		 highSpeedRail(int , int );                
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
highSpeedRail hsr("input.txt"); //initialization
void menu();
void menu1();
void menu2();
void menu3();
/***********************************************************/
/* This is a function to build a highSpeedRail instance    */
/* and display a menu to make operations                   */
/* on highSpeedRail instance for users for convenience.    */
/***********************************************************/   
void menu()
{
	int no; 
	system("cls");//���� 
	//string string1, string2;
	cout<<"                    ��ӭ�����������ϵͳ"<<endl;
	cout<<endl<<endl<<"1������վ̨"<<endl;
	cout<<endl<<"2��������·"<<endl;
	cout<<endl<<"3��վ����̾����ѯ"<<endl;
	cout<<endl<<"4�������������"<<endl;
	cout<<endl<<"5���˳�ϵͳ"<<endl;
	cout<<endl<<endl<<endl<<"������Ҫ���еĲ�����ţ�"<<endl;
	
	while(1)
	{
	//cin>>no,no!=5
	system("cls");//���� 
	//string string1, string2;
	cout<<"                        ��ӭ�����������ϵͳ"<<endl;
	cout<<endl<<endl<<"1������վ̨"<<endl;
	cout<<endl<<"2��������·"<<endl;
	cout<<endl<<"3��վ����̾����ѯ"<<endl;
	cout<<endl<<"4�������������"<<endl;
	cout<<endl<<"5���˳�ϵͳ"<<endl;
	cout<<endl<<endl<<endl<<"������Ҫ���еĲ�����ţ�"<<endl;
	cin>>no;
	if(no == 1)
	{
		menu1();
		
	}
	if(no == 2)
	{
		menu2();
		
	}
	if(no == 3)
	{
		menu3();
		
	}
	if(no == 4)
	{
		
	}
	
	/* highSpeedRail hsr("input.txt"); 
   hsr.getDistance("����","����");
   string a ,b;
   cout<<"��������Ҫ��ѯ�ĳ�վ���룺"<<endl;
   cout<<"����վ�㣺";
   cin>>a;
   cout<<endl<<"Ŀ��վ�㣺";
   cin>>b;
   hsr.getDistance(a,b);*/
    }
}

void menu1()
{
	string string1;
	char bo;
	system("cls");//���� 
	cout<<endl<<"������Ҫ��ӵ�վ̨���ƣ�"<<endl;
	cin>>string1;
	hsr.addStation(string1);
	
	while(1)
	{
		cout<<"�Ƿ������ӣ��ǣ�Y��/��N��"<<endl;
		cin >> bo;
	    if(tolower(bo) == 'y')
	    {
	    	cout<<endl<<"������Ҫ��ӵ�վ̨���ƣ�"<<endl;
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
    		cout<<"�������"<<endl;
	        continue;
	    }
    }
    return;
}

void menu2()
{
	string string1,string2;
	char bo;
	int di;
	system("cls");//���� 
	cout<<endl<<"������Ҫ��ӵ���·�ĳ���վ������Ŀ��վ������վ�����룺"<<endl;
	cout<<"����վ�㣺";
    cin>>string1;
    cout<<endl<<"Ŀ��վ�㣺";
    cin>>string2;
    cout<<endl<<"վ�����룺";
    cin>>di;   
	hsr.addRailWay(string1,string2,di);
	
	while(1)
	{
		cout<<"�Ƿ������ӣ��ǣ�Y��/��N��"<<endl;
		cin >> bo;
	    if(tolower(bo) == 'y')
	    {
           	cout<<endl<<"������Ҫ��ӵ���·�ĳ���վ������Ŀ��վ������վ�����룺"<<endl;
        	cout<<"����վ�㣺";
            cin>>string1;
            cout<<endl<<"Ŀ��վ�㣺";
            cin>>string2;
            cout<<endl<<"վ�����룺";
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
    		cout<<"�������"<<endl;
	        continue;
	    }
    }
    return;
}


void menu3()
{
	string string1,string2;
	char bo;
	
	system("cls");//���� 
	cout<<endl<<"������Ҫ��ѯ�ĳ���վ������Ŀ��վ������"<<endl;
	cout<<"����վ�㣺";
    cin>>string1;
    cout<<endl<<"Ŀ��վ�㣺";
    cin>>string2;
  
	hsr.getDistance(string1,string2);
	
	while(1)
	{
		cout<<"�Ƿ������ѯ���ǣ�Y��/��N��"<<endl;
		cin >> bo;
	    if(tolower(bo) == 'y')
	    {
           		cout<<endl<<"������Ҫ��ѯ�ĳ���վ������Ŀ��վ������"<<endl;
             	cout<<"����վ�㣺";
                cin>>string1;
                cout<<endl<<"Ŀ��վ�㣺";
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
    		cout<<"�������"<<endl;
	        continue;
	    }
    }
    return;
}

/***********************************************************/
/* Construction function to build a network                */
/* with n station and e edges, input from terminal         */
/***********************************************************/                      
highSpeedRail::highSpeedRail(int n, int e)
{
   
   string station;              //վ����
   staNum = 0;                  //
   railWay = e; 
   
       for(int i = 0; i< n ; i++)   //���붥����Ϣ����վ����Ϣ����ʼ��վ���
	   {  
		   cout<<"\n�������"<<staNum+1<<"��վ������ƣ�"<<endl;
	       cin>>station;
           while(isExisted(station))//���ڸ�վ��ʱ
		   {
		     cout<<"��վ̨�Ѵ��ڣ�����������:"<<endl;
			 cin>>station;
		   }
	
           adjlist[i].vertex = station;
           adjlist[i].firstedge = NULL;
           adjlist[i].count = 0;
           staNum ++;
	  }
   
       for(int k = 0; k < e ; k++)    //�ӵ�һ��վ�㿪ʼ���������ͨ��վ��
	   {  
	        string station1,station2;
			int cost;
			//������·�����ӵ���վ̨station1,station2
			cout<<endl<<"��������վ̨�����ֺ�վ̨֮��ľ���(��λ��km)"<<endl;
	        cin>>station1;
		    cin>>station2;
			cin>>cost; 
			while(!isExisted(station1) || !isExisted(station2)) 
			{
				if(isExisted(station1))
			    {
				    cout<<station2<<" վ̨�������ڣ���������������վ̨�����ֺ�վ̨֮��ľ���(��λ��km)��"<<endl;
				    cin>>station1;
		            cin>>station2;
			        cin>>cost; 
			    }
			    else if(isExisted(station2))
			    {
				    cout<<station1<<" վ̨�������ڣ���������������վ̨�����ֺ�վ̨֮��ľ���(��λ��km)��"<<endl;
				    cin>>station1;
		            cin>>station2;
		        	cin>>cost; 
			    }
			    else 
			    {
     				cout<<station1 << " "<<station2<<" վ̨�������ڣ���������������վ̨�����ֺ�վ̨֮��ľ���(��λ��km)��"<<endl;
	    			cin>>station1;
        		    cin>>station2;
			        cin>>cost; 
		    	}	
			}
			
            //��������ȷ 
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

   string station;              //վ����
   staNum = 0;                  //
    
       for(int i = 0; i< n ; i++)   //���붥����Ϣ����վ����Ϣ����ʼ��վ���
	   {  
	       infile>>station;
           if(isExisted(station))//���ڸ�վ��ʱ
		   {
		       cout<<station<<" վ̨�Ѵ��ڣ������ļ����ݴ���"<<endl;
			   exit(1);
		   }

           adjlist[i].vertex = station;

           adjlist[i].firstedge = NULL;
           adjlist[i].count = 0;
           
           staNum ++;
	  }

       for(int k = 0; k < railWay ; k++)    //�ӵ�һ��վ�㿪ʼ���������ͨ��վ��
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
       	       s->adjvex =i;                     //����һ���µı߱��㣬���µ���·
               s->distance=cost;
			   s->next = NULL;                 
			   int j = getIndex(station1);
	           s->next = adjlist[j].firstedge;   //�������뵽��j���߱�ı�ͷ
	           adjlist[j].firstedge = s;  
	           adjlist[j].count ++;
			}
			else if(isExisted(station1))
			{
				cout<<station2<<" վ̨�������ڣ������ļ����ݴ���"<<endl;
				exit(1);
			}
			else if(isExisted(station2))
			{
				cout<<station1<<" վ̨�������ڣ������ļ����ݴ���"<<endl;
				exit(1);
			}
			else 
			{
				cout<<station1 << " "<<station2<<" վ̨�������ڣ������ļ����ݴ���"<<endl;
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
	//cout << "Fail in getting index! Station "<< station << " do not existed��" << endl;
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
/* This is a function to add a Railway                */ 
/******************************************************/
void highSpeedRail::addRailWay(string station1,string station2,int cost)
{
	
	if(!isExisted(station1) || !isExisted(station2)) 
    {
		if(isExisted(station1))
		{
			cout<<station2<<" վ̨�������ڣ��������"<<endl;
			
		}
		else if(isExisted(station2))
		{
			cout<<station1<<" վ̨�������ڣ��������"<<endl;
				
		}
		else 
		{
			cout<<station1 << " "<<station2<<" վ̨�������ڣ��������"<<endl;
			
		}			
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
	if(!isExisted(station1) || !isExisted(station2)) 
    {
		if(isExisted(station1))
		{
			cout<<station2<<" վ̨�������ڣ��������"<<endl;
			
		}
		else if(isExisted(station2))
		{
			cout<<station1<<" վ̨�������ڣ��������"<<endl;
				
		}
		else 
		{
			cout<<station1 << " "<<station2<<" վ̨�������ڣ��������"<<endl;
			
		}			
		return ;
	}
	a = getIndex(station1);
	b = getIndex(station2);
		
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
		cout << endl << station1 << " �� " << station2 <<" �ľ���Ϊ " << dis[b] << " km." << endl; 
	}
	else
	{
		cout << endl << "����" << station1 << " �޷����� " << station2 <<endl; 
	}
	
}
int main()
{
   //highSpeedRail hsr(5,5);
   /*
   highSpeedRail hsr("input.txt"); 
   hsr.getDistance("����","����");
   string a ,b;
   cout<<"��������Ҫ��ѯ�ĳ�վ���룺"<<endl;
   cout<<"����վ�㣺";
   cin>>a;
   cout<<endl<<"Ŀ��վ�㣺";
   cin>>b;
   hsr.getDistance(a,b);
   */
   menu();
   return 0;
}
