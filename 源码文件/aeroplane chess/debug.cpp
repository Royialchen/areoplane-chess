#include"global.h"  //������
#include"item.h"  //ȫ�ֱ�������
#include"some_struct.h"  //�ṹ������
#include"event.h" //��������

extern int TURN;

#define DEBUG
//ָ��������
int pardice() {
	srand((unsigned int)time(0));
	if (TURN == 0 || TURN == 2 || TURN == 4) {
		return 6;
	}
	int dice = rand() % 6 + 1;
	return dice;
}