#include"global.h"  //库声明
#include"item.h"  //全局变量声明
#include"some_struct.h"  //结构体声明
#include"event.h" //函数声明

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

resource res;   //定义一个全局资源变量
resource dice;
resource pimg[4];

//创建按钮
button* set = creat_button(button_zx, 450, 250, 100, "设置游戏", RGB(24, 144, 285), RGB(49, 186, 233));
button* play = creat_button(button_zx, 600, 250, 100, "开始游戏", RGB(24, 144, 285), RGB(49, 186, 233));
button* explain = creat_button(button_zx, 300, 250, 100, "游戏说明", RGB(24, 144, 285), RGB(49, 186, 233));
button* exitgame = creat_button(820, 710, 150, 80, "退出", RGB(24, 144, 285), RGB(49, 186, 233));
button* returnhome = creat_button(820, 710, 150, 80, "返回", RGB(24, 144, 285), RGB(49, 186, 233));
button* confirm = creat_button(425, 710, 150, 80, "确定", RGB(24, 144, 285), RGB(49, 186, 233));
button* buplayer = creat_button(500, 280, 150, 80, "", RGB(255, 255, 255), RGB(255, 255, 255));
button* bucom = creat_button(500, 380, 150, 80, "", RGB(255, 255, 255), RGB(255, 255, 255));
button* buname[4];
button* bucolor[4];

//RECT inplayer={ 500, 300, 150, 80 }, incom={ 500, 280, 600, 330 };

//资源初始化
void res_init(resource* res,resource pimg[],resource* dice) {
	loadimage(res->imgs + 0, "image/img1.jpg", getwidth(), getheight());
	loadimage(res->imgs + 1, "image/img2.png", getwidth(), getheight());
	loadimage(res->imgs + 2, "image/img4.png", getwidth(), getheight());
	loadimage(res->imgs + 3, "image/img12.jpg", 700, 700);  //棋盘白底黑色
	loadimage(res->imgs + 4, "image/img11.jpg", 700, 700);  //棋盘黑底彩色
	loadimage(res->imgs + 5, "image/img9.jpg", 480, 300);  //小飞机白底黑色
	loadimage(res->imgs + 6, "image/img8.jpg", 480, 300);  //小飞机黑底彩色
	loadimage(res->imgs + 7, "image/img4.jpg", 300, 300);  //小飞机2白底黑色
	loadimage(res->imgs + 8, "image/img5.jpg", 300, 300);  //小飞机2黑底彩色
	loadimage(res->imgs + 9, "image/img3.jpg", getwidth(), getheight());  //结束游戏
	//loadimage(res->imgs + 10, "image/2.jpg", 50, 40);  //光晕白底黑色
	//loadimage(res->imgs + 11, "image/1.jpg", 50, 40);  //光晕黑底彩色
	//loadimage(res->imgs + 9, "image/img13.jpg", 50, 50);   //棋子白底黑图
	//loadimage(res->imgs + 10, "image/img14.jpg", 50, 50);   //红棋子
	//loadimage(res->imgs + 11, "image/img15.jpg", 50, 50);   //绿棋子
	//loadimage(res->imgs + 12, "image/img17.ipg", 50, 50);   //黄棋子
	//loadimage(res->imgs + 13, "image/img16.jpg", 50, 50);   //蓝棋子
	loadimage(pimg[0].imgs + 0, "image/img13.jpg", 50, 50);;  //棋子白底黑图
	loadimage(pimg[0].imgs + 1, "image/img14.jpg", 50, 50);  //红棋子
	loadimage(pimg[1].imgs + 0, "image/img13.jpg", 50, 50);   //棋子白底黑图
	loadimage(pimg[1].imgs + 1, "image/img15.jpg", 50, 50);   //绿棋子
	loadimage(pimg[2].imgs + 0, "image/img13.jpg", 50, 50);   //棋子白底黑图
	loadimage(pimg[2].imgs + 1, "image/img17.jpg", 50, 50);   //黄棋子
	loadimage(pimg[3].imgs + 0, "image/img13.jpg", 50, 50);   //棋子白底黑图
	loadimage(pimg[3].imgs + 1, "image/img16.jpg", 50, 50);   //蓝棋子
	loadimage(dice->imgs + 0, "image/20.jpg", 100, 100);
	loadimage(dice->imgs + 1, "image/21.jpg", 100, 100);
	loadimage(dice->imgs + 2, "image/22.jpg", 100, 100);
	loadimage(dice->imgs + 3, "image/23.jpg", 100, 100);
	loadimage(dice->imgs + 4, "image/24.jpg", 100, 100);
	loadimage(dice->imgs + 5, "image/25.jpg", 100, 100);
	loadimage(dice->imgs + 6, "image/26.jpg", 100, 100);

}

//窗口初始化
void scene_init() {

	//修改窗口名字
	HWND hnd = GetHWnd();
	SetWindowTextA(hnd, "飞行棋~~~~");

	//加载图片资源
	res_init(&res,pimg,&dice);

	//创建跑道
	creat_runway();
	cout << "刚刚初始化" << square[0].x <<' ' << square[0].y << endl;
	cout << "刚刚初始化" << square[9].ex_plane[3]<< endl;
}

//绘制棋局
void home_scene() {
	//creat_runway();
	//绘制图片
	putimage(0, 0, res.imgs + 0);
	putimage(530, 50, res.imgs + 5, SRCAND);
	putimage(530, 50, res.imgs + 6, SRCPAINT);
	putimage(50, 530, res.imgs + 7, SRCAND);
	putimage(50, 530, res.imgs + 8, SRCPAINT);

	settextcolor(WHITE);
	setbkmode(TRANSPARENT);  //去除文字背景
	settextstyle(140, 0, "华文行楷");
	outtextxy(40, 160, "飞行棋");

	//绘制按钮
	settextcolor(BLACK);
	settextstyle(45, 0, "楷体");
	draw_button(set);
	draw_button(play);
	draw_button(explain);

	//修改窗口背景颜色
	//setbkcolor(RGB(254,241,209));

	//修改逻辑坐标系
	//setorigin(bkwidth / 2, bkheight / 2);  //原点
	//setaspectratio(-1, 1);  //坐标轴方向

	//刷新窗口(用当前背景色清屏，现在不用背景色，所以不用清屏)
	//cleardevice();

	//双缓冲绘制
	//BeginBatchDraw();
	
	cout << "主界面" << square[0].x << ' ' << square[0].y << endl;
	while (1) {      //关键！
		ExMessage m;
		//消息处理，不断获取鼠标信息（防止消息堆积）
		
		while (peekmessage(&m, EM_MOUSE)) {
			
			//跳转设置界面
			if (isclickbutton(set, m)) {
				set_scene();
			}
			//跳转开始游戏界面
			if (isclickbutton(play, m)) {
				if(iscreat == false){ 
					MessageBox(NULL, "请先设置游戏", "False", MB_SYSTEMMODAL); 
				}
				else {
					run_game();
					//cleardevice();
					//creat_runway();
					//creat_game();
				}
			}
			//跳转说明界面
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

//设置游戏界面
void set_scene() {
	putimage(0, 0, res.imgs + 2);
	//putimage(0, 0, pimg[0].imgs + 0, SRCAND);
	//putimage(0, 0, pimg[0].imgs + 1, SRCPAINT);
	
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);  //去除文字背景
	settextstyle(30, 0, "仿宋");
	outtextxy(200, 300, "请输入真人玩家人数：");
	outtextxy(200, 400, "请输入电脑玩家人数：");
	settextstyle(20, 0, "等线");
	outtextxy(410, 620, "请按回车键确认输入！");
	outtextxy(410, 650, "2 <= 玩家总人数 <= 4");
	//rectangle(500, 80, 600, 130);
	//rectangle(500, 280, 600, 330);

	//draw_button(returnhome);
	settextstyle(45, 0, "楷体");
	draw_button(confirm);
	draw_button(buplayer);
	draw_button(bucom);


	////输入，不可放入循环中
	//char s[5], c[5];
	//InputBox(s, 5, "请输入真人玩家人数：");
	// 
	// 
	//InputBox(c, 5, "请输入电脑玩家人数：");
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
	//	MessageBox(NULL, "错误的输入", "False", MB_SYSTEMMODAL);
	//	set_scene();
	//}
	
	cout << "输入人数界面" << square[0].x << ' ' << square[0].y << endl;
	//消息处理，不断获取鼠标信息
	while (1) {
		ExMessage m;
		//bool f1 = false, f2 = false;
		while (peekmessage(&m, EM_MOUSE)) {
			//if (isclickbutton(returnhome, m)) {
			//	//return;
			//	return home_scene();
			//}
			//输入玩家
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
			//跳转界面
			if (isclickbutton(confirm, m) && buplayer->text != "" && bucom->text != "") {
				//int n1= *(buplayer->text)-'0', n2= *(bucom->text) - '0';
				int n1 = PLAYER_NUMBER, n2 = COMER_NUMBER;
				TOTAL_NUMBER = PLAYER_NUMBER + COMER_NUMBER;
				//cout << TOTAL_NUMBER << endl;
				if (n1 + n2 > 4 || n1 + n2 < 2) {
					MessageBox(NULL, "2 <= 玩家总人数 <= 4", "False", MB_SYSTEMMODAL);    //需要删除原先输入后重新输入
					
				}
				else{
					//cout << "输入人数后" << square[0].x << ' ' << square[0].y << endl;
					set2_scene(n1, n2);
				}
				
			}

		}
	}
	
	
}

//设置界面2
void set2_scene(int n1,int n2) {
	cout << TURN << ' ' << TOTAL_NUMBER << endl;
	putimage(0, 0, res.imgs + 2);
	settextstyle(45, 0, "楷体");
	draw_button(returnhome);
	//draw_button(confirm);

	settextcolor(BLACK);
	setbkmode(TRANSPARENT);  //去除文字背景
	settextstyle(20, 0, "等线");
	outtextxy(280, 650, "颜色输入: r代表红色 g代表绿色 y代表黄色 b代表蓝色");
	settextstyle(30, 0, "仿宋");
	
	//绘制输入框与提示
	int i;
	for ( i = 0; i < TOTAL_NUMBER; i++) {
		//char* c=NULL;
		//sprintf(c, "玩家%d昵称：",i);
		outtextxy(150, 200+i*100, "玩家昵称：");
		if (i < n1) {
			buname[i] = creat_button(300, 180 + i * 100, 200, 80, "", RGB(255, 255, 255), RGB(255, 255, 255));
		}
		else {
			buname[i] = creat_button(300, 180 + i * 100, 200, 80, "电脑", RGB(255, 255, 255), RGB(255, 255, 255));
		}
		draw_button(buname[i]);

		outtextxy(520, 200+i*100, "输入棋子颜色：");
		bucolor[i] = creat_button(730, 180 + i * 100, 100, 80, "", RGB(255, 255, 255), RGB(255, 255, 255));
		draw_button(bucolor[i]);
	}
	
	/*for (i = n1; i < n2; i++) {
		outtextxy(150, 200 + i * 100, "玩家昵称：");
		buname[i] = creat_button(300, 180 + i * 100, 200, 80, "电脑玩家", RGB(255, 255, 255), RGB(255, 255, 255));
		draw_button(buname[i]);

		outtextxy(520, 200 + i * 100, "选择棋子颜色：");
		bucolor[i] = creat_button(730, 180 + i * 100, 100, 80, "", RGB(255, 255, 255), RGB(255, 255, 255));
		draw_button(bucolor[i]);
	}*/
	
	//if (n2 > 0) { outtextxy(150, 200 + i * 100, "电脑玩家随机生成"); }

	cout << "输入具体" << square[0].x << ' ' << square[0].y << endl;
	while (1) {
		ExMessage m;
		while (peekmessage(&m, EM_MOUSE)) {          //获取鼠标信息，一旦鼠标移动就处理消息
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

//绘制开始游戏界面
void play_scene() {
	//creat_runway();
	cout << "新一轮" << endl;
	cout << "drawplay" << endl;
	cout << "TURN" << TURN << ' ' << "TOTAL_NUMBER" << TOTAL_NUMBER << endl;

	putimage(0, 0, res.imgs + 0);   //覆盖
	//cleardevice();   //刷新
	//棋盘
	putimage(50, 50, res.imgs + 3, SRCAND);   //白底黑图按位与
	putimage(50, 50, res.imgs + 4, SRCPAINT); //黑底彩图按位或

	//按钮
	settextstyle(45, 0, "楷体");
	draw_button(exitgame);

	//本轮飞机
	putimage(830, 150, player[TURN % TOTAL_NUMBER].img->imgs + 0, SRCAND);
	putimage(830, 150, player[TURN % TOTAL_NUMBER].img->imgs + 1, SRCPAINT);

	//玩家
	settextstyle(30, 0, "仿宋");
	outtextxy(770, 200, "本轮玩家：");
	outtextxy(905, 200, player[TURN % TOTAL_NUMBER].name);

	//骰子
	putimage(810, 300, dice.imgs + 0);
	settextstyle(18, 0, "仿宋");
	outtextxy(770, 280, "点击骰子图片进行摇骰子");

	//putimage(player[0].hasplane[0]->place->x, player[0].hasplane[0]->place->y, player[0].img->imgs + 0, SRCAND);
	//putimage(player[0].hasplane[0]->place->x, player[0].hasplane[0]->place->y, player[0].hasplane[0]->img->imgs + 1, SRCPAINT);
	//cout << "开始界面1" << square[0].x << ' ' << square[0].y << endl;
	
	// 到达终点记录
	int c = 0;
	for (int i = 0; i < TOTAL_NUMBER; i++) {
		c = 0;
		for (int j = 0; j < 4; j++) {
			if (player[i].hasplane[j]->state < 0) {
				c++;
			}
		}
		outtextxy(square[player[i].plane_color * 4].x - 18, square[player[i].plane_color * 4].y - 17, "到达终点棋子:");
		switch (c) {
		case 0:outtextxy(square[player[i].plane_color * 4].x + 103, square[player[i].plane_color * 4].y - 17, "无"); break;
		case 1:outtextxy(square[player[i].plane_color * 4].x + 103, square[player[i].plane_color * 4].y - 17, "1"); break;
		case 2:outtextxy(square[player[i].plane_color * 4].x + 103, square[player[i].plane_color * 4].y - 17, "2"); break;
		case 3:outtextxy(square[player[i].plane_color * 4].x + 103, square[player[i].plane_color * 4].y - 17, "3"); break;
		}
		

	}
	//棋子
	for (int i = 0; i < TOTAL_NUMBER; i++) {
		for (int j = 0; j < 4; j++) {
			if (player[i].hasplane[j]->state >= 0) {
				if (player[i].hasplane[j]->place->exp == 1) {
					putimage(player[i].hasplane[j]->place->x, player[i].hasplane[j]->place->y, player[i].hasplane[j]->img->imgs + 0, SRCAND);
					putimage(player[i].hasplane[j]->place->x, player[i].hasplane[j]->place->y, player[i].hasplane[j]->img->imgs + 1, SRCPAINT);
				}
				//两个飞机重格错位
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
				//三个飞机重格错位
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
				//四个飞机重格错位
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
	/*cout << "开始界面" << square[0].x << ' ' << square[0].y << endl;
	while (1) {
		creat_game(plane);
	}*/
}

//说明游戏界面
void explain_scene() {
	putimage(0, 0, res.imgs + 1);
	draw_button(returnhome);
	//消息处理，不断获取鼠标信息
	while (1) {
		ExMessage m;
		while (peekmessage(&m, EM_MOUSE)) {
			if (isclickbutton(returnhome, m)) {
				home_scene();
			}
		}
	}

}

//结束游戏界面
void end_game(stplayer& player) {
	putimage(0, 0, res.imgs + 9);
	settextcolor(WHITE);
	settextstyle(60, 0, "仿宋");
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