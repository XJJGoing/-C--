/*#include<iostream.h>

template<class T>
struct Node
{
  T date;
  Node<T>*next;
};

template<class T>
class LinkStack
{
private:
	Node<T>*top,*s,*t,*h,*p;
public:
	LinkStack(){top=NULL;}
    void Push(T x); //入栈元素
	T Pop();
	T GetTop();
	int Empty();
	~LinkStack();
	void print();
};
template<class T>
void LinkStack<T>::Push(T x)
{
    s=new Node<T>;
	s->date=x;
	s->next=top;
	top=s;
}
template<class T>
T LinkStack<T>::Pop()
{
   if(top==NULL) return 0;
   T x;
   p=new Node<T>;
   p=top;
   x=p->date;
   top=top->next;
   delete p;
   return x;
}
template<class T>
T LinkStack<T>::GetTop(){
  return top->date;
}

template<class T>
int LinkStack<T>::Empty()
{
 if(top==NULL) return 0;
    return 1;
}

template<class T>
LinkStack<T>::~LinkStack()
{
	t=new Node<T>;
	while(top!=NULL)
	{
	 t=top;
	 top=top->next;
	 delete t;
	}
}

template<class T>
void LinkStack<T>::print()
{
	h=new Node<T>;
	h=top;
	while(h!=NULL)
	{
	 cout<<h->date<<" ";
	 h=h->next;
	}
}

void main()
{
	LinkStack<int>stack;
	stack.Push(10);
	stack.Push(20);
	stack.Push(30);
	stack.Push(40);
	cout<<"判断是否栈空"<<endl;
	cout<<stack.Empty()<<endl;
	cout<<"入栈后的元素如下："<<endl;
	stack.print();
	cout<<endl;
	cout<<"得到栈顶元素"<<endl;
	cout<<stack.GetTop()<<endl;
	cout<<"出栈操作,并打印出栈后各节点元素的值"<<endl;
	stack.Pop();
	stack.print();
	cout<<endl;
	cout<<"调用析构函数释放改链栈,并判空"<<endl;
	stack.~LinkStack();
	cout<<stack.Empty()<<endl;
}*/

//链队
/*#include<iostream.h>
template<class T>
struct Node
{
  T date;
  Node<T> *next; 
};
template<class T>
class LinkQueue
{	
private:
	Node<T>*front,*rear,*s;
public:
	LinkQueue();
	void EnQueue(T x);
	T DeQueue();
	T GetQueue();
	int Empty();
	void print();
};

template<class T>
LinkQueue<T>::LinkQueue()
{
 s=new Node<T>;
 s->next=NULL;
 front=rear=s;
}

template<class T>
void LinkQueue<T>::EnQueue(T x)
{
  s=new Node<T>;
  s->date=x;
  s->next=NULL;
  rear->next=s;
  rear=s;
}

template<class T>
T LinkQueue<T>::DeQueue()
{ 
  T x;
  s=new Node<T>;
  if(front==rear) return 0;
  s=front->next;
  x=s->date;
  front->next=s->next;
  delete s;
  return x;
}

template<class T>
T LinkQueue<T>::GetQueue()
{
 s=new Node<T>;
 T x;
 s=front->next;
 x=s->date;
 return x;
}

template<class T>
int LinkQueue<T>::Empty()
{
 if(front==rear)
	 return 0;
 return 1;
}

template<class T>
void LinkQueue<T>::print()
{
	if(front==rear) throw" 链队空";
	s=new Node<T>;
	s=front->next;
	while(s!=NULL)
	{
	  cout<<s->date<<" ";
	  s=s->next;
	}

} 
void main()
{
 LinkQueue<int>queue;
 queue.EnQueue(10);
 queue.EnQueue(20);
 queue.EnQueue(30);
 queue.EnQueue(40);
 cout<<"将10,20,30,40入队，并打印入队后的元素如下："<<endl;
 queue.print();
 cout<<endl;
 cout<<"取队头元素："<<queue.GetQueue()<<endl;
 cout<<"出队操作，出了最先入队的元素并返回该元素"<<queue.DeQueue()<<endl;
 cout<<"打印出队后的队列的元素的值:"<<endl;
 queue.print();
 cout<<endl;
 cout<<"判断队列是否为空:"<<queue.Empty()<<endl;
}*/


//链队列
/*#include<iostream.h>

template<class T>
struct Node
{
  T date;
  Node<T>*next;
};

template<class T>
class LinkStack
{
private:
	Node<T>*top,*s,*t,*h,*p;
public:
	LinkStack(){top=NULL;}
    void Push(T x); //入栈元素
	T Pop();
	T GetTop();
	int Empty();
	~LinkStack();
	void print();
};
template<class T>
void LinkStack<T>::Push(T x)
{
    s=new Node<T>;
	s->date=x;
	s->next=top;
	top=s;
}
template<class T>
T LinkStack<T>::Pop()
{
   if(top==NULL) return 0;
   T x;
   p=new Node<T>;
   p=top;
   x=p->date;
   top=top->next;
   delete p;
   return x;
}
template<class T>
T LinkStack<T>::GetTop(){
  return top->date;
}

template<class T>
int LinkStack<T>::Empty()
{
 if(top==NULL) return 0;
    return 1;
}

template<class T>
LinkStack<T>::~LinkStack()
{
	t=new Node<T>;
	while(top!=NULL)
	{
	 t=top;
	 top=top->next;
	 delete t;
	}
}

template<class T>
void LinkStack<T>::print()
{
	h=new Node<T>;
	h=top;
	while(h!=NULL)
	{
	 cout<<h->date<<" ";
	 h=h->next;
	}
}

void main()
{
	LinkStack<int>stack;
	stack.Push(10);
	stack.Push(20);
	stack.Push(30);
	stack.Push(40);
	cout<<"判断是否栈空"<<endl;
	cout<<stack.Empty()<<endl;
	cout<<"入栈后的元素如下："<<endl;
	stack.print();
	cout<<endl;
	cout<<"得到栈顶元素"<<endl;
	cout<<stack.GetTop()<<endl;
	cout<<"出栈操作,并打印出栈后各节点元素的值"<<endl;
	stack.Pop();
	stack.print();
	cout<<endl;
	cout<<"调用析构函数释放改链栈,并判空"<<endl;
	stack.~LinkStack();
	cout<<stack.Empty()<<endl;
}*/

//链队列
/*#include<iostream.h>
template<class T>
struct Node
{
  T date;
  Node<T> *next; 
};
template<class T>
class LinkQueue
{	
private:
	Node<T>*front,*rear,*s;
public:
	LinkQueue();
	void EnQueue(T x);
	T DeQueue();
	T GetQueue();
	int Empty();
	void print();
};

template<class T>
LinkQueue<T>::LinkQueue()
{
 s=new Node<T>;
 s->next=NULL;
 front=rear=s;
}

template<class T>
void LinkQueue<T>::EnQueue(T x)
{
  s=new Node<T>;
  s->date=x;
  s->next=NULL;
  rear->next=s;
  rear=s;
}

template<class T>
T LinkQueue<T>::DeQueue()
{ 
  T x;
  s=new Node<T>;
  if(front==rear) return 0;
  s=front->next;
  x=s->date;
  front->next=s->next;
  delete s;
  return x;
}

template<class T>
T LinkQueue<T>::GetQueue()
{
 s=new Node<T>;
 T x;
 s=front->next;
 x=s->date;
 return x;
}

template<class T>
int LinkQueue<T>::Empty()
{
 if(front==rear)
	 return 0;
 return 1;
}

template<class T>
void LinkQueue<T>::print()
{
	if(front==rear) throw" 链队空";
	s=new Node<T>;
	s=front->next;
	while(s!=NULL)
	{
	  cout<<s->date<<" ";
	  s=s->next;
	}

} 
void main()
{
 LinkQueue<int>queue;
 queue.EnQueue(10);
 queue.EnQueue(20);
 queue.EnQueue(30);
 queue.EnQueue(40);
 cout<<"将10,20,30,40入队，并打印入队后的元素如下："<<endl;
 queue.print();
 cout<<endl;
 cout<<"取队头元素："<<queue.GetQueue()<<endl;
 cout<<"出队操作，出了最先入队的元素并返回该元素"<<queue.DeQueue()<<endl;
 cout<<"打印出队后的队列的元素的值:"<<endl;
 queue.print();
 cout<<endl;
 cout<<"判断队列是否为空:"<<queue.Empty()<<endl;

}
*/