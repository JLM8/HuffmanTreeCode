#include<iostream>
#ifndef _HuffmanTree_
#define _HuffmanTree_
#define max 1000
#include"HTnode.h"
using namespace std;

class HuffmanTree{
	
private:
	int m_HTsize;   //树叶结点数
	HTnode* m_HT;  //静态树表基地址指针
	//根据字符表和相应权值，建立Huffman树
	void _Create(int , char chA[], int weightA[]);
	//在前i个节点中选择parent为0且weight最小的结点，获得其序号
	int _MinVal(const int &);
	//挑选两棵具有最小权值的子树
	void _Select(const int , int &, int &);

public:
	friend class HuffmanCoder;

	HuffmanTree(int n, char chA[], int weightA[]): m_HTsize(0), m_HT(NULL){
		_Create(n, chA, weightA);
	}
	~HuffmanTree(){
		delete []m_HT;
	}
	void Display();
};
#endif