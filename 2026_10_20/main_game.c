#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

void menu()
{
	printf("---------------------\n");
	printf("---------1.开始------\n");
	printf("---------0.退出------\n");
	printf("---------------------\n");
	printf("请输入你的选择：\n");
}

void game()
{
	char shade[ROWS][LINS] = { 0 };
	char show[ROWS][LINS] = { 0 };
	set_array(shade, ROWS, LINS, '0');
	set_array(show, ROWS, LINS, '*');
	//print_array(shade, ROW, LIN);
	print_array(show, ROW, LIN);
	set_array_to_one(shade);
	find_lei(shade, show, ROW, LIN);

	
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		if (scanf("%d", &input) != 1)
		{
			printf("输入无效请重新输入\n");
			while (getchar() != '\n');
			input = 1;
			continue;
		}
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default :
			printf("输入无效请重新输入\n");
		}
	} while (input);
	return 0;
}