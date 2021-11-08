#include "Buttons.h"

Buttons::Buttons() {
	flag = false;
}

void Buttons::show() {
	settextstyle(20, 0, "微软雅黑");
	settextcolor(BLACK);
	for (auto& button : buttons) {
		if (!button.stop) {
			putimage(button.x, button.y, &button.pre);
			if (button.tip.size()) {
				outtextxy(button.length / 2 - 15 + button.x, button.width + button.y + 3, \
					button.tip.c_str());
			}
		}
	}
	FlushBatchDraw();
}

int Buttons::click() {
	while (true)
	{
		if (MouseHit() && !flag) {
			MOUSEMSG msg = GetMouseMsg();

			if (msg.mkLButton) {
				for (unsigned int i = 0; i < buttons.size(); i++) {
					if (!buttons[i].stop) {
						//若点击的位置在图片范围内
						if (msg.x >= buttons[i].x && msg.x <= buttons[i].x + buttons[i].length && \
							msg.y >= buttons[i].y && msg.y <= buttons[i].y + buttons[i].width) {
							//将所有flag设置为true，防止用户在按钮弹跳时点击其他按钮
							this->flag = true;
							for (int j = 0; j < 5; j++) {
								putimage(buttons[i].x, buttons[i].y + j, &buttons[i].back);
								FlushBatchDraw();
								fillrectangle(buttons[i].x, buttons[i].y + j, buttons[i].x + buttons[i].length, \
									buttons[i].y + j + buttons[i].width);
								Sleep(25);
							}
							putimage(buttons[i].x, buttons[i].y + 5, &buttons[i].back);
							FlushBatchDraw();
							fillrectangle(buttons[i].x, buttons[i].y + 5, buttons[i].x + buttons[i].length, \
								buttons[i].y + 5 + buttons[i].width);
							Sleep(20);
							putimage(buttons[i].x, buttons[i].y, &buttons[i].pre);
							FlushBatchDraw();
							this->flag = false;
							return i;
						}
					}
				}
			}
		}
	}
}

Buttons::~Buttons() {}