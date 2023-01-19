#pragma once

//������ɫ
enum fcolor { red = 0, green=1, yellow=2, blue=3 };

//��Դ�ṹ��
typedef struct resource {
	IMAGE imgs[15];
}resource;     

//typedef struct planimg {
//	IMAGE* imgs[2];
//}planimg;

//��ť
typedef struct button {
	int x;  //���Ͻ�x����
	int y;  //���Ͻ�y����
	int w;  //���
	int h;  //�߶�
	COLORREF curcolor;  //��ǰ��ť��ɫ
	//COLORREF linecolor; //�����ɫ
	COLORREF incolor;   //����ڰ�ť�ڵ���ɫ
	COLORREF outcolor;  //��겻�ڰ�ť�ڵ���ɫ
	char* text;         //�ı�
}button;

//����ȫ����
struct stplane;
struct stsquare;
struct stplayer;

//���
typedef struct stplayer {
	int number;         //��ұ��
	//char namein[10];    //����ǳƣ���������洢
	char* name;         //����ǳ�ָ��
	fcolor plane_color; //���ӵ�е�������ɫ
	//int plane_color; //���ӵ�е�������ɫ
	//int plane_number;   //���ӵ�е���������
	stplane* hasplane[4];    //���ӵ�е�����
	int type;            //�������(0Ϊ���ˣ�1Ϊ���ԣ�
	resource* img;
}stplayer;

//�ɻ�����
typedef struct stplane {
	stplayer* player;    //���ӵ�ӵ����	
	int number;         //���ӵı��
	fcolor color;       //���ӵ���ɫ	
	//int color;       //���ӵ���ɫ	
	stsquare* place;      //���ӵ�λ��	
	int havego;          //���ܵ����˶��ĸ�����
	int state;          //���ӵ�״̬��0�ڻ�����1����㣬2����ͨ�ܵ���3�ڷ����ܵ���-1�뿪��֣�
	resource* img;       //��Ƭָ��
}stplane;

//����
typedef struct stsquare {
	int number;	        //ÿ����	
	int x;              //���Ͻ�����
	int y;            
	fcolor color;       //ÿ����ɫ	
	stplane* ex_plane[4]; //ÿ���ڴ��ڵķɻ���ͬɫ�ɻ�����ĸ�����ɫ�ɻ��޷����棩
	int exp;              //ÿ����ڷɻ���
	int type;          //0�ڻ�����1����㣬2����ͨ�ܵ���3�ڷ����ܵ�
}stsquare;



