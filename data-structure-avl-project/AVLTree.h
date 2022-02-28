//AVL平衡树类 
//功能：增加删除结点、左右旋调整树、展示AVL树
//===========================================================================
#include<iostream>
#include<fstream>
#include"AVLNode.h"
#include"assert.h"
#include <windows.h>
using namespace std;
class AVLTree{
	public:
		AVLNode *Root=0;//指向平衡树的根 
	public:
		AVLTree();//无参构造函数 
		bool empty();//判空 
		DataType search(DataType);//搜索 
		void insert(DataType,DataType);//插入
		void remove(DataType);//删除 
		void update(DataType,DataType);//更新 
		void Lrotation(AVLNode**,int);//左旋
		void Rrotation(AVLNode**,int);//右旋 
		void LRrotation(AVLNode**,int);//左右旋 
		void RLrotation(AVLNode**,int);//右左旋 
		void display();//中序遍历法输出AVL树  
		void display2();//前序遍历法输出AVLTree到文件 
		void graph();//图像打印整棵树，纵向输出 
		~AVLTree(); //析构函数 
};

template <typename StackElement>
class Stack{
	public:
	class Node{
		public:
		StackElement data;
		Node* next;
		Node(StackElement d,Node* n=0):data(d),next(n){}
	};
private:
    Node* myTop=0;//栈顶，也是链表的表首指针
public:
	Stack();//构造空栈
	~Stack();//析构函数
	
	bool empty() const;//判空
	void push(const StackElement& item);//压栈
	void pop();//弹出
	StackElement top() const;//访问栈顶
	void settop(StackElement value);//修改栈顶元素 
};


typedef AVLNode* QueueElement;
class Node2{
public:
   QueueElement data;
   Node2* next;
   Node2(){}
   Node2(QueueElement d,Node2* n=0):data(d),next(n){}
};

class Queue{
private:
	Node2* myFront=0,*myBack=0;//指向队列头和尾的指针 
public:
	Queue();//无参构造 
	~Queue();//析构 
	bool empty() const;//判空 
	void push(const QueueElement& item);//入队
	void pop();//出队
	QueueElement front() const;//访问队首
	QueueElement back() const;//访问队尾 
};
