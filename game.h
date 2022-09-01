#pragma once

#define ROW 10 //棋盘行数
#define COL 6//棋盘列数
#define N 5  //连续放置n子胜利


#include<stdio.h>
#include<time.h>

void InitializeBoard(char board[ROW][COL], int row, int col);

void DisplayBoard(char board[ROW][COL], int row, int col);

void PlayMove(char board[ROW][COL], int row, int col);

int IsWin(char board[ROW][COL], int row, int col);

void ShowResult(int ret);

void ComputerMove(char board[ROW][COL], int row, int col);


