//Readme:��������Ļ����Ͻ��иĽ���д��һ���Զ������̴�С���Զ���ʤ��������n������Ϸ��
//����game.h�ļ����޸����̴�С�Լ�ʤ������������n�ӣ�
#define _CRT_SECURE_NO_WARNINGS 

#include"game.h"

void menu()
{
	printf("************  welcome!  ************\n");
	printf("********** 1.play   0.exit *********\n");
	printf("************************************\n");
}

//��Ϸ�������㷨ʵ��
void game()
{
	//��Ŷ�����Ϣ����������
	char board[ROW][COL] = { 0 };
	//��ʼ������
	InitializeBoard(board,ROW,COL);
	//��ӡ����
	DisplayBoard(board,ROW,COL);

	int ret = IsWin(board, ROW, COL);
	
	
	while (1)
	{
		//�����
		PlayMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 2)
			break;
		//������
		ComputerMove(board, ROW, COL);
		DisplayBoard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ
		ret = IsWin(board, ROW, COL);
		if (ret != 2)
			break;

	}
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
		

		//û�õĽ������
		//void ShowResult(ret);

			
		
		
	}
}
	//����Ӯ	

void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
			
		}


	} while (input);
}

int main()
{
	test();
	return 0;
}