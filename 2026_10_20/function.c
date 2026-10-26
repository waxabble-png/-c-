#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void print_array(char arr[ROWS][LINS], int rows, int lins)
{
	int i = 0;
	printf("扫雷游戏正式开始：\n");
	for (i = 0;i <= rows; i++)
	{
		printf("%d ", i);
	}
	printf("\n");

	for (i = 1; i <= rows; i++)
	{
		printf("%d ", i);
		int r = 0;
		for (r = 1;r <= lins; r++)
		{
			printf("%c ", arr[i][r]);
		}
	printf("\n");
	}
}

void set_array(char arr[ROWS][LINS], int rows, int lins, char bit)
{
	int a = 0;
	for (a = 0;a < rows ;a++)
	{
		int b = 0;
		for (b = 0; b < lins; b++)
		{
			arr[a][b] = bit;
		}
	}
}

//埋雷 ： 一共十个雷，先判断随机选取的位子是不是雷，然后再埋雷
void set_array_to_one(char arr[ROWS][LINS])
{
	int timess = 10;
	while (timess)
	{
		int random_row = rand() % ROW + 1;
		int random_lin = rand() % LIN + 1;

		if (arr[random_row][random_lin] == '0')
		{
			arr[random_row][random_lin] = '1';
			timess--;
		}
	}
}

//翻页，根据周围雷的数量来确定数字
int lei_de_shuliang(char arr[ROWS][LINS], int x, int y)
{
	return (arr[x - 1][y] + arr[x - 1][y + 1] + arr[x - 1][y - 1] + arr[x][y - 1]
		+ arr[x][y + 1] + arr[x + 1][y - 1] + arr[x + 1][y] + arr[x + 1][y + 1] - 8 * '0');
}

void find_lei(char shade[ROWS][LINS], char show[ROWS][LINS], int rows, int lins)
{
	int x, y, win = 0;
	int timess = 10;
	while (win < rows * lins - timess)
	{
		printf("请输入你要排查的坐标先纵再横，并用空格隔开：\n");
		if (scanf("%d %d", &x, &y) != 2)
		{
			printf("输入的坐标不合法，请重新输入！\n");
			while (getchar() != '\n');
			continue;
		}
		if (x >= 1 && y >= 1 && x <= rows && y <= lins)
		{
			if (shade[x][y] == '1')
			{
				printf("很遗憾，你踩到雷了\n");
				print_array(shade, ROW, LIN);
				break;
			}
			else
			{
				if (show[x][y] == '*')
				{
					int number = lei_de_shuliang(shade, x, y);
					show[x][y] = number + '0';
					print_array(show, ROW, LIN);
					win++;
				}
				else
				{
					printf("该坐标已经排查过了，请重新输入！\n");
				}
			}
		
		}
		else
		{
			printf("输入的坐标不合法，请重新输入！\n");
		}
	}
	if (win == rows * lins - timess)
	{
		printf("恭喜你扫雷成功\n");
		print_array(shade, ROW, LIN);
	}
}