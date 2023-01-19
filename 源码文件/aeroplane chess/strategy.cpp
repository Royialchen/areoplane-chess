#include"global.h"  //������
#include"item.h"  //ȫ�ֱ�������
#include"some_struct.h"  //�ṹ������
#include"event.h" //��������

extern int PLAYER_NUMBER;
extern int COMER_NUMBER;
extern int TOTAL_NUMBER;
extern int TURN;
extern bool ROLLAGAIN;

extern stplane* justoutplane;

//�ж����˻��ǵ���
void real_or_com(stplayer &player, int dice) {
	cout << "real_or_com" << endl;
	settextstyle(22, 0, "����");
	//cout << PLAYER_NUMBER << endl;
	if (TURN % TOTAL_NUMBER < PLAYER_NUMBER) {
		choose_strategy(player, dice);
	}
	else {
		random_strategy(player, dice);
	}
}

//ѡ�񷽰���������ң�
void choose_strategy(stplayer &player, int dice) {
	cout << "����" << endl;
	ExMessage m;
	//�ڶ���ҡ���ӣ��ոճ����ķɻ�ǰ��
	if (ROLLAGAIN == true) {
		outtextxy(770, 500, "�ոճ�����С�ɻ��尡");
		while (1) {
			while (peekmessage(&m, EM_MOUSE)) {
				if (m.message == WM_LBUTTONDOWN) {
					advance(justoutplane, dice);
					return;
				}
			}
		}
		
	}

	bool allout = true;
	bool allin = true;
	for (int i = 0; i < 4; i++) {
		//�������ڻ��������������ж�������
		if (player.hasplane[i]->state == 0) {
			allout = false;
		}
		//������������
		else if(player.hasplane[i]->state > 0) {
			allin = false;
		}
		
	}
	cout <<"allout"<< allout << ' ' <<"allin" << allin << endl;
	if (dice == 6) {
		outtextxy(770, 500, "��ѡ�����С�ɻ��ɣ�");
		while (1) {
			while (peekmessage(&m, EM_MOUSE)) {
				for (int i = 0; i < 4; i++) {
					cout << i << endl;
					cout << "choose" << player.hasplane[i]->state << endl;
					//�������ڻ�����ѡ��������ڻ���                  ok
					if (isclickplane(m, player.hasplane[i]) && allout == false && player.hasplane[i]->state == 0) {
						out_airport(player.hasplane[i]);
						return;   //��û��return��һֱ��ѭ��
					}
					//�������ڻ�������ѡ�����������
					else if (isclickplane(m, player.hasplane[i]) && allout == false && player.hasplane[i]->state > 0) {
						MessageBox(NULL, "�����Ӳ���ѡ��������ѡ��", "False", MB_SYSTEMMODAL);
					}
					//ȫ�����������棬ѡ�������������                 ok
					else if (isclickplane(m, player.hasplane[i]) && allout == true && player.hasplane[i]->state > 0) {
						advance(player.hasplane[i], dice);
						return;
					}
				}
			}
		}
	}
	//��6
	else {
		//ȫ�������ڻ������޷�ѡ��    ok
		if (allin == true) {
			outtextxy(760, 500, "̫�ź���,��������+1");
			while (1) {
				while (peekmessage(&m, EM_MOUSE)) {
					if (m.message == WM_LBUTTONDOWN) {
						return;
					}
				}
			}
		}
		outtextxy(770, 500, "��ѡ�����С�ɻ���!");
		while (1) {
			while (peekmessage(&m, EM_MOUSE)) {
				for (int i = 0; i < 4; i++) {
					//�������ڻ�����ѡ��������ڻ���
					if (isclickplane(m, player.hasplane[i]) && allout == false && player.hasplane[i]->state == 0) {
						MessageBox(NULL, "�����Ӳ���ѡ��������ѡ��", "False", MB_SYSTEMMODAL);
					}
					//�������ڻ�����ѡ�����������
					else if (isclickplane(m, player.hasplane[i]) && allout == false && player.hasplane[i]->state > 0) {
						advance(player.hasplane[i], dice);
						return;
					}
					//ȫ�����������棬ѡ�������������
					else if (isclickplane(m, player.hasplane[i]) && allout == true && player.hasplane[i]->state > 0) {
						advance(player.hasplane[i], dice);
						return;
					}
				}
			}
		}
	}

	//for (int i = 0; i < 4; i++) {
	//	//���������ڻ��������������ж�������
	//	if (player.hasplane[i]->state == 0) {
	//		allout = false;      
	//		//�������ڻ����ҿ�����Ҽ���ҡ����
	//		if (dice == 6 ) {
	//			out_airport(player.hasplane[i]);
	//			//return play_scene(player.hasplane[i]);   
	//		}
	//	}
	//}
	////�������Ӷ��ڻ�����
	//if (allout == true) {  
	//	for (int i = 0; i < 4; i++) {
	//		if (player.hasplane[i]->state > 0) { 
	//			//ѡ��
	//			advance(player.hasplane[i],dice);
	//			TURN++;
	//			//return play_scene();
	//		}
	//	}
	//}
	//else {
	//	//�������ڻ������ֵ���һ���
	//	TURN++;
	//	//return play_scene();   
	//}
}

//���������������ң�
void random_strategy(stplayer& player, int dice) {
	cout << "����" << endl;
	ExMessage m;
	if (ROLLAGAIN == true) {
		while (1) {
			while (peekmessage(&m, EM_MOUSE)) {
				if (m.message == WM_LBUTTONDOWN) {
					advance(justoutplane, dice);
					return;
				}
			}
		}
	}

	bool allout = true;
	bool allin = true;
	for (int i = 0; i < 4; i++) {
		//�������ڻ���
		if (player.hasplane[i]->state == 0) {
			allout = false;   

			//ѡ���һ���ڻ��������ӳ���         ok
			if (dice == 6 ) {
				outtextxy(770, 500, "�Զ�ʽ�ɻ�����");
				while (1) {
					while (peekmessage(&m, EM_MOUSE)) {
						if (m.message == WM_LBUTTONDOWN) {
							out_airport(player.hasplane[i]);
							return;
						}
					}
				}
				//out_airport(player.hasplane[i]);
				//return play_scene(player.hasplane[i]);   
			}
		}
		//������������
		else if (player.hasplane[i]->state > 0) {
			allin = false;
		}
	}
	//ȫ�������ڻ�������6���޷�ѡ��  ok
	if (allin == true && dice != 6) { 
		outtextxy(770, 500, "������Ծ���ѷ��");
		//return; 
		while (1) {
			while (peekmessage(&m, EM_MOUSE)) {
				if (m.message == WM_LBUTTONDOWN) {
					return;
				}
			}
		}
	}
	//�������ڻ�����
	else if (allin == false) {  
		outtextxy(770, 500, "�������ѡ��ɻ�");
		//���ѡ��һ�������ƶ�                ok
		srand((unsigned int)time(0));
		int ran = rand() % 4;
		cout << "ran" << endl;
		for (int i = ran; i < 4 + ran; i++) {
			if (player.hasplane[i % 4]->state > 0) { 
				while (1) {
					while (peekmessage(&m, EM_MOUSE)) {
						if (m.message == WM_LBUTTONDOWN) {
							advance(player.hasplane[i % 4], dice);
							return;
						}
					}
				}
				//advance(player.hasplane[i% 4],dice);
				//return play_scene();
			}
		}
	}

}

//����ɻ�
bool isclickplane(ExMessage m, stplane* plane) {
	cout << "click" << endl;
	if (m.message == WM_LBUTTONDOWN && m.x > (plane->place->x + 4) && m.x < (plane->place->x + 44) && m.y > (plane->place->y + 13) && m.y < (plane->place->y + 37)) {
		//cout << plane->place->x + 4 << ' ' << plane->place->x + 44 << ' ' << plane->place->y + 13 << ' ' << plane->place->y + 37 << endl;
		//cout << "true" << endl;
		return true;
	}
	else {
		//cout << "false" << endl;
		return false;
	}
}
