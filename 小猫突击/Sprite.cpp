#include "Sprite.h"

Sprite::Sprite(int length, int width)
	:length(length), width(width) {
	this->isMove = 0;
	this->speed = 0;
	this->isChange = 0;
	this->died = false;
}

Sprite::~Sprite() {}