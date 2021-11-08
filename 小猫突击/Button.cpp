#include "Button.h"

Button::Button(int x, int y, int length, int width) :x(x), y(y), width(width), length(length) {
	stop = false;
	tip = "";
}

void Button::hide() {
	setlinecolor(WHITE);
	setfillcolor(WHITE);
	fillrectangle(x, y, x + length, y + width + 20);
}

Button::~Button() {}