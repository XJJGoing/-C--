#include<iostream.h>
void Print1(int r[],int n)
{
  cout<<"ԭʼ�������˳��Ϊ��"<<endl;
  for(int i=0;i<n;i++)
	  cout<<r[i]<<" ";
}
void Print2(int r[],int n)
{
	for(int i=1;i<=n;i++)
		cout<<r[i]<<" ";
}
//ֱ�Ӳ�������
void StInsert_sort(int r[],int n)
{
	cout<<"ֱ�Ӳ����������������£�"<<endl;
	for(int i=2;i<=n;i++)
	{
	  r[0]=r[i];
	  for(int j=i-1;r[0]<r[j];j--)
		r[j+1]=r[j];
	  r[j+1]=r[0];
	}
}

//ϣ������
//ϣ��������ʵ�����������ֻ࣬���ȶ������Ƚ����˷ֳ����ɸ�������
void Shell_sort(int r[],int n)
{   
	int count=1;
	cout<<"ϣ������Ľ����"<<endl;
	for(int d=n/2;d>=1;d/=2)
	{
		for(int i=d+1;i<=n;i++)
		{
		  r[0]=r[i];
		  for(int j=i-d;j>0&&r[0]<r[j];j=j-d)
			  r[j+d]=r[j];
		  r[j+d]=r[0];
		}
		cout<<"��"<<count<<"��ϣ������Ľ����"<<endl;
		Print2(r,n);
		cout<<endl;
		count++;
	}
   cout<<endl;
}
//ð������
void Bubble_sort(int r[],int n)
{
  cout<<"ð������Ľ����"<<endl;
  int exchange=n;
  while(exchange!=0)
  {
   int bound=exchange;
       exchange=0;
	   for(int j=1;j<bound;j++) //һ������
	   {
		   if(r[j]>r[j+1]){
		     r[0]=r[j];
			 r[j]=r[j+1];
			 r[j+1]=r[0];
			 exchange=j;       //��¼������λ��
		   }
	   }            
  }
}

//��������
int Partition(int r[],int first,int end)
{
  int i=first;
  int j=end;
  r[0]=r[first];
  while(i<j)
  {
	 //�Ҳ�ɨ��
     while(i<j&&r[0]<=r[j])j--;
        if(i<j) r[i++]=r[j];
	 //���ɨ��
	 while(i<j&&r[0]>=r[i])i++;
		 if(i<j) r[j--]=r[i];
  }
   r[i]=r[0];        //��r[0]��ֵ����ֵ��ȥ
   return i;
}

void Quick_sort(int r[],int first,int end)
{
	if(first<end)
	{
	int t=Partition(r,first,end);
	    //��߽��п�������
	    Quick_sort(r,first,t-1);
		Quick_sort(r,t+1,end);        
	}
}

//������
void Select_sort(int r[],int n)
{
	cout<<"��ѡ������"<<endl;
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

//������
//��ʼ������--�����
void Sift(int r[],int k,int m)
{ //m��ʾ���һ��������±�
	int i=k;         //k��ʾ��ɹѡ��ʼ�Ľڵ�
    int j=2*i;    //j��ʾ˫�׵����ӽڵ�
	while(j<=m)
	{
		 if(j<m&&r[j]<r[j+1]) j++;
		 if(r[i]>=r[j]) break;
		 else {
			 r[0]=r[i];
			 r[i]=r[j];
			 r[j]=r[0];
			 i=j;j=2*i;                  //ֻҪ�����˽����ͽ�����һ����������
		 }
	}
}

//�������Լ����½���
//��2��֮n��ʼ���жѵĳ�ʼ��
void Heap_sort(int r[],int n)
{
  cout<<"������Ľ����"<<endl;
  for(int i=n/2;i<=1;i--)
	  Sift(r,i,n);
  //�ؽ���
  for(i=1;i<=n;i++){
	r[0]=r[1];
    r[1]=r[n-i+1];
	r[n-i+1]=r[0];
	Sift(r,1,n-i);         //�ƶ�֮���ֽ���һ�����򣬲����ƶ�֮��Ķ��㿪ʼ����
  }
}

//�鲢����

//һ�ι鲢�㷨
void  Merge(int r[],int s,int m,int t)
{
	int i=s,j=m+1,k=s;           //i��ŵ�һ���������е��±꣬j��ŵڶ����������е��±�
	int r1[20];
	while(i<=m&&j<=t)
	{
      if(r[i]<=r[j]) r1[k++]=r[i++];
		  else r1[k++]=r[j++];
	}
	//��û�н��бȽ�������е�һ���������е�Ԫ�ط���r1��
	while(i<=m) r1[k++]=r[i++];
	while(j<=t) r1[k++]=r[j++];
	//������õ���r1�е��������е�Ԫ��ֵ����r
     for(i=s;i<=t;i++)
       r[i]=r1[i];
}

//һ�˹鲢�����㷨
void Merge_pass(int r[],int n, int h)
{
	//������������λ����Ϊh��������
	int i=1;
	while(i<=n-2*h+1){
	Merge(r,i,i+h-1,i+2*h-1);
	i+=2*h;
	}
	//����һ������С��h��������,��������һ�ι鲢
	if(i<=n-h+1){
	Merge(r,i,i+h-1,n);
	}
}
//�鲢����ǵݹ��㷨
void Merge_sort(int r[],int n)
{
   int	h=1;
   int count=1;
	while(h<n)
	{
	  Merge_pass(r,n,h);
	  //�鿴ÿ�ι鲢����������
	  cout<<"��"<<count<<"�ι鲢�Ľ����"<<endl;
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
	cout<<"��������Ľ����"<<endl;
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
	cout<<"�鲢��������ս����"<<endl;
	Print2(r7,n);
	cout<<endl;
}


