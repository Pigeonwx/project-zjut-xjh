//Interface��
//���ܣ��Ե�¼�������һ����װ����
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
	cout<<"###                                  ��ӭ��½                                 ###"<<endl;
	cout<<"#################################################################################"<<endl; 
	cout<<endl;
	cout<<endl;
	
	AVLTree avl=AVLTree();
	DataType username,password;
	while(true){
		cout<<"                       �����������˺ţ�";
		cin>>username;
		cout<<endl;
		cout<<"                       �������������룺";

		cin>>password;
		system("cls");
		cout<<endl;
		DataType data=avl.search(username);
		if (data!="")//����û������ҵõ� 
		{
			if (password==data)//���������ƥ�� 
			    {cout<<"                                   ��½�ɹ�"<<endl;break;}
			else{cout<<"                                ������������"<<endl; 
		    	 cout<<"                                ����������\n"<<endl;} 
		}
		else
	    {    cout<<"                                ������˺Ŵ���"<<endl;
		     cout<<"                                ����������\n"<<endl;} 
        }
	
	cout<<endl;
	cout<<endl;
    
	while(true){
		cout<<"��ѡ�����Ĳ�����"<<endl;
		cout<<"1.��������"<<endl;
		cout<<"2.ע�����û�"<<endl;
		cout<<"3.ɾ�����û�"<<endl;
		cout<<"4.����չʾ�����û�"<<endl; 
		cout<<"5.�˳�ϵͳ"<<endl; 
		cout<<endl;
		int in;
		cin>>in;
		system("cls");
		cout<<endl; 
        switch(in){//diferent choices
        	case 1:{
        		DataType newpassword1,newpassword2;
				while(true){
					cout<<"������������:";
					cin>>newpassword1;
					cout<<"��������һ��������:";
					cin>>newpassword2;
					if (newpassword1==newpassword2){
						system("cls");
						cout<<endl;
						cout<<"�޸ĳɹ���"<<endl;
						break;
					}
					else {
						system("cls");
						cout<<endl;
						cout<<"��������������벻һ�£�����������"<<endl; 
					}
				}
				avl.update(username,newpassword1);
				system("cls");
				cout<<endl;
				cout<<"���ĳɹ�"<<endl; 
        		break;
        	}
        	case 2:{
        		DataType newusername,newpassword1,newpassword2;
				cout<<"���������û���ע���˺�:";
				cin>>newusername;
				if (avl.search(newusername)!=""){cout<<"this username existed!"<<endl;}
				else {
				while(true){
					cout<<"���������û�������:";
					cin>>newpassword1;
					cout<<"��������һ�����û�������:";
					cin>>newpassword2;
					if (newpassword1==newpassword2){
						system("cls");
						cout<<endl;
						cout<<"ע��ɹ���"<<endl;
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
        		cout<<"��������Ҫע���ľ��û�����";
				DataType oldusername;
				cin>>oldusername; 
				cout<<"ȷ��Ҫɾ�����˻���  "<<oldusername<<"  �˺���"<<endl;
				cout<<"1-ȷ��    ��1-ȡ��"<<endl;
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
        		cout<<"ȷ��Ҫ�˳�������"<<endl;
		    	cout<<"1-ȷ��    ��1-ȡ��"<<endl;
		    	string sure;
			    cin>>sure;
			    system("cls");
			    cout<<endl;
			    if (sure=="1")goto loop;
			    else continue;
        	}
        	default:{
        		 cout<<"������Ĳ�����������������"<<endl;
		         cout<<endl;
		         cout<<endl;
		         cout<<"1-���ز˵�"<<endl;
		         cout<<"��1-�˳�����"<<endl;
	             string inp;
		         cin>>inp;
	             if (inp=="1");
	       	     else {
			        system("cls");
			        cout<<endl;
			        cout<<"ȷ��Ҫ�˳�������"<<endl;
		           	cout<<"1-ȷ��    ��1-ȡ��"<<endl;
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
	cout<<"#####################################��лʹ��#####################################";
	cout<<endl; 
	cout<<"#######################################�ټ�#######################################";
	cout<<endl;
	Sleep(2000);
	system("cls");
}

