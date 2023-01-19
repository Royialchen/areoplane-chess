#include"global.h"  //库声明
#include"item.h"  //全局变量声明
#include"some_struct.h"  //结构体声明
#include"event.h" //函数声明

extern int TURN;

#define DEBUG
//指定骰子数
int pardice() {
	srand((unsigned int)time(0));
	if (TURN == 0 || TURN == 2 || TURN == 4) {
		return 6;
	}
	int dice = rand() % 6 + 1;
	return dice;
}