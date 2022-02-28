//AVLTree.cpp
//===========================================================================
#include"AVLTree.h"
#include<iostream>
#include<fstream>
#include"assert.h"
#include<iomanip>
using namespace std;
template <typename StackElement>
Stack<StackElement>::Stack(){
	myTop=0;
}

template <typename StackElement>
Stack<StackElement>::~Stack(){
	Node* node=myTop;
	while (node){
		node=node->next;
		delete myTop;
		myTop=node;
	}
}

template <typename StackElement>
bool Stack<StackElement>::empty() const{
	if (myTop) return false;
	else return true;
}

template <typename StackElement>
void Stack<StackElement>::push(const StackElement& item){
	Node* node=new Node(item,myTop);
	myTop=node;
}

template <typename StackElement>
void Stack<StackElement>::pop(){
	Node* node=myTop;
	myTop=myTop->next;
	delete node;
}

template <typename StackElement>
StackElement Stack<StackElement>::top()const{
	return myTop->data;
} 

template <typename StackElement>
void Stack<StackElement>::settop(StackElement value){
	myTop->data=value;
} 
AVLTree::AVLTree(){//无参构造函数
	fstream fin;
	fin.open("data.txt",ios::in);
	assert(fin.is_open());
	DataType username,password;//储存用户名和密码，其中使用用户名作为插入平衡树的节点值 
	while(fin>>username>>password){
		insert(username,password);
	}
	fin.close();
}

bool AVLTree::empty(){ if(Root==0)return false;else return true;}

DataType AVLTree::search(DataType username){
	AVLNode* ptr=Root;
	while (ptr!=0){
		if (ptr->usernamedata==username)
			return ptr->passworddata;
		if (ptr->usernamedata < username)
			ptr=ptr->right;
		else if (ptr->usernamedata > username)
			ptr=ptr->left;
	}
	return ""; 
}

void AVLTree::insert(DataType username,DataType password){
	if (Root==0){
		Root=new AVLNode(username , password , 0);
		return;
	} 
	AVLNode* ptr=Root,*preptr=Root;
	int lf=0;       //记录上一次判断的移动方向，1代表左，2代表右 
	
	//确定应该被挂的位置 
	while (ptr!=0){
		if (username > ptr->usernamedata){
			preptr=ptr;
			ptr=ptr->right;
			lf=2;
			}
		else if (username < ptr->usernamedata){
			preptr=ptr;
			ptr=ptr->left;
			lf=1;
			}
	}
	
	//挂上新节点 
	AVLNode* newptr;//指向被挂的新节点，为上溯做准备 
	if (lf==1){
	preptr->left=new AVLNode(username,password,preptr);
	newptr=preptr->left;
	}
	else if (lf==2){
	preptr->right=new AVLNode(username,password,preptr);
	newptr=preptr->right;
	}
	
	//开始上溯，确定本次悬挂新节点对其他节点层高的改变 
	int direction1=0,direction2=0;//表示出现不平衡节点的下两步的方向，1代表左，2代表右 
	AVLNode *inspect=0;//用来指向不平衡点，即平衡因子factor=2或-2的节点 
	while(newptr->usernamedata!=Root->usernamedata){
		if (newptr->usernamedata < newptr->father->usernamedata){//新节点在其左子树中 
			direction2=direction1;
			direction1=1;
			newptr->father->Lhight++;//左层高增加 
			newptr->father->factor=newptr->father->Lhight-newptr->father->Rhight;
			if (newptr->father->factor==2){inspect=newptr->father;break;}
			if (newptr->father->Lhight > newptr->father->Rhight){newptr->father->hight++;}//增加结点树高 
			else break;
			newptr=newptr->father; 
		}
		else if(newptr->usernamedata > newptr->father->usernamedata){//新节点在其右子树中
			direction2=direction1;
			direction1=2;
			newptr->father->Rhight++;//右层高增加 
			newptr->father->factor=newptr->father->Lhight-newptr->father->Rhight;
			if (newptr->father->factor==-2){inspect=newptr->father;break;}
			if (newptr->father->Lhight < newptr->father->Rhight){newptr->father->hight++;}
			else break;
			newptr=newptr->father; 
		}
	}
	
	//判断是否需要平衡化，即是否需要旋转 
	if (inspect!=0){
		int flf=0;             //判断不平等点是其父亲的左子树还是右子树 ，1代表左，2代表右 
		if (inspect->usernamedata!=Root->usernamedata){
			if (inspect->usernamedata < inspect->father->usernamedata)flf=1;
			else flf=2;
		}
		if (direction1==1 && direction2==1)
			Rrotation(&inspect,flf);
		else if (direction1==1 && direction2==2)
			LRrotation(&inspect,flf);
		else if (direction1==2 && direction2==1)
			RLrotation(&inspect,flf);
		else if (direction1==2 && direction2==2)
			Lrotation(&inspect,flf);
	}  
	
}

void AVLTree::remove(DataType username){
	if (Root==0){
		cout<<"当前注册用户数为零，删除失败"<<endl;
		return;
	} 

	//寻找待删节点 
	AVLNode* ptr=Root,*preptr=Root;
	int lf=0;       //记录上一次判断的移动方向，1代表左，2代表右
	while (ptr!=0){ 
		if (username == ptr->usernamedata){
			break;
		}
		if (username > ptr->usernamedata){
			preptr=ptr;
			ptr=ptr->right;
			lf=2;
			}
		else  if (username < ptr->usernamedata){
			preptr=ptr;
			ptr=ptr->left;
			lf=1;
			}
	}
	if (ptr==0){cout<<"未找到该用户名，删除失败"<<endl;return;}
	
	//删除节点 
	bool isgen=false;
	if (ptr->left==0 || ptr->right==0){//被删节点没有左右子树或只有左子树或只有右子树
		if (ptr->left==0){
			if (lf==0){Root=ptr->right;isgen=true;}//当待删节点是树根时
			else if (lf==1){preptr->left=ptr->right;}
			else if (lf==2){preptr->right=ptr->right;}
		}
		else {
			if (lf==0){Root=ptr->left;isgen=true;}//当待删节点是树根时
			else if (lf==1){preptr->left=ptr->left;}
			else if (lf==2){preptr->right=ptr->left;}
		}
		
		AVLNode* temp=ptr;
		if (!isgen){ 
		//开始上溯 
		AVLNode *inspect=0;//用来指向不平衡点，即平衡因子factor=2或-2的节点 
		lf=0;//用来表示删除的节点在不平衡点的左子树中还是右子树中  
		while (ptr->usernamedata!=Root->usernamedata){
			if (ptr->usernamedata < ptr->father->usernamedata){
				lf=1;
				ptr->father->Lhight--;
				ptr->father->factor=ptr->father->Lhight - ptr->father->Rhight;
				if (ptr->father->factor==-2) {inspect=ptr->father;break;}
				if (ptr->father->Lhight == ptr->father->Rhight){ptr->father->hight=ptr->father->Lhight;}
				else break;
				ptr=ptr->father;
			}
			else if (ptr->usernamedata > ptr->father->usernamedata){
				lf=2;
				ptr->father->Rhight--;
				ptr->father->factor=ptr->father->Lhight - ptr->father->Rhight;
				if (ptr->father->factor==2) {inspect=preptr;break;}
				if (ptr->father->Lhight == ptr->father->Rhight){ptr->father->hight=ptr->father->Lhight;}
				else break;
				ptr=ptr->father;
			}
		}
		
	    //判断是否需要平衡化，即是否需要旋转 
		if (inspect!=0){
			int flf=0;             //判断不平等点是其父亲的左子树还是右子树 ，1代表左，2代表右 
			if (inspect->usernamedata!=Root->usernamedata){
				if (inspect->usernamedata < inspect->father->usernamedata)flf=1;
				else flf=2;
			}
			if (lf==1){
				if (inspect->right->Rhight >= inspect->right->Lhight)
					Lrotation(&inspect,flf);
				else RLrotation(&inspect,flf);
			}
			else if (lf==2){
				if (inspect->left->Lhight >= inspect->left->Rhight)
					Rrotation(&inspect,flf);
				else LRrotation(&inspect,flf);
			}
		}
		}
		delete temp;cout<<"删除成功！"<<endl;
	}
	else {//待删节点有左子树也有右子树 
		DataType repassword;
		Stack<AVLNode*> s;
		AVLNode* root =Root;
		while(!s.empty()|| root) 
		{//通过中序遍历法找到替代节点 
			if(root){
				s.push(root);
				root=root->left; }
			else{
				root=s.top(); 
				s.pop();
				if (s.top()->usernamedata == ptr->usernamedata){//找到中序前驱，即替代节点 
					username=root->usernamedata;//记录替代节点的数据 
					repassword=root->passworddata;
					break;
				} 
				root=root->right;}
		}
		remove(username);//删除替代节点 
		ptr->usernamedata=username;//将替代节点的值写入原来的待删节点
		ptr->passworddata=repassword;
	}
}

void AVLTree::update(DataType username,DataType password){
	AVLNode* ptr=Root;
	while (ptr!=0){
		if (ptr->usernamedata==username)
			{ptr->passworddata=password;return;}
		if (ptr->usernamedata < username)
			ptr=ptr->right;
		else if (ptr->usernamedata > username)
			ptr=ptr->left;
	}
}

void AVLTree::Lrotation(AVLNode** aa,int flf){
	AVLNode* a=*aa;
	AVLNode* b=a->right;
	AVLNode* af=a->father;
	
	//对层高的调整 
	a->Rhight=b->Lhight;
	if (a->Lhight >= a->Rhight)a->hight=a->Lhight+1;
	else if (a->Lhight < a->Rhight)a->hight=a->Rhight+1;
	b->Lhight=a->hight;
	if (b->Lhight >= b->Rhight)b->hight=b->Lhight+1;
	else if (b->Lhight < b->Rhight)b->hight=b->Rhight+1;
	
	//开始平衡化操作
	if (a->usernamedata==Root->usernamedata){
		Root=b;
		b->father=b;
	}
	else {AVLNode *af=a->father;
			if (flf==1){
				af->left = b;
				b->father = a->father;
			}
			else if (flf==2){
				af->right = b;
				b->father = a->father;
			}
		}
	a->right=b->left;
	if (b->left)b->left->father=a;
	b->left=a;
	a->father=b;
}

void AVLTree::Rrotation(AVLNode** aa,int flf){
	AVLNode* a=*aa;
	AVLNode* b=a->left;
	AVLNode *af=a->father;
	
	//对层高的调整 
	a->Lhight=b->Rhight;
	if (a->Lhight >= a->Rhight)a->hight=a->Lhight+1;
	else if (a->Lhight < a->Rhight)a->hight=a->Rhight+1;
	b->Rhight=a->hight;
	if (b->Lhight >= b->Rhight)b->hight=b->Lhight+1;
	else if (b->Lhight < b->Rhight)b->hight=b->Rhight+1;
	
	//开始平衡化操作
	if (a->usernamedata==Root->usernamedata){
		Root=b;
		b->father=b;}
	else {
		if (flf==1){
			af->left = b;
			b->father = a->father;
		}
		else if(flf==2){
			af->right = b;
			b->father = a->father;
		}
	}
	a->left=b->right;
	if (b->right)b->right->father=a;
	b->right=a;
	a->father=b;
	
}

void AVLTree::LRrotation(AVLNode** aa,int flf){
	Lrotation(&((*aa)->left),1);
	Rrotation(&(*aa),flf);
}

void AVLTree::RLrotation(AVLNode** aa,int flf){
	Rrotation(&((*aa)->right),2);
	Lrotation(&(*aa),flf);
}

void AVLTree::display(){//前序遍历法输出AVLTree到控制台 
	Stack<AVLNode*> s;
    AVLNode* root =Root;
    while(!s.empty()|| root) {
    if(root){
		cout<<root->usernamedata<<' ';    
    	s.push(root);
    	root=root->left; }
    else{
		root=s.top(); 
    	s.pop();                     
    	root=root->right;}
	}
}


void AVLTree::display2(){//前序遍历法输出AVLTree到文件 
	ofstream outs;
	outs.open("data.txt");
	
	Stack<AVLNode*> s;
    AVLNode* root =Root;
    while(!s.empty()|| root) {
    if(root){
		outs<<root->usernamedata<<"  "<<root->passworddata<<"\n";    
    	s.push(root);
    	root=root->left; }
    else{
		root=s.top(); 
    	s.pop();                     
    	root=root->right;}
	}
	
	outs.close();
}

void AVLTree::graph(){//纵向输出整棵树
	int width=0,newwidth=0;			//主体采用层次周游的方法，通过层高来判断间隔情况 
	int Hight=Root->hight;
	for (int i=0,plus=1;i<Hight;i++,plus*=2)
		width+=plus;//计算，当前的树如果是完整的二叉树，其所有节点的个数 
	
	//计算所有节点中值的长度的最大值，通过前序周游进行遍历
	int maxlen=(Root->usernamedata).length();
	Stack<AVLNode*> s;
    AVLNode* root3 =Root;
    while(!s.empty()|| root3) {
    if(root3){
		if ((root3->usernamedata).length() > maxlen)maxlen=(root3->usernamedata).length();
    	s.push(root3);
    	root3=root3->left; }
    else{
		root3=s.top(); 
    	s.pop();                     
    	root3=root3->right;}
	}

	Queue q;
	q.push(Root);
	AVLNode* last=Root;//检测当前节点是否是该层的最后一个节点 
	bool isfirst=true;//判断是否是每层的第一个数据 
	int hight=1; //当前输出的层数 
	while (!q.empty()){
		AVLNode* root2=q.front();
		if (isfirst){isfirst=false;newwidth=(width+1)/2;}
		else newwidth=width;
		if (root2->usernamedata!=""){//当节点值不为空串时，将其左右子节点插入队列中 
			cout<<setw(maxlen*newwidth)<<root2->usernamedata;
		}
		else cout<<setw(maxlen*newwidth)<<"";
		if(root2->left)
			q.push(root2->left);
		else q.push(new AVLNode());//如果节点为空，则new一个空串节点来代替 
		if(root2->right)
			q.push(root2->right);
		else q.push(new AVLNode());//如果节点为空，则new一个空串节点来代替 
		if (root2==last){
			cout<<endl;
			hight++;
			if (hight>Hight)break;
			last=q.back();
			width=(width+1)/2;
			isfirst=true;
			cout<<endl;
			cout<<endl;
			cout<<endl;
		}
		q.pop();  
	}
}

AVLTree::~AVLTree(){//析构函数，通过后序周游进行析构 
    Stack<AVLNode *> s;
	AVLNode* root =Root;
    Stack<int> flag_s;
    while(!s.empty( )|| root){
		if(root){
	    	s.push(root);
			flag_s.push(0);
			root=root->left;
		}
	    else if(flag_s.top( )==0){
	    	flag_s.settop(1);
			root=s.top( )->right;
			}
	    else { 
	    	root=s.top();
			s.pop( );
			flag_s.pop( ); 
	    	delete root; 
	    	root=0;
	    }
	}
}


Queue::Queue(){
	myFront=myBack=0;
}

Queue::~Queue(){
	myBack=myFront;
	while (myBack){
		myBack=myBack->next;
		delete myFront;
		myFront=myBack;
	}
}

bool Queue::empty() const{
	if (myFront)return false;
	else return true;
}

void Queue::push(const QueueElement& item){
	if (myFront==0)myFront=myBack=new Node2(item,0);
	else {
		myBack->next=new Node2(item);
		myBack=myBack->next;
	} 
}

void Queue::pop(){
	Node2* node=myFront;
	myFront=myFront->next;
	delete node;
}

QueueElement Queue::front() const{
	return myFront->data;
}

QueueElement Queue::back() const{
	return myBack->data;
}
