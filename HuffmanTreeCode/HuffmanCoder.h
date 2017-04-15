#include<iostream>
#ifndef _HuffmanCoder_
#define _HuffmanCoder_
#include"HCnode.h"
#include"HuffmanTree.h"
using namespace std;

class HuffmanCoder{
private:
	HCnode *m_HC;  //huffman编码表基地址指针
	int m_HCsize;   //外结点个数
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
	void CreateBook(HuffmanTree & ht);/*{ //建立n个字符的huffman编码表HC
		int i, j, c, f, start;
		char ch1, *cd = new char[m_HCsize];
		cd[m_HCsize-1] = '\0';
		cout<<"以下是各字符的huffman编码: "<<endl<<endl;
		for(i=0; i<m_HCsize; i++){
			start = m_HCsize -1;
			m_HC[i].ch = ht.m_HT[i].ch;
		for(c=i, f=ht
}*/
	void Coder(char ch[]);  //编码
	void Decoder(HuffmanTree &);  //译码
};
#endif
