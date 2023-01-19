#include"global.h"  //库声明
#include"item.h"  //全局变量声明
#include"some_struct.h"  //结构体声明
#include"event.h" //函数声明

extern int PLAYER_NUMBER;
extern int COMER_NUMBER;
extern int TOTAL_NUMBER;
extern int TURN;
extern bool ROLLAGAIN;

//判断输赢
void judge(stplayer &player) {
	cout << "judge" << endl;
	//cout << "TURN" << TURN << endl;
	//cout << "TURN" << TURN << endl;
	TURN++;
	//防止奇怪的bug：若第一轮骰子数为6则下面循环不进去
	if (TURN == 0) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		cout << "循环" << endl;
		cout << player.number << ' ' << player.hasplane[i]->number << endl;
		cout << player.hasplane[i]->state << endl;
		if (player.hasplane[i]->state >= 0) {
			cout << "现在的TURN" << TURN << endl;
			cout << endl;
			return;
		}
	}
	return end_game(player);
}