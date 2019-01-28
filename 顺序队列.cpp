#ifndef CirQueue_byNim
#define CirQueue_byNim

#include<iostream>
using namespace std;

const int QueueSize=100;    //循环队列的最大存储空间 
template <class T>
class CirQueue
{
    private:
        T *data;    //存储数据的数组 
        int front,rear,p; //队头队尾指针 
    public:
        CirQueue();
        ~CirQueue();
        void EnQueue(T e);   //进队
        T DeQueue();         //出队，并返回队里面的元素的值
        T GetQueue();        //得到队的元素
        bool empty();        //判空
		void Print();
};

template<class T>
CirQueue<T>::CirQueue()
{
    data=new T[QueueSize];
    front=rear=0;
}

template<class T>
CirQueue<T>::~CirQueue()
{
    delete []data;
    front=rear=0;
}

template<class T>
void CirQueue<T>::EnQueue(T e)
{
    if((rear+1)%QueueSize==front)   //队满条件 
        throw "上溢";
    rear=(rear+1)%QueueSize;
    data[rear]=e;
}

template<class T>
T CirQueue<T>::DeQueue()
{
    if(rear==front) //队空条件 
        throw "下溢";
    front=(front+1)%QueueSize;
    return data[front];
}

template<class T>
T CirQueue<T>::GetQueue()
{
    if(rear==front) //队空条件 
        throw "下溢";
    return data[(front+1)%QueueSize];
}

template<class T>
bool CirQueue<T>::empty()
{
    if(front==rear)   //队空条件：front==rear 
        return true;
    return false;
}

template<class T>
void CirQueue<T>::Print()
{
    p=front;
	while(p!=rear)
	{
       cout<<data[(p+1)%QueueSize]<<" "; 
	   p++;
	}

}
#endif
void main()
{
	CirQueue<int>Queue;
    Queue.EnQueue(1);
    Queue.EnQueue(2);
    Queue.EnQueue(3);
	Queue.EnQueue(4);
	Queue.EnQueue(5);
	Queue.Print();
	cout<<endl;
	cout<<"得到队里的元素"<<endl;
	cout<<Queue.GetQueue();
	cout<<endl;
	cout<<"出队操作,并在次打印该队"<<endl;
	Queue.DeQueue();
	Queue.Print();
}