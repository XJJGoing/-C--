#include<iostream.h>
const int Max=32;
template<typename T>
struct biNode{
	T data;
	biNode<T> *lChild,*rChild;
};
template<typename T>
class biTree{
	biNode<T> *root;
public:
	biNode<T> *getRoot(){ return root;}
	biTree();//构造函数，初始化二叉链表
	~biTree();//析构函数，释放二叉链表中的结点
	void release(biNode<T> *rt);
	//释放以rt所指向的结点为根结点的二叉树
	void preOrder(biNode<T> *rt);
	//对以rt所指向的结点为根结点的二叉树进行前序遍历
	void inOrder(biNode<T> *rt);
	//对以rt所指向的结点为根结点的二叉树进行中序遍历
	void postOrder(biNode<T> *rt);
	//对以rt所指向的结点为根结点的二叉树进行后序遍历
	void leverOrder();      //层序遍历
	int BiHight(biNode<T> *rt);         //求树的高度的函数
	int LeafNumber(biNode<T> *rt);     //求叶节点的个数的函数
	int AllNode(biNode<T> *rt);         //求所有节点个数的函数
};

//前序遍历
template<typename T>
void biTree<T>::preOrder(biNode<T> *rt){
	if(rt){
		cout<<rt->data;//访问根结点
		preOrder(rt->lChild);//先序遍历左子树
		preOrder(rt->rChild);//先序遍历右子树
	}
	//else return;
}
//中序遍历
template<typename T>
void biTree<T>::inOrder(biNode<T> *rt){
	if(rt){
		inOrder(rt->lChild);//中序遍历左子树
		cout<<rt->data;//访问根结点
		inOrder(rt->rChild);//中序遍历右子树
	}
	//else return;
}
//后序遍历
template<typename T>
void biTree<T>::postOrder(biNode<T> *rt){
	if(rt){
		postOrder(rt->lChild);//后序遍历左子树
		postOrder(rt->rChild);//后序遍历右子树
		cout<<rt->data;//访问根结点
	}
	//else return;
}
template<typename T>
void biTree<T>::release(biNode<T> *rt){
	if(rt){
		release(rt->lChild);//释放左子树
		release(rt->rChild);//释放右子树
		delete rt;//释放根结点
	}
}

template<typename T>
biTree<T>::~biTree(){
	release(root);
	cout<<"释放完毕"<<endl;
}
//构造数组
template<typename T>
biTree<T>::biTree(){
	cout<<"通过增加虚结点变成完全二叉树，";
	cout<<"按完全二叉树层序遍历的序列，";
	cout<<"依次输入每个结点名称，虚结点用'@'表示，";
	cout<<"结束用'#'表示,建立二叉链表\n";
	biNode<T> *Q[Max];
	int front=1,rear=0;
	//front表示当前结点的双亲结点在队列中的下标
    //rear表示当前产生结点的层序编号
	char ch;//存放从键盘输入的字符值
	cin>>ch;
	if(ch=='#'){ biNode<T> *root=NULL;cout<<"该树为空树，无法进行以下操作"<<endl; return;}
	while(ch!='#'){
		biNode<T> *s=NULL;
		if(ch!='@'){
			s=new biNode<T>;
			s->data=ch;
			s->rChild=s->lChild=NULL;
		}
		//将s入队
		Q[++rear]=s;
		if(rear==1) root=s;
		else{
			if(s)
				if(rear%2==0)
					Q[front]->lChild=s;
				else
					Q[front]->rChild=s;
			if(rear%2==1) front++;
		}
		cin>>ch;
	}
}

//层序遍历           //画图理解
template<typename T>
void biTree<T>::leverOrder(){
	biNode<T> *Q[Max];
	int front=-1,rear=-1;
	if(root) Q[++rear]=root;
	while(front!=rear){
		biNode<T> *s=Q[++front];
		cout<<s->data;
		if(s->lChild) Q[++rear]=s->lChild;
		if(s->rChild) Q[++rear]=s->rChild;
	}
	cout<<endl;
}

//求树的高度
template<typename T>
int biTree<T>::BiHight(biNode<T> *rt)
{
  if(!rt) return 0;
  if(!(rt->lChild)&&!(rt->rChild)) return 1;  
  else
  {
	  int h1=BiHight(rt->lChild);
      int h2=BiHight(rt->rChild);
      return h1>=h2?h1+1:h2+1;
  }
}

//求树的叶子节点
template<typename T>
int biTree<T>::LeafNumber(biNode<T> *rt)
{
	if(!rt) return 0;
	if(!(rt->lChild)&&!(rt->rChild)) return 1;
	else
	{
      return LeafNumber(rt->lChild)+LeafNumber(rt->rChild);
	}
	
}

//求树的所有节点的个数,  记录返回0的个数
template<typename T>
int biTree<T>::AllNode(biNode<T> *rt)
{
	if(!rt) return 0;
	int leaf=AllNode(rt->lChild);
	int right=AllNode(rt->rChild);
	return leaf+right+1;
}



void main(){
	cout<<"请输入一颗树，按照层序输入从左到右的输入方法"<<endl;
	biTree<char> bt;
	cout<<"前序遍历序列：";
	bt.preOrder(bt.getRoot());
	cout<<endl;
	cout<<"中序遍历序列：";
	bt.inOrder(bt.getRoot());
	cout<<endl;
	cout<<"后序遍历序列：";
	bt.postOrder(bt.getRoot());
	cout<<endl;
	cout<<"层序遍历序列：";
	bt.leverOrder();
	cout<<endl;
	cout<<"树的高度：";
    cout<<bt.BiHight(bt.getRoot())<<endl;
	cout<<"树的叶子节点数：";
	cout<<bt.LeafNumber(bt.getRoot())<<endl;
	cout<<"所有节点的个数：";
	cout<<bt.AllNode(bt.getRoot())<<endl;
	cout<<"释放该二叉树：";
	bt.~biTree();
}
