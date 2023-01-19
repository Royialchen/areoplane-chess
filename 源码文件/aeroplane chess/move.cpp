#include"global.h"  //库声明
#include"item.h"  //全局变量声明
#include"some_struct.h"  //结构体声明
#include"event.h" //函数声明

extern stsquare square[96];
extern stplane* justoutplane;
extern int PLAYER_NUMBER;
extern int COMER_NUMBER;
extern int TOTAL_NUMBER;
extern int TURN;
extern bool ROLLAGAIN;

//出机场
void out_airport(stplane* plane) {
	cout << "out_airport" << plane->number << endl;
	/*putimage(square[plane->color + 16].x, square[plane->color + 16].y, plane->img->imgs + 0, SRCAND);
	putimage(square[plane->color + 16].x, square[plane->color + 16].y, plane->img->imgs + 1, SRCPAINT);*/
	awaysquare(plane, plane->place);
	//重建plane到place的联系
	plane->place = &square[plane->color + 16];
	plane->state = 1;
	plane->havego = 1;
	cout << plane->number << endl;
	landsquare(plane, plane->place);
	//第二次摇骰子，指定刚刚出机场的飞机
	TURN--;
	ROLLAGAIN = true;
	justoutplane = plane;
	cout << "turn" << TURN << endl;
}

//返回机场
void return_airport(stplane* plane) {
	cout << "return_airport" << plane->number << endl;
	awaysquare(plane, plane->place);
	plane->place = &square[plane->color * 4 + plane->number];
	plane->state = 0;
	plane->havego = 0;
	landsquare(plane, plane->place);
}

//前进
void advance(stplane* plane, int dice ) {
	cout << "advance" << plane->state <<' '<<plane->havego <<' '<< plane->havego + dice << endl;
	//第二次摇骰子的情况
	if (ROLLAGAIN == true) {
		ROLLAGAIN = false;
		justoutplane = NULL;
	}
	awaysquare(plane, plane->place);
	//从起点出发
	if (plane->state == 1) {
		cout << "从起点出发" << endl;
		plane->place = &square[19 + plane->color * 13 + dice];
		plane->state = 2;
	}
	//本轮末尾进入分流跑道
	else if (plane->state == 2 && (plane->havego + dice) > 51 && (plane->havego + dice) != 57) {
		cout << "本轮末尾进入分流跑道" << endl;
		//超出普通跑道的格数在分流跑道上前进
		//plane->place = &square[plane->place->number + dice - ((49 + plane->color * 13) % 52 + 20) + 71 + 6 * (plane->color)];
		plane->place = &square[plane->havego + dice - 51 + 71 + 6 * (plane->color)];
		plane->state = 3;
	}
	//本轮末尾仍在普通跑道
	else if (plane->state == 2 && (plane->havego + dice) != 57) {
		cout << "本轮末尾仍在普通跑道" << endl;
		plane->place = &square[(plane->place->number + dice - 20) % 52 + 20];
	}
	//本轮停在分流跑道末尾
	else if (plane->state == 3 && plane->place->number + dice == 77 + 6 * (plane->color) || plane->state == 2 && (plane->havego + dice) == 57) {
		cout << "本轮停在分流跑道末尾" << endl;
		plane->place = &square[77 + 6 * (plane->color)];
		landsquare(plane, plane->place);

		play_scene();
		show_dice(dice);

		settextstyle(22, 0, "仿宋");
		outtextxy(780, 500, "小飞机到达终点啦");
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
	//本轮未到分流跑道末尾
	else if (plane->state == 3 && plane->place->number + dice < 77 + 6 * (plane->color)) {
		cout << "本轮未到分流跑道末尾" << endl;
		plane->place = &square[plane->place->number + dice];
	}
	//本轮超出分流跑道末尾，反弹
	else if (plane->state == 3 && plane->place->number + dice > 77 + 6 * (plane->color)) {
		rebound(plane, dice);
	}

	plane->havego += dice;

	//本轮末尾在同色格子，飞行或者跳跃
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

//反弹
void rebound(stplane* plane, int dice) {
	cout << "reound" << endl;
	plane->place = &square[77 + 6 * (plane->color) - (plane->place->number + dice - (77 + 6 * (plane->color)))];
}

//同色跳跃
void jump(stplane* plane) {
	cout << "jump" << endl;
	plane->place = &square[(plane->place->number + 4 - 20) % 52 + 20];
	plane->havego += 4;

}

//飞行
void fly(stplane* plane) {
	cout <<"fly"<< endl;
	plane->place = &square[((29 + plane->color * 13) % 52 + 20)];
	plane->havego += 12;
}

//飞机离开格子,断开place到plane的联系
void awaysquare(stplane* plane, stsquare* square) {
	cout << "away" << plane->place->number << endl;
	for (int i = 0; i < 4; i++) {
		if (square->ex_plane[i] == plane) {
			square->ex_plane[i] = NULL;
			int j = i;
			//确保叠子绘制的可视化
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

//飞机降落在格子内,建立place到plane的联系
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

//棋子落点处有多个棋子
void in_same_square(stplane* plane, stsquare* square) {
	cout << "same_square" << endl;
	cout << plane->color << endl;

	for (int i = 0; i < 4; i++) {
		cout << "判断" << endl;
		if (square->ex_plane[i] != plane && square->ex_plane[i] != NULL) {
			//异色返回
			cout << "有多个" << endl;
			if (square->ex_plane[i]->color != plane->color) {
				cout << "异色飞机" << endl;
				return_airport(square->ex_plane[i]);
			}
			else {
				cout << "同色" << endl;
				;
			}
		}
	}

}