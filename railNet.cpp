/*************************************************************/
/*����������                    120804��  3212002890   ���־�*/
/*************************************************************/
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
/*                  ��������                   */
/***********************************************/
class highSpeedRail
{
public:
         highSpeedRail(string,string);                            //���캯��      
         ~highSpeedRail(){};                                      //��������
		 bool isExisted(string );                                 //վ��station�Ƿ����
		 int getIndex(string );                                   //���վ�������
         void addStation(string );                                //����һ��վ̨
		 void addRailWay(string ,string ,int );                   //����һ��������·
         void getDistance(string ,string );                       // ���station1 �� station2  �����·��
         bool clear();

private:
	    VertexNode adjlist[Maxsize];             //���վ��������
		int staNum;                              //������վ����
		int railWay;                             //����������·��
		string  stationFile;
        string  railFile;		
};

//�˵�����
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
	//��ʼ��
    highSpeedRail hsr("station.txt","rail.txt"); //
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
		    cout <<"��ճɹ���"<<endl;
		else 
		    cout<<"���ʧ�ܣ�"<<endl;
	}
    else if(no == 5) break;
    }
}

void menu1(highSpeedRail hsr)
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

void menu2(highSpeedRail hsr)
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


void menu3(highSpeedRail hsr)
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
/*               ���캯��������һ��������                  */ 
/***********************************************************/   
highSpeedRail::highSpeedRail(string s,string r)
{

   ifstream infile;
   stationFile = s;
   railFile = r; 
   infile.open(stationFile.c_str(),ios::in);//��stationFile�ļ�

   if (!infile.is_open())
   {
       cout<<"\nCannot open input file!\n"<<endl;
       exit(1);
   }

   //���붥����Ϣ����վ����Ϣ����ʼ��վ���
   string station;              //վ����   
   staNum = 0;
       while(infile>>station)
	   {  
	       
           if(isExisted(station))//���ڸ�վ��ʱ
		   {
		       cout<<station<<" վ̨�Ѵ��ڣ������ļ����ݴ���"<<endl;
			   exit(1);
		   }

           adjlist[staNum].vertex = station;        //��վ̨����
           adjlist[staNum].firstedge = NULL;        //�޿ɴ�վ̨
           adjlist[staNum].count = 0;               
           
           staNum ++;
	  }
	  infile.close();
	  
	  //¼����·��· 
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
			if(isExisted(station1) && isExisted(station2))      //��station1 �� station2 ����ʱ
            {
			   ArcNode *s =new ArcNode;            //����һ���µı߱��㣬���µ���·
			   int i = getIndex(station2);         //���station2 ������
       	       s->adjvex =i;                    
               s->distance=cost;
			   s->next = NULL;                 
			   int j = getIndex(station1);         //���staion1 ������
	           s->next = adjlist[j].firstedge;     //�������뵽��j���߱�ı�ͷ
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
				cout<<station1 <<"��"<< " "<<station2<<" վ̨���������ڣ������ļ����ݴ���"<<endl;
				exit(1);
			}
			railWay ++;				
	   }
   
   	   infiler.close();

}


/*****************************************************/
/*                 �ж��Ƿ����վ̨station           */
/*****************************************************/
bool highSpeedRail::isExisted(string station)
{  
	for(int i = 0;i<staNum;i++)	
	    if(adjlist[i].vertex == station)
	        return 1;
    
	return 0;		//if fail ,return 0
}

/******************************************************/
/*                  ���վ̨station������             */ 
/******************************************************/
int highSpeedRail::getIndex(string station)
{
	for(int i = 0; i < staNum; i ++)
	    if(adjlist[i].vertex == station)
	        return i;
	
	// δ��ø�վ̨����
	//cout << "Fail in getting index! Station "<< station << " do not existed��" << endl;
	return -1;
	
}

/******************************************************/
/*                   ���һ��վ̨                     */ 
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
/*                    ���һ����·                    */ 
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

	int e = getIndex(station2);//��·�յ�end ���������
	int b = getIndex(station1);//��·���begin���������
	
	//�����·�Ѵ���
	ArcNode *tmp;
	tmp = adjlist[b].firstedge;
	for(int j = 0 ;j < adjlist[b].count; j++,tmp = tmp->next)
	{
		if(e == tmp->adjvex)
	       //if(cost >= tmp->distance )
		   {
		      cout<<"����·�Ѿ����ڣ�"<<endl;
		      return;
		   }
	}
	
	//��·������
	ofstream outfile;
	outfile.open(railFile.c_str(),ios::app);
	
	ArcNode *s =new ArcNode;

  	s->adjvex =e;                     //����һ���µı߱��㣬���µ���·
    s->distance=cost;                 
		
	s->next = adjlist[b].firstedge;   //�������뵽��j���߱�ı�ͷ
	adjlist[b].firstedge = s;  
	railWay ++;	
		
	outfile<<station1<<" "<<station2<<" "<<cost<<endl;
    outfile.close();
}

/******************************************************/
/*     վ̨station1 �� վ̨station2 ֮�����̾���    */ 
/*                      dijkstra                      */
/******************************************************/
void highSpeedRail::getDistance(string station1, string station2)
{
	int a, b;           //��㣬�յ�
	//վ̨������
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
	//վ̨����
	a = getIndex(station1);
	b = getIndex(station2);
	
	//dijkstra	
	bool known[Maxsize]; //��ʾһ�������Ƿ�֪̽�����Ϊ0��1
	int dis[Maxsize];    //�洢����
	int sum = 0;         //�ѱ�֪̽�Ķ�����
	
	//��ʼ��һƬ�������ڴ�ռ䣬��ʼ����known[]��Ϊ0��sizeof(known)Ϊknown[]����
	memset(known,0,sizeof(known));
	//��ʼ��һƬ�������ڴ�ռ䣬��ʼ����dis[]��Ϊ�����sizeof(dis)Ϊdis[]����
	memset(dis,0x3f,sizeof(dis));		
	dis[a] = 0;
	
	ArcNode *tmp;
	int s,t,v;         //
	
	while(sum < staNum)//sum = staNum,���еĽ�㶼��֪̽��������
	{
		s = 0;
		while(known[s])//�˴�s��ֵֻ����ʱ�Ĺ��ɣ���Ϊ�ȽϵĽ�㣬�޾������壬��known[s]==1������֪̽����s++
		{
			s++;
		}
		
		for(int i = 0; i < staNum ; i++)//Ѱ��known[]��û�б�֪̽����̾�����s
		{
			if(known[i] == 0 && dis[i] < dis[s] ) //i��һ��û�б�֪̽���ĵ㣬��dis[i]�������
			{
			    s = i;
			}
		}
		known[s] = 1; 
		tmp = adjlist[s].firstedge;

		for(int j = 0 ;j < adjlist[s].count; j++,tmp = tmp->next)//���¾���
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
		cout << endl << station1 << " �� " << station2 <<" �ľ���Ϊ " << dis[b] << " km." << endl; 
	}
	else
	{
		cout << endl << "����" << station1 << " �޷����� " << station2 <<endl; 
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
