//顺序表
#include<iostream.h>
const int Max=10;
template<class T>
class SeqList
{
private:
	T date[Max];
	int lenght;
public:
	 SeqList(){lenght=0;}
	 SeqList(T a[],int n);
	 int Len();
     bool empty();
     void Get(int i);
	 void Insert(T x,int i);
	 T Delete(int i);
	 void print();
};
template<class T>   
SeqList<T>::SeqList(T a[],int n)
{
	  if(n>Max) throw"参数不正当";
	  cout<<endl;
	  for(int i=0;i<n;i++)
	    date[i]=a[i];
	  lenght=n;
}
template<class T>  
int SeqList<T>::Len()
{
	 int count=0;
	 for(int i=0;i<lenght;i++)
		 count++;
	 return count;
}
template<class T>  
bool SeqList<T>::empty(){
	 if(lenght==0)
		 return 0;
	 return 1;
}
template<class T>  
//取值函数，i代表寻找的位置
void SeqList<T>::Get(int i)
{
	  if(empty()==0) cout<<"表空";
	  if(i<1||i>lenght) cout<< "位置不正当";
	  else cout<<date[i-1];
}
template<class T>  	//插入函数,i代表插入的位置
void SeqList<T>::Insert(T x,int i)
{
		if(lenght==Max) cout<<"表满";
	    if(i<1||i>lenght+1) cout<< "插入位置不正确";
		else 
		{
		  for(int j=lenght-1;j>=i-1;j--)
		   date[j+1]=date[j];
		   date[i-1]=x;
		   lenght++;
		}
}
template<class T>  	//删除元素，将第i个元素删除，并返回删除的函数
T SeqList<T>::Delete(int i)
{
		T x;
		if(empty()==0) throw"表空";
		cout<<endl;
		if(i<1||i>=lenght+1) throw"位置不正常";
		cout<<endl;
		x=date[i-1];
		for(int j=i-1;j<=lenght-2;j++)
			date[j]=date[j+1];
		lenght--;
		return x;
}
template<class T>  
void SeqList<T>::print()
{
	  for(int i=0;i<lenght;i++)
		  cout<<date[i]<<" ";
}
void main()
{
	int a[]={1,2,3,4,5,6,7};
	int n=7;
	SeqList<int>seq(a,n);
	cout<<"打印出来该顺序表:"<<endl;
	seq.print();
	cout<<endl;
    cout<<"表判空函数"<<seq.empty()<<endl;
	cout<<"表长为："<<seq.Len()<<endl;
	cout<<"寻找第三个位置的元素："<<endl;
	seq.Get(3);
	cout<<endl;
	cout<<"寻找第10 个位置的元素"<<endl;
	seq.Get(10);
	cout<<endl;
	cout<<"寻找第0个位置的元素"<<endl;
	seq.Get(0);
	cout<<endl;
	cout<<"在第0个位置插入一个T类型的值为20的元素"<<endl;
	seq.Insert(20,0);
	cout<<endl;
	cout<<"在第10个位置插入一个T类型的值为20的元素"<<endl;
	seq.Insert(20,0);
	cout<<endl;
	cout<<"在第四个位置插入一个T类型的值为10的元素,插入后打印出该表"<<endl;
	seq.Insert(10,4);
	seq.print();
	cout<<endl;
	cout<<"删除第四个位置的元素,并返回删除元素的值:"<<seq.Delete(4)<<endl;
	cout<<"打印删除后的顺序表："<<endl;
	seq.print();
	cout<<endl;
}




//单链表的的链表模式
#include<iostream>
using namespace std;
//结构体
template<class T>
struct STU
{
	T data;
	STU<T>*next;
};

template<class T>
class LinkList
{
private:
	STU<T>*head, *p, *s,*t,*u;
	int n;
public:
	LinkList(T a[], int n);           //将数组里面的元素初始化data
	~LinkList();                    //析构函数。
	int Length();                   //求该链表的长度
	T Get(int i);         //查找第 i个节点的位置的元素的值
	int Locate(T x);      //查找元素x的所在的位置
	void Insert(int i, T y);   //在i的位置插入某个元素
	void Delete(int i);     //删除元素，删除第几个位置的元素
	void PrintList();       //打印该链表；

};

//头插法建立链表
template<class T>
LinkList<T>::LinkList(T a[], int n)
{
	this->n = n;
	head = new STU<T>;
	head->next=NULL;
	for (int i = 0; i<n; i++)
	{   
		s = new STU<T>;
		s->data = a[i];
		s->next=head->next;
		head->next=s;
	}
}

//求链表的长度（不包括头结点的求长度）
template <class T>
int LinkList<T>::Length()
{
	p = head->next;
	int count = 1;
	while (p->next!=NULL)
	{
		p = p->next;
		count++;
	}
	return count;
}


//查找第i个位置的元素的值
template<class T>
T LinkList<T>::Get(int i)
{
	if (i<1 || i>n) throw " 位置异常";
	int j = 1;
	p = head->next;
	T num;
	while (j!= i)
	{
		num = p->data;
		p = p->next;
		j++;
	}
	return	num;

}

//查找元素X的位置
template<class T>
int LinkList<T>::Locate(T x)
{
	p = head->next;
	int i = 1;
	while(p!=NULL&&p->data!=x)
	{
	  p=p->next;
	  i++;
	}
	if(!p) throw"找不到该元素";
	return i;
}


//在i的位置插入一个值y
template<class T>
void LinkList<T>::Insert(int i, T y)
{
	p = head->next;
	int count = 1;
	while (p!=NULL&&count<i-1)     //找到i这个节点
	{
		p = p->next;
		count++;
	}
	if (p == NULL) throw "找不到插入的位置";  //找不到i这个点
	else
	{
		s = new STU<T>;
		s->data = y;
		s->next = p->next;
		p->next = s;
		n++;           
	}

}


//删除某个位置的元素
template<class T>
void LinkList<T>::Delete(int i)
{
	p = head->next;
	int j = 1;
	if(i<1||i>n)  throw"删除异常";
    while (j<i-1)     //找到前一个节点
	{
		p = p->next;
		j++;
	}
	t=p->next;
    p->next=t->next;
    delete t;
	n--;
}

//打印这张表

template<class T>
void LinkList<T>::PrintList()
{
	p = head->next;
	cout << "打印的表如下" << endl;
	for (int i = 0; i<n; i++)
	{
		cout << p->data << '\t';
		p = p->next;
	}
}

template <class T>

LinkList<T>::~LinkList()
{
   p=head->next;
  while(p!=NULL)
  {
	   u=p;
	   p=p->next;
       delete u;
  }
  cout<<"释放完毕"<<endl;
}

//主函数

void main()
{
	int n = 5;
	int test[5] = { 1, 2, 3, 4, 5 };
	LinkList<int>List(test, n);
	List.PrintList();
	cout << endl;
	cout << "表的长度" << endl;
	cout << List.Length();
	cout << endl;
	cout << "找到第三个位置的元素的值" << endl;
	cout << List.Get(3);
	cout << endl;
	cout << "查找元素值为4的位置" << endl;
	cout << List.Locate(4);
	cout << endl;
	cout << "插入一个元素 插入2到第二个位置";
	List.Insert(2, 2);
	cout << endl;
	cout << "再次打印这List" << endl;
	List.PrintList();
	cout << endl;
	cout << "删除第二个位置的元素" << endl;
	List.Delete(2);
	cout << endl;
	cout << "再次打印这张List" << endl;
	List.PrintList();
	cout<<endl;
	cout<<"调用析构函数释放整条链表"<<endl;
	List.~LinkList();

}