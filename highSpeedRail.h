#include<stdio.h>
#include<fstream.h>

#ifndef HSRAIL
#define HSRAIL

#include "VertexNode"

const int Maxsize = 1000;    //���ֵΪ1000

class highSpeedRail
{
   public��
         void highSpeedRail(int array[],int n, int e);        //���캯��������һ����n��վ�㣬e����·�ĸ�������ͼ
         ~highSpeedRail();                                          //��������
		 bool isExisted(string station);                                      //վ��station�Ƿ����
         void addStation();                                              //����һ��վ̨
		 void addRailWay();                                              //����һ��������·
         

   private:
	    VertexNode adjlist[Maxsize];                //���վ��������
		int staNum;                              //������վ����
		int railWay;                             //����������·��
}

void highSpeedRail::highSpeedRail(string array[],int n, int e)
{  
   ifstream in("rail.txt");    //���վ����Ϣ��txt�ļ�
   string station;              //վ����
     
   if(in)                    //�������rail.txt�ļ�
   {
       for(int i = 0; i< n ; i++)   //���붥����Ϣ����վ����Ϣ����ʼ��վ���
	   {  
		   cout<<"\n�������">>staNum+i+1>>"��վ������ƣ�"<<endl;
	       cin>>station;
           while(isExited(station))
		   {
		     cout<<"��վ̨�Ѵ��ڣ�����������:"<<endl;
			 cin>>station;
		   }
		   in<<station<<endl;                  //��վ̨�������ļ�
           adjlist[i].vertex = station;
           adjlist[i].firstedge = NULL;
	  }
   
       for(int k = 0; k < e ; k++)    //�ӵ�һ��վ�㿪ʼ���������ͨ��վ��
	   {  
	        string i,j;
			//������·�����ӵ���վ̨i,j
			cout<<"��������վ̨�����֣�"<<endl;
	        cin>>i;
		    cin>>j; 
			if(isExisten(i)&&isExisten(j)) 
            {
			   ArcNode s = new ArcNode;           
       	       s->adjvex =j;                     //����һ���µı߱��㣬���µ���·
		       cout<<"\n������վ̨"<<i<<"��վ̨"<<j<<"֮��ľ��룺"<<endl;
               cin>>cost;
               s->distance=cost;                 //վ��x��y֮��ľ���Ϊn
	           s->next = adjlist[i].firstedge;   //�������뵽��i���߱�ı�ͷ
			}
			else
				cout<<'վ̨��������'<<endl
	   }
   
       staNum = n;
       railWay = e;
   }
   else 
   {
	   cout<<"������rail.txt�ļ�"<<endl;
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
   cout<<"��������ӵ�վ̨��"<<endl;
   cin>>station;
   while(isExited(station))
   {
		     cout<<"��վ̨�Ѵ��ڣ�����������:"<<endl;
			 cin>>station;
   }
	in<<station<<endl;                  //��վ̨�������ļ�
    adjlist[i].vertex = station;
    adjlist[i].firstedge = NULL;
	  
}


void highSpeedRail::addRailWay()
{
    string i,j;
	//������·�����ӵ���վ̨i,j
	cout<<"��������վ̨�����֣�"<<endl;
	cin>>i;
	cin>>j; 
	if(isExisten(i)&&isExisten(j)) 
     {
		ArcNode s = new ArcNode;           
       	s->adjvex =j;                     //����һ���µı߱��㣬���µ���·
		cout<<"\n������վ̨"<<i<<"��վ̨"<<j<<"֮��ľ��룺"<<endl;
        cin>>cost;
        s->distance=cost;                 //վ��x��y֮��ľ���Ϊn
	    s->next = adjlist[i].firstedge;   //�������뵽��i���߱�ı�ͷ

	}
	else
	     cout<<'վ̨��������'<<endl
	 
}

}
