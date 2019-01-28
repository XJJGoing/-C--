#include<iostream.h>
void Print1(int r[],int n)
{
  cout<<"原始的数组的顺序为："<<endl;
  for(int i=0;i<n;i++)
	  cout<<r[i]<<" ";
}
void Print2(int r[],int n)
{
	for(int i=1;i<=n;i++)
		cout<<r[i]<<" ";
}
//直接插入排序
void StInsert_sort(int r[],int n)
{
	cout<<"直接插入排序后的数组如下："<<endl;
	for(int i=2;i<=n;i++)
	{
	  r[0]=r[i];
	  for(int j=i-1;r[0]<r[j];j--)
		r[j+1]=r[j];
	  r[j+1]=r[0];
	}
}

//希尔排序
//希尔排序其实跟插入排序差不多，只是先对数据先进行了分成若干个子序列
void Shell_sort(int r[],int n)
{   
	int count=1;
	cout<<"希尔排序的结果："<<endl;
	for(int d=n/2;d>=1;d/=2)
	{
		for(int i=d+1;i<=n;i++)
		{
		  r[0]=r[i];
		  for(int j=i-d;j>0&&r[0]<r[j];j=j-d)
			  r[j+d]=r[j];
		  r[j+d]=r[0];
		}
		cout<<"第"<<count<<"趟希尔排序的结果："<<endl;
		Print2(r,n);
		cout<<endl;
		count++;
	}
   cout<<endl;
}
//冒泡排序
void Bubble_sort(int r[],int n)
{
  cout<<"冒泡排序的结果："<<endl;
  int exchange=n;
  while(exchange!=0)
  {
   int bound=exchange;
       exchange=0;
	   for(int j=1;j<bound;j++) //一趟排序
	   {
		   if(r[j]>r[j+1]){
		     r[0]=r[j];
			 r[j]=r[j+1];
			 r[j+1]=r[0];
			 exchange=j;       //记录交换的位置
		   }
	   }            
  }
}

//快速排序
int Partition(int r[],int first,int end)
{
  int i=first;
  int j=end;
  r[0]=r[first];
  while(i<j)
  {
	 //右侧扫描
     while(i<j&&r[0]<=r[j])j--;
        if(i<j) r[i++]=r[j];
	 //左侧扫描
	 while(i<j&&r[0]>=r[i])i++;
		 if(i<j) r[j--]=r[i];
  }
   r[i]=r[0];        //把r[0]的值给赋值回去
   return i;
}

void Quick_sort(int r[],int first,int end)
{
	if(first<end)
	{
	int t=Partition(r,first,end);
	    //左边进行快速排序
	    Quick_sort(r,first,t-1);
		Quick_sort(r,t+1,end);        
	}
}

//简单排序
void Select_sort(int r[],int n)
{
	cout<<"简单选择排序："<<endl;
	for(int i=1;i<n;i++)
	{ 
	  int index=i;
	  for(int j=i+1;j<=n;j++)
		  if(r[index]>r[j]) index=j;
	  if(index!=i){
	    r[0]=r[i];
		r[i]=r[index];
		r[index]=r[0];
	  }
	}
}

//堆排序
//初始化建堆--大根堆
void Sift(int r[],int k,int m)
{ //m表示最后一个顶点的下标
	int i=k;         //k表示被晒选开始的节点
    int j=2*i;    //j表示双亲的左孩子节点
	while(j<=m)
	{
		 if(j<m&&r[j]<r[j+1]) j++;
		 if(r[i]>=r[j]) break;
		 else {
			 r[0]=r[i];
			 r[i]=r[j];
			 r[j]=r[0];
			 i=j;j=2*i;                  //只要发生了交换就进行下一个进行排序
		 }
	}
}

//堆排序以及重新建堆
//从2份之n开始进行堆的初始化
void Heap_sort(int r[],int n)
{
  cout<<"堆排序的结果："<<endl;
  for(int i=n/2;i<=1;i--)
	  Sift(r,i,n);
  //重建堆
  for(i=1;i<=n;i++){
	r[0]=r[1];
    r[1]=r[n-i+1];
	r[n-i+1]=r[0];
	Sift(r,1,n-i);         //移动之后又进行一个排序，并从移动之后的顶点开始排序
  }
}

//归并排序

//一次归并算法
void  Merge(int r[],int s,int m,int t)
{
	int i=s,j=m+1,k=s;           //i存放第一个有序序列的下标，j存放第二个有序序列的下标
	int r1[20];
	while(i<=m&&j<=t)
	{
      if(r[i]<=r[j]) r1[k++]=r[i++];
		  else r1[k++]=r[j++];
	}
	//将没有进行比较完的其中的一个有序序列的元素放入r1中
	while(i<=m) r1[k++]=r[i++];
	while(j<=t) r1[k++]=r[j++];
	//将排序好的在r1中的有序序列的元素值赋给r
     for(i=s;i<=t;i++)
       r[i]=r1[i];
}

//一趟归并排序算法
void Merge_pass(int r[],int n, int h)
{
	//至少有两个单位长度为h的子序列
	int i=1;
	while(i<=n-2*h+1){
	Merge(r,i,i+h-1,i+2*h-1);
	i+=2*h;
	}
	//存在一个长度小于h的子序列,则进行最后一次归并
	if(i<=n-h+1){
	Merge(r,i,i+h-1,n);
	}
}
//归并排序非递归算法
void Merge_sort(int r[],int n)
{
   int	h=1;
   int count=1;
	while(h<n)
	{
	  Merge_pass(r,n,h);
	  //查看每次归并排序后的序列
	  cout<<"第"<<count<<"次归并的结果："<<endl;
	  for(int i=1;i<=n;i++)
	  {   
		  cout<<r[i]<<" ";
	  }
	   h=2*h;
	   count++;
	   cout<<endl;
	}
}

void main()
{
	int r[]={15,12,5,8,9,6,16,9,10};
	int r1[]={0,15,12,5,8,9,6,16,9,10};
	int r2[]={0,15,12,5,8,9,6,16,9,10};
	int r3[]={0,15,12,5,8,9,6,16,9,10};
	int r4[]={0,15,12,5,8,9,6,16,9,10};
	int r5[]={0,15,12,5,8,9,6,16,9,10};
	int r6[]={0,15,12,5,8,9,6,16,9,10};
	int r7[]={0,15,12,5,8,9,6,16,9,10};
	int n=9;
	Print1(r,n);
	cout<<endl;
	StInsert_sort(r1,n);
	Print2(r1,n);
	cout<<endl;
	Shell_sort(r2,n);
	Print2(r2,n);
	cout<<endl;
	Bubble_sort(r3,n);
	Print2(r3,n);
	cout<<endl;
	cout<<"快速排序的结果："<<endl;
	Quick_sort(r4,1,n);
	Print2(r4,n);
	cout<<endl;
	Select_sort(r5,n);
	Print2(r5,n);
	cout<<endl;
	Heap_sort(r6,n);
	Print2(r6,n);
    cout<<endl;
	Merge_sort(r7,n);
	cout<<endl;
	cout<<"归并排序的最终结果："<<endl;
	Print2(r7,n);
	cout<<endl;
}


