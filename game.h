#pragma once

#define ROW 10 //��������
#define COL 6//��������
#define N 5  //��������n��ʤ��


#include<stdio.h>
#include<time.h>

void InitializeBoard(char board[ROW][COL], int row, int col);

void DisplayBoard(char board[ROW][COL], int row, int col);

void PlayMove(char board[ROW][COL], int row, int col);

int IsWin(char board[ROW][COL], int row, int col);

void ShowResult(int ret);

void ComputerMove(char board[ROW][COL], int row, int col);


