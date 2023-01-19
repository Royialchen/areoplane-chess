#include"global.h"  //库声明
#include"item.h"  //全局变量声明
#include"some_struct.h"  //结构体声明
#include"event.h" //函数声明

extern resource res;
extern resource pimg[4];
extern resource dice;
extern button* exitgame;

extern int PLAYER_NUMBER;
extern int COMER_NUMBER;
extern int TOTAL_NUMBER;
extern int TURN;
extern bool ROLLAGAIN;
extern bool iscreat;

stplayer player[4];
stplane plane[16];
stsquare square[96];   //4*4个机场，4个起点，52个普通跑道，4*6个分流跑道
//int fcol[4];


//生成跑道
void creat_runway() {

	for (int i = 0; i < 96; i++) {
		square[i].number = i;
		for (int j = 0; j < 4; j++) {
			square[i].ex_plane[j] = NULL;
		}
		square[i].exp = 0;
	}
	//机场*16
	square[0].x = 585; square[0].y = 590; square[0].color = red; 
	square[1].x = 643; square[1].y = 590; square[1].color = red; 
	square[2].x = 585; square[2].y = 650; square[2].color = red; 
	square[3].x = 643; square[3].y = 650; square[3].color = red; 
	square[4].x = 100; square[4].y = 590; square[4].color = green;
	square[5].x = 155; square[5].y = 590; square[5].color = green;
	square[6].x = 100; square[6].y = 650; square[6].color = green;
	square[7].x = 155; square[7].y = 650; square[7].color = green;
	square[8].x = 99; square[8].y = 92; square[8].color = yellow;
	square[9].x = 155; square[9].y = 92; square[9].color = yellow;
	square[10].x = 99; square[10].y = 150; square[10].color = yellow;
	square[11].x = 155; square[11].y = 150; square[11].color = yellow;
	square[12].x = 585; square[12].y = 92; square[12].color = blue;
	square[13].x = 643; square[13].y = 92; square[13].color = blue;
	square[14].x = 585; square[14].y = 150; square[14].color = blue;
	square[15].x = 643; square[15].y = 150; square[15].color = blue;
	//起点*4
	square[16].x = 680; square[16].y = 515; square[16].color = red;
	square[17].x = 230; square[17].y = 690; square[17].color = green;
	square[18].x = 60; square[18].y = 230; square[18].color = yellow;
	square[19].x = 510; square[19].y = 55; square[19].color = blue;

	//跑道x
	square[20].x = 630; square[66].x = 630; square[75].x = 482;
	square[21].x = 595; square[65].x = 595; square[72].x = 590;
	square[22].x = 557; square[64].x = 557; square[73].x = 553;
	square[23].x = 518; square[63].x = 518; square[74].x = 517;
								   					   
	square[28].x = 445; square[58].x = 445; square[76].x = 445;
	square[29].x = 408; square[57].x = 408; square[77].x = 405;
	square[30].x = 370; square[56].x = 370;			   
	square[31].x = 333; square[55].x = 333; square[89].x = 335;
	square[32].x = 295; square[54].x = 295; square[88].x = 295;
								   					   
	square[37].x = 227; square[49].x = 227; square[86].x = 225;
	square[38].x = 187; square[48].x = 187; square[85].x = 187;
	square[39].x = 150; square[47].x = 150; square[84].x = 150;
	square[40].x = 113; square[46].x = 113; square[87].x = 260;
	for (int i = 20; i < 96; i++) {

		if (24 < i && i < 27 || 59 < i && i < 62) { square[i].x = 500; }
		else if (i == 24 || i == 27 || i == 59 || i == 62) { square[i].x = 485; }
		else if (67 <= i && i <= 71) { square[i].x = 643; }
		else if (33 < i && i < 36 || 50 < i && i < 53) { square[i].x = 241; }
		else if (i == 33 || i == 36 || i == 50 || i == 53) { square[i].x = 258; }
		else if (41 <= i && i <= 45) { square[i].x = 96; }
		else if (78 <= i && i <= 83 || 90 <= i && i <= 95) { square[i].x = 370; }

	}
	//跑道y
	square[24].y = 520; square[36].y = 520; square[80].y = 524;
	square[25].y = 560; square[35].y = 560; square[79].y = 562;
	square[26].y = 597; square[34].y = 597; square[78].y = 598;
	square[27].y = 638; square[33].y = 638; square[81].y = 485;

	square[41].y = 447; square[71].y = 447; square[82].y = 448;
	square[42].y = 410; square[70].y = 410; square[83].y = 406;
	square[43].y = 373; square[69].y = 373;				   
	square[44].y = 336; square[68].y = 336; square[95].y = 338;
	square[45].y = 299; square[67].y = 299; square[94].y = 296;

	square[50].y = 225; square[62].y = 225; square[92].y = 220;
	square[51].y = 185; square[61].y = 185; square[91].y = 183;
	square[52].y = 147; square[60].y = 147; square[90].y = 147;
	square[53].y = 107; square[59].y = 107; square[93].y = 258;
	for (int i = 20; i < 96; i++) {

		if (20 < i && i < 23 || 37 < i && i < 40) { square[i].y = 505; }
		else if (i == 20 || i == 23 || i == 37 || i == 40) { square[i].y = 485; }
		else if (28 <= i && i <= 32) { square[i].y = 654; }
		else if (46 < i && i < 49 || 63 < i && i < 66) {square[i].y = 242; }
		else if (i == 46 || i == 49 || i == 63 || i == 66) { square[i].y = 259; }
		else if (54 <= i && i <= 58) { square[i].y = 92; }
		else if (72 <= i && i <= 77 || 84 <= i && i <= 89) { square[i].y = 373; }
		
	}
	//格子颜色
	for (int i = 20; i < 96; i++) {
		if (i <= 71) { square[i].color = (fcolor)((i - 1) % 4); }
		else if (72 <= i && i <= 77) { square[i].color = red; }
		else if (78 <= i && i <= 83) { square[i].color = green; }
		else if (84 <= i && i <= 89) { square[i].color = yellow; }
		else if (90 <= i && i <= 95) { square[i].color = blue; }

	}
}

//生成玩家
void creat_player(int k, char* name, const char* strcolor) {
	//creat_runway();
	//player[k].number = k;;
	//真人玩家
	//if (type == 0) {
	iscreat = true;
	//玩家昵称
	player[k].name = name;
	cout << "玩家" << player[k].name << ' ' << strcolor << endl;
	cout << square[0].x << square[0].y << endl;
	//pimg[k].imgs[0] = res.imgs+9;
	//loadimage(pimg[k].imgs[0], "image/img13.jpg", 50, 50);   //棋子白底黑图
	
	//玩家棋子颜色
	if (strcmp(strcolor,"r")==0){
		player[k].plane_color = red;
		player[k].img = &pimg[0];
		//pimg[k].imgs[1] = res.imgs+10;
		//loadimage(pimg[k].imgs[1], "image/img14.jpg", 50, 50);   //红棋子
		//fcol[0] = 1;
	}
	else if (strcmp(strcolor, "g")==0) {
		player[k].plane_color = green;
		player[k].img = &pimg[1];
		//pimg[k].imgs[1] = res.imgs+11;
		//fcol[1] = 1;
	}
	else if (strcmp(strcolor, "y")==0) {
		player[k].plane_color = yellow;
		player[k].img = &pimg[2];
		//pimg[k].imgs[1] = res.imgs+12;
		//fcol[2] = 1;
	}
	else if (strcmp(strcolor, "b")==0) {
		player[k].plane_color = blue;
		player[k].img = &pimg[3];
		//pimg[k].imgs[1] = res.imgs+13;
		//fcol[3] = 1;
	}
	//cout << player[k].plane_color << endl;
	//cout << square[player[k].plane_color * 4 + 0].x << square[player[k].plane_color * 4 + 0].y << endl;
	//玩家的棋子
	int t = 0;
	for (int i = 4 * k; i < 4 * (k + 1); i++) {
		plane[i].number = i % 4;                //可作为从player到plane访问的数组下标
		plane[i].color = player[k].plane_color;
		plane[i].player = &player[k];           //构建从plane到player的访问联系
		plane[i].place = &square[player[k].plane_color * 4 + t];   //构建从plane到place的访问联系

		//cout << player[k].plane_color * 4 + t << endl;
		//cout <<"棋子"<< square[player[k].plane_color * 4 + t].x << square[player[k].plane_color * 4 + t].y << endl;

		plane[i].state = 0;                     //初始在机场
		plane[i].img = player[k].img;           //图片指针
		plane[i].havego = 0;

		player[k].hasplane[t] = &plane[i];  //构建从player到plane的访问联系
		plane[i].place->ex_plane[0] = &plane[i];   //构建从place到plane的访问联系
		plane[i].place->exp = 1;
		
		//cout << "飞机" << i << ' ' << player[k].plane_color << ' ' <<t<<' ' << player[k].hasplane[t]->place->x << player[k].hasplane[t]->place->y << endl;
		t++;
	}

	//玩家类型
	if (k < PLAYER_NUMBER) {
		player[k].type = 0;
	}
	else {
		player[k].type = 1;
	}
	return;

	//}
	////电脑玩家
	//else {
	//	//char* c = NULL;
	//	strcpy(player[k].name, "电脑玩家");
	//	cout << "玩家"<<player[k].name << endl;
	//	//player[k].name = c;

	//	for (int i = 0; i < 4; i++) {
	//		if (fcol[i] == 0) {
	//			player[k].plane_color = (fcolor)2;
	//		}
	//	}
	//}

	

	/*if (k < pn - 1) {
		return;
	}
	else if (k == pn - 1 && pn < tn) {
		return creat_player(k + 1, pn, tn, 1);
	}
	else if (pn <= k && k < tn - 1) {
		return creat_player(k + 1, pn, tn, 1);
	}
	else {
		return home_scene();
	}*/
}

//开始游戏
void creat_game() {
	//creat_runway();
	//cout << "开始游戏" << square[0].x << ' ' << square[0].y << endl;
	cout << "creat_game" << endl;
	int dice = roll_dice();
	//int dice = pardice();
	cout << "dice" << dice << endl;
	bool f = true;
	while (1) {
		ExMessage m;
		while (peekmessage(&m, EM_MOUSE)) {
			if (isclickbutton(exitgame, m)) {
				home_scene();
			}
			if (m.x > 810 && m.x < 910 && m.y > 300 && m.y < 400 && m.message == WM_LBUTTONDOWN) {
				//putimage(810, 300, dice.imgs + ndice);
				//cout << TURN << ' ' << TOTAL_NUMBER << endl;
				//cout << "put" << endl;
				cout <<"本轮玩家" << TURN % TOTAL_NUMBER <<' '<< player[TURN % TOTAL_NUMBER].name<< endl;
				show_dice(dice);
				real_or_com(player[TURN % TOTAL_NUMBER], dice);
				judge(player[TURN % TOTAL_NUMBER]);

				return;
			}
			
			
		}
	}
}