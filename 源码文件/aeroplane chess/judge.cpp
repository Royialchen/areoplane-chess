#include"global.h"  //������
#include"item.h"  //ȫ�ֱ�������
#include"some_struct.h"  //�ṹ������
#include"event.h" //��������

extern int PLAYER_NUMBER;
extern int COMER_NUMBER;
extern int TOTAL_NUMBER;
extern int TURN;
extern bool ROLLAGAIN;

//�ж���Ӯ
void judge(stplayer &player) {
	cout << "judge" << endl;
	//cout << "TURN" << TURN << endl;
	//cout << "TURN" << TURN << endl;
	TURN++;
	//��ֹ��ֵ�bug������һ��������Ϊ6������ѭ������ȥ
	if (TURN == 0) {
		return;
	}
	for (int i = 0; i < 4; i++) {
		cout << "ѭ��" << endl;
		cout << player.number << ' ' << player.hasplane[i]->number << endl;
		cout << player.hasplane[i]->state << endl;
		if (player.hasplane[i]->state >= 0) {
			cout << "���ڵ�TURN" << TURN << endl;
			cout << endl;
			return;
		}
	}
	return end_game(player);
}