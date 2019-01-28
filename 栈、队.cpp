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
    void Push(T x); //��ջԪ��
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
	cout<<"�ж��Ƿ�ջ��"<<endl;
	cout<<stack.Empty()<<endl;
	cout<<"��ջ���Ԫ�����£�"<<endl;
	stack.print();
	cout<<endl;
	cout<<"�õ�ջ��Ԫ��"<<endl;
	cout<<stack.GetTop()<<endl;
	cout<<"��ջ����,����ӡ��ջ����ڵ�Ԫ�ص�ֵ"<<endl;
	stack.Pop();
	stack.print();
	cout<<endl;
	cout<<"�������������ͷŸ���ջ,���п�"<<endl;
	stack.~LinkStack();
	cout<<stack.Empty()<<endl;
}*/

//����
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
	if(front==rear) throw" ���ӿ�";
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
 cout<<"��10,20,30,40��ӣ�����ӡ��Ӻ��Ԫ�����£�"<<endl;
 queue.print();
 cout<<endl;
 cout<<"ȡ��ͷԪ�أ�"<<queue.GetQueue()<<endl;
 cout<<"���Ӳ���������������ӵ�Ԫ�ز����ظ�Ԫ��"<<queue.DeQueue()<<endl;
 cout<<"��ӡ���Ӻ�Ķ��е�Ԫ�ص�ֵ:"<<endl;
 queue.print();
 cout<<endl;
 cout<<"�ж϶����Ƿ�Ϊ��:"<<queue.Empty()<<endl;
}*/


//������
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
    void Push(T x); //��ջԪ��
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
	cout<<"�ж��Ƿ�ջ��"<<endl;
	cout<<stack.Empty()<<endl;
	cout<<"��ջ���Ԫ�����£�"<<endl;
	stack.print();
	cout<<endl;
	cout<<"�õ�ջ��Ԫ��"<<endl;
	cout<<stack.GetTop()<<endl;
	cout<<"��ջ����,����ӡ��ջ����ڵ�Ԫ�ص�ֵ"<<endl;
	stack.Pop();
	stack.print();
	cout<<endl;
	cout<<"�������������ͷŸ���ջ,���п�"<<endl;
	stack.~LinkStack();
	cout<<stack.Empty()<<endl;
}*/

//������
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
	if(front==rear) throw" ���ӿ�";
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
 cout<<"��10,20,30,40��ӣ�����ӡ��Ӻ��Ԫ�����£�"<<endl;
 queue.print();
 cout<<endl;
 cout<<"ȡ��ͷԪ�أ�"<<queue.GetQueue()<<endl;
 cout<<"���Ӳ���������������ӵ�Ԫ�ز����ظ�Ԫ��"<<queue.DeQueue()<<endl;
 cout<<"��ӡ���Ӻ�Ķ��е�Ԫ�ص�ֵ:"<<endl;
 queue.print();
 cout<<endl;
 cout<<"�ж϶����Ƿ�Ϊ��:"<<queue.Empty()<<endl;

}
*/