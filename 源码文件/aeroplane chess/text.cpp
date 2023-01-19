#include"global.h"  //库声明
#include"item.h"  //全局变量声明
#include"some_struct.h"  //结构体声明
#include"event.h" //函数声明

//外部按钮
extern button* buplayer ;
extern button* bucom;
extern stsquare square[96];

//输入文本框（将输入显示并不断刷新按钮）
void input(ExMessage m, button* pb, int type, int* val, char* str) {   //type=1代表一位输入，type=0代表字符输入
	cout << "输入框" << square[0].x << ' ' << square[0].y << endl;
	while (1) {
		//while (peekmessage(&m, EM_MOUSE)) {             //反应迟钝，加载缓慢
		if (MouseHit()) { m = getmessage(EM_MOUSE); }
		if (kbhit()) {
			char c = getch();

			//回车确定
			if (c == '\n' || c == '\r') {
				if (type==1 && strlen(pb->text) > 1) {     //限制数字一位输入
					MessageBox(NULL, "错误的输入", "False", MB_SYSTEMMODAL);     //需要删除原先输入后重新输入

				}
				else {
					setlinecolor(WHITE);
					draw_button(pb);
					return;
				}

			}
			//删除
			else if (c == '\b') {
				cout << "删除"<<endl;
				pb->text[strlen(pb->text) - 1] = '\0';
			}
			//数字正常输入
			else if(type == 1) {
				*val = c - '0';
				strncat(pb->text, &c, 1);
				//cout << pb->text<<endl;

			}
			//字符正常输入
			else if (type == 0) {
				strncat(pb->text, &c, 1);
				//cout << pb->text<<endl;
			}
		}
		/*if (not isinbutton(pb, m)) {
			setlinecolor(WHITE);
			draw_button(player);
			return;
		}*/
		draw_button(pb);
		FlushBatchDraw();      //防止频闪
	}
	//break;
//}

}

