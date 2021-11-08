#include "Node.h"

Node::Node(int top, int buttom, int left, int right, int shoot) :top(top), buttom(buttom), left(left), \
right(right), isShoot(shoot) {
	this->speed = 2;
	this->dx = (rand() % 3 - 1) * speed;
	this->dy = (rand() % 3 - 1) * speed;
}

Node::~Node() {}

void Node::showBlood(int bloodLength, int length) {
	setlinecolor(BLACK);
	setfillcolor(WHITE);
	fillrectangle(point.x + length / 10, point.y - blood.bloodWidth, point.x + length, point.y - 2);
	if (bloodLength <= 0) {
		return;
	}
	setfillcolor(RGB(221, 59, 57));
	fillrectangle(point.x + length / 10, point.y - blood.bloodWidth, point.x + bloodLength + length / 10, \
		point.y - 2);
}