//����ת�þ���
#include<iostream.h>
const int  Max=10;
template<typename T>
struct element
{
 T item;
 int row,col;
};
template<class T>
class SpareMatrix
{
private:
	element<T> data[Max];
	int mt,nt,rt;  //ϡ�������������������Լ���0Ԫ�صĸ���
public:
	SpareMatrix(int mt,int nt,int rt)
	{
		this->mt=mt;
		this->nt=nt;
		this->rt=rt;
		cout<<"����Ϊ���������������0Ԫ�ص����Լ��У��Լ�����Ԫ�ص�ֵ��"<<endl;
		for(int i=0;i<rt;i++)
			cin>>data[i].row>>data[i].col>>data[i].item;
	}
    SpareMatrix(){mt=nt=rt=0;} //����һ������ֵΪ�յĹ��캯������ת�þ������;
	void print()
	{
	  cout<<"������������£�"<<endl;
	  cout<<"row"<<"\t"<<"col"<<"\t"<<"item"<<endl;
	  for(int i=0;i<rt;i++)
	   cout<<data[i].row<<"\t"<<data[i].col<<"\t"<<data[i].item<<endl;
	}
	//ת�þ���Ķ���
	void jzzz(SpareMatrix<T> &jz)
	{
		nt=jz.mt;
		mt=jz.nt;
		rt=jz.rt;
		int k=0;
		for(int Col=0;Col<nt;Col++)
		{
		   for(int i=0;i<rt;i++)
			   if(jz.data[i].col==Col)
			   {
				   data[k].row=jz.data[i].col;
                   data[k].col=jz.data[i].row;
				   data[k].item=jz.data[i].item;
				   k++;
			   }
		}
	}
};

void main()
{
  int mt=4;
  int nt=4;
  int rt=4;
  SpareMatrix<int>SM(mt,nt,rt);
  SM.print();
  SpareMatrix<int>SA;
  SA.jzzz(SM);
  cout<<endl;
  SA.print();
}
