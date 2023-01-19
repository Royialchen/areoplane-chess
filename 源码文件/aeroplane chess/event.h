#pragma once
//函数声明

//窗口初始化
void scene_init();
//游戏主界面
void home_scene();
//设置游戏界面
void set_scene();
void set2_scene(int n1, int np);
//开始游戏界面
void play_scene();
//说明游戏界面
void explain_scene();
//结束游戏界面
void end_game(stplayer& player);

//生成按钮
button* creat_button(int x, int y, int w, int h, const char* str , COLORREF incolor, COLORREF outcolor);
//绘制按钮
void draw_button(button* pb);
//判断鼠标位置
bool isinbutton(button* pb, ExMessage m);
//鼠标点击
bool isclickbutton(button* pb, ExMessage m);
//改变按钮颜色
void changecolor(button* pb, ExMessage m);

//处理输入（将输入显示并不断刷新按钮）
void input(ExMessage m, button* pb, int type, int* val = NULL, char* str = NULL);   //type=1代表一位输入，type=0代表字符输入

//生成跑道
void creat_runway();
//生成玩家
void creat_player(int k, char* name, const char* strcolor);


//游戏运行
void run_game();
//判断输赢
void judge(stplayer& player);
//开始游戏
void creat_game();

//摇骰子
int roll_dice();
//显示骰子图片
void show_dice(int ndice);

// 判断真人还是电脑
void real_or_com(stplayer &player, int dice);
//选择方案（真人玩家）
void choose_strategy(stplayer &player, int dice);
//随机方案（电脑玩家）
void random_strategy(stplayer &player, int dice);

//点击飞机
bool isclickplane(ExMessage m, stplane* plane);
//出机场
void out_airport(stplane* plane);
//返回机场
void return_airport(stplane* plane);
//前进
void advance(stplane* plane, int dice);
//反弹
void rebound(stplane* plane, int dice);
//同色跳跃
void jump(stplane* plane);
//飞行
void fly(stplane* plane);

//棋子落点处有多个棋子
void in_same_square(stplane* plane, stsquare* square);
//飞机离开格子,断开place到plane的联系
void awaysquare(stplane* plane, stsquare* square);
//飞机降落在格子内,建立place到plane的联系
void landsquare(stplane* plane, stsquare* square);

//指定骰子数
int pardice();
