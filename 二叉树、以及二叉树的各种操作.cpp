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
	biTree();//���캯������ʼ����������
	~biTree();//�����������ͷŶ��������еĽ��
	void release(biNode<T> *rt);
	//�ͷ���rt��ָ��Ľ��Ϊ�����Ķ�����
	void preOrder(biNode<T> *rt);
	//����rt��ָ��Ľ��Ϊ�����Ķ���������ǰ�����
	void inOrder(biNode<T> *rt);
	//����rt��ָ��Ľ��Ϊ�����Ķ����������������
	void postOrder(biNode<T> *rt);
	//����rt��ָ��Ľ��Ϊ�����Ķ��������к������
	void leverOrder();      //�������
	int BiHight(biNode<T> *rt);         //�����ĸ߶ȵĺ���
	int LeafNumber(biNode<T> *rt);     //��Ҷ�ڵ�ĸ����ĺ���
	int AllNode(biNode<T> *rt);         //�����нڵ�����ĺ���
};

//ǰ�����
template<typename T>
void biTree<T>::preOrder(biNode<T> *rt){
	if(rt){
		cout<<rt->data;//���ʸ����
		preOrder(rt->lChild);//�������������
		preOrder(rt->rChild);//�������������
	}
	//else return;
}
//�������
template<typename T>
void biTree<T>::inOrder(biNode<T> *rt){
	if(rt){
		inOrder(rt->lChild);//�������������
		cout<<rt->data;//���ʸ����
		inOrder(rt->rChild);//�������������
	}
	//else return;
}
//�������
template<typename T>
void biTree<T>::postOrder(biNode<T> *rt){
	if(rt){
		postOrder(rt->lChild);//�������������
		postOrder(rt->rChild);//�������������
		cout<<rt->data;//���ʸ����
	}
	//else return;
}
template<typename T>
void biTree<T>::release(biNode<T> *rt){
	if(rt){
		release(rt->lChild);//�ͷ�������
		release(rt->rChild);//�ͷ�������
		delete rt;//�ͷŸ����
	}
}

template<typename T>
biTree<T>::~biTree(){
	release(root);
	cout<<"�ͷ����"<<endl;
}
//��������
template<typename T>
biTree<T>::biTree(){
	cout<<"ͨ��������������ȫ��������";
	cout<<"����ȫ������������������У�";
	cout<<"��������ÿ��������ƣ�������'@'��ʾ��";
	cout<<"������'#'��ʾ,������������\n";
	biNode<T> *Q[Max];
	int front=1,rear=0;
	//front��ʾ��ǰ����˫�׽���ڶ����е��±�
    //rear��ʾ��ǰ�������Ĳ�����
	char ch;//��ŴӼ���������ַ�ֵ
	cin>>ch;
	if(ch=='#'){ biNode<T> *root=NULL;cout<<"����Ϊ�������޷��������²���"<<endl; return;}
	while(ch!='#'){
		biNode<T> *s=NULL;
		if(ch!='@'){
			s=new biNode<T>;
			s->data=ch;
			s->rChild=s->lChild=NULL;
		}
		//��s���
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

//�������           //��ͼ���
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

//�����ĸ߶�
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

//������Ҷ�ӽڵ�
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

//���������нڵ�ĸ���,  ��¼����0�ĸ���
template<typename T>
int biTree<T>::AllNode(biNode<T> *rt)
{
	if(!rt) return 0;
	int leaf=AllNode(rt->lChild);
	int right=AllNode(rt->rChild);
	return leaf+right+1;
}



void main(){
	cout<<"������һ���������ղ�����������ҵ����뷽��"<<endl;
	biTree<char> bt;
	cout<<"ǰ��������У�";
	bt.preOrder(bt.getRoot());
	cout<<endl;
	cout<<"����������У�";
	bt.inOrder(bt.getRoot());
	cout<<endl;
	cout<<"����������У�";
	bt.postOrder(bt.getRoot());
	cout<<endl;
	cout<<"����������У�";
	bt.leverOrder();
	cout<<endl;
	cout<<"���ĸ߶ȣ�";
    cout<<bt.BiHight(bt.getRoot())<<endl;
	cout<<"����Ҷ�ӽڵ�����";
	cout<<bt.LeafNumber(bt.getRoot())<<endl;
	cout<<"���нڵ�ĸ�����";
	cout<<bt.AllNode(bt.getRoot())<<endl;
	cout<<"�ͷŸö�������";
	bt.~biTree();
}
