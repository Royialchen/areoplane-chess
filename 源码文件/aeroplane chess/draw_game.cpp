#include"global.h"  //������
#include"item.h"  //ȫ�ֱ�������
#include"some_struct.h"  //�ṹ������
#include"event.h" //��������

extern stplane plane[16];
extern stplayer player[4];
//extern planimg pimg[4];
extern stsquare square[96];
extern int PLAYER_NUMBER;
extern int COMER_NUMBER;
extern int TOTAL_NUMBER;
extern int TURN;
extern bool ROLLAGAIN;
extern bool iscreat;

resource res;   //����һ��ȫ����Դ����
resource dice;
resource pimg[4];

//������ť
button* set = creat_button(button_zx, 450, 250, 100, "������Ϸ", RGB(24, 144, 285), RGB(49, 186, 233));
button* play = creat_button(button_zx, 600, 250, 100, "��ʼ��Ϸ", RGB(24, 144, 285), RGB(49, 186, 233));
button* explain = creat_button(button_zx, 300, 250, 100, "��Ϸ˵��", RGB(24, 144, 285), RGB(49, 186, 233));
button* exitgame = creat_button(820, 710, 150, 80, "�˳�", RGB(24, 144, 285), RGB(49, 186, 233));
button* returnhome = creat_button(820, 710, 150, 80, "����", RGB(24, 144, 285), RGB(49, 186, 233));
button* confirm = creat_button(425, 710, 150, 80, "ȷ��", RGB(24, 144, 285), RGB(49, 186, 233));
button* buplayer = creat_button(500, 280, 150, 80, "", RGB(255, 255, 255), RGB(255, 255, 255));
button* bucom = creat_button(500, 380, 150, 80, "", RGB(255, 255, 255), RGB(255, 255, 255));
button* buname[4];
button* bucolor[4];

//RECT inplayer={ 500, 300, 150, 80 }, incom={ 500, 280, 600, 330 };

//��Դ��ʼ��
void res_init(resource* res,resource pimg[],resource* dice) {
	loadimage(res->imgs + 0, "image/img1.jpg", getwidth(), getheight());
	loadimage(res->imgs + 1, "image/img2.png", getwidth(), getheight());
	loadimage(res->imgs + 2, "image/img4.png", getwidth(), getheight());
	loadimage(res->imgs + 3, "image/img12.jpg", 700, 700);  //���̰׵׺�ɫ
	loadimage(res->imgs + 4, "image/img11.jpg", 700, 700);  //���̺ڵײ�ɫ
	loadimage(res->imgs + 5, "image/img9.jpg", 480, 300);  //С�ɻ��׵׺�ɫ
	loadimage(res->imgs + 6, "image/img8.jpg", 480, 300);  //С�ɻ��ڵײ�ɫ
	loadimage(res->imgs + 7, "image/img4.jpg", 300, 300);  //С�ɻ�2�׵׺�ɫ
	loadimage(res->imgs + 8, "image/img5.jpg", 300, 300);  //С�ɻ�2�ڵײ�ɫ
	loadimage(res->imgs + 9, "image/img3.jpg", getwidth(), getheight());  //������Ϸ
	//loadimage(res->imgs + 10, "image/2.jpg", 50, 40);  //���ΰ׵׺�ɫ
	//loadimage(res->imgs + 11, "image/1.jpg", 50, 40);  //���κڵײ�ɫ
	//loadimage(res->imgs + 9, "image/img13.jpg", 50, 50);   //���Ӱ׵׺�ͼ
	//loadimage(res->imgs + 10, "image/img14.jpg", 50, 50);   //������
	//loadimage(res->imgs + 11, "image/img15.jpg", 50, 50);   //������
	//loadimage(res->imgs + 12, "image/img17.ipg", 50, 50);   //������
	//loadimage(res->imgs + 13, "image/img16.jpg", 50, 50);   //������
	loadimage(pimg[0].imgs + 0, "image/img13.jpg", 50, 50);;  //���Ӱ׵׺�ͼ
	loadimage(pimg[0].imgs + 1, "image/img14.jpg", 50, 50);  //������
	loadimage(pimg[1].imgs + 0, "image/img13.jpg", 50, 50);   //���Ӱ׵׺�ͼ
	loadimage(pimg[1].imgs + 1, "image/img15.jpg", 50, 50);   //������
	loadimage(pimg[2].imgs + 0, "image/img13.jpg", 50, 50);   //���Ӱ׵׺�ͼ
	loadimage(pimg[2].imgs + 1, "image/img17.jpg", 50, 50);   //������
	loadimage(pimg[3].imgs + 0, "image/img13.jpg", 50, 50);   //���Ӱ׵׺�ͼ
	loadimage(pimg[3].imgs + 1, "image/img16.jpg", 50, 50);   //������
	loadimage(dice->imgs + 0, "image/20.jpg", 100, 100);
	loadimage(dice->imgs + 1, "image/21.jpg", 100, 100);
	loadimage(dice->imgs + 2, "image/22.jpg", 100, 100);
	loadimage(dice->imgs + 3, "image/23.jpg", 100, 100);
	loadimage(dice->imgs + 4, "image/24.jpg", 100, 100);
	loadimage(dice->imgs + 5, "image/25.jpg", 100, 100);
	loadimage(dice->imgs + 6, "image/26.jpg", 100, 100);

}

//���ڳ�ʼ��
void scene_init() {

	//�޸Ĵ�������
	HWND hnd = GetHWnd();
	SetWindowTextA(hnd, "������~~~~");

	//����ͼƬ��Դ
	res_init(&res,pimg,&dice);

	//�����ܵ�
	creat_runway();
	cout << "�ոճ�ʼ��" << square[0].x <<' ' << square[0].y << endl;
	cout << "�ոճ�ʼ��" << square[9].ex_plane[3]<< endl;
}

//�������
void home_scene() {
	//creat_runway();
	//����ͼƬ
	putimage(0, 0, res.imgs + 0);
	putimage(530, 50, res.imgs + 5, SRCAND);
	putimage(530, 50, res.imgs + 6, SRCPAINT);
	putimage(50, 530, res.imgs + 7, SRCAND);
	putimage(50, 530, res.imgs + 8, SRCPAINT);

	settextcolor(WHITE);
	setbkmode(TRANSPARENT);  //ȥ�����ֱ���
	settextstyle(140, 0, "�����п�");
	outtextxy(40, 160, "������");

	//���ư�ť
	settextcolor(BLACK);
	settextstyle(45, 0, "����");
	draw_button(set);
	draw_button(play);
	draw_button(explain);

	//�޸Ĵ��ڱ�����ɫ
	//setbkcolor(RGB(254,241,209));

	//�޸��߼�����ϵ
	//setorigin(bkwidth / 2, bkheight / 2);  //ԭ��
	//setaspectratio(-1, 1);  //�����᷽��

	//ˢ�´���(�õ�ǰ����ɫ���������ڲ��ñ���ɫ�����Բ�������)
	//cleardevice();

	//˫�������
	//BeginBatchDraw();
	
	cout << "������" << square[0].x << ' ' << square[0].y << endl;
	while (1) {      //�ؼ���
		ExMessage m;
		//��Ϣ�������ϻ�ȡ�����Ϣ����ֹ��Ϣ�ѻ���
		
		while (peekmessage(&m, EM_MOUSE)) {
			
			//��ת���ý���
			if (isclickbutton(set, m)) {
				set_scene();
			}
			//��ת��ʼ��Ϸ����
			if (isclickbutton(play, m)) {
				if(iscreat == false){ 
					MessageBox(NULL, "����������Ϸ", "False", MB_SYSTEMMODAL); 
				}
				else {
					run_game();
					//cleardevice();
					//creat_runway();
					//creat_game();
				}
			}
			//��ת˵������
			if (isclickbutton(explain, m)) {
				explain_scene();
				//end_game(player + 0);
			}
		}
		
	}
	
	//FlushBatchDraw();
	
	//EndBatchDraw();
	
	//getchar();
	//while (1);
}

//������Ϸ����
void set_scene() {
	putimage(0, 0, res.imgs + 2);
	//putimage(0, 0, pimg[0].imgs + 0, SRCAND);
	//putimage(0, 0, pimg[0].imgs + 1, SRCPAINT);
	
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);  //ȥ�����ֱ���
	settextstyle(30, 0, "����");
	outtextxy(200, 300, "�������������������");
	outtextxy(200, 400, "������������������");
	settextstyle(20, 0, "����");
	outtextxy(410, 620, "�밴�س���ȷ�����룡");
	outtextxy(410, 650, "2 <= ��������� <= 4");
	//rectangle(500, 80, 600, 130);
	//rectangle(500, 280, 600, 330);

	//draw_button(returnhome);
	settextstyle(45, 0, "����");
	draw_button(confirm);
	draw_button(buplayer);
	draw_button(bucom);


	////���룬���ɷ���ѭ����
	//char s[5], c[5];
	//InputBox(s, 5, "�������������������");
	// 
	// 
	//InputBox(c, 5, "������������������");
	//int i = 0;
	//while (s[i] != '\0') {
	//	PLAYER_NUMBER = s[i] - '0';
	//	i++;
	//}
	//i = 0;
	//while (c[i] != '\0') {
	//	COMER_NUMBER = c[i] - '0';
	//	i++;
	//}
	//if (PLAYER_NUMBER + COMER_NUMBER > 4) {
	//	MessageBox(NULL, "���������", "False", MB_SYSTEMMODAL);
	//	set_scene();
	//}
	
	cout << "������������" << square[0].x << ' ' << square[0].y << endl;
	//��Ϣ�������ϻ�ȡ�����Ϣ
	while (1) {
		ExMessage m;
		//bool f1 = false, f2 = false;
		while (peekmessage(&m, EM_MOUSE)) {
			//if (isclickbutton(returnhome, m)) {
			//	//return;
			//	return home_scene();
			//}
			//�������
			if (isclickbutton(buplayer, m)) {
				setlinecolor(RGB(1,123,200));
				draw_button(buplayer);
				input( m, buplayer, 1, &PLAYER_NUMBER);
			}
			if (isclickbutton(bucom, m)) {
				setlinecolor(RGB(1, 123, 200));
				draw_button(bucom);
				input(m, bucom, 1, &COMER_NUMBER);
			}
			//��ת����
			if (isclickbutton(confirm, m) && buplayer->text != "" && bucom->text != "") {
				//int n1= *(buplayer->text)-'0', n2= *(bucom->text) - '0';
				int n1 = PLAYER_NUMBER, n2 = COMER_NUMBER;
				TOTAL_NUMBER = PLAYER_NUMBER + COMER_NUMBER;
				//cout << TOTAL_NUMBER << endl;
				if (n1 + n2 > 4 || n1 + n2 < 2) {
					MessageBox(NULL, "2 <= ��������� <= 4", "False", MB_SYSTEMMODAL);    //��Ҫɾ��ԭ���������������
					
				}
				else{
					//cout << "����������" << square[0].x << ' ' << square[0].y << endl;
					set2_scene(n1, n2);
				}
				
			}

		}
	}
	
	
}

//���ý���2
void set2_scene(int n1,int n2) {
	cout << TURN << ' ' << TOTAL_NUMBER << endl;
	putimage(0, 0, res.imgs + 2);
	settextstyle(45, 0, "����");
	draw_button(returnhome);
	//draw_button(confirm);

	settextcolor(BLACK);
	setbkmode(TRANSPARENT);  //ȥ�����ֱ���
	settextstyle(20, 0, "����");
	outtextxy(280, 650, "��ɫ����: r�����ɫ g������ɫ y�����ɫ b������ɫ");
	settextstyle(30, 0, "����");
	
	//�������������ʾ
	int i;
	for ( i = 0; i < TOTAL_NUMBER; i++) {
		//char* c=NULL;
		//sprintf(c, "���%d�ǳƣ�",i);
		outtextxy(150, 200+i*100, "����ǳƣ�");
		if (i < n1) {
			buname[i] = creat_button(300, 180 + i * 100, 200, 80, "", RGB(255, 255, 255), RGB(255, 255, 255));
		}
		else {
			buname[i] = creat_button(300, 180 + i * 100, 200, 80, "����", RGB(255, 255, 255), RGB(255, 255, 255));
		}
		draw_button(buname[i]);

		outtextxy(520, 200+i*100, "����������ɫ��");
		bucolor[i] = creat_button(730, 180 + i * 100, 100, 80, "", RGB(255, 255, 255), RGB(255, 255, 255));
		draw_button(bucolor[i]);
	}
	
	/*for (i = n1; i < n2; i++) {
		outtextxy(150, 200 + i * 100, "����ǳƣ�");
		buname[i] = creat_button(300, 180 + i * 100, 200, 80, "�������", RGB(255, 255, 255), RGB(255, 255, 255));
		draw_button(buname[i]);

		outtextxy(520, 200 + i * 100, "ѡ��������ɫ��");
		bucolor[i] = creat_button(730, 180 + i * 100, 100, 80, "", RGB(255, 255, 255), RGB(255, 255, 255));
		draw_button(bucolor[i]);
	}*/
	
	//if (n2 > 0) { outtextxy(150, 200 + i * 100, "��������������"); }

	cout << "�������" << square[0].x << ' ' << square[0].y << endl;
	while (1) {
		ExMessage m;
		while (peekmessage(&m, EM_MOUSE)) {          //��ȡ�����Ϣ��һ������ƶ��ʹ�����Ϣ
			if (isclickbutton(returnhome, m)) {
				return home_scene();
			}
			for (int i = 0; i < TOTAL_NUMBER; i++) {
				if (isclickbutton(buname[i], m)) {
					setlinecolor(RGB(1, 123, 200));
					draw_button(buname[i]);
					input(m, buname[i], 0, NULL, buname[i]->text);
					//cout <<"setname"<< square[0].x << square[0].y << endl;
				}
				if (isclickbutton(bucolor[i], m)) {
					setlinecolor(RGB(1, 123, 200));
					draw_button(bucolor[i]);
					input(m, bucolor[i], 0, NULL, bucolor[i]->text);
					//cout <<"setcolor"<< square[0].x << square[0].y << endl;
				}
				if (strcmp(buname[i]->text,"") != 0 && strcmp(bucolor[i]->text, "") != 0) {
					//creat_runway();
					//cout <<"setall"<< square[0].x <<' '<< square[0].y << endl;
					creat_player(i, buname[i]->text, bucolor[i]->text);
				}
			}
		}
	}

}

//���ƿ�ʼ��Ϸ����
void play_scene() {
	//creat_runway();
	cout << "��һ��" << endl;
	cout << "drawplay" << endl;
	cout << "TURN" << TURN << ' ' << "TOTAL_NUMBER" << TOTAL_NUMBER << endl;

	putimage(0, 0, res.imgs + 0);   //����
	//cleardevice();   //ˢ��
	//����
	putimage(50, 50, res.imgs + 3, SRCAND);   //�׵׺�ͼ��λ��
	putimage(50, 50, res.imgs + 4, SRCPAINT); //�ڵײ�ͼ��λ��

	//��ť
	settextstyle(45, 0, "����");
	draw_button(exitgame);

	//���ַɻ�
	putimage(830, 150, player[TURN % TOTAL_NUMBER].img->imgs + 0, SRCAND);
	putimage(830, 150, player[TURN % TOTAL_NUMBER].img->imgs + 1, SRCPAINT);

	//���
	settextstyle(30, 0, "����");
	outtextxy(770, 200, "������ң�");
	outtextxy(905, 200, player[TURN % TOTAL_NUMBER].name);

	//����
	putimage(810, 300, dice.imgs + 0);
	settextstyle(18, 0, "����");
	outtextxy(770, 280, "�������ͼƬ����ҡ����");

	//putimage(player[0].hasplane[0]->place->x, player[0].hasplane[0]->place->y, player[0].img->imgs + 0, SRCAND);
	//putimage(player[0].hasplane[0]->place->x, player[0].hasplane[0]->place->y, player[0].hasplane[0]->img->imgs + 1, SRCPAINT);
	//cout << "��ʼ����1" << square[0].x << ' ' << square[0].y << endl;
	
	// �����յ��¼
	int c = 0;
	for (int i = 0; i < TOTAL_NUMBER; i++) {
		c = 0;
		for (int j = 0; j < 4; j++) {
			if (player[i].hasplane[j]->state < 0) {
				c++;
			}
		}
		outtextxy(square[player[i].plane_color * 4].x - 18, square[player[i].plane_color * 4].y - 17, "�����յ�����:");
		switch (c) {
		case 0:outtextxy(square[player[i].plane_color * 4].x + 103, square[player[i].plane_color * 4].y - 17, "��"); break;
		case 1:outtextxy(square[player[i].plane_color * 4].x + 103, square[player[i].plane_color * 4].y - 17, "1"); break;
		case 2:outtextxy(square[player[i].plane_color * 4].x + 103, square[player[i].plane_color * 4].y - 17, "2"); break;
		case 3:outtextxy(square[player[i].plane_color * 4].x + 103, square[player[i].plane_color * 4].y - 17, "3"); break;
		}
		

	}
	//����
	for (int i = 0; i < TOTAL_NUMBER; i++) {
		for (int j = 0; j < 4; j++) {
			if (player[i].hasplane[j]->state >= 0) {
				if (player[i].hasplane[j]->place->exp == 1) {
					putimage(player[i].hasplane[j]->place->x, player[i].hasplane[j]->place->y, player[i].hasplane[j]->img->imgs + 0, SRCAND);
					putimage(player[i].hasplane[j]->place->x, player[i].hasplane[j]->place->y, player[i].hasplane[j]->img->imgs + 1, SRCPAINT);
				}
				//�����ɻ��ظ��λ
				else if (player[i].hasplane[j]->place->exp == 2 ) {
					if (player[i].hasplane[j]->place->ex_plane[0] == player[i].hasplane[j]) {
						putimage(player[i].hasplane[j]->place->x + 5, player[i].hasplane[j]->place->y + 5, player[i].hasplane[j]->img->imgs + 0, SRCAND);
						putimage(player[i].hasplane[j]->place->x + 5, player[i].hasplane[j]->place->y + 5, player[i].hasplane[j]->img->imgs + 1, SRCPAINT);
					}
					else {
						putimage(player[i].hasplane[j]->place->x, player[i].hasplane[j]->place->y, player[i].hasplane[j]->img->imgs + 0, SRCAND);
						putimage(player[i].hasplane[j]->place->x, player[i].hasplane[j]->place->y, player[i].hasplane[j]->img->imgs + 1, SRCPAINT);
					}
				}
				//�����ɻ��ظ��λ
				else if (player[i].hasplane[j]->place->exp == 3 ) {
					if (player[i].hasplane[j]->place->ex_plane[0] == player[i].hasplane[j]) {
						putimage(player[i].hasplane[j]->place->x + 5, player[i].hasplane[j]->place->y + 5, player[i].hasplane[j]->img->imgs + 0, SRCAND);
						putimage(player[i].hasplane[j]->place->x + 5, player[i].hasplane[j]->place->y + 5, player[i].hasplane[j]->img->imgs + 1, SRCPAINT);
					}
					else if (player[i].hasplane[j]->place->ex_plane[1] == player[i].hasplane[j]) {
						putimage(player[i].hasplane[j]->place->x - 5, player[i].hasplane[j]->place->y - 5, player[i].hasplane[j]->img->imgs + 0, SRCAND);
						putimage(player[i].hasplane[j]->place->x - 5, player[i].hasplane[j]->place->y - 5, player[i].hasplane[j]->img->imgs + 1, SRCPAINT);
					}
					else {
						putimage(player[i].hasplane[j]->place->x, player[i].hasplane[j]->place->y, player[i].hasplane[j]->img->imgs + 0, SRCAND);
						putimage(player[i].hasplane[j]->place->x, player[i].hasplane[j]->place->y, player[i].hasplane[j]->img->imgs + 1, SRCPAINT);
					}
				}
				//�ĸ��ɻ��ظ��λ
				else if (player[i].hasplane[j]->place->exp == 4) {
					if (player[i].hasplane[j]->place->ex_plane[0] == player[i].hasplane[j]) {
						putimage(player[i].hasplane[j]->place->x + 5, player[i].hasplane[j]->place->y + 5, player[i].hasplane[j]->img->imgs + 0, SRCAND);
						putimage(player[i].hasplane[j]->place->x + 5, player[i].hasplane[j]->place->y + 5, player[i].hasplane[j]->img->imgs + 1, SRCPAINT);
					}
					else if (player[i].hasplane[j]->place->ex_plane[1] == player[i].hasplane[j]) {
						putimage(player[i].hasplane[j]->place->x - 5, player[i].hasplane[j]->place->y - 5, player[i].hasplane[j]->img->imgs + 0, SRCAND);
						putimage(player[i].hasplane[j]->place->x - 5, player[i].hasplane[j]->place->y - 5, player[i].hasplane[j]->img->imgs + 1, SRCPAINT);
					}
					else if (player[i].hasplane[j]->place->ex_plane[2] == player[i].hasplane[j]) {
						putimage(player[i].hasplane[j]->place->x, player[i].hasplane[j]->place->y, player[i].hasplane[j]->img->imgs + 0, SRCAND);
						putimage(player[i].hasplane[j]->place->x, player[i].hasplane[j]->place->y, player[i].hasplane[j]->img->imgs + 1, SRCPAINT);
					}

					else {
						putimage(player[i].hasplane[j]->place->x, player[i].hasplane[j]->place->y, player[i].hasplane[j]->img->imgs + 0, SRCAND);
						putimage(player[i].hasplane[j]->place->x, player[i].hasplane[j]->place->y, player[i].hasplane[j]->img->imgs + 1, SRCPAINT);
					}
				}
			}
		}
	}
	/*while (1) {
		creat_game();
	}*/
	/*for (int i = 0; i < 96; i++) {
		cout << i<<' '<<square[i].color << endl;
		putimage(square[i].x, square[i].y, pimg[0].imgs + 0, SRCAND);
		putimage(square[i].x, square[i].y, pimg[0].imgs + 1, SRCPAINT);
	}
	while (1);*/
	//for (int i = 0; i < 4; i++) {
	//	//putimage(square[16 + i].x, square[16 + i].y, pimg[i].imgs + 0, SRCAND);
	//	//putimage(square[16 + i].x, square[16 + i].y, pimg[i].imgs + 1, SRCPAINT);
	//	for (int j = 4 * i; j < 4 * (i + 1); j++) {
	//		putimage(square[j].x, square[j].y, pimg[i].imgs + 0, SRCAND);
	//		putimage(square[j].x, square[j].y, pimg[i].imgs + 1, SRCPAINT);
	//	}
	//	
	//}
	/*cout << "��ʼ����" << square[0].x << ' ' << square[0].y << endl;
	while (1) {
		creat_game(plane);
	}*/
}

//˵����Ϸ����
void explain_scene() {
	putimage(0, 0, res.imgs + 1);
	draw_button(returnhome);
	//��Ϣ�������ϻ�ȡ�����Ϣ
	while (1) {
		ExMessage m;
		while (peekmessage(&m, EM_MOUSE)) {
			if (isclickbutton(returnhome, m)) {
				home_scene();
			}
		}
	}

}

//������Ϸ����
void end_game(stplayer& player) {
	putimage(0, 0, res.imgs + 9);
	settextcolor(WHITE);
	settextstyle(60, 0, "����");
	int textw = textwidth(player.name);
	int texth = textheight(player.name);
	outtextxy(372+(250-textw)/2, 250, player.name);
	putimage(474, 173, player.img->imgs + 0, SRCAND);
	putimage(474, 173, player.img->imgs + 1, SRCPAINT);
	ExMessage m;
	while (1) {
		while (peekmessage(&m, EM_MOUSE)) {
			if (m.message == WM_LBUTTONDOWN) {
				home_scene();
			}
		}
	}
}