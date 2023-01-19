#include"global.h"  //库声明
#include"item.h"  //全局常量，全局变量声明
#include"some_struct.h"  //结构体声明
#include"event.h" //函数声明

//创建按钮
button* creat_button(int x, int y, int w, int h, const char* str, COLORREF incolor, COLORREF outcolor) {
	button* pb = (button*)malloc(sizeof(button));
	assert(pb);
	pb->x = x;
	pb->y = y;
	pb->w = w;
	pb->h = h;
	pb->incolor = incolor;
	pb->outcolor = outcolor;
	//pb->linecolor = linecolor;
	pb->curcolor = pb->outcolor;
	int len = strlen(str) + 1;
	pb->text = (char*)malloc(sizeof(char) * len);
	assert(pb->text);
	strcpy(pb->text, str);
	return pb;
}

//绘制按钮
void draw_button(button* pb) {
	//setlinecolor(pb->linecolor);
	setfillcolor(pb->outcolor);
	fillroundrect(pb->x,pb->y,pb->x+pb->w,pb->y+pb->h,(pb->w)/3,(pb->h)/2);
	settextcolor(BLACK);
	setbkmode(TRANSPARENT);  //去除文字背景
	//settextstyle(45, 0, "楷体");
	int textw = textwidth(pb->text);
	int texth = textheight(pb->text);
	outtextxy((pb->x + (pb->w - textw) / 2), (pb->y + (pb->h - texth) / 2), pb->text);
}

//鼠标在按钮内
bool isinbutton(button* pb, ExMessage m) {
	if (m.x > pb->x && m.x < (pb->x + pb->w) && m.y > pb->y && m.y < (pb->y + pb->h)) {
		//pb->curcolor = (pb->incolor);
		//draw_button(pb);
		//changecolor(pb,m);
		return true;
	}
	else {
		//pb->curcolor = pb->outcolor;
		//draw_button(pb);
		return false;
	}
}

//鼠标点击按钮
bool isclickbutton(button* pb, ExMessage m) {
	if (isinbutton(pb, m) && m.message == WM_LBUTTONDOWN) {
		return true;
	}
	else {
		return false;
	}
}

////改变按钮颜色
//void changecolor(button* pb,ExMessage m) {
//	if(isinbutton(pb,m)){
//		pb->curcolor = (pb->incolor);
//	}
//	else {
//		pb->curcolor = pb->outcolor;
//	}
//}
