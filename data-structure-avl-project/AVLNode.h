//����� 
//���ܣ����Ľ�㣬���幹�캯��
//===========================================================================
#ifndef AVLNODE
#define AVLNODE
#include<string>
using namespace std;
typedef string DataType;
class AVLNode{
	public:
		DataType usernamedata,passworddata;//�����û��������룬�û�����������ƽ���� 
		short int factor,Lhight,Rhight,hight;//factorΪƽ�����ӣ���Lhight-Rhight����factor=2��-2����ƽ�� 
		AVLNode * father; //ָ�򸸽ڵ� 
		AVLNode * left;//ָ��������
		AVLNode * right;//ָ�������� 
	
	AVLNode():usernamedata(""),passworddata(""),factor(0),Lhight(0),Rhight(0),hight(1),father(0),left(0),right(0){}
	AVLNode(DataType item1,DataType item2,AVLNode* ptr):factor(0),Lhight(0),Rhight(0),hight(1),usernamedata(item1),passworddata(item2),father(ptr),left(0),right(0){}
};
#endif
