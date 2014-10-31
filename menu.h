#include<cstdio>
#include<fstream>
#include<string>
#include<cstring>
#include<iostream>
#include "windows.h"

#include "highSpeedRail.h"
using namespace std;

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
		{
		    cout <<"��ճɹ���"<<endl;
			cout<<"station.txt �� rail.txt �Ѿ�ɾ�����´��������Ƚ���"<<endl;
		}
		else 
		    cout<<"���ʧ�ܣ�"<<endl;
		system("pause");
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