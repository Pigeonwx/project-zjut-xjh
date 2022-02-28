//结点类 
//功能：树的结点，定义构造函数
//===========================================================================
#ifndef AVLNODE
#define AVLNODE
#include<string>
using namespace std;
typedef string DataType;
class AVLNode{
	public:
		DataType usernamedata,passworddata;//储存用户名和密码，用户名拿来构建平衡树 
		short int factor,Lhight,Rhight,hight;//factor为平衡因子，即Lhight-Rhight，若factor=2或-2，则不平衡 
		AVLNode * father; //指向父节点 
		AVLNode * left;//指向左子树
		AVLNode * right;//指向右子树 
	
	AVLNode():usernamedata(""),passworddata(""),factor(0),Lhight(0),Rhight(0),hight(1),father(0),left(0),right(0){}
	AVLNode(DataType item1,DataType item2,AVLNode* ptr):factor(0),Lhight(0),Rhight(0),hight(1),usernamedata(item1),passworddata(item2),father(ptr),left(0),right(0){}
};
#endif
