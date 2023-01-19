#include"global.h"  //库声明
#include"item.h"  //全局变量声明
#include"some_struct.h"  //结构体声明
#include"event.h" //函数声明

extern resource dice;
extern stplayer player[4];
extern int PLAYER_NUMBER;
extern int COMER_NUMBER;
extern int TOTAL_NUMBER;
extern int TURN;
extern bool ROLLAGAIN;

//摇骰子
int roll_dice() {
	srand((unsigned int)time(0));
	int dice = (rand() % 18) % 6 + 1;
	//show_dice(dice);
	return dice;
}

//显示骰子图片
void show_dice(int ndice) {
	putimage(810, 300, dice.imgs + ndice);
	//cout << "show_dice" << endl;
	//return real_or_com(player[TURN % TOTAL_NUMBER], ndice);
}