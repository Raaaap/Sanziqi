#define _CRT_SECURE_NO_WARNINGS 

#include"game.h"

void InitializeBoard(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL],int row,int col)
{
	
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			//1.打印一行的数据
			printf(" %c ", board[i][j]);
			if (j < col -1)
				printf("|");
		}
		printf("\n");
		//2.打印分割行
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
	printf("\n");

}

void PlayMove(char board[ROW][COL],int row,int col)
{
	int x = 0;
	int y = 0;
	printf("it is your turn \n");

	while(1)
	{
		printf("请输入坐标:> \n如 1,1 \n");
		scanf("%d,%d", &x, &y);
		//判断用户输入坐标合法性
		if ((x >= 1 && x <= ROW) && (y >= 1 && y <= COL))
		{
			if (' ' == board[x - 1][y - 1])
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("这里已经下过了，请重新输入\n");
			}
		}
		else
		{
			int ch = 0;
			printf("输入的坐标不在棋盘内,请重新输入\n");
			while ((ch = getchar()) != '\n')
			{
				;
			}
		}
	
	}
	
}


//行列斜线都扫描一遍，并用计数器统计，直到出现n个相同连续符号。
//返回整形，1代表玩家赢，0代表电脑赢，2代表继续
int IsWin(char board[ROW][COL], int row, int col)
{

    int i = 0;
    //从上到下，扫描每一行
    for (i = 0; i < row; i++)
    {
        int PlayerCount = 0;
        int ComputerCount = 0;
        int j = 0;
        for (j = 0; j < col; j++)
        {

            if ('*' == board[i][j])
            {
                ComputerCount = 0;
                PlayerCount++;
                if (N == PlayerCount)
                {
                    return 1;
                }
            }
            else if ('#' == board[i][j])
            {
                PlayerCount = 0;
                ComputerCount++;
                if (N == ComputerCount)
                {
                    return 0;
                }
            }
            else
            {
                PlayerCount = ComputerCount = 0;
            }

        }
    }

    //扫描列
    for (i = 0; i < col; i++)
    {
        int PlayerCount = 0;
        int ComputerCount = 0;
        int j = 0;
        for (j = 0; j < row; j++)
        {

            if ('*' == board[j][i])
            {
                ComputerCount = 0;
                PlayerCount++;
                if (N == PlayerCount)
                {
                    return 1;
                }
            }
            else if ('#' == board[j][i])
            {
                PlayerCount = 0;
                ComputerCount++;
                if (N == ComputerCount)
                {
                    return 0;
                }
            }
            else
            {
                PlayerCount = ComputerCount = 0;
            }

        }
    }

    //捺式右上部分扫描
    for (i = 0; i < col; i++)
    {
        int PlayerCount = 0;
        int ComputerCount = 0;
        int j = 0;
        for (j = 0; j < row ; j++)
        {

            if ('*' == board[j][i+j])
            {
                ComputerCount = 0;
                PlayerCount++;
                if (N == PlayerCount)
                {
                    return 1;
                }
            }
            else if ('#' == board[j][i+j])
            {
                PlayerCount = 0;
                ComputerCount++;
                if (N == ComputerCount)
                {
                    return 0;
                }
            }
            else
            {
                PlayerCount = ComputerCount = 0;
            }

        }
    }

    //捺式左下部分扫描
    for (i = 0; i < row; i++)
    {
        int PlayerCount = 0;
        int ComputerCount = 0;
        int j = 0;
        for (j = 0; j < col ; j++)
        {

            if ('*' == board[i+j][j])
            {
                ComputerCount = 0;
                PlayerCount++;
                if (N == PlayerCount)
                {
                    return 1;
                }
            }
            else if ('#' == board[i+j][j])
            {
                PlayerCount = 0;
                ComputerCount++;
                if (N == ComputerCount)
                {
                    return 0;
                }
            }
            else
            {
                PlayerCount = ComputerCount = 0;
            }

        }
    }

    //撇式左上扫描
    for (i = 0; i < row; i++)
    {
        int PlayerCount = 0;
        int ComputerCount = 0;
        int j = 0;
        for (j = 0; j < col; j++)
        {

            if ('*' == board[row-1-i-j][j])
            {
                ComputerCount = 0;
                PlayerCount++;
                if (N == PlayerCount)
                {
                    return 1;
                }
            }
            else if ('#' == board[row-1-i-j][j])
            {
                PlayerCount = 0;
                ComputerCount++;
                if (N == ComputerCount)
                {
                    return 0;
                }
            }
            else
            {
                PlayerCount = ComputerCount = 0;
            }

        }
    }

    //撇式右下扫描
    for (i = 0; i <col; i++)
    {
        int PlayerCount = 0;
        int ComputerCount = 0;
        int j = 0;
        for (j = 0; j <row; j++)
        {

            if ('*' == board[row-1-j][j+i])
            {
                ComputerCount = 0;
                PlayerCount++;
                if (N == PlayerCount)
                {
                    return 1;
                }
            }
            else if ('#' == board[row-1-j][j+i])
            {
                PlayerCount = 0;
                ComputerCount++;
                if (N == ComputerCount)
                {
                    return 0;
                }
            }
            else
            {
                PlayerCount = ComputerCount = 0;
            }

        }
    }

    for (i = 0; i < row; i++)
    {
        int j = 0;
        for (j = 0; j < col; j++)
        {
            if (' ' == board[i][j])
                return 2;
        }
    }


}

void ShowResult(int ret)
{
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
    }
    
}

void ComputerMove(char board[ROW][COL],int row,int col)
{
    int x = 0;
    int y = 0;
    printf("电脑走:>\n");
    while (1)
    {
        x = rand() % row;
        y = rand() % col;
        if (' ' == board[x][y])
        {
            board[x][y] = '#';
            break;
        }
    }


}