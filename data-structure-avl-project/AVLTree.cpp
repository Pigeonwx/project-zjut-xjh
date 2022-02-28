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
AVLTree::AVLTree(){//�޲ι��캯��
	fstream fin;
	fin.open("data.txt",ios::in);
	assert(fin.is_open());
	DataType username,password;//�����û��������룬����ʹ���û�����Ϊ����ƽ�����Ľڵ�ֵ 
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
	int lf=0;       //��¼��һ���жϵ��ƶ�����1������2������ 
	
	//ȷ��Ӧ�ñ��ҵ�λ�� 
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
	
	//�����½ڵ� 
	AVLNode* newptr;//ָ�򱻹ҵ��½ڵ㣬Ϊ������׼�� 
	if (lf==1){
	preptr->left=new AVLNode(username,password,preptr);
	newptr=preptr->left;
	}
	else if (lf==2){
	preptr->right=new AVLNode(username,password,preptr);
	newptr=preptr->right;
	}
	
	//��ʼ���ݣ�ȷ�����������½ڵ�������ڵ��ߵĸı� 
	int direction1=0,direction2=0;//��ʾ���ֲ�ƽ��ڵ���������ķ���1������2������ 
	AVLNode *inspect=0;//����ָ��ƽ��㣬��ƽ������factor=2��-2�Ľڵ� 
	while(newptr->usernamedata!=Root->usernamedata){
		if (newptr->usernamedata < newptr->father->usernamedata){//�½ڵ������������� 
			direction2=direction1;
			direction1=1;
			newptr->father->Lhight++;//�������� 
			newptr->father->factor=newptr->father->Lhight-newptr->father->Rhight;
			if (newptr->father->factor==2){inspect=newptr->father;break;}
			if (newptr->father->Lhight > newptr->father->Rhight){newptr->father->hight++;}//���ӽ������ 
			else break;
			newptr=newptr->father; 
		}
		else if(newptr->usernamedata > newptr->father->usernamedata){//�½ڵ�������������
			direction2=direction1;
			direction1=2;
			newptr->father->Rhight++;//�Ҳ������ 
			newptr->father->factor=newptr->father->Lhight-newptr->father->Rhight;
			if (newptr->father->factor==-2){inspect=newptr->father;break;}
			if (newptr->father->Lhight < newptr->father->Rhight){newptr->father->hight++;}
			else break;
			newptr=newptr->father; 
		}
	}
	
	//�ж��Ƿ���Ҫƽ�⻯�����Ƿ���Ҫ��ת 
	if (inspect!=0){
		int flf=0;             //�жϲ�ƽ�ȵ����丸�׵����������������� ��1������2������ 
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
		cout<<"��ǰע���û���Ϊ�㣬ɾ��ʧ��"<<endl;
		return;
	} 

	//Ѱ�Ҵ�ɾ�ڵ� 
	AVLNode* ptr=Root,*preptr=Root;
	int lf=0;       //��¼��һ���жϵ��ƶ�����1������2������
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
	if (ptr==0){cout<<"δ�ҵ����û�����ɾ��ʧ��"<<endl;return;}
	
	//ɾ���ڵ� 
	bool isgen=false;
	if (ptr->left==0 || ptr->right==0){//��ɾ�ڵ�û������������ֻ����������ֻ��������
		if (ptr->left==0){
			if (lf==0){Root=ptr->right;isgen=true;}//����ɾ�ڵ�������ʱ
			else if (lf==1){preptr->left=ptr->right;}
			else if (lf==2){preptr->right=ptr->right;}
		}
		else {
			if (lf==0){Root=ptr->left;isgen=true;}//����ɾ�ڵ�������ʱ
			else if (lf==1){preptr->left=ptr->left;}
			else if (lf==2){preptr->right=ptr->left;}
		}
		
		AVLNode* temp=ptr;
		if (!isgen){ 
		//��ʼ���� 
		AVLNode *inspect=0;//����ָ��ƽ��㣬��ƽ������factor=2��-2�Ľڵ� 
		lf=0;//������ʾɾ���Ľڵ��ڲ�ƽ�����������л�����������  
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
		
	    //�ж��Ƿ���Ҫƽ�⻯�����Ƿ���Ҫ��ת 
		if (inspect!=0){
			int flf=0;             //�жϲ�ƽ�ȵ����丸�׵����������������� ��1������2������ 
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
		delete temp;cout<<"ɾ���ɹ���"<<endl;
	}
	else {//��ɾ�ڵ���������Ҳ�������� 
		DataType repassword;
		Stack<AVLNode*> s;
		AVLNode* root =Root;
		while(!s.empty()|| root) 
		{//ͨ������������ҵ�����ڵ� 
			if(root){
				s.push(root);
				root=root->left; }
			else{
				root=s.top(); 
				s.pop();
				if (s.top()->usernamedata == ptr->usernamedata){//�ҵ�����ǰ����������ڵ� 
					username=root->usernamedata;//��¼����ڵ������ 
					repassword=root->passworddata;
					break;
				} 
				root=root->right;}
		}
		remove(username);//ɾ������ڵ� 
		ptr->usernamedata=username;//������ڵ��ֵд��ԭ���Ĵ�ɾ�ڵ�
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
	
	//�Բ�ߵĵ��� 
	a->Rhight=b->Lhight;
	if (a->Lhight >= a->Rhight)a->hight=a->Lhight+1;
	else if (a->Lhight < a->Rhight)a->hight=a->Rhight+1;
	b->Lhight=a->hight;
	if (b->Lhight >= b->Rhight)b->hight=b->Lhight+1;
	else if (b->Lhight < b->Rhight)b->hight=b->Rhight+1;
	
	//��ʼƽ�⻯����
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
	
	//�Բ�ߵĵ��� 
	a->Lhight=b->Rhight;
	if (a->Lhight >= a->Rhight)a->hight=a->Lhight+1;
	else if (a->Lhight < a->Rhight)a->hight=a->Rhight+1;
	b->Rhight=a->hight;
	if (b->Lhight >= b->Rhight)b->hight=b->Lhight+1;
	else if (b->Lhight < b->Rhight)b->hight=b->Rhight+1;
	
	//��ʼƽ�⻯����
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

void AVLTree::display(){//ǰ����������AVLTree������̨ 
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


void AVLTree::display2(){//ǰ����������AVLTree���ļ� 
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

void AVLTree::graph(){//�������������
	int width=0,newwidth=0;			//������ò�����εķ�����ͨ��������жϼ����� 
	int Hight=Root->hight;
	for (int i=0,plus=1;i<Hight;i++,plus*=2)
		width+=plus;//���㣬��ǰ��������������Ķ������������нڵ�ĸ��� 
	
	//�������нڵ���ֵ�ĳ��ȵ����ֵ��ͨ��ǰ�����ν��б���
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
	AVLNode* last=Root;//��⵱ǰ�ڵ��Ƿ��Ǹò�����һ���ڵ� 
	bool isfirst=true;//�ж��Ƿ���ÿ��ĵ�һ������ 
	int hight=1; //��ǰ����Ĳ��� 
	while (!q.empty()){
		AVLNode* root2=q.front();
		if (isfirst){isfirst=false;newwidth=(width+1)/2;}
		else newwidth=width;
		if (root2->usernamedata!=""){//���ڵ�ֵ��Ϊ�մ�ʱ�����������ӽڵ��������� 
			cout<<setw(maxlen*newwidth)<<root2->usernamedata;
		}
		else cout<<setw(maxlen*newwidth)<<"";
		if(root2->left)
			q.push(root2->left);
		else q.push(new AVLNode());//����ڵ�Ϊ�գ���newһ���մ��ڵ������� 
		if(root2->right)
			q.push(root2->right);
		else q.push(new AVLNode());//����ڵ�Ϊ�գ���newһ���մ��ڵ������� 
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

AVLTree::~AVLTree(){//����������ͨ���������ν������� 
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
