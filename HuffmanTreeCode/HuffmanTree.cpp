#include"HuffmanTree.h"

void HuffmanTree::_Create(int n, char cha[], int weighta[]){
	char c;
	int i, s1, s2;
	m_HT = new HTnode[2*n-1];
	m_HTsize = 2*n-1;
	if(n>1){
		for(i=0; i<n; i++){
			m_HT[i].ch = cha[i];
			m_HT[i].weight = weighta[i];
			m_HT[i].parent = -1;
			m_HT[i].lchild = -1;
			m_HT[i].rchild = -1;
		}
		//在HT[1~i-1]中选择parent为0且weight最小的两个结点，其序号分别为s1和s2
		for(;i<m_HTsize; ++i){
			_Select(i,s1,s2);
			m_HT[s1].parent = m_HT[s2].parent = i;
			m_HT[i].lchild = s1;
			m_HT[i].rchild = s2;
			m_HT[i].weight = m_HT[s1].weight + m_HT[s2].weight;
			m_HT[i].parent = -1;
		}
	}
}

void HuffmanTree::Display(){
	int i;
	cout<<"所建Huffman树的静态链表表示如下: "<<endl;
	cout<<"位置  "<<"字符  "<<"权值  "<<"双亲  "<<"左孩子  "<<"右孩子  "<<endl;
	for(i=0; i<(m_HTsize+1)/2; i++){
		cout<<"  "<<i<<"    "<<m_HT[i].ch<<"    "<<m_HT[i].weight<<"     ";
		cout<<m_HT[i].parent<<"      "<<m_HT[i].lchild<<"      "<<m_HT[i].rchild<<endl;
	}
	for(; i<m_HTsize; i++){
		cout<<"  "<<i<<"         "<<m_HT[i].weight<<"     "<<m_HT[i].parent<<"     ";
		cout<<m_HT[i].lchild<<"          "<<m_HT[i].rchild<<endl;
	}
	cout<<endl;
}

int HuffmanTree::_MinVal(const int & i){
	int j, k, min=max;
	for(j=0; j<i; j++){
		if(m_HT[j].parent == -1 && m_HT[j].weight<min){
			min = m_HT[j].weight;
			k=j;
		}
	}
	m_HT[k].parent = max;
	return k;
}

void HuffmanTree::_Select(const int i, int &s1, int &s2){
	int s;
	s1 = _MinVal(i);
	s2 = _MinVal(i);
	if(s1 > s2){
		s = s1;
		s1 = s2;
		s2 = s;
	}
}