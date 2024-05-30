#pragma once

#include <graphics.h>
#include <vector>
using namespace std;

//整个地图中可以分为20行10列，从而在地图上确定一些点就可以确定一个俄罗斯方块
struct Point
{
	int row;
	int column;
};


class Block
{
public:
	Block();

	void drop();
	void moveLeftRight(int offset);
	void rotate();	//控制旋转

	//绘制的方块需要判断和边框的距离
	void draw(int leftMargin,int topMargin);
	static IMAGE** getImages();
	
	//用来判断方块是否在主地图中从而判断是否需要固化位置
	bool blockInMap(const vector<vector<int>>& map);
	//Point* getsmallBlocks();


	Block& operator=(const Block& other);

	void solidify( vector<vector<int>>& map);

	int getBlockType();
	~Block();

private:
	//一般在C++开发中我们都是发现需要额外使用到某个变量时才会去添加这个变量
	//也即根据需求来开发
	int blockType;	//方块的类型
	Point smallBlocks[4];	//用方块点来表示一个俄罗斯方块
	IMAGE* img;
	static IMAGE* imgs[7];
	
	//方块的大小
	static int size;	//和Tetris类中传入的方块大小保持一致


};

