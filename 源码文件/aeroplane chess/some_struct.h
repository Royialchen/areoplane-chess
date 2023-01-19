#pragma once

//棋子颜色
enum fcolor { red = 0, green=1, yellow=2, blue=3 };

//资源结构体
typedef struct resource {
	IMAGE imgs[15];
}resource;     

//typedef struct planimg {
//	IMAGE* imgs[2];
//}planimg;

//按钮
typedef struct button {
	int x;  //左上角x坐标
	int y;  //左上角y坐标
	int w;  //宽度
	int h;  //高度
	COLORREF curcolor;  //当前按钮颜色
	//COLORREF linecolor; //外框颜色
	COLORREF incolor;   //鼠标在按钮内的颜色
	COLORREF outcolor;  //鼠标不在按钮内的颜色
	char* text;         //文本
}button;

//不完全声明
struct stplane;
struct stsquare;
struct stplayer;

//玩家
typedef struct stplayer {
	int number;         //玩家编号
	//char namein[10];    //玩家昵称（用于输入存储
	char* name;         //玩家昵称指针
	fcolor plane_color; //玩家拥有的棋子颜色
	//int plane_color; //玩家拥有的棋子颜色
	//int plane_number;   //玩家拥有的棋子数量
	stplane* hasplane[4];    //玩家拥有的棋子
	int type;            //玩家类型(0为真人，1为电脑）
	resource* img;
}stplayer;

//飞机棋子
typedef struct stplane {
	stplayer* player;    //棋子的拥有者	
	int number;         //棋子的编号
	fcolor color;       //棋子的颜色	
	//int color;       //棋子的颜色	
	stsquare* place;      //棋子的位置	
	int havego;          //在跑道上运动的格子数
	int state;          //棋子的状态（0在机场，1在起点，2在普通跑道，3在分流跑道，-1离开棋局）
	resource* img;       //照片指针
}stplane;

//格子
typedef struct stsquare {
	int number;	        //每格编号	
	int x;              //左上角坐标
	int y;            
	fcolor color;       //每格颜色	
	stplane* ex_plane[4]; //每格内存在的飞机（同色飞机最多四个，异色飞机无法共存）
	int exp;              //每格存在飞机数
	int type;          //0在机场，1在起点，2在普通跑道，3在分流跑道
}stsquare;



