#include<stdio.h>
#include<fstream>
#include<string>
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
	ArcNode*firstedge;      //ָ����ָ��߱��е�һ�����
};

/***********************************************/
/* declaration of haghSpeddRail class          */
/***********************************************/
class highSpeedRail
{
public:
         highSpeedRail(int , int );        
         highSpeedRail(string );//for file input
         ~highSpeedRail();                                                //��������
		 bool isExisted(string );                                 //վ��station�Ƿ����
		 int getIndex(string );                                                 //���վ�������
         void addStation();                                              //����һ��վ̨
		 void addRailWay();                                              //����һ��������·
         

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
     
   //if(in)                    //�������rail.txt�ļ�
   {
       for(int i = 0; i< n ; i++)   //���붥����Ϣ����վ����Ϣ����ʼ��վ���
	   {  
		   cout<<"\n�������"<<staNum+i+1<<"��վ������ƣ�"<<endl;
	       cin>>station;
           while(isExisted(station))//���ڸ�վ��ʱ
		   {
		     cout<<"��վ̨�Ѵ��ڣ�����������:"<<endl;
			 cin>>station;
		   }
		   //out<<station<<endl;                  //��վ̨�������ļ�
           adjlist[i].vertex = station;
           adjlist[i].firstedge = NULL;
	  }
   
       for(int k = 0; k < e ; k++)    //�ӵ�һ��վ�㿪ʼ���������ͨ��վ��
	   {  
	        string station1,station2;
			int cost;
			//������·�����ӵ���վ̨i,j
			cout<<"��������վ̨�����ֺ�վ̨֮��ľ���"<<endl;
	        cin>>station1;
		    cin>>station2;
			cin>>cost; 
			if(isExisted(station1)&&isExisted(station2)) 
            {
			   ArcNode *s =new ArcNode;
			   int i = getIndex(station2);
       	       s->adjvex =i;                     //����һ���µı߱��㣬���µ���·
               s->distance=cost;                 
			   int j = getIndex(station1);
	           s->next = adjlist[j].firstedge;   //�������뵽��j���߱�ı�ͷ
	           adjlist[j].firstedge = s;  
			}
			else
				cout<<"վ̨��������"<<endl;
	   }
   
       staNum = n;
       railWay = e;
	  // in.close();
	  // out.close();
   }
   else 
   {
	   cout<<"������rail.txt�ļ�"<<endl;
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
		cout<<"û�и��ļ�"<<endl;
}*/


void main(){
   
}
