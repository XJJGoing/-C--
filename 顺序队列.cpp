#ifndef CirQueue_byNim
#define CirQueue_byNim

#include<iostream>
using namespace std;

const int QueueSize=100;    //ѭ�����е����洢�ռ� 
template <class T>
class CirQueue
{
    private:
        T *data;    //�洢���ݵ����� 
        int front,rear,p; //��ͷ��βָ�� 
    public:
        CirQueue();
        ~CirQueue();
        void EnQueue(T e);   //����
        T DeQueue();         //���ӣ������ض������Ԫ�ص�ֵ
        T GetQueue();        //�õ��ӵ�Ԫ��
        bool empty();        //�п�
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
    if((rear+1)%QueueSize==front)   //�������� 
        throw "����";
    rear=(rear+1)%QueueSize;
    data[rear]=e;
}

template<class T>
T CirQueue<T>::DeQueue()
{
    if(rear==front) //�ӿ����� 
        throw "����";
    front=(front+1)%QueueSize;
    return data[front];
}

template<class T>
T CirQueue<T>::GetQueue()
{
    if(rear==front) //�ӿ����� 
        throw "����";
    return data[(front+1)%QueueSize];
}

template<class T>
bool CirQueue<T>::empty()
{
    if(front==rear)   //�ӿ�������front==rear 
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
	cout<<"�õ������Ԫ��"<<endl;
	cout<<Queue.GetQueue();
	cout<<endl;
	cout<<"���Ӳ���,���ڴδ�ӡ�ö�"<<endl;
	Queue.DeQueue();
	Queue.Print();
}