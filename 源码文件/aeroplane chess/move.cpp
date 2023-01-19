#include"global.h"  //������
#include"item.h"  //ȫ�ֱ�������
#include"some_struct.h"  //�ṹ������
#include"event.h" //��������

extern stsquare square[96];
extern stplane* justoutplane;
extern int PLAYER_NUMBER;
extern int COMER_NUMBER;
extern int TOTAL_NUMBER;
extern int TURN;
extern bool ROLLAGAIN;

//������
void out_airport(stplane* plane) {
	cout << "out_airport" << plane->number << endl;
	/*putimage(square[plane->color + 16].x, square[plane->color + 16].y, plane->img->imgs + 0, SRCAND);
	putimage(square[plane->color + 16].x, square[plane->color + 16].y, plane->img->imgs + 1, SRCPAINT);*/
	awaysquare(plane, plane->place);
	//�ؽ�plane��place����ϵ
	plane->place = &square[plane->color + 16];
	plane->state = 1;
	plane->havego = 1;
	cout << plane->number << endl;
	landsquare(plane, plane->place);
	//�ڶ���ҡ���ӣ�ָ���ոճ������ķɻ�
	TURN--;
	ROLLAGAIN = true;
	justoutplane = plane;
	cout << "turn" << TURN << endl;
}

//���ػ���
void return_airport(stplane* plane) {
	cout << "return_airport" << plane->number << endl;
	awaysquare(plane, plane->place);
	plane->place = &square[plane->color * 4 + plane->number];
	plane->state = 0;
	plane->havego = 0;
	landsquare(plane, plane->place);
}

//ǰ��
void advance(stplane* plane, int dice ) {
	cout << "advance" << plane->state <<' '<<plane->havego <<' '<< plane->havego + dice << endl;
	//�ڶ���ҡ���ӵ����
	if (ROLLAGAIN == true) {
		ROLLAGAIN = false;
		justoutplane = NULL;
	}
	awaysquare(plane, plane->place);
	//��������
	if (plane->state == 1) {
		cout << "��������" << endl;
		plane->place = &square[19 + plane->color * 13 + dice];
		plane->state = 2;
	}
	//����ĩβ��������ܵ�
	else if (plane->state == 2 && (plane->havego + dice) > 51 && (plane->havego + dice) != 57) {
		cout << "����ĩβ��������ܵ�" << endl;
		//������ͨ�ܵ��ĸ����ڷ����ܵ���ǰ��
		//plane->place = &square[plane->place->number + dice - ((49 + plane->color * 13) % 52 + 20) + 71 + 6 * (plane->color)];
		plane->place = &square[plane->havego + dice - 51 + 71 + 6 * (plane->color)];
		plane->state = 3;
	}
	//����ĩβ������ͨ�ܵ�
	else if (plane->state == 2 && (plane->havego + dice) != 57) {
		cout << "����ĩβ������ͨ�ܵ�" << endl;
		plane->place = &square[(plane->place->number + dice - 20) % 52 + 20];
	}
	//����ͣ�ڷ����ܵ�ĩβ
	else if (plane->state == 3 && plane->place->number + dice == 77 + 6 * (plane->color) || plane->state == 2 && (plane->havego + dice) == 57) {
		cout << "����ͣ�ڷ����ܵ�ĩβ" << endl;
		plane->place = &square[77 + 6 * (plane->color)];
		landsquare(plane, plane->place);

		play_scene();
		show_dice(dice);

		settextstyle(22, 0, "����");
		outtextxy(780, 500, "С�ɻ������յ���");
		plane->state = -1;
		
		//putimage(square[77 + 6 * (plane->color)].x, square[77 + 6 * (plane->color)].y, plane->img->imgs + 0, SRCAND);
		//putimage(square[77 + 6 * (plane->color)].x, square[77 + 6 * (plane->color)].y, plane->img->imgs + 1, SRCPAINT);
		ExMessage m;
		while (1) {
			while (peekmessage(&m, EM_MOUSE)) {
				if (m.message == WM_LBUTTONDOWN) {
					return;
				}
			}
		}
	}
	//����δ�������ܵ�ĩβ
	else if (plane->state == 3 && plane->place->number + dice < 77 + 6 * (plane->color)) {
		cout << "����δ�������ܵ�ĩβ" << endl;
		plane->place = &square[plane->place->number + dice];
	}
	//���ֳ��������ܵ�ĩβ������
	else if (plane->state == 3 && plane->place->number + dice > 77 + 6 * (plane->color)) {
		rebound(plane, dice);
	}

	plane->havego += dice;

	//����ĩβ��ͬɫ���ӣ����л�����Ծ
	if (plane->state == 2 && plane->place->color == plane->color && plane->havego != 51) {
		if (plane->place->number == ((17 + plane->color * 13) % 52 + 20)) {
			fly(plane);
		}
		else {
			jump(plane);
		}
	}

	landsquare(plane, plane->place);
	cout << plane->havego  << endl;
	if (plane->state == 2 && plane->place->exp > 1) { in_same_square(plane, plane->place); }
}

//����
void rebound(stplane* plane, int dice) {
	cout << "reound" << endl;
	plane->place = &square[77 + 6 * (plane->color) - (plane->place->number + dice - (77 + 6 * (plane->color)))];
}

//ͬɫ��Ծ
void jump(stplane* plane) {
	cout << "jump" << endl;
	plane->place = &square[(plane->place->number + 4 - 20) % 52 + 20];
	plane->havego += 4;

}

//����
void fly(stplane* plane) {
	cout <<"fly"<< endl;
	plane->place = &square[((29 + plane->color * 13) % 52 + 20)];
	plane->havego += 12;
}

//�ɻ��뿪����,�Ͽ�place��plane����ϵ
void awaysquare(stplane* plane, stsquare* square) {
	cout << "away" << plane->place->number << endl;
	for (int i = 0; i < 4; i++) {
		if (square->ex_plane[i] == plane) {
			square->ex_plane[i] = NULL;
			int j = i;
			//ȷ�����ӻ��ƵĿ��ӻ�
			for (j = i; j < square->exp - 1; j++) {
				square->ex_plane[j] = square->ex_plane[j + 1];
			}
			square->ex_plane[j] = NULL;
			square->exp -= 1;
			cout << ' ' << square->exp << endl;
			break;
		}
	}
}

//�ɻ������ڸ�����,����place��plane����ϵ
void landsquare(stplane* plane, stsquare* square) {
	cout << "land" << plane->place->number << endl;
	for (int i = 0; i < 4; i++) {
		if (square->ex_plane[i] == NULL) {
			square->ex_plane[i] = plane;
			cout << "ex_plane" << i << endl;
			square->exp += 1;
			cout << ' ' << square->exp << endl;
			break;
		}
	}
	
}

//������㴦�ж������
void in_same_square(stplane* plane, stsquare* square) {
	cout << "same_square" << endl;
	cout << plane->color << endl;

	for (int i = 0; i < 4; i++) {
		cout << "�ж�" << endl;
		if (square->ex_plane[i] != plane && square->ex_plane[i] != NULL) {
			//��ɫ����
			cout << "�ж��" << endl;
			if (square->ex_plane[i]->color != plane->color) {
				cout << "��ɫ�ɻ�" << endl;
				return_airport(square->ex_plane[i]);
			}
			else {
				cout << "ͬɫ" << endl;
				;
			}
		}
	}

}