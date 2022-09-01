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
			//1.��ӡһ�е�����
			printf(" %c ", board[i][j]);
			if (j < col -1)
				printf("|");
		}
		printf("\n");
		//2.��ӡ�ָ���
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
		printf("����������:> \n�� 1,1 \n");
		scanf("%d,%d", &x, &y);
		//�ж��û���������Ϸ���
		if ((x >= 1 && x <= ROW) && (y >= 1 && y <= COL))
		{
			if (' ' == board[x - 1][y - 1])
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("�����Ѿ��¹��ˣ�����������\n");
			}
		}
		else
		{
			int ch = 0;
			printf("��������겻��������,����������\n");
			while ((ch = getchar()) != '\n')
			{
				;
			}
		}
	
	}
	
}


//����б�߶�ɨ��һ�飬���ü�����ͳ�ƣ�ֱ������n����ͬ�������š�
//�������Σ�1�������Ӯ��0�������Ӯ��2�������
int IsWin(char board[ROW][COL], int row, int col)
{

    int i = 0;
    //���ϵ��£�ɨ��ÿһ��
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

    //ɨ����
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

    //��ʽ���ϲ���ɨ��
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

    //��ʽ���²���ɨ��
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

    //Ʋʽ����ɨ��
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

    //Ʋʽ����ɨ��
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
            printf("������\n");
        else if (1 == ret)
            printf("��Ӯ��\n");
        else
        {
            printf("ƽ��\n");
            
        }
    }
    
}

void ComputerMove(char board[ROW][COL],int row,int col)
{
    int x = 0;
    int y = 0;
    printf("������:>\n");
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