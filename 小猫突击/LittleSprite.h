#ifndef LITTLE_SPRITE_H
#define LITTLE_SPRITE_H
#include"Sprite.h"
const int SpriteLength = 80;
const int SpriteWidth = 45;

class LittleSprite :
	public Sprite {
public:
	LittleSprite(int speed, int length, int width, int maxNums, int sumNums)
		:Sprite(length, width) {
		//memset(isExsited, 0, sizeof isExsited);
		this->maxNums = maxNums;
		this->sumNums = sumNums;
		this->counter = 0;
		this->isShoot = 0;
		this->isMove = 0;
		this->isGenerate = 0;
		this->speed = speed;
		this->died = false;
	}
	~LittleSprite();
	//�ƶ�
	void move(Map*);
	//�滭
	//Ѫ��+ͼƬ
	void paint();
	//����ͼƬ
	void init();
	//���ɾ���
	void generate();
	//�����ж�
	void die(CatStore* catStore);
	//����λ��
	void loadPositon();

	//�ڵ�ͼ�����ɵ�λ��
	vector<Node>position;
	//�洢С�����Ե�vector
	vector<Node>nums;

	////�жϸ���λ���Ƿ��Ѿ����ھ���
	//bool isExsited[5][4];

	//���ͬʱ���ڼ�ֻС��
	int maxNums;
	//�ܹ����ɼ�ֻС��
	int sumNums;
	//�Ƿ�����
	int isGenerate;

	//ע�� maxNums<=sumNums

	//������ǰ�ܹ��Ѿ������˶��ٵ�С��
	int counter;

	//���ƹ���
	int isShoot;

	//ȫ���������
	bool died;
};
#endif //LITTLE_SPRITE_H