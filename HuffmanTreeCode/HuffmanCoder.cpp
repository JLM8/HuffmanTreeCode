#include<iostream>
#include<fstream>
#include"HuffmanCoder.h"
using namespace std;

void HuffmanCoder::CreateBook(HuffmanTree &ht){
	int i, j, c, f, start;
	char ch1, *cd = new char[m_HCsize];
	cd[m_HCsize-1] = '\0';
	cout<<"以下是各字符的huffman编码: "<<endl<<endl;
	for(i=0; i<m_HCsize; i++){           //逐个字符求赫夫曼编码
		start = m_HCsize -1;        //编码结束符位置
		m_HC[i].ch = ht.m_HT[i].ch;  //从叶子到根逆向求编码
		for(c=i, f=ht.m_HT[i].parent; f != -1; c=f, f=ht.m_HT[f].parent){
			if(ht.m_HT[f].lchild == c)
				cd[--start] = '0';
			else
				cd[--start] = '1';
		}
		m_HC[i].pstring = new char[m_HCsize - start];
		cout<<"第"<<i<<"个字符"<<ht.m_HT[i].ch<<"的编码是:  ";
		for(j = start; j<m_HCsize; j++){
			cout<<cd[j];
			m_HC[i].pstring[j-start] = cd[j];
		}
		cout<<endl;
	}
	cout<<endl;
	delete []cd;           //释放工作空间
}


//对用字符串组成的电文用赫夫曼编码表进行编码
void HuffmanCoder::Coder(char ch[]){
	ofstream outfile("f1.txt",ios::out);  //打开数据文件f1.txt
	for(int i=0; i<strlen(ch); i++){
		for(int j=0; j<m_HCsize; j++){
			if(ch[i] == m_HC[j].ch){
				for(int k=0; m_HC[j].pstring[k]; k++){
					cout<<m_HC[j].pstring[k];        //编码结果打印
					outfile.put(m_HC[j].pstring[k]);  //编码结果写入数据文件f1
				}
				break;
			}
		}
	}
	cout<<endl;
	outfile.close();     //关闭数据文件
}

//对用0,1串组成的电文用赫夫曼树表进行译码
void HuffmanCoder::Decoder(HuffmanTree & ht){
	char ch[256];
	int j=0, i=0, p, pre, root = ht.m_HTsize-1;
	ifstream infile("f1.txt", ios::in);
	while(infile.get(ch[j]))
		j++;
	ch[j] = 0;
	cout<<"需译码的二进制电文是: "<<endl;
	j=0;
	while(ch[j]){
		cout<<ch[j];
		j++;
	}
	cout<<endl;
	cout<<"译码结果: "<<endl;
	pre = -1;
	p = root;
	while(i<strlen(ch)){
		while(p != -1){
			if(ch[i] == '0'){
				pre = p;
				p = ht.m_HT[p].lchild;
			}
			else{
				pre = p;
				p = ht.m_HT[p].rchild;
			}
			i++;
		}
		cout<<ht.m_HT[pre].ch;
		i--;
		pre = 0;
		p = root;
	}
	cout<<endl;
	infile.close();
}