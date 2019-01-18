/*
2017 C-language curriculum design
SNAKE
author:andrew
*/

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <malloc.h>
#include <graphics.h>  
#pragma comment(lib, "Winmm.lib")


#define NOR 0
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define ENTER 5
#define ESC 6

void show();
void move();
void turn();
void check();
void ini();
void food();
void bomb();
void poison();
void antidote();
void gameover();
void sort(int array[], int n);
void smart();
void calculate();
void turn2();
void show2();
void show3();
void hide();
int keyBoard();
void start();
void safe();
void read1();
void base1();
void pause();
void graph();
void turn3();
void show2();
void ini2();
void computer();
void check2();
void move2();
void calculate2();
void build();
void paihang();
void ini3();
void time2();
void set_poison();
void choose_food();
void kai();
void outcome();
void checklevel();
void loadpicture();
void set_map();
void ini3_();
void time2();
void set_poison();
void playmusic(int j);
void checksnake();
void choosesnake();
void checktime_vscomputer();

int  dy[4] = { 0, 1, 0, -1 };  //四种方向，分别为0下 1右 2上 3左。
int  dx[4] = { -1, 0, 1, 0 };
int over = 0;
int speed;
int speed2;
int score = 0;
int score2 = 0;
int k;
int sum = 3;
int sum2 = 3;
int flag = 0;
int movable[4];  //数组的下标表示方向，0123分别表示上下左右，下同
int distance[4] = { 9999, 9999, 9999, 9999 };
int foodx, foody;
int ch1, ch2;
int mark_arrow = 0;
int dir;
int dir2;
int m = 0;
IMAGE img1, img2, img3, img4, img5, img6, img7, img8, img9, img10;
IMAGE over5, over1, over2, over3, over4, bye;
IMAGE s1, s2, s3, s4, s5, s6, s7, s8, s9, s10, s11, s12, s13, s14, s15, s16;
IMAGE phead0, phead1, phead2, phead3, pbody,pbody2;
IMAGE p1, p2, p3;
IMAGE k0, k1, k2, k3;
IMAGE h1, h2, h3, h0;
IMAGE map2, map3, map4;
IMAGE w1, w2, w3, w4;
int startgame = 0;
int flag2 = 0;
int step;
int level = 1;
float _time = 0;
float _time2 = 0;
time_t start1, end1;
int _s = 0;
int kind;
int t_kind = 0;
int color = 1;
int musicflag = 0;
int musicflag2 = 0;
int pauseflag = 0;

char map[30][30];  //地图

struct snake{
	int x;
	int y;
	struct snake *previous;
	struct snake *next;
};
struct snake head, tail, body;

struct snake2   //人机模式的小蛇
{
	int x;
	int y;
	struct snake2 *previous;
	struct snake2 *next;
};
struct snake2 head2, tail2, body2;

void ini() {  //初始化界面

	over = 0;
	sum = 3;
	int i, j;
	dir = 1;  //一开始往右走

	head.x = 1;
	head.y = 5;
	head.previous = &body;
	head.next = NULL;

	body.x = 1;
	body.y = 4;
	body.previous = &tail;
	body.next = &head;

	tail.x = 1;
	tail.y = 3;
	tail.previous = NULL;   //溯源法（从尾到头的双向链表）
	tail.next = &body;

	srand(time(0));    //随机数发生器的初始化函数srand,配合rand使用

	for (i = 0; i < 30; i++) {  //设置地图
		for (j = 0; j < 30; j++) {
			map[i][j] = '#';
		}
	}
	for (i = 1; i < 29; i++) {
		for (j = 1; j < 29; j++) {
			map[i][j] = ' ';
		}
	}

	map[head.x][head.y] = '*';  //设置蛇头
	map[tail.x][tail.y] = '*';
	map[body.x][body.y] = '*';


}

void ini3() //迷宫模式初始化
{
	int i, j;
	srand(time(0));

	for (i = 0; i < 30; i++) {  //设置地图
		for (j = 0; j < 30; j++) {
			map[i][j] = '#';
		}
	}
	for (i = 1; i < 29; i++) {
		for (j = 1; j < 29; j++) {
			map[i][j] = ' ';
		}
	}

	{  //设置迷宫
		map[1][5] = '#';
		map[2][5] = '#';
		map[3][5] = '#';

		for (j = 1; j <= 18; j++)
			map[5][j] = '#';

		map[3][10] = '#';
		map[4][10] = '#';

		for (j = 16; j <= 21; j++)
			map[3][j] = '#';

		for (i = 1; i <= 6; i++)
			map[i][22] = '#';

		for (j = 22; j <= 26; j++)
			map[7][j] = '#';

		for (j = 1; j <= 3; j++)
			map[17][j] = '#';

		for (i = 8; i <= 17; i++)
			map[i][3] = '#';

		map[10][4] = '#';
		map[10][5] = '#';

		for (i = 6; i <= 8; i++)
			map[i][7] = '#';

		for (j = 8; j <= 11; j++)
			map[8][j] = '#';

		for (i = 9; i <= 12; i++)
			map[i][9] = '#';

		for (j = 13; j <= 20; j++)
			map[12][j] = '#';

		for (i = 8; i <= 11; i++)
			map[i][16] = '#';

		for (i = 10; i <= 12; i++)
			map[i][23] = '#';

		for (j = 24; j <= 28; j++)
			map[12][j] = '#';

		for (i = 13; i <= 15; i++)
			map[i][26] = '#';

		map[9][27] = '#';
		map[9][28] = '#';

		for (j = 1; j <= 5; j++)
			map[21][j] = '#';

		for (i = 21; i <= 26; i++)
			map[i][5] = '#';

		map[25][1] = '#';
		map[25][2] = '#';
		map[18][6] = '#';
		map[18][7] = '#';

		for (i = 16; i <= 28; i++)
			map[i][8] = '#';

		for (i = 15; i <= 21; i++)
			map[i][11] = '#';

		for (j = 9; j <= 13; j++)
			map[20][j] = '#';

		for (j = 9; j <= 15; j++)
			map[24][j] = '#';

		map[23][14] = '#';
		map[25][14] = '#';
		map[27][11] = '#';
		map[28][11] = '#';

		for (i = 15; i <= 18; i++)
			map[i][15] = '#';
		map[15][16] = '#';
		map[15][17] = '#';
		for (i = 13; i <= 25; i++)
			map[i][18] = '#';

		for (j = 19; j <= 22; j++)
			map[17][j] = '#';

		for (i = 18; i <= 21; i++)
			map[i][21] = '#';

		for (j = 24; j <= 28; j++)
			map[19][j] = '#';

		for (j = 26; j <= 28; j++)
			map[24][j] = '#';

		for (i = 23; i <= 28; i++)
			map[i][23] = '#';

		map[25][21] = '#';
		map[25][22] = '#';
	}
	if (_s == 0)
		ini3_();

	bomb();
	poison();
	for (i = 1; i <= 10; i++)
		food();

}

void ini3_()
{

	over = 0;
	sum = 3;
	dir = 0;

	head.x = 13;
	head.y = 2;
	head.previous = &body;
	head.next = NULL;

	body.x = 14;
	body.y = 2;
	body.previous = &tail;
	body.next = &head;

	tail.x = 15;
	tail.y = 2;
	tail.previous = NULL;   //溯源法（从尾到头的双向链表）
	tail.next = &body;

	//随机数发生器的初始化函数srand,配合rand使用

	map[head.x][head.y] = '*';  //设置蛇头
	map[tail.x][tail.y] = '*';
	map[body.x][body.y] = '*';

}

void ini4() {  //初始化-人机对战模式

	int i, j;
	for (i = 0; i < 30; i++) {  //设置地图
		for (j = 0; j < 30; j++) {
			map[i][j] = '#';
		}
	}
	for (i = 1; i < 29; i++) {
		for (j = 1; j < 29; j++) {
			map[i][j] = ' ';
		}
	}
	if (_s == 0)
	{
		sum2 = 3;
		head2.x = 10;
		head2.y = 5;
		dir2 = 1;  //一开始往右走
		head2.previous = &body2;
		head2.next = NULL;

		body2.x = 10;
		body2.y = 4;
		body2.previous = &tail2;
		body2.next = &head2;

		tail2.x = 10;
		tail2.y = 3;
		tail2.previous = NULL;   //溯源法（从尾到头的双向链表）
		tail2.next = &body2;

		map[head2.x][head2.y] = '*';  //设置蛇头
		map[tail2.x][tail2.y] = '*';
		map[body2.x][body2.y] = '*';


		
	}


	if (_s == 0)
	{
		sum = 3;
		dir = 1;
		head.x = 1;
		head.y = 5;
		head.previous = &body;
		head.next = NULL;

		body.x = 1;
		body.y = 4;
		body.previous = &tail;
		body.next = &head;

		tail.x = 1;
		tail.y = 3;
		tail.previous = NULL;   //溯源法（从尾到头的双向链表）
		tail.next = &body;

		map[head.x][head.y] = '*';  //设置蛇头
		map[tail.x][tail.y] = '*';
		map[body.x][body.y] = '*';
	}
	over = 0;
	if (_s == 1)
		_s = 0;
	srand(time(0));
	for (i = 1; i <= 5; i++)
		food();
}

void show() {  //显示界面 
	int i, j;
	graph();

	while (1) {
		//界面刷新速度
		turn();
		turn();          //连用两个turn，提高方向键的灵敏度
		move();
		checksnake();
		if (startgame == 1)  //毒草闪烁
			time2();
		if (startgame == 4||kind==4)
		{
			if (startgame == 4)computer();
			if(startgame!=2)checktime_vscomputer();
		}
		if (startgame == 2)
			checklevel();
		
		Sleep(speed);
		graph();
		if (over)
		{  //设置蛇死掉后可以进行的操作 
			while (1)
			{
				char ch = _getch();
				if (ch == 113) {  //输入‘q’结束 
					int a[1000] = { 0 };
					FILE *fpRead = fopen("data.txt", "r");
					for (int i = 0; i<1000; i++)
					{
						fscanf(fpRead, "%d", &a[i]);

					}
					sort(a, 100);
					system("cls");
					printf("得分排行榜如下:\n\n");
					int j = 1;
					for (i = 0; i < 1000; i++)
						if (a[i] != 0)
						{
						printf("第%-2d名：%d\n", j, a[i]);
						j++;
						}

					printf("\n");
					return;
				}
				else if (ch == 114) {  //输入‘r’重新开始 
					system("color 70");
					score = 0;
					flag = 0;
					speed = speed2;
					ini();
					base1();
					sum = 3;
					score = 0;
					for (i = 0; i < 30; i++) {  //显示界面
						for (j = 0; j < 30; j++) {
							printf("%c", map[i][j]);
						}
						printf("\n");
					}
					printf("your length is %d\n", sum);
					printf("your score is %d\n", score);
					break;
				}
			}
		}
		if (startgame == 4)calculate2();
	}
}

void show2()
{
	calculate2();
	turn3();
	move2();
	calculate2();
}

void show3()
{
	int i, j;
	{
		calculate();
		Sleep(speed);  //界面刷新速度
		turn2();          //连用两个turn，提高方向键的灵敏度
		move();
		if (over)
		{  //设置蛇死掉后可以进行的操作 
			gameover();
			step = 151;

		}
		calculate();
	}
}

void move() {  //蛇移动
	int i, j;
	int t = sum;  //t记录当前蛇总长度 
	struct snake*p;
	check();  //移动前检查按当前方向移动一步后的情况

	if (flag == 0) {  //没有吃到食物
		map[tail.x][tail.y] = ' ';

		p = &tail;
		for (; p->next != NULL;)
		{
			p->x = p->next->x;
			p->y = p->next->y;
			p = p->next;
		}
		p = &head;
		p->x = head.x + dx[dir];
		p->y = head.y + dy[dir];

		p = &tail;
		do{
			map[p->x][p->y] = '*';
			p = p->next;
		} while (p != &head);

		map[head.x][head.y] = '*';
	}

	if (flag == 1)   //吃到了食物
	{

		if (tail.next == &head)
		{
			p = (struct snake*)malloc(sizeof(struct snake));
			p->x = head.x;
			p->y = head.y;
			p->previous = &tail;
			tail.next = p;
			p->next = &head;
			head.previous = p;

			head.x = head.x + dx[dir];
			head.y = head.y + dy[dir];
		}

		else
		{
			p = (struct snake*)malloc(sizeof(struct snake));
			p->x = head.x;
			p->y = head.y;
			p->previous = head.previous;
			head.previous->next = p;
			p->next = &head;
			head.previous = p;

			head.x = head.x + dx[dir];
			head.y = head.y + dy[dir];
		}

		p = &tail;
		do{
			map[p->x][p->y] = '*';
			p = p->next;
		} while (p != NULL);

		food();

	}

	if (flag == 2)         //吃到了地雷
	{
		int L = sum;
		p = &tail;
		do
		{
			map[p->x][p->y] = ' ';
			p = p->next;
		} while (p != NULL);

		if (L <= 4) //长度过短，变成只剩两节
		{


			p = head.previous;
			tail.x = p->x;
			tail.y = p->y;
			tail.next = &head;
			head.previous = &head;
			sum = 2;
		}
		if (L > 4)
		{

			int k, i;
			i = 0;
			if ((L - 2) % 2 == 0)
				k = (L - 2) / 2;
			else
				k = (L - 3) / 2;

			p = &head;
			for (i = 0; i <= k; i++)
			{
				p = p->previous;
			}
			tail.x = p->previous->x;
			tail.y = p->previous->y;
			tail.next = p;
			p->previous = &tail;

			p = &tail;
			int x = 0;
			for (i = 2; x != 1;)
			{
				p = p->next;
				if (p == &head)x = 1;
				i = i + 1;
			}
			sum = i - 1;
		}

		p = &tail;
		for (; p->next != NULL;)
		{
			p->x = p->next->x;
			p->y = p->next->y;
			p = p->next;
		}
		p = &head;
		p->x = head.x + dx[dir];
		p->y = head.y + dy[dir];

		p = &tail;
		do{
			map[p->x][p->y] = '*';
			p = p->next;
		} while (p != NULL);


		bomb();

	}

	if (flag == 3)     //吃到了毒草
	{
		if (sum != 1)
		{
			p = &tail;
			map[p->x][p->y] = ' ';
			p->x = p->next->x;
			p->y = p->next->y;
			p = p->next;
			p->previous->next = p->next;
			p->next->previous = p->previous;

			p = &tail;
			for (; p->next != NULL;)
			{
				p->x = p->next->x;
				p->y = p->next->y;
				p = p->next;
			}
			p = &head;
			p->x = head.x + dx[dir];
			p->y = head.y + dy[dir];

			p = &tail;
			do{
				map[p->x][p->y] = '*';
				p = p->next;
			} while (p != NULL);

			speed = 300;
			antidote();
		}
	}

	if (flag == 4)    //吃到了智慧草
	{
		int i, j;
		i = head.x + dx[dir];
		j = head.y + dy[dir];
		map[i][j] = ' ';

		int _kind = kind;
		kind = 4;

		int u = speed;
		speed = 30;

		step = 0;
		int x, y;
		for (; step <= 150;)  //只走150步，从而限定自动行走的时间
		{
			choose_food();
			for (i = 0; i < 4; i++) //记录下能走的方向
			{
				x = head.x + dx[i];
				y = head.y + dy[i];
				if (map[x][y] == ' ' || map[x][y] == 'O')
					movable[i] = 1;  //能走就把对应方向的值设置为1 

				else
					movable[i] = 0;  //不能走就把对应方向的值设置为0 

			}
			show3();
			graph();
			step++;
		}

		kind = _kind;
		speed = u;
		m = 0;
		if (step <= 151)
			smart();

	}

	if (flag == 5)  //吃到解药
	{
		speed = speed2;
		system("color 70");
		poison();
		map[tail.x][tail.y] = ' ';

		p = &tail;
		for (; p->next != NULL;)
		{
			p->x = p->next->x;
			p->y = p->next->y;
			p = p->next;
		}
		p = &head;
		p->x = head.x + dx[dir];
		p->y = head.y + dy[dir];

		p = &tail;
		do{
			map[p->x][p->y] = '*';
			p = p->next;
		} while (p != &head);

		map[head.x][head.y] = '*';
	}

	if (flag == 10)
	{
		map[tail.x][tail.y] = ' ';
		p = &tail;
		for (; p->next != NULL;)
		{
			p->x = p->next->x;
			p->y = p->next->y;
			p = p->next;
		}
	
		
		if (head.y == 1)
			head.y = 28;
		else if (head.y == 28)
			head.y = 1;

		
		if (head.x == 1)
			head.x = 28;
		else if (head.x == 28)
			head.x = 1;

		p = &tail;
		do
		{
			map[p->x][p->y] = '*';
			p = p->next;
		} while (p != &head);
		map[head.x][head.y] = '*';
	}
}

void move2()
{
	struct snake2 *p;
	check2();  //移动前检查按当前方向移动一步后的情况

	if (flag2 == 0) {  //没有吃到食物
		map[tail2.x][tail2.y] = ' ';

		p = &tail2;
		for (; p->next != NULL;)
		{
			p->x = p->next->x;
			p->y = p->next->y;
			p = p->next;
		}
		p = &head2;
		p->x = head2.x + dx[dir2];
		p->y = head2.y + dy[dir2];

		p = &tail2;
		do{
			map[p->x][p->y] = '*';
			p = p->next;
		} while (p != &head2);

		map[head2.x][head2.y] = '*';

	}

	if (flag2 == 1)   //吃到了食物
	{

		if (tail2.next == &head2)
		{
			p = (struct snake2*)malloc(sizeof(struct snake2));
			p->x = head2.x;
			p->y = head2.y;
			p->previous = &tail2;
			tail2.next = p;
			p->next = &head2;
			head2.previous = p;

			head2.x = head2.x + dx[dir2];
			head2.y = head2.y + dy[dir2];
		}

		else
		{
			p = (struct snake2*)malloc(sizeof(struct snake2));
			p->x = head2.x;
			p->y = head2.y;
			p->previous = head2.previous;
			head2.previous->next = p;
			p->next = &head2;
			head2.previous = p;
			head2.x = head2.x + dx[dir2];
			head2.y = head2.y + dy[dir2];
		}

		p = &tail2;
		do{
			map[p->x][p->y] = '*';
			p = p->next;
		} while (p != NULL);


		food();

	}
}

void check() {  //检查是否死亡或者吃到食物
	flag = 0;
	int x, y, i, j;
	x = head.x + dx[dir];  //记录按当前方向移动一格后蛇头的坐标 
	y = head.y + dy[dir];
	if (map[x][y] == '*' || map[x][y] == '#') 
	{  

		
		if ((x==0||x==29||y==0||y==29)&&(kind==4))
		{
			flag = 10;
			return;
		}
		if (x != tail.x&&kind != 4)
		{
			FILE *fpWrite = fopen("data.txt", "a");
			fprintf(fpWrite, "%d ", score);
			fclose(fpWrite);
			gameover();
			return;
		}
	}

	else if (map[x][y] == 'O')  //吃到苹果 
	{
		playmusic(11);
		musicflag2 = 1;
		flag = 1;
		sum++;
		score = score + k;
		cleardevice();
		graph();
	}


	else if (map[x][y] == '$')//炸弹
	{
		if (kind != 4)
		{
			
			playmusic(12);
			musicflag2 = 1;
			flag = 2;
			score = (int)(score / 2);
			cleardevice();
			graph();
			if (sum == 2)
			{
				gameover();
				flag = 0;
			}
		}
		if (kind == 4)
			bomb();
	}

	else if (map[x][y] == '@')//毒草
	{
		if (kind != 4)
		{
			
			playmusic(12);
			musicflag2 = 1;
			flag = 3;
			score = score - k;
			sum--;
			cleardevice();
			graph();
			if (sum == 1)
			{
				gameover();
				flag = 0;
			}
			m = 0;
		}
		if (kind==4)
		poison();
	}

	else if (map[x][y] == '%')//智慧草
	{
		flag = 4;
	}
	else if (map[x][y] == '&')  //解药
	{
		flag = 5;
		m = 0;
	}
	if (musicflag2 == 1)
	{
		musicflag++;
	}
	if (musicflag == 4)
	{
		playmusic(98);
		musicflag = 0;
		musicflag2 = 0;
	}

}

void check2()
{
	flag2 = 0;
	int x, y, i, j;
	x = head2.x + dx[dir2];  //记录按当前方向移动一格后蛇头的坐标 
	y = head2.y + dy[dir2];
	if (map[x][y] == '*' || map[x][y] == '#')
	{ 
		if (x != tail2.x || y != tail2.y) //蛇尾除外 
		{
			struct snake2 *p;
			map[tail2.x][tail2.y] = ' ';
			p = &tail2;
			for (; p->next != NULL;)
			{
				p->x = p->next->x;
				p->y = p->next->y;
				p = p->next;
			}


			if (head2.y == 1)
				head2.y = 28;
			else if (head2.y == 28)
				head2.y = 1;


			if (head2.x == 1)
				head2.x = 28;
			else if (head2.x == 28)
				head2.x = 1;

			p = &tail2;
			do
			{
				map[p->x][p->y] = '*';
				p = p->next;
			} while (p != &head2);
			map[head2.x][head2.y] = '*';
		}
	}

	else if (map[x][y] == 'O')  //吃到苹果 
	{
		score2 = score2 + k;
		flag2 = 1;
		sum2++;
	}



}

void food() {  //随机生成食物
	int x, y;
	while (1) {
		x = (int)(28 * rand() / (RAND_MAX + 1.0));  //随机产生一组食物坐标
		y = (int)(28 * rand() / (RAND_MAX + 1.0));
		if (map[x][y] == ' ') {  //如果是空格则在该处生成食物
			map[x][y] = 'O';
			foodx = x;
			foody = y;
			break;
		}
	}
}

void bomb()             //随机生成地雷
{
	int x, y;
	while (1) {
		x = (int)(28 * rand() / (RAND_MAX + 1.0));
		y = (int)(28 * rand() / (RAND_MAX + 1.0));
		if (map[x][y] == ' ') {
			map[x][y] = '$';
			break;
		}
	}
}

void poison() {  //随机生成毒草，毒草功效：减少一节身体，形成一堵墙
	int x, y;
	while (1) {
		x = (int)(28 * rand() / (RAND_MAX + 1.0));
		y = (int)(28 * rand() / (RAND_MAX + 1.0));
		if (map[x][y] == ' ')
		{
			map[x][y] = '@';
			break;
		}
	}
}

void smart()             //随机生成智慧草
{
	int x, y;
	while (1) {
		x = (int)(28 * rand() / (RAND_MAX + 1.0));
		y = (int)(28 * rand() / (RAND_MAX + 1.0));
		if (map[x][y] == ' ') {
			map[x][y] = '%';
			break;
		}
	}
}

void antidote()
{
	int x, y;
	while (1) {
		x = (int)(28 * rand() / (RAND_MAX + 1.0));
		y = (int)(28 * rand() / (RAND_MAX + 1.0));
		if (map[x][y] == ' ') {
			map[x][y] = '&';
			break;
		}
	}
}

void turn() {  //转弯
	if (_kbhit()) {
		int d = _getch();  //读取输入的键 
		switch (d)
		{  //改变方向 

		case 72: dir = (dir == 2) ? 2 : 0; break;
		case 77: dir = (dir == 3) ? 3 : 1; break;
		case 80: dir = (dir == 0) ? 0 : 2; break;
		case 75: dir = (dir == 1) ? 1 : 3; break;
		case 27:   //暂停
		{

			pause();
			break;
		}
		}
	}
}

void turn2() {  //转弯2
	int i, k = 0;
	for (i = 1; i < 4; i++) {  //找到走一步后离食物距离最短的方向
		if (distance[k] > distance[i]) {
			k = i;
		}
	}
	switch (k) {  //把把蛇头方向改为该方向 
	case 0: dir = (dir == 2) ? 2 : 0; break;
	case 1: dir = (dir == 3) ? 3 : 1; break;
	case 2: dir = (dir == 0) ? 0 : 2; break;
	case 3: dir = (dir == 1) ? 1 : 3; break;
	}
}

void turn3() {  //转弯3 人机
	int i, k = 0;
	for (i = 1; i < 4; i++) {  //找到走一步后离食物距离最短的方向
		if (distance[k] > distance[i]) {
			k = i;
		}
	}
	switch (k) {  //把把蛇头方向改为该方向 
	case 0: dir2 = (dir2 == 2) ? 2 : 0; break;
	case 1: dir2 = (dir2 == 3) ? 3 : 1; break;
	case 2: dir2 = (dir2 == 0) ? 0 : 2; break;
	case 3: dir2 = (dir2 == 1) ? 1 : 3; break;
	}
}

void calculate() {  //计算并记录蛇头与食物距离
	int i = 0, x, y;

	for (i = 0; i < 4; i++) {
		if (movable[i] == 1) {  //如果该方向能走，则记录下沿该方向走一步后与食物的距离 
			x = head.x + dx[i];
			y = head.y + dy[i];
			distance[i] = abs(foodx - x) + abs(foody - y);
		}
		else {  //如果不能走则把距离设置为9999 
			distance[i] = 9999;
		}
	}
	if (dir == 2)
		distance[0] = 9999;
	if (dir == 0)
		distance[2] = 9999;
	if (dir == 1)
		distance[3] = 9999;
	if (dir == 3)
		distance[1] = 9999;


}

void calculate2()
{  //计算并记录蛇头与食物距离
	int i = 0, x, y;
	for (i = 0; i < 4; i++) {
		if (movable[i] == 1) {  //如果该方向能走，则记录下沿该方向走一步后与食物的距离 
			x = head2.x + dx[i];
			y = head2.y + dy[i];
			distance[i] = abs(foodx - x) + abs(foody - y);
		}
		else {  //如果不能走则把距离设置为9999 
			distance[i] = 9999;
		}
	}
	if (dir2 == 2)
		distance[0] = 9999;
	if (dir2 == 0)
		distance[2] = 9999;
	if (dir2 == 1)
		distance[3] = 9999;
	if (dir2 == 3)
		distance[1] = 9999;
}

void gameover()
{
	playmusic(99);
	cleardevice();
	fflush(stdin);
	putimage(0, 0, &over1);
	outcome();
	step = 151;
	int i;
	int guide = 1;
	while (1)
	{

		i = keyBoard();
		if (i == UP)
		{
			if (guide != 1)
			{
				guide--;
				if (guide == 1)putimage(0, 0, &over1);
				if (guide == 2)putimage(0, 0, &over2);
				if (guide == 3)putimage(0, 0, &over3);
				if (guide == 4)putimage(0, 0, &over5);
			}
		}


		if (i == DOWN)
		{
			if (guide != 4)
			{
				guide++;
				if (guide == 1)putimage(0, 0, &over1);
				if (guide == 2)putimage(0, 0, &over2);
				if (guide == 3)putimage(0, 0, &over3);
				if (guide == 4)putimage(0, 0, &over5);

			}
		}



		if (i == ENTER)
		{
			if (guide == 1)
			{

				if (startgame == 2 || startgame == 4||kind==4)
				{
					start1 = time(NULL);
					end1 = time(NULL);
				}
				_time2 = 0;

				flag = 0;
				m = 0;
				speed = speed2;
				ini();
				build();
				playmusic(startgame);
				cleardevice();
				break;



			}
			if (guide == 2)//查看排行榜
			{
				cleardevice();
				paihang();
				putimage(0, 0, &over2);
			}


			if (guide == 3)
			{
				cleardevice();
				score = score2 = 0;
				closegraph();
				initgraph(600, 600);
				start();
				build();
				break;
			}
			if (guide == 4)
			{
				closegraph();
				initgraph(600, 600);
				putimage(0, 0, &bye);
				Sleep(2000);
				exit(1);
			}

		}

	}


}

void sort(int array[], int n)
{
	int i, j, k, t;
	for (i = 0; i < n - 1; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
			if (array[j] > array[k])
				k = j;
		t = array[k];
		array[k] = array[i];
		array[i] = t;
	}
}

void start()
{
	
	playmusic(0);
	fflush(stdin);
	putimage(1, 1, &s1);


	int guide = 1;
	int i = 0;
	int s = 0;
	int begin = 0;

	startgame = 1;//默认模式;
	speed = 120;
	k = 5;

	while (1)//一级菜单
	{
		i = keyBoard();


		if (i == UP)
		{
			if (guide != 1)
			{
				guide--;
				if (guide == 1)putimage(1, 1, &s1);
				if (guide == 2)putimage(1, 1, &s2);
				if (guide == 3)putimage(1, 0, &s3);
				if (guide == 4)putimage(0, 1, &s4);
				if (guide == 5)putimage(1, 1, &s5);
				if (guide == 6)putimage(0, 0, &s6);

			}
			else
			{
				guide = 6;
				putimage(0, 0, &s6);
			}
		}


		if (i == DOWN)
		{
			if (guide != 6)
			{
				guide++;
				if (guide == 1)putimage(1, 1, &s1);
				if (guide == 2)putimage(1, 1, &s2);
				if (guide == 3)putimage(1, 0, &s3);
				if (guide == 4)putimage(0, 1, &s4);
				if (guide == 5)putimage(1, 1, &s5);
				if (guide == 6)putimage(0, 0, &s6);
			}
			else
			{
				guide = 1;
				putimage(1, 1, &s1);
			}
		}



		if (i == ENTER)
		{
			if (guide == 1)   //模式菜单
			{
				putimage(0, 0, &s7);
				guide = 7;
				while (1)
				{
					i = keyBoard();
					if (i == UP)
					{
						if (guide != 7)
						{
							guide--;
							if (guide == 7)putimage(0, 0, &s7);
							if (guide == 8)putimage(0, 1, &s8);
							if (guide == 9)putimage(0, 0, &s9);
							if (guide == 10)putimage(0, 0, &s10);

						}

					}
					if (i == DOWN)
					{
						if (guide != 10)
						{
							guide++;
							if (guide == 7)putimage(0, 0, &s7);
							if (guide == 8)putimage(0, 1, &s8);
							if (guide == 9)putimage(0, 0, &s9);
							if (guide == 10)putimage(0, 0, &s10);
						}

					}
					if (i == ENTER)
					{
						if (guide == 7)startgame = 1;
						if (guide == 8)startgame = 2;
						if (guide == 9)startgame = 3;
						if (guide == 10)startgame = 4;
						guide = 1;
						putimage(1, 1, &s1);
						break;
					}

				}

			}


			if (guide == 2)                                        //速度二级菜单
			{
				putimage(1, 1, &s11);
				guide = 11;
				while (1)
				{
					i = keyBoard();
					if (i == UP)
					{
						if (guide != 11)
						{
							guide--;
							if (guide == 11)putimage(1, 1, &s11);
							if (guide == 12)putimage(0, 0, &s12);
							if (guide == 13)putimage(2, 1, &s13);
							if (guide == 14)putimage(2, 1, &s14);
							if (guide == 15)putimage(2, 1, &s15);

						}

					}
					if (i == DOWN)
					{
						if (guide != 15)
						{
							guide++;
							if (guide == 11)putimage(1, 1, &s11);
							if (guide == 12)putimage(0, 0, &s12);
							if (guide == 13)putimage(2, 1, &s13);
							if (guide == 14)putimage(2, 1, &s14);
							if (guide == 15)putimage(2, 1, &s15);
						}

					}
					if (i == ENTER)
					{
						if (guide == 11) { speed = 200; k = 1; }
						if (guide == 12){ speed = 150; k = 3; }
						if (guide == 13){ speed = 120; k = 5; }
						if (guide == 14){ speed = 50; k = 8; }
						if (guide == 15) { speed = 30; k = 10; }
						speed2=speed;
						guide = 2;
						putimage(1, 1, &s2);
						break;
					}

				}

			}

			if (guide == 3)//读取存档
			{
				read1();
				_s = 1;
				outtextxy(100, 200, "读取成功!");
			}

			if (guide == 4)  //游戏指南
			{
				putimage(0, 0, &s16);
				char ch = _getch();
				putimage(0, 1, &s4);
			}

			if (guide == 5)
			{
				paihang();
				putimage(1, 1, &s5);
			}

			if (guide == 6)
			{
				begin = 1;
			}

			if (begin == 1)
			{
				m = 0;
				cleardevice();
				if (_s == 0)
				{
					choosesnake();
				}
				kai();
				end1 = time(NULL);
				start1 = time(NULL);
				closegraph();
				initgraph(700, 600);
				break;
			}
		}
	}
}

int keyBoard()                                         //开始游戏前的键盘处理
{
	if (_kbhit())
	{
		ch1 = _getch();
		if (ch1 == 224)
		{
			mark_arrow = 1;
			ch2 = _getch();
		}
		if (mark_arrow)
		{
			if (ch2 == 72)//up
			{
				mark_arrow = 0;
				return UP;
			}
			else if (ch2 == 80)//down
			{
				mark_arrow = 0;
				return DOWN;
			}
			else if (ch2 == 75)//left
			{
				mark_arrow = 0;
				return LEFT;
			}
			else if (ch2 == 77)//right
			{
				mark_arrow = 0;
				return RIGHT;
			}
		}
		else
		{
			if (ch1 == 13) return ENTER;
			if (ch1 == 27) return ESC;
		}
	}
	return NOR;
}

void safe()
{
	FILE *fpWrite2 = fopen("data2.txt", "w+");
	fprintf(fpWrite2, "%d ", sum);
	struct snake *p3 = &head;
	int b = (int)_time;
	for (; p3 != NULL;)
	{
		fprintf(fpWrite2, "%d ", p3->x);
		fprintf(fpWrite2, "%d ", p3->y);
		p3 = p3->previous;
	}
	fprintf(fpWrite2, "%d ", dir);
	fprintf(fpWrite2, "%d ", score);
	fprintf(fpWrite2, "%d ", speed);
	fprintf(fpWrite2, "%d ", startgame);
	fprintf(fpWrite2, "%d ", level);
	fprintf(fpWrite2, "%d ", b);
	fprintf(fpWrite2, "%d ", kind);
	fclose(fpWrite2);

	if (startgame == 4)//人机模式存档
	{
		FILE *fpWrite2 = fopen("data3.txt", "w+");
		fprintf(fpWrite2, "%d ", sum2);
		struct snake2 *p3 = &head2;
		for (; p3 != NULL;)
		{
			fprintf(fpWrite2, "%d ", p3->x);
			fprintf(fpWrite2, "%d ", p3->y);
			p3 = p3->previous;
		}
		fprintf(fpWrite2, "%d ", dir2);
		fprintf(fpWrite2, "%d ", score2);

		fclose(fpWrite2);
	}
}

void read1()
{
	int i, j;

	for (i = 0; i < 30; i++) {  //设置地图
		for (j = 0; j < 30; j++) {
			map[i][j] = '#';
		}
	}
	for (i = 1; i < 29; i++)
	{
		for (j = 1; j < 29; j++)
		{
			map[i][j] = ' ';
		}
	}


	int a[1000] = { 0 };
	FILE *fpRead = fopen("data2.txt", "r");
	for (i = 0; i<1000; i++)
	{
		fscanf(fpRead, "%d", &a[i]);

	}
	sum = a[0];
	struct snake *p, *p2;
	p = &head;
	p->next = NULL;
	i = 1;
	int flag = 0;
	for (i = 1; flag != 1; i++)
	{
		p->x = a[i];
		i++;
		p->y = a[i];
		map[p->x][p->y] = '*';
		if (i != 2 * sum - 2)
		{
			p2 = (struct snake*)malloc(sizeof(struct snake));
			p->previous = p2;
			p2->next = p;
			p = p2;
		}
		if (i == 2 * sum - 2)
		{
			p2 = &tail;
			tail.x = a[2 * sum - 1];
			tail.y = a[2 * sum];
			map[p2->x][p2->y] = '*';
			p->previous = p2;
			p2->next = p;
			tail.previous = NULL;

			dir = a[2 * sum + 1];
			score = a[2 * sum + 2];
			speed = a[2 * sum + 3];
			startgame = a[2 * sum + 4];
			level = a[2 * sum + 5];
			int b = a[2 * sum + 6];
			_time2 = (float)b;
			kind = a[2 * sum + 7];
		}
		if (i == 2 * sum - 2)
			flag = 1;

	}



	if (startgame == 4)
	{
		int b[1000] = { 0 };
		FILE *fpRead = fopen("data3.txt", "r");
		for (i = 0; i<1000; i++)
		{
			fscanf(fpRead, "%d", &b[i]);

		}
		sum = b[0];
		struct snake2 *p, *p2;
		p = &head2;
		p->next = NULL;
		i = 1;
		flag = 0;
		for (i = 1; flag != 1; i++)
		{
			p->x = b[i];
			i++;
			p->y = b[i];
			map[p->x][p->y] = '*';
			if (i != 2 * sum2 - 2)
			{
				p2 = (struct snake2*)malloc(sizeof(struct snake2));
				p->previous = p2;
				p2->next = p;
				p = p2;
			}
			if (i == 2 * sum2 - 2)
			{
				p2 = &tail2;
				tail2.x = b[2 * sum2 - 1];
				tail2.y = b[2 * sum2];
				map[p2->x][p2->y] = '*';
				p->previous = p2;
				p2->next = p;
				tail2.previous = NULL;

				dir2 = b[2 * sum2 + 1];
				score2 = b[2 * sum2 + 2];

			}
			if (i == 2 * sum2 - 2)
				flag = 1;

		}
	}

}

void base1()   //一种最初功能性物品设置
{
	int i = 1;
	srand(time(0));

	for (; i <= 5; i++)
	{
		food();
	}
	for (i = 1; i <= 5; i++)
	{
		poison();
	}
	for (i = 1; i <= 5; i++)
	{
		bomb();
	}

	smart();
}

void computer()  //实现电脑自动操作
{
	int i, j, t, x, y;
	for (i = 0; i < 4; i++)
	{  //记录下能走的方向
		x = head2.x + dx[i];
		y = head2.y + dy[i];
		if (map[x][y] == ' ' || map[x][y] == 'O')
			movable[i] = 1;  //能走就把对应方向的值设置为1 

		else
			movable[i] = 0;  //不能走就把对应方向的值设置为0 
	}
	show2();
	choose_food();
}

void graph()
{

	int i, j;

	if(startgame==1)putimage(0, 0, &img9);
	if (startgame == 2)putimage(0, 0, &map2);
	if (startgame == 3)putimage(0, 0, &map3);
	if (startgame == 4)putimage(0, 0, &map4);
	



	for (i = 0; i < 30; i++)
		for (j = 0; j < 30; j++)
		{

		if (map[i][j] == '*'&&color==1)  putimage(20 * j, 20 * i, &pbody);
		if (map[i][j] == '*'&&color == 2)  putimage(20 * j, 20 * i, &pbody2);

		if (map[i][j] == 'O')  putimage(20 * j, 20 * i, &img2);
		if (map[i][j] == '#')  putimage(20 * j, 20 * i, &img4);
		if (startgame!=1&&map[i][j] == '@')  putimage(20 * j, 20 * i, &img5);
		if (map[i][j] == '$')  putimage(20 * j, 20 * i, &img6);
		if (map[i][j] == '&')  putimage(20 * j, 20 * i, &img7);
		if (map[i][j] == '%')  putimage(20 * j, 20 * i, &img8);
		}
	i = head.x;
	j = head.y;
	switch (dir)
	{
	case 0: putimage(20 * j, 20 * i, &phead2); break;
	case 1: putimage(20 * j, 20 * i, &phead1); break;
	case 2: putimage(20 * j, 20 * i, &phead0); break;
	case 3: putimage(20 * j, 20 * i, &phead3); break;
	}
	if (startgame == 4)
	{
		i = head2.x;
		j = head2.y;
		switch (dir2)
		{
		case 0: putimage(20 * j, 20 * i, &h2); break;
		case 1: putimage(20 * j, 20 * i, &h1); break;
		case 2: putimage(20 * j, 20 * i, &h0); break;
		case 3: putimage(20 * j, 20 * i, &h3); break;
		}
	}

	outtextxy(601, 300, "score:");
	char s[5];
	sprintf(s, "%d", score);
	outtextxy(650, 300, s);

	if (startgame == 2||startgame==4||kind==4)
	{
		end1 = time(NULL);
		_time = difftime(end1, start1)+_time2;

		if (startgame == 4||kind==4)
		{
			float pp = 40.0 - _time;
			char t1[10];
			outtextxy(610, 350, "time:");
			sprintf(t1, "%.2f", pp);
			outtextxy(650, 350, t1);
		}
		if (startgame == 2)
		{
			
			char t1[10];
			outtextxy(610, 350, "time:");
			sprintf(t1, "%.2f", _time);
			outtextxy(650, 350, t1);
		}
		
	}
}

void build()
{
	t_kind = 0;
	if (_s == 0)
	{
		score = score2 = 0;
		_time = _time2 = 0;
	}
	int i, j;

	if (_s == 0)
	{
		for (i = 0; i < 30; i++)
			for (j = 0; j < 30; j++)
				map[i][j] = ' ';
	}

	if (startgame == 1)  //街机模式
	{
		if (_s == 0)
			ini();
		if (_s == 1)
		{
			_s = 0;
			for (i = 0; i < 30; i++) {  //设置地图
				for (j = 0; j < 30; j++) {
					map[i][j] = '#';
				}
			}
			for (i = 1; i < 29; i++) {
				for (j = 1; j < 29; j++) {
					map[i][j] = ' ';
				}
			}
			_s = 0;
		}
		base1();

	}

	if (startgame == 2) //闯关模式
	{
		if (level == 1)
		{
			start1 = time(NULL);
			end1 = time(NULL);
			if (_s == 0)
				ini();
			if (_s == 1)
				_s = 0;
			set_map();
			speed = 120;
			for (i = 1; i <= 5; i++)
				food();
			for (i = 1; i <= 5; i++)
				poison();
			for (i = 1; i <= 5; i++)
				bomb();
			cleardevice();
		}
		if (level == 2)
		{
			start1 = time(NULL);
			end1 = time(NULL);
			if (_s == 0)
				ini();
			if (_s == 1)
				_s = 0;
			set_map();
			speed = 120;
			for (i = 1; i <= 5; i++)
				food();
			for (i = 1; i <= 10; i++)
				poison();
			for (i = 1; i <= 10; i++)
				bomb();
			flag = 0;
			cleardevice();
		}
		if (level == 3)
		{
			start1 = time(NULL);
			end1 = time(NULL);
			if (_s == 0)
				ini();
			if (_s == 1)
				_s = 0;
			set_map();
			speed = 120;
			for (i = 1; i <= 5; i++)
				food();
			for (i = 1; i <= 20; i++)
				poison();
			for (i = 1; i <= 20; i++)
				bomb();
			cleardevice();
		}

	}


	if (startgame == 3)//迷宫模式
	{
		ini3();
	}
	if (startgame == 4)//人机对战模式
	{
		ini4();
	}
}

void paihang()
{
	playmusic(99);
	playmusic(5);
	int i, j;
	char s[5];
	char k[5];
	loadimage(&over4, "C:\\Users\\周展科\\Documents\\Visual Studio 2013\\Projects\\snake\\photo\\over4.jpg");
	putimage(0, 0, &over4);
	int a[1000] = { 0 };
	FILE *fpRead = fopen("data.txt", "r");
	for (int i = 0; i<1000; i++)
	{
		fscanf(fpRead, "%d", &a[i]);

	}
	sort(a, 100);

	for (i = 0; i < 1000; i++)
	{
		if (a[i] != 0)
		{
			sprintf(s, "%d", a[i]);//将整形a[i]转换成字符串
			sprintf(k, "%d", (i + 1));
			outtextxy(100, (160 + 20 * i), "第");
			outtextxy(120, (160 + 20 * i), k);
			outtextxy(140, (160 + 20 * i), "名");


			outtextxy(160, (160 + 20 * i), s);
		}
	}
	char ch = _getch();
	playmusic(99);
}

void pause()
{

	putimage(0, 0, &p1);
	int i;
	int guide = 1;
	int x1, x2;
	pauseflag = 1;

	while (1)
	{

		i = keyBoard();
		if (i == UP)
		{
			if (guide != 1)
			{
				guide--;
				if (guide == 1)putimage(0, 0, &p1);
				if (guide == 2)putimage(0, 0, &p2);
			}
		}


		if (i == DOWN)
		{
			if (guide != 3)
			{
				guide++;
				if (guide == 3)putimage(0, 0, &p3);
				if (guide == 2)putimage(0, 0, &p2);

			}
		}



		if (i == ENTER)
		{
			if (guide == 1)
			{
				kai();
				if (startgame == 2 || startgame == 4||kind==4)
				{
					_time2 += _time;
					end1 = time(NULL);
					start1 = time(NULL);
				}
				break;
			}
			if (guide == 2)
			{
				safe();
				outtextxy(100, (200), "存档成功!");
			}


			if (guide == 3)
			{
				build();
				break;
			}

		}

	}
}

void choose_food()
{
	int i, j;
	int t = 1;
	int x1, x2, x3, x4, x5;
	int y1, y2, y3, y4, y5;

	for (i = 0; i < 30; i++)
		for (j = 0; j < 30; j++)
			if (map[i][j] == 'O')
			{
		if (t == 1){ x1 = i; y1 = j; }
		if (t == 2){ x2 = i; y2 = j; }
		if (t == 3){ x3 = i; y3 = j; }
		if (t == 4){ x4 = i; y4 = j; }
		if (t == 5){ x5 = i; y5 = j; }
		t++;
			}

	int s[5];
	s[0] = abs(x1 - head.x) + abs(y1 - head.y);
	s[1] = abs(x2 - head.x) + abs(y2 - head.y);
	s[2] = abs(x3 - head.x) + abs(y3 - head.y);
	s[3] = abs(x4 - head.x) + abs(y4 - head.y);
	s[4] = abs(x5 - head.x) + abs(y5 - head.y);

	sort(s, 5);

	if (s[4] == abs(x1 - head.x) + abs(y1 - head.y)){ foodx = x1; foody = y1; }
	if (s[4] == abs(x2 - head.x) + abs(y2 - head.y)){ foodx = x2; foody = y2; }
	if (s[4] == abs(x3 - head.x) + abs(y3 - head.y)){ foodx = x3; foody = y3; }
	if (s[4] == abs(x4 - head.x) + abs(y4 - head.y)){ foodx = x4; foody = y4; }
	if (s[4] == abs(x5 - head.x) + abs(y5 - head.y)){ foodx = x5; foody = y5; }


}

void kai()  //倒计时函数
{
	if (pauseflag == 0)
	{
		playmusic(99);
		playmusic(startgame);
	}
	if (pauseflag == 1)
		pauseflag =0;
	
	putimage(0, 0, &k3);
	Sleep(1000);
	putimage(0, 0, &k2);
	Sleep(1000);
	putimage(0, 0, &k1);
	Sleep(1000);
	
}

void outcome()
{
	if (startgame == 1)
	{
		char s1[5];
		sprintf(s1, "%d", score);
		outtextxy(200, 20, "your score:");
		outtextxy(200, 40, s1);
		if (score>0)
			outtextxy(200, 60, "Congratulations!");


	}
	if (startgame == 4)
	{
		char s1[5], s2[5];
		sprintf(s1, "%d", score);
		sprintf(s2, "%d", score2);
		outtextxy(200, 20, "your score:");
		outtextxy(200, 40, s1);
		outtextxy(200, 60, "computer's score:");
		outtextxy(200, 80, s2);
		if (score>score2)
			outtextxy(200, 100, "you win!");
		else
			outtextxy(200, 100, "you lose!");
	}
}

void checklevel()
{
	if (level == 1 && _time >= 30)
	{
		if (score<25)
		{
			outtextxy(250, 20, "很遗憾，通关失败！");
			Sleep(2500);
			gameover();//要提示闯关失败
		}

		if (score >= 25)
		{
			putimage(0, 0, &img9);
			outtextxy(250, 200, "成功通过第一关");
			outtextxy(250, 300, "第二关：40秒内得35分");
			Sleep(2000);
			score = 0;
			level = 2;
			_time = 0;
			start1 = time(NULL);
			end1 = time(NULL);

			build();
			fflush(stdin);
		}                   //插入图片，恭喜你闯入下一关
	}

	if (level == 2 && _time >= 40)
	{
		if (score < 35)
		{
			outtextxy(250, 20, "很遗憾，通关失败！");
			Sleep(2500);
			gameover();
		}
		if (score >= 35)
		{
			putimage(0, 0, &img9);
			outtextxy(250, 200, "成功通过第二关");
			outtextxy(250, 300, "第三关：50秒内得40分");
			Sleep(2000);
			score = 0;
			level = 3;
			start1 = time(NULL);
			end1 = time(NULL);
			build();
			fflush(stdin);
		}     
		
	}

	if (level == 3 && _time >= 50)
	{
		if (score >= 40)  //闯完三关
		{
			outtextxy(250, 20, "恭喜你！全部通关成功！");
			Sleep(2500);
			gameover();

		}
		else
		{
			outtextxy(250, 20, "很遗憾，通关失败！");
			Sleep(2500);
			gameover();

		}//要提示闯关失败
	}
}

void loadpicture()
{
	loadimage(&img1, "img1.jpg");
	loadimage(&img2, "img2.jpg");
	loadimage(&img3, "img3.jpg");
	loadimage(&img4, "img4.jpg");
	loadimage(&img5, "img5.jpg");
	loadimage(&img6, "img6.jpg");
	loadimage(&img7, "img7.jpg");
	loadimage(&img8, "img8.jpg");
	loadimage(&img9, "img9.jpg");
	loadimage(&phead0, "head0.jpg");
	loadimage(&phead1, "head1.jpg");
	loadimage(&phead2, "head2.jpg");
	loadimage(&phead3, "head3.jpg");
	loadimage(&pbody, "body.jpg");
	loadimage(&pbody2, "body2.jpg");
	loadimage(&h0, "_head0.jpg");
	loadimage(&h1, "_head1.jpg");
	loadimage(&h2, "_head2.jpg");
	loadimage(&h3, "_head3.jpg");
	loadimage(&k0, "k0.jpg");
	loadimage(&over5, "over.jpg");
	loadimage(&over1, "over1.jpg");
	loadimage(&over2, "over2.jpg");
	loadimage(&over3, "over3.jpg");
	loadimage(&bye, "bye.jpg");
	loadimage(&k1, "k1.jpg");
	loadimage(&k2, "k2.jpg");
	loadimage(&k3, "k3.jpg");
	loadimage(&p1, "p1.jpg");
	loadimage(&p2, "p2.jpg");
	loadimage(&p3, "p3.jpg");
	loadimage(&s1, "s1.jpg");
	loadimage(&s2, "s2.jpg");
	loadimage(&s3, "s3.jpg");
	loadimage(&s4, "s4.jpg");
	loadimage(&s5, "s5.jpg");
	loadimage(&s6, "s6.jpg");
	loadimage(&s7, "s7.jpg");
	loadimage(&s8, "s8.jpg");
	loadimage(&s9, "s9.jpg");
	loadimage(&s10, "s10.jpg");
	loadimage(&s11, "s11.jpg");
	loadimage(&s12, "s12.jpg");
	loadimage(&s13, "s13.jpg");
	loadimage(&s14, "s14.jpg");
	loadimage(&s15, "s15.jpg");
	loadimage(&s16, "s16.jpg");
	loadimage(&w1, "w1.jpg");
	loadimage(&w2, "w2.jpg");
	loadimage(&w3, "w3.jpg");
	loadimage(&w4, "w4.jpg");
	loadimage(&map3, "map3.jpg");
	loadimage(&map2, "map2.jpg");
	loadimage(&map4, "map4.jpg");

}

void set_map()
{
	int i, j;




	for (j = 5; j <= 9; j++)
		map[3][j] = '#';
	for (j = 5; j <= 9; j++)
		map[6][j] = '#';
	for (j = 5; j <= 9; j++)
		map[9][j] = '#';
	map[5][5] = '#';
	map[4][5] = '#';
	map[7][9] = '#';
	map[8][9] = '#';

	for (i = 6; i <= 10; i++)
		map[i][12] = '#';
	for (i = 6; i <= 10; i++)
		map[i][16] = '#';
	map[7][13] = '#';
	map[8][14] = '#';
	map[9][15] = '#';


	map[11][22] = '#';
	map[12][21] = '#';
	map[12][22] = '#';
	map[12][23] = '#';
	map[13][20] = '#';
	map[13][21] = '#';
	map[13][23] = '#';
	map[13][24] = '#';
	map[14][19] = '#';
	map[14][20] = '#';
	map[14][21] = '#';
	map[14][22] = '#';
	map[14][23] = '#';
	map[14][24] = '#';
	map[14][25] = '#';
	map[15][18] = '#';
	map[15][19] = '#';
	map[15][25] = '#';
	map[15][26] = '#';
	map[16][17] = '#';
	map[16][18] = '#';
	map[16][26] = '#';
	map[16][27] = '#';

	for (j = 12; j <= 16; j++)
		map[18][j] = '#';
	for (j = 12; j <= 16; j++)
		map[23][j] = '#';
	for (i = 18; i <= 23; i++)
		map[i][12] = '#';
	map[19][16] = '#';
	map[22][16] = '#';

	for (i = 20; i <= 27; i++)
		map[i][3] = '#';
	map[23][4] = '#';
	map[24][4] = '#';
	map[22][5] = '#';
	map[25][5] = '#';
	map[21][6] = '#';
	map[26][6] = '#';
	map[20][7] = '#';
	map[27][7] = '#';

}

int main() {
	int i;
	initgraph(600, 600);
	loadpicture();
	
	putimage(0, 0, &k0);
	Sleep(3000);

	
	

	
	start();
	speed2 = speed;
	build();
	closegraph();
	initgraph(700, 600);
	start1 = time(NULL);
	show();
	closegraph();
	return 0;
}

void time2()
{
	int i, j;
	m = m + speed;
	

	if (m % 600 == 0)  //实现闪烁
	{

		for (i = 0; i < 30; i++)
			for (j = 0; j < 30; j++)
			{
			if (map[i][j] == '@')  putimage(20 * j, 20 * i, &img5);
			}
		
	}

	if (m % 6000 == 0)
	{
		set_poison();
	}
}

void set_poison()
{
	int i, j;
	for (i = 0; i < 30; i++)
		for (j = 0; j < 30; j++)
		{
		if (map[i][j] == '@')  map[i][j] = ' ';
		}
	for (i = 0; i <= 5; i++)
	{
		poison();
	}

}

void playmusic(int n)
{
	if (n == 0)
	{
		mciSendString(_T("open 0.wav alias music0"), NULL, 0, NULL);
		mciSendString(_T("play music0"), NULL, 0, NULL);
	}
	if (n == 1)
	{
		mciSendString(_T("open 1.wav alias music1"), NULL, 0, NULL);
		mciSendString(_T("play music1"), NULL, 0, NULL);
	}
	if (n == 2)
	{
		mciSendString(_T("open 2.wav alias music2"), NULL, 0, NULL);
		mciSendString(_T("play music2"), NULL, 0, NULL);
	}
	if (n == 3)
	{
		mciSendString(_T("open 3.wav alias music3"), NULL, 0, NULL);
		mciSendString(_T("play music3"), NULL, 0, NULL);
	}
	if (n == 4)
	{
		mciSendString(_T("open 4.wav alias music4"), NULL, 0, NULL);
		mciSendString(_T("play music4"), NULL, 0, NULL);
	}
	if (n == 5)
	{
		mciSendString(_T("open 5.wav alias music5"), NULL, 0, NULL);
		mciSendString(_T("play music5"), NULL, 0, NULL);
	}

	
	
	if (n == 11)
	{
		mciSendString(_T("open 食物.wav alias music11"), NULL, 0, NULL);
		mciSendString(_T("play music11"), NULL, 0, NULL);
	}
	if (n == 12)
	{
		mciSendString(_T("open 非食物.wav alias music12"), NULL, 0, NULL);
		mciSendString(_T("play music12"), NULL, 0, NULL);
	}
	
	if (n == 98)
	{
		mciSendString(_T("close music11"), NULL, 0, NULL);
		mciSendString(_T("close music12"), NULL, 0, NULL);
	}

	if (n == 99)
	{
		mciSendString(_T("close music0"), NULL, 0, NULL);
		mciSendString(_T("close music1"), NULL, 0, NULL);
		mciSendString(_T("close music2"), NULL, 0, NULL);
		mciSendString(_T("close music3"), NULL, 0, NULL);
		mciSendString(_T("close music4"), NULL, 0, NULL);
		mciSendString(_T("close music5"), NULL, 0, NULL);
		mciSendString(_T("close music11"), NULL, 0, NULL);
		mciSendString(_T("close music12"), NULL, 0, NULL);
	}
}

void checksnake()
{
	t_kind+=speed;


	if (kind == 2)
	{
		if (t_kind>= 1500)
		{
			if(color==1)color = 2;
			else color = 1;
			t_kind = 0;
		}
	}

	if (kind == 3)
	{
		
		if (t_kind >= 6000)
		{
			t_kind = 0;

			if (sum == 2)
				gameover();

			else
			{
				int L = sum;
				struct snake *p = &tail;
				do
				{
					map[p->x][p->y] = ' ';
					p = p->next;
				} while (p != NULL);

				if (L <= 4) //长度过短，变成只剩两节
				{


					p = head.previous;
					tail.x = p->x;
					tail.y = p->y;
					tail.next = &head;
					head.previous = &head;
					sum = 2;
				}
				if (L > 4)
				{

					int k, i;
					i = 0;
					if ((L - 2) % 2 == 0)
						k = (L - 2) / 2;
					else
						k = (L - 3) / 2;

					p = &head;
					for (i = 0; i <= k; i++)
					{
						p = p->previous;
					}
					tail.x = p->previous->x;
					tail.y = p->previous->y;
					tail.next = p;
					p->previous = &tail;

					p = &tail;
					int x = 0;
					for (i = 2; x != 1;)
					{
						p = p->next;
						if (p == &head)x = 1;
						i = i + 1;
					}
					sum = i - 1;
				}

				p = &tail;
				for (; p->next != NULL;)
				{
					p->x = p->next->x;
					p->y = p->next->y;
					p = p->next;
				}
				p = &head;
				p->x = head.x + dx[dir];
				p->y = head.y + dy[dir];

				p = &tail;
				do{
					map[p->x][p->y] = '*';
					p = p->next;
				} while (p != NULL);
			}
		}
	}




}

void choosesnake()
{
	putimage(0, 0, &w1);
	
	int i;
	int guide = 1;
	while (1)
	{

		i = keyBoard();
		if (i == UP)
		{
			if (guide != 1)
			{
				guide--;
				if (guide == 1)putimage(0, 0, &w1);
				if (guide == 2)putimage(0, 0, &w2);
				if (guide == 3)putimage(0, 0, &w3);
				if (guide == 4)putimage(0, 0, &w4);
			}
		}


		if (i == DOWN)
		{
			if (guide != 4)
			{
				guide++;
				if (guide == 1)putimage(0, 0, &w1);
				if (guide == 2)putimage(0, 0, &w2);
				if (guide == 3)putimage(0, 0, &w3);
				if (guide == 4)putimage(0, 0, &w4);

			}
		}



		if (i == ENTER)
		{
			if (guide == 1)
			{
				kind = 1;
				break;

			}
			if (guide == 2)
			{
				kind = 2;
				break;
			}


			if (guide == 3)
			{
				kind = 3;
				break;
				
			}
			if (guide == 4)
			{
				kind = 4;
				break;
			}

		}

	}

}

void checktime_vscomputer()
{
	if (_time >= 40)
	{
		_time = 0;
		FILE *fpWrite = fopen("data.txt", "a");
		fprintf(fpWrite, "%d ", score);
		fclose(fpWrite);
		gameover();
	}
}
