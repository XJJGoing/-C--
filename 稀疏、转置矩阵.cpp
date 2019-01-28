//包括转置矩阵
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
	int mt,nt,rt;  //稀疏矩阵的行数，列数，以及非0元素的个数
public:
	SpareMatrix(int mt,int nt,int rt)
	{
		this->mt=mt;
		this->nt=nt;
		this->rt=rt;
		cout<<"以行为主，请依次输入非0元素的行以及列，以及非零元素的值："<<endl;
		for(int i=0;i<rt;i++)
			cin>>data[i].row>>data[i].col>>data[i].item;
	}
    SpareMatrix(){mt=nt=rt=0;} //定义一个参数值为空的构造函数用于转置矩阵的用途
	void print()
	{
	  cout<<"依次输出的如下："<<endl;
	  cout<<"row"<<"\t"<<"col"<<"\t"<<"item"<<endl;
	  for(int i=0;i<rt;i++)
	   cout<<data[i].row<<"\t"<<data[i].col<<"\t"<<data[i].item<<endl;
	}
	//转置矩阵的定义
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
