#include<iostream>
#include"HuffmanTree.h"
#include"HuffmanCoder.h"
using namespace std;
int main(){
	int n;
	cout<<"---�˳���ʵ�ֽ����շ��������շ�������---"<<endl<<endl;
	cout<<"��������Ҷ���ĸ���(n>1): "<<endl;
	cin>>n;
	char chA[256];
	int weightA[256];

	for(int i=0; i<n; i++){
		cout<<"�������"<<i<<"���ַ���Ȩֵ"<<endl;
		cin>>chA[i]>>weightA[i];
	}
	HuffmanTree ht(n, chA, weightA);   //�����շ�����
	ht.Display();                                    //��ʾ�����շ�����

	HuffmanCoder hc(n);
	hc.CreateBook(ht);                          //�����շ��������
	cout<<"������������ַ���(�ַ����е��ַ����ǵ�ǰ�����е��ַ�):  "<<endl;
	cin>>chA;
	cout<<"������:  "<<endl;
	hc.Coder(chA);                  //����������ַ������б��룬����Ľ��ͬʱ���������ļ�f1��
	cout<<endl;
	hc.Decoder(ht);                  //�������ļ�f1�еı����������
	cout<<endl;

	system("pause");
	return 0;
}