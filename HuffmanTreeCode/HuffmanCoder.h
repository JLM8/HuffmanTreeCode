#include<iostream>
#ifndef _HuffmanCoder_
#define _HuffmanCoder_
#include"HCnode.h"
#include"HuffmanTree.h"
using namespace std;

class HuffmanCoder{
private:
	HCnode *m_HC;  //huffman��������ַָ��
	int m_HCsize;   //�������
public:
	HuffmanCoder(const int &n){
		m_HC = new HCnode[n];
		m_HCsize = n;
	}
	~HuffmanCoder(){
		for(int i=0; i<m_HCsize; i++)
			delete []m_HC[i].pstring;
		delete []m_HC;
	}
	void CreateBook(HuffmanTree & ht);/*{ //����n���ַ���huffman�����HC
		int i, j, c, f, start;
		char ch1, *cd = new char[m_HCsize];
		cd[m_HCsize-1] = '\0';
		cout<<"�����Ǹ��ַ���huffman����: "<<endl<<endl;
		for(i=0; i<m_HCsize; i++){
			start = m_HCsize -1;
			m_HC[i].ch = ht.m_HT[i].ch;
		for(c=i, f=ht
}*/
	void Coder(char ch[]);  //����
	void Decoder(HuffmanTree &);  //����
};
#endif
