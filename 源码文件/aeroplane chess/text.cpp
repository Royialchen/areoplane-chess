#include"global.h"  //������
#include"item.h"  //ȫ�ֱ�������
#include"some_struct.h"  //�ṹ������
#include"event.h" //��������

//�ⲿ��ť
extern button* buplayer ;
extern button* bucom;
extern stsquare square[96];

//�����ı��򣨽�������ʾ������ˢ�°�ť��
void input(ExMessage m, button* pb, int type, int* val, char* str) {   //type=1����һλ���룬type=0�����ַ�����
	cout << "�����" << square[0].x << ' ' << square[0].y << endl;
	while (1) {
		//while (peekmessage(&m, EM_MOUSE)) {             //��Ӧ�ٶۣ����ػ���
		if (MouseHit()) { m = getmessage(EM_MOUSE); }
		if (kbhit()) {
			char c = getch();

			//�س�ȷ��
			if (c == '\n' || c == '\r') {
				if (type==1 && strlen(pb->text) > 1) {     //��������һλ����
					MessageBox(NULL, "���������", "False", MB_SYSTEMMODAL);     //��Ҫɾ��ԭ���������������

				}
				else {
					setlinecolor(WHITE);
					draw_button(pb);
					return;
				}

			}
			//ɾ��
			else if (c == '\b') {
				cout << "ɾ��"<<endl;
				pb->text[strlen(pb->text) - 1] = '\0';
			}
			//������������
			else if(type == 1) {
				*val = c - '0';
				strncat(pb->text, &c, 1);
				//cout << pb->text<<endl;

			}
			//�ַ���������
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
		FlushBatchDraw();      //��ֹƵ��
	}
	//break;
//}

}

