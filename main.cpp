/*开发日志
* 1.创建项目
* 2.UI设计
* 3.C++开发
* 4.设计C++项目的模块
*	设计Block和Tetris类
* 5.设计各个模块的接口
*	Tetris类需要初始化界面，接着启动游戏
*	Block类中的绘制方块，移动方块，让方块下落，固化方块
* 6.启动游戏
*/

#include "Tetris.h"
#include "Block.h"
#include <mciapi.h>

//终于回来了

int main()
{
	//行数，列数，距离左侧和顶部距离(根据背景图片而定),和方块大小
	Tetris is_game(20, 10, 263, 133, 36);

	//现在开始愉快的游戏吧！
	is_game.play();
	return 0;

}

//最大的收获就是搭建框架再写会让思路清晰很多！！
