#include<iostream>
#ifndef _HuffmanTree_
#define _HuffmanTree_
#define max 1000
#include"HTnode.h"
using namespace std;

class HuffmanTree{
	
private:
	int m_HTsize;   //��Ҷ�����
	HTnode* m_HT;  //��̬�������ַָ��
	//�����ַ������ӦȨֵ������Huffman��
	void _Create(int , char chA[], int weightA[]);
	//��ǰi���ڵ���ѡ��parentΪ0��weight��С�Ľ�㣬��������
	int _MinVal(const int &);
	//��ѡ���þ�����СȨֵ������
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