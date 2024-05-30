#pragma once
#include <graphics.h>
#include <vector>
#include "Block.h"
#include <mciapi.h>
using namespace std;

class Tetris
{
private:
	int delay;	//关卡不同刷新频率不同
	bool update;	//判断是否更新

	//存储列信息和行信息的数据
	//0表示没有方块，1-7表示第n中方块
	vector<vector<int>> map;
	int column_num;
	int row_num;
	int leftMargin;
	int topMargin;
	int blockSize;

	int score;	//当前的分数
	int level;	//当前关卡
	int lineCount;	//当前已经消除了多少行

	int highestScore;	//最高分																					

	IMAGE bkimg;
	IMAGE imgOver;
	IMAGE imgWin;
	Block* curBlock;
	Block* nextBlock;	//预告方块
	
	Block copyBlock;	//在当前方块掉落过程中用来备份上一个合法位置的方块

	bool gameOver;	//游戏是否结束

private:
	//类内部用的接受接口，放在隐私权限中
	void keyEven();
	void updateWindow();

	//返回上一次调用这个函数间隔过多长时间(ms)
	//第一次调用时返回0
	int getDelay();
	
	//方块的下落
	void drop();

	//清行
	void clearLine();

	//检查游戏是否结束
	void checkOver();

public:
	Tetris(int rows,int columns,int left,int top,int blockSize);
	
	void init();
	void play();

	void moveLeftRight(int offset);

	void rotate();
	void drawScore();

	void saveScore();
	void displayOver();


~Tetris();


};

