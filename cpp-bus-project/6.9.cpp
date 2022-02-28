#ifndef GOOD_H
#define GOOD_H
#include <string>
using namespace std;
class Good{
  string num;
  string name;
  string mtime;
  int vtime;
 // string otime;
  int price;
  int discount	;
  int balance;
public:
  void get()
  void buy(int);	
  friend ifstream& operator<<(ifstream&,good&);  
  friend ofstream& operator>>(ofstream&,good&);
};
void buy(int a){
   	balance-=a;
}
ifstream&operator<<(ostream& if,good&g){
	if>>g.num>>g.name>>g.mtime>>g.vtime>>g.otime>>g.price>>g.discout<<g.balance;
	return if;
}
ofstream&operator>>(ofstream&of,good&g){
	of<<g.num>>g.name>>g.mtime>>g.vtime>>g.otime>>g.price>>g.discout<<g.balance;
	return of;
}


#endif

面包店销售管理系统
基本要求：
销售信息包括商品号、商品名称、制作日期、有效期、销售日期、售价、折扣、数量。
功能要求：
1、设计菜单实现功能选择； 
2、从文件读入商品号和商品名称、制作日期，有效期，库存数量等信息；
3、销售记录的登记；
4、对当日销售信息的查询，将销售记录按日期、总价、数量等项目排序；
5、销售记录的分类统计（按商品号、销售日期）；
6、可以将当日销售记录和统计信息导出登记到文件；

