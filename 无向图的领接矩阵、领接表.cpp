//无向图的领接矩阵存储结构
/*#include<iostream.h>
const int Max=20;
template<class T>
class MGraph
{
private:
	T vertex[Max]; //存放顶点元素
	int arc[Max][Max];   //存放边的关系
	int vertexnum,arcnum;  //顶点的个数以及边的个数
	int visited[Max];   //访问标志
public:
	MGraph(T a[],int vertexnum,int arcnum); //构造函数
	~MGraph(); //析构函数
	void DFS(int v);  //深度优先遍历
	void BFS(int v);  //广度优先遍历
	void Change();
};

template<class T>
MGraph<T>::MGraph(T a[],int vertexnum,int arcnum)
{
	this->vertexnum=vertexnum;
	this->arcnum=arcnum;
	//初始化顶点元素
	for(int i=0;i<vertexnum;i++)
	    vertex[i]=a[i];
	//输入具有边关系的两个顶点，先对二维数组进行初始化
	for(i=0;i<vertexnum;i++)
		for(int j=0;j<vertexnum;j++)
  			arc[i][j]=0;

    //输入具有联系的两条边
		cout<<"请输入具有联系的边数"<<endl;
		for(i=0;i<arcnum;i++)
		{
			int k,m;
			cin>>k>>m;
			arc[k][m]=1;
			arc[m][k]=1;
		}
	//初始化访问确定的visited
		for(i=0;i<vertexnum;i++)
			visited[i]=0;
}

//V表示顶点的下标
template<class T>
void MGraph<T>::DFS(int v)
{
	cout<<vertex[v];
	visited[v]=1;
    for(int j=0;j<vertexnum;j++)
		if(arc[v][j]==1&&visited[j]==0)
			DFS(j);
}

//v表示顶点的下标
template<class T>
void MGraph<T>::BFS(int v)
{
	int Q[Max];
    int	front,rear;
	front=rear=-1;
	cout<<vertex[v];
	visited[v]=1;
    Q[++rear]=v;            //将访问过的元素入队
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

//对visited进行重置的函数

template<class T>
void MGraph<T>::Change()
{
  for(int i=0;i<vertexnum;i++)
	  visited[i]=0;
}

//析构函数
template<class T>
MGraph<T>::~MGraph()
{
   cout<<"直接释放顶点的数组以及边关系的数组"<<endl;
   delete vertex;
   delete  arc;
   cout<<endl;
}

//主函数
void main()
{
   char a[]={'A','B','C','D','E','F','G','H'};
   int vertexnum=8;
   int arcnum=9;
   MGraph<char>MG(a,vertexnum,arcnum);
   //先进行深度优先遍历
   cout<<"请输入你要从那个顶点的下标进行深度优先遍历:"<<endl;
   int v;
   cin>>v;
   MG.DFS(v);
   cout<<endl;
   MG.Change();
   cout<<"请输入你要从那个点进行广度优先遍历:"<<endl;
   int j;
   cin>>j;
   MG.BFS(j);
   cout<<endl;
}*/


//无向图的邻接表的存储
#include<iostream.h>
//定义边表节点
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
	Vertexnode<T>adjlist[Max]; //定义一个存放顶点元素的结构体类型的数组
	int vertexnum,arcnum;//定义顶点的个数以及边的个数
	int visited[Max];  //定义一个访问标志
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
  //先对访问标志进行该表为0；
	for(int i=0;i<vertexnum;i++)
		visited[i]=0;
  //对顶点元素进行初始化
	for(i=0;i<vertexnum;i++)
	{
	   adjlist[i].vertex=a[i];
	   adjlist[i].firstedge=NULL;
	}
	cout<<"请输入具有边的两个顶点之间的下标"<<endl;
   //输入具有边关系的两个顶点
	for(int k=0;k<arcnum;k++)
	{
		int m;
		int n;
		cin>>m>>n;
		Arcnode *s=new Arcnode;
		s->adjvex=n;
        s->next=adjlist[m].firstedge;
		adjlist[m].firstedge=s;
		//还要进行再次的处理,就是边表
		s=new Arcnode;
		s->adjvex=m;
		s->next=adjlist[n].firstedge;
		adjlist[n].firstedge=s;
	}

}
//深度优先遍历
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

//广度优先遍历
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
   //先进行深度优先遍历
   cout<<"请输入你要从那个顶点的下标进行深度优先遍历:"<<endl;
   int v;
   cin>>v;
   AL.DFS(v);
   cout<<endl;
   AL.Change();
   cout<<"请输入你要从那个点进行广度优先遍历:"<<endl;
   int j;
   cin>>j;
   AL.BFS(j);
   cout<<endl;
}