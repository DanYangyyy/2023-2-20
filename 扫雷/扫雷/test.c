#include"game.h"

void menu()
{
	printf("********************\n");
	printf("****** 1.play ******\n");
	printf("****** 0.exit ******\n");
	printf("********************\n");
}
void game()
{
	//扫雷游戏的实现
	//mine数组是用来存放布置好的雷的信息
	//show数组是用来存放排查出的雷的信息
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };

	//初始化棋盘
	init_board(mine, ROWS, COLS, '0');
	init_board(show, ROWS, COLS, '*');

	//打印棋盘
	//show_board(mine, ROW, COL);
	//show_board(show, ROW, COL);
	//布置雷
	set_mine(mine, ROW, COL);
	show_board(show, ROW, COL);

	//排查雷
	find_mine(mine, show, ROW, COL);
}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:\n");
		scanf("%d", &input);
		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏结束\n");
			break;
		defaut:
			break;
		}

	} while (input);
	return 0;
}
