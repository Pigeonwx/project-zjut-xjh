//AVLƽ������ 
//���ܣ�����ɾ����㡢��������������չʾAVL��
//===========================================================================
#include<iostream>
#include<fstream>
#include"AVLNode.h"
#include"assert.h"
#include <windows.h>
using namespace std;
class AVLTree{
	public:
		AVLNode *Root=0;//ָ��ƽ�����ĸ� 
	public:
		AVLTree();//�޲ι��캯�� 
		bool empty();//�п� 
		DataType search(DataType);//���� 
		void insert(DataType,DataType);//����
		void remove(DataType);//ɾ�� 
		void update(DataType,DataType);//���� 
		void Lrotation(AVLNode**,int);//����
		void Rrotation(AVLNode**,int);//���� 
		void LRrotation(AVLNode**,int);//������ 
		void RLrotation(AVLNode**,int);//������ 
		void display();//������������AVL��  
		void display2();//ǰ����������AVLTree���ļ� 
		void graph();//ͼ���ӡ��������������� 
		~AVLTree(); //�������� 
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
    Node* myTop=0;//ջ����Ҳ������ı���ָ��
public:
	Stack();//�����ջ
	~Stack();//��������
	
	bool empty() const;//�п�
	void push(const StackElement& item);//ѹջ
	void pop();//����
	StackElement top() const;//����ջ��
	void settop(StackElement value);//�޸�ջ��Ԫ�� 
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
	Node2* myFront=0,*myBack=0;//ָ�����ͷ��β��ָ�� 
public:
	Queue();//�޲ι��� 
	~Queue();//���� 
	bool empty() const;//�п� 
	void push(const QueueElement& item);//���
	void pop();//����
	QueueElement front() const;//���ʶ���
	QueueElement back() const;//���ʶ�β 
};
