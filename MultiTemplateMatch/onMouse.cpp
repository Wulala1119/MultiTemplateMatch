#include "onMouse.h"
void on_mouse(int event, int x, int y, int flags, void* param)
{		
    if( event == CV_EVENT_LBUTTONDOWN)   //按下鼠标左键
	{
		lp = Point(x, y);
		//bool selected_flag = false;
	}
    else if( event == CV_EVENT_LBUTTONUP )   //鼠标左键弹起
	{		
		rp = Point(x, y);
		int width = rp.x - lp.x;
		int height = rp.y -lp.y;
	}
}