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

��������۹���ϵͳ
����Ҫ��
������Ϣ������Ʒ�š���Ʒ���ơ��������ڡ���Ч�ڡ��������ڡ��ۼۡ��ۿۡ�������
����Ҫ��
1����Ʋ˵�ʵ�ֹ���ѡ�� 
2�����ļ�������Ʒ�ź���Ʒ���ơ��������ڣ���Ч�ڣ������������Ϣ��
3�����ۼ�¼�ĵǼǣ�
4���Ե���������Ϣ�Ĳ�ѯ�������ۼ�¼�����ڡ��ܼۡ���������Ŀ����
5�����ۼ�¼�ķ���ͳ�ƣ�����Ʒ�š��������ڣ���
6�����Խ��������ۼ�¼��ͳ����Ϣ�����Ǽǵ��ļ���

