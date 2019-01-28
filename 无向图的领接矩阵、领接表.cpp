//����ͼ����Ӿ���洢�ṹ
/*#include<iostream.h>
const int Max=20;
template<class T>
class MGraph
{
private:
	T vertex[Max]; //��Ŷ���Ԫ��
	int arc[Max][Max];   //��űߵĹ�ϵ
	int vertexnum,arcnum;  //����ĸ����Լ��ߵĸ���
	int visited[Max];   //���ʱ�־
public:
	MGraph(T a[],int vertexnum,int arcnum); //���캯��
	~MGraph(); //��������
	void DFS(int v);  //������ȱ���
	void BFS(int v);  //������ȱ���
	void Change();
};

template<class T>
MGraph<T>::MGraph(T a[],int vertexnum,int arcnum)
{
	this->vertexnum=vertexnum;
	this->arcnum=arcnum;
	//��ʼ������Ԫ��
	for(int i=0;i<vertexnum;i++)
	    vertex[i]=a[i];
	//������б߹�ϵ���������㣬�ȶԶ�ά������г�ʼ��
	for(i=0;i<vertexnum;i++)
		for(int j=0;j<vertexnum;j++)
  			arc[i][j]=0;

    //���������ϵ��������
		cout<<"�����������ϵ�ı���"<<endl;
		for(i=0;i<arcnum;i++)
		{
			int k,m;
			cin>>k>>m;
			arc[k][m]=1;
			arc[m][k]=1;
		}
	//��ʼ������ȷ����visited
		for(i=0;i<vertexnum;i++)
			visited[i]=0;
}

//V��ʾ������±�
template<class T>
void MGraph<T>::DFS(int v)
{
	cout<<vertex[v];
	visited[v]=1;
    for(int j=0;j<vertexnum;j++)
		if(arc[v][j]==1&&visited[j]==0)
			DFS(j);
}

//v��ʾ������±�
template<class T>
void MGraph<T>::BFS(int v)
{
	int Q[Max];
    int	front,rear;
	front=rear=-1;
	cout<<vertex[v];
	visited[v]=1;
    Q[++rear]=v;            //�����ʹ���Ԫ�����
	while(front!=rear)
	{
	  int k=Q[++front];
	  for(int i=0;i<vertexnum;i++)
	  {
		  if(arc[k][i]==1&&visited[i]==0)
		  {
			cout<<vertex[i];
			visited[i]=1;
			Q[++rear]=i;
		  }
	  }
	}

}

//��visited�������õĺ���

template<class T>
void MGraph<T>::Change()
{
  for(int i=0;i<vertexnum;i++)
	  visited[i]=0;
}

//��������
template<class T>
MGraph<T>::~MGraph()
{
   cout<<"ֱ���ͷŶ���������Լ��߹�ϵ������"<<endl;
   delete vertex;
   delete  arc;
   cout<<endl;
}

//������
void main()
{
   char a[]={'A','B','C','D','E','F','G','H'};
   int vertexnum=8;
   int arcnum=9;
   MGraph<char>MG(a,vertexnum,arcnum);
   //�Ƚ���������ȱ���
   cout<<"��������Ҫ���Ǹ�������±����������ȱ���:"<<endl;
   int v;
   cin>>v;
   MG.DFS(v);
   cout<<endl;
   MG.Change();
   cout<<"��������Ҫ���Ǹ�����й�����ȱ���:"<<endl;
   int j;
   cin>>j;
   MG.BFS(j);
   cout<<endl;
}*/


//����ͼ���ڽӱ�Ĵ洢
#include<iostream.h>
//����߱�ڵ�
const  int Max=20;
struct Arcnode
{
  int adjvex;   
  Arcnode *next;
};
template<class T>
struct Vertexnode
{
  T vertex;
  Arcnode *firstedge;
};

template<class T>
class ALGraph
{
private:
	Vertexnode<T>adjlist[Max]; //����һ����Ŷ���Ԫ�صĽṹ�����͵�����
	int vertexnum,arcnum;//���嶥��ĸ����Լ��ߵĸ���
	int visited[Max];  //����һ�����ʱ�־
public:
	ALGraph(T a[],int vertexnum,int arcnum);
	~ALGraph(){};
	void DFS(int v);
	void BFS(int v);
	void Change();
};

template<class T>
ALGraph<T>::ALGraph(T a[],int vertexnum,int arcnum)
{
	this->vertexnum=vertexnum;
	this->arcnum=arcnum;
  //�ȶԷ��ʱ�־���иñ�Ϊ0��
	for(int i=0;i<vertexnum;i++)
		visited[i]=0;
  //�Զ���Ԫ�ؽ��г�ʼ��
	for(i=0;i<vertexnum;i++)
	{
	   adjlist[i].vertex=a[i];
	   adjlist[i].firstedge=NULL;
	}
	cout<<"��������бߵ���������֮����±�"<<endl;
   //������б߹�ϵ����������
	for(int k=0;k<arcnum;k++)
	{
		int m;
		int n;
		cin>>m>>n;
		Arcnode *s=new Arcnode;
		s->adjvex=n;
        s->next=adjlist[m].firstedge;
		adjlist[m].firstedge=s;
		//��Ҫ�����ٴεĴ���,���Ǳ߱�
		s=new Arcnode;
		s->adjvex=m;
		s->next=adjlist[n].firstedge;
		adjlist[n].firstedge=s;
	}

}
//������ȱ���
template<class T>
void ALGraph<T>::DFS(int v)
{
   cout<<adjlist[v].vertex;
   visited[v]=1;
   Arcnode *p=new Arcnode;
   p=adjlist[v].firstedge;
   while(p!=NULL)
   {
    int t=p->adjvex;
	if(visited[t]==0)
       DFS(t);
	p=p->next;
   }
}

//������ȱ���
template<class T>
void ALGraph<T>::BFS(int v)
{
	int Q[Max];
	int front,rear;
	front=rear=-1;
	cout<<adjlist[v].vertex;
	visited[v]=1;
	Q[++rear]=v;
	while(front!=rear)
	{
	  int t=Q[++front];
	  Arcnode *T=new Arcnode;
	  T=adjlist[t].firstedge;
	  while(T!=NULL)
	  {
		 int k=T->adjvex;
		 if(visited[k]==0)
			{
				 cout<<adjlist[k].vertex;
				 visited[k]=1;
				 Q[++rear]=k;
			 }
	     T=T->next;
	  }
		
	}
}
template<class T>
void ALGraph<T>::Change()
{
  for(int i=0;i<vertexnum;i++)
	  visited[i]=0;
}


void main()
{

   char a[]={'A','B','C','D','E','F','G','H'};
   int vertexnum=8;
   int arcnum=9;
   ALGraph<char>AL(a,vertexnum,arcnum);
   //�Ƚ���������ȱ���
   cout<<"��������Ҫ���Ǹ�������±����������ȱ���:"<<endl;
   int v;
   cin>>v;
   AL.DFS(v);
   cout<<endl;
   AL.Change();
   cout<<"��������Ҫ���Ǹ�����й�����ȱ���:"<<endl;
   int j;
   cin>>j;
   AL.BFS(j);
   cout<<endl;
}