#include"global.h"  //������
#include"item.h"  //ȫ�ֳ�����ȫ�ֱ�������
#include"some_struct.h"  //�ṹ������
#include"event.h" //��������

int PLAYER_NUMBER;
int COMER_NUMBER;
int TOTAL_NUMBER;
int TURN = 0;
bool iscreat = false;  //�ж��Ƿ����������
bool ROLLAGAIN = false;  //����Ƿ���Ҫ����ҡ����
stplane* justoutplane = NULL;  //��ǵڶ���ҡ���ӵ��˶��ɻ�


int main() {
	
	//��������
	initgraph(bkwidth, bkheight);
	//initgraph(bkwidth, bkheight, EW_SHOWCONSOLE);
	
	while (1) {
		//��Ϸ��ʼ��
		scene_init();
		//��Ϸ������
		home_scene();
	}

	//�رմ���
	closegraph();
	return 0;
}

//��Ϸ����
void run_game() {
	while (1) {
		//������Ϸ����
		play_scene();
		//��ʼ��Ϸ
		creat_game();
	}
}


//���ֽ�˵ ok
//�������ƻ��� ok
//���ӷֿ�  ok
//�����յ�  ok