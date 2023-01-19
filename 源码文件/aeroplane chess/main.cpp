#include"global.h"  //库声明
#include"item.h"  //全局常量，全局变量声明
#include"some_struct.h"  //结构体声明
#include"event.h" //函数声明

int PLAYER_NUMBER;
int COMER_NUMBER;
int TOTAL_NUMBER;
int TURN = 0;
bool iscreat = false;  //判断是否设置了玩家
bool ROLLAGAIN = false;  //标记是否需要二次摇骰子
stplane* justoutplane = NULL;  //标记第二次摇骰子的运动飞机


int main() {
	
	//创建窗口
	initgraph(bkwidth, bkheight);
	//initgraph(bkwidth, bkheight, EW_SHOWCONSOLE);
	
	while (1) {
		//游戏初始化
		scene_init();
		//游戏主界面
		home_scene();
	}

	//关闭窗口
	closegraph();
	return 0;
}

//游戏运行
void run_game() {
	while (1) {
		//绘制游戏界面
		play_scene();
		//开始游戏
		creat_game();
	}
}


//文字解说 ok
//坐标疑似混乱 ok
//叠子分开  ok
//到达终点  ok