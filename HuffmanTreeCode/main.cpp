#include<iostream>
#include"HuffmanTree.h"
#include"HuffmanCoder.h"
using namespace std;
int main(){
	int n;
	cout<<"---此程序实现建立赫夫曼树并赫夫曼编码---"<<endl<<endl;
	cout<<"请输入树叶结点的个数(n>1): "<<endl;
	cin>>n;
	char chA[256];
	int weightA[256];

	for(int i=0; i<n; i++){
		cout<<"请输入第"<<i<<"个字符及权值"<<endl;
		cin>>chA[i]>>weightA[i];
	}
	HuffmanTree ht(n, chA, weightA);   //建立赫夫曼树
	ht.Display();                                    //显示所建赫夫曼树

	HuffmanCoder hc(n);
	hc.CreateBook(ht);                          //建立赫夫曼编码表
	cout<<"请输入需编码字符串(字符串中的字符须是当前对象中的字符):  "<<endl;
	cin>>chA;
	cout<<"编码结果:  "<<endl;
	hc.Coder(chA);                  //对所输入的字符串进行编码，编码的结果同时放如数据文件f1中
	cout<<endl;
	hc.Decoder(ht);                  //对数据文件f1中的编码进行译码
	cout<<endl;

	system("pause");
	return 0;
}