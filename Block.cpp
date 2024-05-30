#include "Block.h"
#include <time.h>
#include <stdlib.h>


IMAGE* Block::imgs[7] = { NULL, };
int Block::size = 36;
Block::Block()
{

	if (imgs[0] == NULL)
	{
		IMAGE tempImg;
		loadimage(&tempImg, "./images/tiles.png");
		//将工作区设置在临时图片上
		SetWorkingImage(&tempImg);
		for (int i = 0; i < 7; i++)
		{
			imgs[i] = new IMAGE;
			getimage(imgs[i], i * size, 0,size, size);	//切出的方块大小为size
		}
		SetWorkingImage();	//恢复工作区
		srand(time(NULL));	
	}


	//相对坐标表示法,原理参见image文件夹下的相对坐标表示法.jpg
	int blocks[7][4] = {
	 1,3,5,7, // 长条
	 2,4,5,7, // Z 1型
	 3,5,4,6, // Z 2型
	 3,5,4,7, // 小T
	 2,3,5,7, // 左手折角
	 3,5,7,6, // 右手折角
	 2,3,4,5, // 愤怒男孩
	};

	//随机生成一种俄罗斯方块
	blockType =1+rand() % 7;	//类型从1到7来命名

	//初始化smallBlock
	for (int i = 0; i < 4; i++)
	{
		int value = blocks[blockType-1][i];
		smallBlocks[i].row = value / 2;
		smallBlocks[i].column = value % 2;
	}

	img = imgs[blockType - 1];	//绘制的方块对应的图片参数
}

int Block::getBlockType()
{

	return 0;
}

Block::~Block()
{
}

void Block::drop()
{
	//下降就是行标加加
	for (auto &block:smallBlocks)
		block.row++;
}

void Block::moveLeftRight(int offset)
{
	for (int i = 0; i < 4; i++)
		smallBlocks[i].column += offset;
}


//旋转函数公式确实很复杂，我在考虑要不要写了拍张照弄上去
void Block::rotate()
{
	//把第二个点作为中心
	Point p = smallBlocks[1];
	for (int i = 0; i < 4; i++)
	{
		Point temp = smallBlocks[i];
		smallBlocks[i].column = p.column - temp.row + p.row;
		smallBlocks[i].row = p.row + temp.column - p.column;
	}

}

void Block::draw(int leftMargin, int topMargin)
{
	for (int i = 0; i < 4; i++)
	{
		//这里直接用逻辑坐标乘以小方块大小加上和四周的距离来计算像素坐标
		int x = leftMargin + smallBlocks[i].column * size;
		int y = topMargin + smallBlocks[i].row * size;
		putimage(x, y, img);
	}
}

IMAGE** Block::getImages()
{
	return imgs;
}

bool Block::blockInMap(const vector<vector<int>>& map)
{
	//方块超出前后左右边界，或者该处有方块都表示这个不是合法位置
	for (int i = 0; i < 4; i++)
	{
		int rows = map.size();
		int cols = map[0].size();
		if (smallBlocks[i].column<0 || smallBlocks[i].column>=cols
			|| smallBlocks[i].row<0 || smallBlocks[i].row>=rows
			|| map[smallBlocks[i].row][smallBlocks[i].column] != 0)
			return false;

	}
	return true;
}

Block& Block::operator=(const Block& other)
{
	if (this == &other)
		return *this;
	
	this->blockType = other.blockType;
	
	for (int i = 0; i < 4; i++)
		this->smallBlocks[i] = other.smallBlocks[i];
	return *this;
}

void Block::solidify(vector<vector<int>>& map)
{
	//改写地图标记
	for (int i = 0; i < 4; i++)
		map[smallBlocks[i].row][smallBlocks[i].column] = blockType;

}
