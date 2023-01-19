#include"global.h"  //库声明
#include"item.h"  //全局变量声明
#include"some_struct.h"  //结构体声明
#include"event.h" //函数声明

extern int PLAYER_NUMBER;
extern int COMER_NUMBER;
extern int TOTAL_NUMBER;
extern int TURN;
extern bool ROLLAGAIN;

extern stplane* justoutplane;

//判断真人还是电脑
void real_or_com(stplayer &player, int dice) {
	cout << "real_or_com" << endl;
	settextstyle(22, 0, "仿宋");
	//cout << PLAYER_NUMBER << endl;
	if (TURN % TOTAL_NUMBER < PLAYER_NUMBER) {
		choose_strategy(player, dice);
	}
	else {
		random_strategy(player, dice);
	}
}

//选择方案（真人玩家）
void choose_strategy(stplayer &player, int dice) {
	cout << "真人" << endl;
	ExMessage m;
	//第二次摇骰子，刚刚出来的飞机前进
	if (ROLLAGAIN == true) {
		outtextxy(770, 500, "刚刚出发的小飞机冲啊");
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
		//有棋子在机场，并不是所有都在外面
		if (player.hasplane[i]->state == 0) {
			allout = false;
		}
		//有棋子在外面
		else if(player.hasplane[i]->state > 0) {
			allin = false;
		}
		
	}
	cout <<"allout"<< allout << ' ' <<"allin" << allin << endl;
	if (dice == 6) {
		outtextxy(770, 500, "快选择你的小飞机吧！");
		while (1) {
			while (peekmessage(&m, EM_MOUSE)) {
				for (int i = 0; i < 4; i++) {
					cout << i << endl;
					cout << "choose" << player.hasplane[i]->state << endl;
					//有棋子在机场，选择的棋子在机场                  ok
					if (isclickplane(m, player.hasplane[i]) && allout == false && player.hasplane[i]->state == 0) {
						out_airport(player.hasplane[i]);
						return;   //若没有return则一直死循环
					}
					//有棋子在机场，但选择外面的棋子
					else if (isclickplane(m, player.hasplane[i]) && allout == false && player.hasplane[i]->state > 0) {
						MessageBox(NULL, "该棋子不可选择，请重新选择", "False", MB_SYSTEMMODAL);
					}
					//全部棋子在外面，选择的棋子在外面                 ok
					else if (isclickplane(m, player.hasplane[i]) && allout == true && player.hasplane[i]->state > 0) {
						advance(player.hasplane[i], dice);
						return;
					}
				}
			}
		}
	}
	//非6
	else {
		//全部棋子在机场，无法选择    ok
		if (allin == true) {
			outtextxy(760, 500, "太遗憾了,下轮运气+1");
			while (1) {
				while (peekmessage(&m, EM_MOUSE)) {
					if (m.message == WM_LBUTTONDOWN) {
						return;
					}
				}
			}
		}
		outtextxy(770, 500, "快选择你的小飞机吧!");
		while (1) {
			while (peekmessage(&m, EM_MOUSE)) {
				for (int i = 0; i < 4; i++) {
					//有棋子在机场，选择的棋子在机场
					if (isclickplane(m, player.hasplane[i]) && allout == false && player.hasplane[i]->state == 0) {
						MessageBox(NULL, "该棋子不可选择，请重新选择", "False", MB_SYSTEMMODAL);
					}
					//有棋子在机场，选择外面的棋子
					else if (isclickplane(m, player.hasplane[i]) && allout == false && player.hasplane[i]->state > 0) {
						advance(player.hasplane[i], dice);
						return;
					}
					//全部棋子在外面，选择的棋子在外面
					else if (isclickplane(m, player.hasplane[i]) && allout == true && player.hasplane[i]->state > 0) {
						advance(player.hasplane[i], dice);
						return;
					}
				}
			}
		}
	}

	//for (int i = 0; i < 4; i++) {
	//	//有棋子仍在机场，并不是所有都在外面
	//	if (player.hasplane[i]->state == 0) {
	//		allout = false;      
	//		//有棋子在机场且可以玩家继续摇骰子
	//		if (dice == 6 ) {
	//			out_airport(player.hasplane[i]);
	//			//return play_scene(player.hasplane[i]);   
	//		}
	//	}
	//}
	////所有棋子都在机场外
	//if (allout == true) {  
	//	for (int i = 0; i < 4; i++) {
	//		if (player.hasplane[i]->state > 0) { 
	//			//选择
	//			advance(player.hasplane[i],dice);
	//			TURN++;
	//			//return play_scene();
	//		}
	//	}
	//}
	//else {
	//	//有棋子在机场但轮到下一玩家
	//	TURN++;
	//	//return play_scene();   
	//}
}

//随机方案（电脑玩家）
void random_strategy(stplayer& player, int dice) {
	cout << "电脑" << endl;
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
		//有棋子在机场
		if (player.hasplane[i]->state == 0) {
			allout = false;   

			//选择第一个在机场的棋子出发         ok
			if (dice == 6 ) {
				outtextxy(770, 500, "自动式飞机出发");
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
		//有棋子在外面
		else if (player.hasplane[i]->state > 0) {
			allin = false;
		}
	}
	//全部棋子在机场，非6，无法选择  ok
	if (allin == true && dice != 6) { 
		outtextxy(770, 500, "这个电脑就是逊啦");
		//return; 
		while (1) {
			while (peekmessage(&m, EM_MOUSE)) {
				if (m.message == WM_LBUTTONDOWN) {
					return;
				}
			}
		}
	}
	//有棋子在机场外
	else if (allin == false) {  
		outtextxy(770, 500, "电脑随机选择飞机");
		//随机选择一个棋子移动                ok
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

//点击飞机
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
