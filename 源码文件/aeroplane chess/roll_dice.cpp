#include"global.h"  //������
#include"item.h"  //ȫ�ֱ�������
#include"some_struct.h"  //�ṹ������
#include"event.h" //��������

extern resource dice;
extern stplayer player[4];
extern int PLAYER_NUMBER;
extern int COMER_NUMBER;
extern int TOTAL_NUMBER;
extern int TURN;
extern bool ROLLAGAIN;

//ҡ����
int roll_dice() {
	srand((unsigned int)time(0));
	int dice = (rand() % 18) % 6 + 1;
	//show_dice(dice);
	return dice;
}

//��ʾ����ͼƬ
void show_dice(int ndice) {
	putimage(810, 300, dice.imgs + ndice);
	//cout << "show_dice" << endl;
	//return real_or_com(player[TURN % TOTAL_NUMBER], ndice);
}