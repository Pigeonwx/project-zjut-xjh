//Interface类
//功能：对登录界面进行一个封装操作
//===========================================================================
 #include <windows.h>
 #include<iostream>
 using namespace std;
 class Interface{
 public:
	void Show();
 };
void Interface:: Show(){
	cout<<endl;
	cout<<endl;
	cout<<"#################################################################################"<<endl;
	cout<<"###                                  欢迎登陆                                 ###"<<endl;
	cout<<"#################################################################################"<<endl; 
	cout<<endl;
	cout<<endl;
	
	AVLTree avl=AVLTree();
	DataType username,password;
	while(true){
		cout<<"                       请输入您的账号：";
		cin>>username;
		cout<<endl;
		cout<<"                       请输入您的密码：";

		cin>>password;
		system("cls");
		cout<<endl;
		DataType data=avl.search(username);
		if (data!="")//如果用户名能找得到 
		{
			if (password==data)//如果密码能匹配 
			    {cout<<"                                   登陆成功"<<endl;break;}
			else{cout<<"                                输入的密码错误"<<endl; 
		    	 cout<<"                                请重新输入\n"<<endl;} 
		}
		else
	    {    cout<<"                                输入的账号错误"<<endl;
		     cout<<"                                请重新输入\n"<<endl;} 
        }
	
	cout<<endl;
	cout<<endl;
    
	while(true){
		cout<<"请选择您的操作："<<endl;
		cout<<"1.更改密码"<<endl;
		cout<<"2.注册新用户"<<endl;
		cout<<"3.删除旧用户"<<endl;
		cout<<"4.树型展示所有用户"<<endl; 
		cout<<"5.退出系统"<<endl; 
		cout<<endl;
		int in;
		cin>>in;
		system("cls");
		cout<<endl; 
        switch(in){//diferent choices
        	case 1:{
        		DataType newpassword1,newpassword2;
				while(true){
					cout<<"请输入新密码:";
					cin>>newpassword1;
					cout<<"请再输入一遍新密码:";
					cin>>newpassword2;
					if (newpassword1==newpassword2){
						system("cls");
						cout<<endl;
						cout<<"修改成功！"<<endl;
						break;
					}
					else {
						system("cls");
						cout<<endl;
						cout<<"您两次输入的密码不一致，请重新输入"<<endl; 
					}
				}
				avl.update(username,newpassword1);
				system("cls");
				cout<<endl;
				cout<<"更改成功"<<endl; 
        		break;
        	}
        	case 2:{
        		DataType newusername,newpassword1,newpassword2;
				cout<<"请输入新用户的注册账号:";
				cin>>newusername;
				if (avl.search(newusername)!=""){cout<<"this username existed!"<<endl;}
				else {
				while(true){
					cout<<"请输入新用户的密码:";
					cin>>newpassword1;
					cout<<"请再输入一遍新用户的密码:";
					cin>>newpassword2;
					if (newpassword1==newpassword2){
						system("cls");
						cout<<endl;
						cout<<"注册成功！"<<endl;
						break;
					}
					else {
						system("cls");
						cout<<endl;
				        
					}
				}
				avl.insert(newusername,newpassword1);
				}
        		break;
        	}
        	case 3:{
        		cout<<"请输入需要注销的旧用户名：";
				DataType oldusername;
				cin>>oldusername; 
				cout<<"确定要删除该账户？  "<<oldusername<<"  账号吗？"<<endl;
				cout<<"1-确定    非1-取消"<<endl;
				string sure;
				cin>>sure;
				system("cls");
				cout<<endl;
				if (sure=="1")avl.remove(oldusername);
        		break;
        	}
        	case 4:{
        			avl.display();
			        cout<<endl;
			        cout<<endl; 
			        avl.graph();
        	     	break;
        	}
        	case 5:{
        		cout<<"确定要退出程序吗？"<<endl;
		    	cout<<"1-确定    非1-取消"<<endl;
		    	string sure;
			    cin>>sure;
			    system("cls");
			    cout<<endl;
			    if (sure=="1")goto loop;
			    else continue;
        	}
        	default:{
        		 cout<<"您输入的操作有误，请重新输入"<<endl;
		         cout<<endl;
		         cout<<endl;
		         cout<<"1-返回菜单"<<endl;
		         cout<<"非1-退出程序"<<endl;
	             string inp;
		         cin>>inp;
	             if (inp=="1");
	       	     else {
			        system("cls");
			        cout<<endl;
			        cout<<"确定要退出程序吗？"<<endl;
		           	cout<<"1-确定    非1-取消"<<endl;
		        	string sure;
		        	cin>>sure;
			        system("cls");
			        cout<<endl;
			        if (sure=="1") goto loop;
        	       } 
            }
		system("cls");
		cout<<endl;
     	}
	}
	loop:
	avl.display2();
	system("cls");
	cout<<endl;
	cout<<endl;
	cout<<endl;
	cout<<"#####################################感谢使用#####################################";
	cout<<endl; 
	cout<<"#######################################再见#######################################";
	cout<<endl;
	Sleep(2000);
	system("cls");
}

