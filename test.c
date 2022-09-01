//Readme:在三子棋的基础上进行改进，写了一个自定义棋盘大小，自定义胜利条件的n子棋游戏。
//请在game.h文件中修改棋盘大小以及胜利条件（连续n子）
#define _CRT_SECURE_NO_WARNINGS 

#include"game.h"

void menu()
{
	printf("************  welcome!  ************\n");
	printf("********** 1.play   0.exit *********\n");
	printf("************************************\n");
}

//游戏的整个算法实现
void game()
{
	//存放对弈信息的棋盘数组
	char board[ROW][COL] = { 0 };
	//初始化棋盘
	InitializeBoard(board,ROW,COL);
	//打印棋盘
	DisplayBoard(board,ROW,COL);

	int ret = IsWin(board, ROW, COL);
	
	
	while (1)
	{
		//玩家走
		PlayMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断玩家是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 2)
			break;
		//电脑走
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//判断电脑是否赢
		ret = IsWin(board, ROW, COL);
		if (ret != 2)
			break;

	}
		if (2 != ret)
		{
			if (0 == ret)
				printf("你输了\n");
			else if (1 == ret)
				printf("你赢了\n");
			else
			{
				printf("平局\n");

			}
		

		//没用的结果函数
		//void ShowResult(ret);

			
		
		
	}
}
	//判输赢	

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
			
		}


	} while (input);
}

int main()
{
	test();
	return 0;
}