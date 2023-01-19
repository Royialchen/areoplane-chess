#pragma once
//��������

//���ڳ�ʼ��
void scene_init();
//��Ϸ������
void home_scene();
//������Ϸ����
void set_scene();
void set2_scene(int n1, int np);
//��ʼ��Ϸ����
void play_scene();
//˵����Ϸ����
void explain_scene();
//������Ϸ����
void end_game(stplayer& player);

//���ɰ�ť
button* creat_button(int x, int y, int w, int h, const char* str , COLORREF incolor, COLORREF outcolor);
//���ư�ť
void draw_button(button* pb);
//�ж����λ��
bool isinbutton(button* pb, ExMessage m);
//�����
bool isclickbutton(button* pb, ExMessage m);
//�ı䰴ť��ɫ
void changecolor(button* pb, ExMessage m);

//�������루��������ʾ������ˢ�°�ť��
void input(ExMessage m, button* pb, int type, int* val = NULL, char* str = NULL);   //type=1����һλ���룬type=0�����ַ�����

//�����ܵ�
void creat_runway();
//�������
void creat_player(int k, char* name, const char* strcolor);


//��Ϸ����
void run_game();
//�ж���Ӯ
void judge(stplayer& player);
//��ʼ��Ϸ
void creat_game();

//ҡ����
int roll_dice();
//��ʾ����ͼƬ
void show_dice(int ndice);

// �ж����˻��ǵ���
void real_or_com(stplayer &player, int dice);
//ѡ�񷽰���������ң�
void choose_strategy(stplayer &player, int dice);
//���������������ң�
void random_strategy(stplayer &player, int dice);

//����ɻ�
bool isclickplane(ExMessage m, stplane* plane);
//������
void out_airport(stplane* plane);
//���ػ���
void return_airport(stplane* plane);
//ǰ��
void advance(stplane* plane, int dice);
//����
void rebound(stplane* plane, int dice);
//ͬɫ��Ծ
void jump(stplane* plane);
//����
void fly(stplane* plane);

//������㴦�ж������
void in_same_square(stplane* plane, stsquare* square);
//�ɻ��뿪����,�Ͽ�place��plane����ϵ
void awaysquare(stplane* plane, stsquare* square);
//�ɻ������ڸ�����,����place��plane����ϵ
void landsquare(stplane* plane, stsquare* square);

//ָ��������
int pardice();
