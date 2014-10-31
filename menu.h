#include<cstdio>
#include<fstream>
#include<string>
#include<cstring>
#include<iostream>
#include "windows.h"

#include "highSpeedRail.h"
using namespace std;

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
		{
		    cout <<"清空成功！"<<endl;
			cout<<"station.txt 和 rail.txt 已经删除，下次运行请先建立"<<endl;
		}
		else 
		    cout<<"清空失败！"<<endl;
		system("pause");
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