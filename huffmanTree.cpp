#include<iostream>
#include<iomanip>
using namespace std;
struct element{
	float weight;
	int lChild,rChild,parent;
};
class huffmanTree{
	int numLeaf;//叶子结点个数
	element *hufTree;
public:
    huffmanTree(int n,float x[]){
		numLeaf=n;
		hufTree=new element[2*numLeaf-1];  //生成多少个节点
		for(int i=0;i<2*numLeaf-1;i++)
			hufTree[i].parent=hufTree[i].lChild=hufTree[i].rChild=-1;
		for(i=0;i<numLeaf;i++)//初始化各叶子结点的权值
			hufTree[i].weight=x[i];
		for(i=numLeaf;i<2*numLeaf-1;i++){//找最小权值的两个结点的下标           进行numLef-1次合并
			int min1,min2;
			for(int k=0;k<i;k++)
				if(hufTree[k].parent==-1){  min1=k; break;}
		    for(k=0;k<i;k++)
				if(hufTree[k].parent==-1&&hufTree[k].weight<hufTree[min1].weight)
					min1=k;
			for(k=0;k<i;k++)
				if(hufTree[k].parent==-1&&k!=min1){min2=k;break;}
            for(k=0;k<i;k++)
				if(hufTree[k].parent==-1&&hufTree[k].weight<hufTree[min2].weight&&k!=min1)
					min2=k;
			hufTree[min1].parent=i;
			hufTree[min2].parent=i;
			hufTree[i].lChild=min1;
			hufTree[i].rChild=min2;
			hufTree[i].weight=hufTree[min1].weight+hufTree[min2].weight;
		}
	}
	~huffmanTree(){ delete []hufTree;}
	void print(){
		cout<<"index  weight parent lChild rChild\n";
		cout<<std::left;//左对齐输出
		for(int i=0;i<2*numLeaf-1;i++){
			cout<<setw(5)<<i<<"  ";
			cout<<setw(6)<<hufTree[i].weight<<"  ";
			cout<<setw(6)<<hufTree[i].parent<<"  ";
			cout<<setw(6)<<hufTree[i].lChild<<"  ";
			cout<<setw(6)<<hufTree[i].rChild<<endl;
		}
	}
};
void main(){
	int n;
	cout<<"输入叶子结点个数:";
	cin>>n;
	float x[]={0.31,0.16,0.1,0.08,0.11,0.2,0.04};
	huffmanTree hT(n,x);
	hT.print();
}
