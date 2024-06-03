#include "Block.h"
#include "Tetris.h"
#include <conio.h>
#include <cstdio>
#include<cstdlib>
#include <fstream>
#include <iostream>
#include<Windows.h>
#include <mmsystem.h>
#include <time.h>
#include <mciapi.h>
#pragma commemt(lib,"winmm.lib")
#define RECORD_FILE "score.txt"
//使用mt19937生成随机数种子以确保播放音乐的随机性
#include <random>
using namespace std;
mt19937 myseed(0);
uniform_int_distribution<int> myrand(15, 150);


//正常速度500ms，快速50ms
//const int normal_speed = 500;
const int normal_speed[6] = { 500,450,390,330,220,110 };
const int quick_speed = 90;

void Tetris::openmusic()
{

	//加载游戏音乐，歌曲名使用英文
	mciSendString("open res/To_the_love'end.mp3 alias m1", 0, 0, 0);
	mciSendString("open res/Faded.mp3 alias m2", 0, 0, 0);
	mciSendString("open res/Merry_Christmas_Mr. Lawrence.mp3 alias m3", 0, 0, 0);
	mciSendString("open res/Minecraft.mp3 alias m4", 0, 0, 0);
	mciSendString("open res/Seasonse.mp3 alias m5", 0, 0, 0);
	mciSendString("open res/I_Love.mp3 alias m6", 0, 0, 0);
	mciSendString("open res/To_the_love'end.mp3 alias m7", 0, 0, 0);
	mciSendString("open res/whale.mp3 alias m8", 0, 0, 0);
	mciSendString("open res/Confession.mp3 alias m9", 0, 0, 0);
	mciSendString("open res/Sea_flowers.mp3 alias m10", 0, 0, 0);
	mciSendString("open res/See_off.mp3 alias m11", 0, 0, 0);
	mciSendString("open res/at_dusk.mp3 alias m12", 0, 0, 0);
	mciSendString("open res/Summer.mp3 alias m13", 0, 0, 0);
	mciSendString("open res/Snow.mp3 alias m14", 0, 0, 0);
	mciSendString("open res/porcelain.mp3 alias m15", 0, 0, 0);
	mciSendString("open res/if_forgotten.mp3 alias m16", 0, 0, 0);
	mciSendString("open res/lose_time.mp3 alias m17", 0, 0, 0);
	mciSendString("open res/Only.mp3 alias m18", 0, 0, 0);
	mciSendString("open res/frost.mp3 alias m19", 0, 0, 0);
	mciSendString("open res/paper_plane.mp3 alias m20", 0, 0, 0);
	mciSendString("open res/road_with_flower.mp3 alias m21", 0, 0, 0);
	mciSendString("open res/cloud_loop.mp3 alias m22", 0, 0, 0);
	mciSendString("open res/divorce.mp3 alias m23", 0, 0, 0);
	mciSendString("open res/looking_for_you.mp3 alias m24", 0, 0, 0);
	mciSendString("open res/See_You_Again.mp3 alias m25", 0, 0, 0);
}

void Tetris::closemusic(int m)
{
	if (m == 0)mciSendString("close m1 ", 0, 0, 0);
	if (m == 1)mciSendString("close m2 ", 0, 0, 0);
	if (m == 2)mciSendString("close m3 ", 0, 0, 0);
	if (m == 3)mciSendString("close m4 ", 0, 0, 0);
	if (m == 4)mciSendString("close m5 ", 0, 0, 0);
	if (m == 5)mciSendString("close m6 ", 0, 0, 0);
	if (m == 6)mciSendString("close m7 ", 0, 0, 0);
	if (m == 7)mciSendString("close m8 ", 0, 0, 0);
	if (m == 8)mciSendString("close m9 ", 0, 0, 0);
	if (m == 9)mciSendString("close m10", 0, 0, 0);
	if (m == 10)mciSendString("close m11", 0, 0, 0);
	if (m == 11)mciSendString("close m12", 0, 0, 0);
	if (m == 12)mciSendString("close m13", 0, 0, 0);
	if (m == 13)mciSendString("close m14", 0, 0, 0);
	if (m == 14)mciSendString("close m15", 0, 0, 0);
	if (m == 15)mciSendString("close m16", 0, 0, 0);
	if (m == 16)mciSendString("close m17", 0, 0, 0);
	if (m == 17)mciSendString("close m18", 0, 0, 0);
	if (m == 18)mciSendString("close m19", 0, 0, 0);
	if (m == 19)mciSendString("close m20", 0, 0, 0);
	if (m == 20)mciSendString("close m21", 0, 0, 0);
	if (m == 21)mciSendString("close m22", 0, 0, 0);
	if (m == 22)mciSendString("close m23", 0, 0, 0);
	if (m == 23)mciSendString("close m24", 0, 0, 0);
	if (m == 24)mciSendString("close m25", 0, 0, 0);
}


void Tetris::changemusic(int m)
{
	openmusic();
	playmusic(m);
}

void Tetris::playmusic(int m)
{
	
	if (m == 0)mciSendString("play m1 repeat", 0, 0, 0);
	if (m == 1)mciSendString("play m2 repeat", 0, 0, 0);
	if (m == 2)mciSendString("play m3 repeat", 0, 0, 0);
	if (m == 3)mciSendString("play m4 repeat", 0, 0, 0);
	if (m == 4)mciSendString("play m5 repeat", 0, 0, 0);
	if (m == 5)mciSendString("play m6  repeat", 0, 0, 0);
	if (m == 6)mciSendString("play m7 repeat", 0, 0, 0);
	if (m == 7)mciSendString("play m8 repeat", 0, 0, 0);
	if (m == 8)mciSendString("play m9 repeat", 0, 0, 0);
	if (m == 9)mciSendString("play m10 repeat",0,0,0);
	if (m == 10)mciSendString("play m11 repeat",0,0,0);
	if (m == 11)mciSendString("play m12 repeat",0,0,0);
	if (m == 12)mciSendString("play m13 repeat",0,0,0);
	if (m == 13)mciSendString("play m14 repeat",0,0,0);
	if (m == 14)mciSendString("play m15 repeat",0,0,0);
	if (m == 15)mciSendString("play m16 repeat",0,0,0);
	if (m == 16)mciSendString("play m17 repeat",0,0,0); 
	if (m == 17)mciSendString("play m18 repeat",0,0,0);
	if (m == 18)mciSendString("play m19 repeat",0,0,0);
	if (m == 19)mciSendString("play m20 repeat",0,0,0);
	if (m == 20)mciSendString("play m21 repeat",0,0,0); 
	if (m == 21)mciSendString("play m22 repeat",0,0,0);
	if (m == 22)mciSendString("play m23 repeat",0,0,0);
	if (m == 23)mciSendString("play m24 repeat",0,0,0);
	if (m == 24)mciSendString("play m25 repeat", 0, 0, 0);

}

void Tetris::keyEven()
{
	unsigned char userkey;
	bool rotateFlag = false;
	int dx = 0;

	if (_kbhit())
	{
		userkey = _getch();

		//如果按下方向键，会自动返回两个字符
		//按向上方向键  224 72
		//按向下方向键  224 80
		//按向左方向键  224 75
		//按向右方向键  224 77 
		/*if (userkey == 224)
		{
			userkey = _getch();
			switch (userkey)
			{
			//向上旋转
			case 72:
				rotateFlag = true;
				break;
			case 80:
				delay=quick_speed;
				break;
			case 75:
				dx = -1;
				break;
			case 77:
				dx = 1;
				break;
			default:
				break;
			}
		}
		*/

		switch (userkey)
		{
		case 'W':
		case 'w':
			rotateFlag = true;
			break;
		case 'S':
		case 's':
			delay = quick_speed;
			break;
		case 'A':
		case 'a':
			dx = -1;
			break;
		case 'D':
		case 'd':
			dx = 1;
			break;
		case 'Q':
		case 'q':
			delay = normal_speed[0];
			break;
		case 'E':
		case 'e':
		{
			closemusic(music);
			music =( myrand(myseed)%25);
			changemusic(music);
			break;
		}
		default:
			break;
		}


	}
	if (rotateFlag)
	{
		rotate();
		update = true;
		rotateFlag = false;

	}

	if (dx != 0)
	{
		moveLeftRight(dx);
		update = true;
	}
}

void Tetris::updateWindow()
{
	putimage(0, 0, &bkimg);	//绘制背景图片
	
	IMAGE** imggs = Block::getImages();

	BeginBatchDraw();
	for (int i = 0; i < row_num; i++)
	{
		for (int j = 0; j < column_num; j++)
		{
			if (map[i][j] == 0)
				continue;
			int x = j * blockSize + leftMargin;
			int y = i * blockSize + topMargin;
			putimage(x, y, imggs[map[i][j] - 1]);
		}
	}

	curBlock->draw(leftMargin, topMargin);
	nextBlock->draw(689, 150);	//这里也是由背景给出的测量好的数据

	drawScore();	//绘制分数


	EndBatchDraw();
}


int Tetris::getDelay()
{
	static unsigned long long lastTime = 0;
	//用开机时间到现在的时间来描述
	unsigned long long currentTime=GetTickCount();
	if (lastTime == 0)
	{
		lastTime=currentTime;
		return 0;
	}
	else
	{
		int ret = currentTime - lastTime;
		lastTime = currentTime;
		return ret;
	}
}

void Tetris::drop()
{
	copyBlock = *curBlock;	//需要动用赋值构造函数
	curBlock->drop();
	

	if (!curBlock->blockInMap(map))
	{
		copyBlock.solidify(map);
		delete curBlock;
		curBlock = nextBlock;
		nextBlock = new Block;


		//检查游戏是否结束
		checkOver();
	}
	
	//调控正常速度
	//delay = normal_speed[level-1];
}

void Tetris::clearLine() 
{
	int clearedlines = 0;
	int k = row_num - 1;
	for (int i = row_num - 1; i >= 0; --i)
	{
		//先检查第i行是否满行
		int count = 0;
		for (int j = 0; j < column_num; j++)
		{
			if (map[i][j])	count++;

			map[k][j] = map[i][j];	//一边扫描一边存储
		}
		if (count < column_num)	k--;	//不满行
		else clearedlines++;			//计算一次性消除行数

	}

	//switch (clearedlines)
	//{
	//case 1:
	//	break;
	//default:
	//	break;
	//}

	if (clearedlines > 0)
	{
		//计算得分
		int addScore[4] = { 5,12,20,30 };

		//播放音乐
		//mciSendString("play ")
		update = true;

		score += addScore[clearedlines - 1];

		//60分为第一关 130分为第二关  200分为第三关  300分为第四关  450分为第五关，结束
		if (score <= 60)			level = 1;
		else if (score <= 130)		level = 2;
		else if (score <= 200)		level = 3;
		else if (score <= 300)		level = 4;
		else if (score <= 450)		level = 5;
		else if (score <= 1000)		level = 6;
		else						level = 7;

		if (level == 7)
		{
			gameOver = true;
		}

		lineCount += clearedlines;


	}

}

void Tetris::checkOver()
{
	gameOver=(curBlock->blockInMap(map) == false);


}

Tetris::Tetris(int rows, int columns, int left, int top, int blockSize)
{

	//这个主要是考虑到有外界的要求导致游戏的展示大小改变从而方便调整用的
	//实际上对于一个固定设计尺寸的游戏例如手机端或者Switch上面固定大小的游戏
	//而言，并不需要这些
	this->row_num = rows;
	this->column_num = columns;
	this->leftMargin = left;
	this->topMargin = top;
	this->blockSize = blockSize;

	for (int i = 0; i < row_num; i++)
	{
		vector<int> map_row;
		for (int j = 0; j < column_num; j++)
			map_row.push_back(0);
		map.push_back(map_row);
	}

	//初始设置为播放第一首
	music = 0;
	openmusic();
	

}

void Tetris::rotate()
{
	//愤怒男孩类型不用返回
	if (curBlock->getBlockType() == 7)	return;

	copyBlock = *curBlock;
	curBlock->rotate();
	if (!curBlock->blockInMap(map))
		*curBlock = copyBlock;
}

void Tetris::drawScore()
{
	//思路不错
	char scoreText[32];
	sprintf_s(scoreText, sizeof(scoreText), "%d", score);	


	//调整字体颜色，大小，抗锯齿,字体
	setcolor(RGB(180, 180, 180));	

	LOGFONT f;
	gettextstyle(&f);	//获取当前的字体
	f.lfHeight = 60;
	f.lfWeight = 30;
	f.lfQuality = ANTIALIASED_QUALITY;	//抗锯齿效果
	strcpy_s(f.lfFaceName,sizeof(f.lfFaceName),_T("Segoe UI Black"));

	
	settextstyle(&f);
	setbkmode(TRANSPARENT);	//字体的背景设置为透明效果
	outtextxy(670, 727, scoreText);

	//绘制消除了多少行
	sprintf_s(scoreText, sizeof(scoreText), "%d", lineCount);
	gettextstyle(&f);
	int xPos = 224 - f.lfWeight * strlen(scoreText);
	outtextxy(xPos, 817, scoreText);

	//绘制当前是第几关卡
	sprintf_s(scoreText, sizeof(scoreText), "%d", level);
	outtextxy(224-30, 727, scoreText);

	sprintf_s(scoreText, sizeof(scoreText), "%d", highestScore);
	outtextxy(670, 817, scoreText);

}

void Tetris::saveScore()
{
	if (score > highestScore)
	{
		highestScore = score;
		ofstream score_file(RECORD_FILE);
		score_file << highestScore;
		score_file.close();
	}
}

//绘制游戏结束画面
void Tetris::displayOver()
{
	//mciSendString("stop .pure1.mp3", 0, 0, 0);
	//关闭音乐
	closemusic(music);

	//胜利结束还是失败结束
	if (level <= 7)
	{
		putimage(262, 361, &imgOver);
	}
}

Tetris::~Tetris()
{
	//to.do
	//update=true;
}


void Tetris::init()
{
	//播放游戏音乐
	//mciSendString("play pure1.mp3",0,0,0);
	playmusic(music);



	delay = normal_speed[0];

	//配置随机种子
	srand(time(NULL));

	//测出来的背景图片尺寸
	initgraph(938,896);

	//加载背景图片
	loadimage(&bkimg, "./images/bg2.png");

	loadimage(&imgOver, "./images/over.png");

	//开启下一局时初始化map数组
	for (int i = 0; i < row_num; i++)
		for (int j = 0; j < column_num; j++) map[i][j] = 0;

	score = 0;
	lineCount = 0;
	level = 1;

	//初始化最高分
	ifstream score_file(RECORD_FILE);
	if (!score_file.is_open())
	{
		std::cout << RECORD_FILE << "OPEN FLASE\n";
		highestScore = 0;
	}
	else
	{
		score_file >> highestScore;
	}

	score_file.close();		//关闭文件

	gameOver = false;



}

//这是最先设计的部分
void Tetris::play()
{

	init();

	nextBlock = new Block;
	curBlock = nextBlock;
	nextBlock = new Block;

	//用计时器设置刷新频率，从而使得画面流畅
	int timer = 0;


	//双缓冲机制
	BeginBatchDraw();

	while (1)
	{
		//接受用户输入
		keyEven();

		timer += getDelay();

		//屏幕刷新率30Hz,合理安排渲染的次数

		//需要修改为60Hz,更加适合人眼的辨识度
		if (timer > delay)
		{
			timer = 0;


			drop();
			//渲染游戏画面
			update = true;

		}

		//用户按键或者屏幕自动刷新都会渲染游戏画面
		if (update)
		{
			update = false;
			//更新游戏画面
			updateWindow();

			//更新游戏数据
			clearLine();
		}

		if (gameOver)
		{
			//保存分数
			saveScore();

			//更新游戏结束界面
			displayOver();

			system("pause");
			init();				//重新开始下一局

		}

		FlushBatchDraw();

	}
	EndBatchDraw();

};




void Tetris::moveLeftRight(int offset)
{
	copyBlock = *curBlock;
	curBlock->moveLeftRight(offset);

	if (!curBlock->blockInMap(map))
	{
		*curBlock = copyBlock;
	}
}


