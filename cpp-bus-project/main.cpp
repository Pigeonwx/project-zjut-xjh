#include<iostream>
#include<fstream>
#include<vector>
#include "good.h"
using namespace std;
int main(){
	cout<<"    ###########################"<<endl;
	cout<<"    ###       ѡ��˵�      ###"<<endl;
	cout<<"    ###    1���ļ�����      ###"<<endl;
	cout<<"    ###    2�����۵Ǽ�      ###"<<endl;
	cout<<"    ###    3�������۲�ѯ    ###"<<endl;
	cout<<"    ###    4������ͳ��      ###"<<endl;
    cout<<"    ###    5���ļ�����      ###"<<endl;
    cout<<"    ###########################"<<endl;
    for(int n;cin>>n;){
    	if(n<1||n>5) {cout<<"�޴���ѡ��������ȷ�ϲ�ȷ�ϣ�����";continue; }
		switch(n){
			case 1:{
				ifstream fin("input.tet");
                vector<good>v;				
				for(good a;fin>>a;){
				v.push_back(a);	
				}
				break;
			};
			case 2:{
			    vector<day>d;
				string n;int sa,pr,dis;
				for(string t;cin>>t>>n>>sa;){
				  day dd(t);
				  for(int i=0;i<v.size() ;i++){
				  	if(v[i].name()==n){
				  	  dd.gettp(v[i].tprice()*sa);
					  v[i].buy(sa);		
				  	}
				  }	
				  d.push_back(dd) ;	  
				}
				break;
			};
		    case 3:{
		    	for(string td;cin>>td;){
		        	for(int i=0;i<d.size() ;i++){
		    	    	if(d[i].getday()=td)
		    	    	  d[i].show();
		    	    }
		    }
		    	break;
		    };
		    case 4:;
		    case 5:{
		    	
		    	break;
		    };
		} 	
    } 
}
  


//1����Ʋ˵�ʵ�ֹ���ѡ�� 
//2�����ļ�������Ʒ�ź���Ʒ���ơ��������ڣ���Ч�ڣ������������Ϣ��
//3�����ۼ�¼�ĵǼǣ�
//4���Ե���������Ϣ�Ĳ�ѯ�������ۼ�¼�����ڡ��ܼۡ���������Ŀ����
//5�����ۼ�¼�ķ���ͳ�ƣ�����Ʒ�š��������ڣ���
//6�����Խ��������ۼ�¼��ͳ����Ϣ�����Ǽǵ��ļ���


