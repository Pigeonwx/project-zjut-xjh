#include<iostream>
#include<fstream>
#include<vector>
#include "good.h"
using namespace std;
int main(){
	cout<<"    ###########################"<<endl;
	cout<<"    ###       选择菜单      ###"<<endl;
	cout<<"    ###    1：文件导入      ###"<<endl;
	cout<<"    ###    2：销售登记      ###"<<endl;
	cout<<"    ###    3：日销售查询    ###"<<endl;
	cout<<"    ###    4：分类统计      ###"<<endl;
    cout<<"    ###    5：文件导出      ###"<<endl;
    cout<<"    ###########################"<<endl;
    for(int n;cin>>n;){
    	if(n<1||n>5) {cout<<"无此项选则，请重新确认并确认！！！";continue; }
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
  


//1、设计菜单实现功能选择； 
//2、从文件读入商品号和商品名称、制作日期，有效期，库存数量等信息；
//3、销售记录的登记；
//4、对当日销售信息的查询，将销售记录按日期、总价、数量等项目排序；
//5、销售记录的分类统计（按商品号、销售日期）；
//6、可以将当日销售记录和统计信息导出登记到文件；


