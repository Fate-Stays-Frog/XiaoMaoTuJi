#include"View.h"
vector<Bullet*> vectorBullet;//存放子弹
vector<Fish*> vectorFish;//存放鱼干
float dd = -4;//子弹伤害
float v_fish = 2;
IMAGE buffleaf, buffleafs, buffguantou, buffguantous,buffmilk,buffmilks;

void loadBuff() {
	loadimage(&buffguantou, _T("pic\\guantou.jpg"), 50, 40);
	loadimage(&buffguantous, _T("pic\\guantous.jpg"), 50, 40);
	loadimage(&buffleaf, _T("pic\\maobohe.jpg"), 50, 40);
	loadimage(&buffleafs, _T("pic\\maobohes.jpg"), 50, 40);
	loadimage(&buffmilk, _T("pic\\milk.jpg"), 80, 70);
	loadimage(&buffmilks, _T("pic\\milks.jpg"), 80, 70);
}

//添加子弹或者鱼干
void addBullet(float x, float y, Cat cat) {
	Bullet* p = new Bullet(x, y, 2);
	p->setDirection(cat.catX + CatLength / 2, cat.catY + CatWidth / 2);
	p->attack = 2;
	vectorBullet.push_back(p);
}

void addFish(Cat& cat, MOUSEMSG m) {
	if (cat.catMagic <= 0 || cat.catHealth <= 0) return;
	Fish* p = new  Fish(cat.catX + CatLength / 2 - 15, cat.catY, v_fish);
	if (level != 1) {
		cat.catBlue(-0.5);
	}
	p->setDirection(m);
	p->attack = 7;//普通鱼干伤害为7
	vectorFish.push_back(p);
}

//猫猫大招释放，区分小怪和boss
void addFish2(Cat& cat, int at, LittleSprite ls) {
	if (cat.catHealth <= 0) return;

	for (int i = 0; i < ls.nums.size(); i++) {
		Fish* p = new  Fish(cat.catX + CatLength / 2 - 15, cat.catY, 2, at);
		p->setDirection2(ls.nums[i].point.x, ls.nums[i].point.y);
		vectorFish.push_back(p);
	}
}

//导弹
void addFish3(Cat& cat, int at, Boss b) {//at设置导弹伤害
	if (cat.catHealth <= 0) return;
	int speed = 2;
	for (int i = 0; i < 3; i++) {
		Fish* p = new  Fish(cat.catX + CatLength / 2 - 15, cat.catY, speed, at);
		p->setDirection2(b.node.point.x, b.node.point.y);
		vectorFish.push_back(p);
		speed += 2;
	}
}

//猫猫大招
void catAoligeiLs(Cat& cat, int at, LittleSprite ls) {
	if (ls.died) {
		return;
	}
	if ((GetAsyncKeyState(0x52) & 0x8000)) {
		if (cat.catEnergy >= 100 && ls.nums.size() > 0) {
			addFish2(cat, at, ls);//第二个数值是伤害
			cat.catSkill(-100);//充能归零
			if (play) {
				mciSendString("close skillMusic", NULL, 0, NULL);
				mciSendString("open music\\大招.mp3 alias skillMusic", NULL, 0, NULL);
				mciSendString("play skillMusic", NULL, 0, NULL);
			}
		}
	}
}

void catAoligeiB(Cat& cat, int at, Boss b) {
	if (b.died) {
		return;
	}
	if ((GetAsyncKeyState(0x52) & 0x8000)) {
		if (cat.catEnergy >= 100) {
			addFish3(cat, at, b);
			cat.catSkill(-100);
			if (play) {
				mciSendString("close skillMusic", NULL, 0, NULL);
				mciSendString("open music\\大招.mp3 alias skillMusic", NULL, 0, NULL);
				mciSendString("play skillMusic", NULL, 0, NULL);
			}
		}
	}
}

//显示子弹或者鱼干
void showBullet() {
	for (auto i = vectorBullet.begin(); i != vectorBullet.end(); i++) {
		if (vectorBullet.size() == 0) {
			break;
		}
		(*i)->move();
		(*i)->appear();
	}
}

//区分小怪和boss
void showFishLs(LittleSprite ls) {
	int cnt = 0;
	for (auto i = vectorFish.begin(); i != vectorFish.end(); i++) {
		if ((*i)->attack >= 10 && ls.nums.size() > 0) {
			(*i)->setDirection2(ls.nums[cnt].point.x + ls.length / 2, ls.nums[cnt].point.y + ls.width / 2);
			cnt++;
		}
		(*i)->move();
		(*i)->appear();
	}
}

void showFishLs2(LittleSprite ls) {
	for (auto i = vectorFish.begin(); i != vectorFish.end(); i++) {
		if ((*i)->attack >= 10) {
			continue;
		}
		(*i)->appear();
	}
}

void showFishB(Boss b) {
	if (b.died) {
		return;
	}
	for (auto i = vectorFish.begin(); i != vectorFish.end(); i++) {
		if ((*i)->attack >= 10) {
			(*i)->setDirection2(b.node.point.x + b.length / 2, b.node.point.y + b.width / 2);
		}
		(*i)->move();
		(*i)->appear();
	}
}

void deleteBullet(Map* mp) {
	for (auto i = vectorBullet.begin(); i != vectorBullet.end(); ) {
		int x = (*i)->bullet_x;
		int y = (*i)->bullet_y;
		int x1 = (int)(x / 50);//左上
		int y1 = (int)(y / 50);
		int x2 = (int)(x + BulletLength) / 50;//右上
		int y2 = y1;
		int x3 = x1;//左下
		int y3 = (int)(y + BulletWidth) / 50;
		int x4 = (int)(x + BulletLength) / 50;//右下
		int y4 = (int)(y + BulletWidth) / 50;
		if (vectorBullet.size() == 0) {
			break;
		}
		if ((*i)->bullet_x<0 || (*i)->bullet_x>Length
			|| (*i)->bullet_y<0 || (*i)->bullet_y>Width
			|| mp->map[y1][x1] || mp->map[y2][x2]
			|| mp->map[y3][x3] || mp->map[y4][x4]) {
			i = vectorBullet.erase(i);
		}
		else i++;
	}

	for (auto j = vectorFish.begin(); j != vectorFish.end();) {
		int x = (*j)->fish_x;
		int y = (*j)->fish_y;
		int x1 = (int)(x / 50);
		int y1 = (int)(y / 50);
		int x2 = (int)(x + FishLength) / 50;
		int y2 = y1;
		int x3 = x1;
		int y3 = (int)(y + FishWidth) / 50;
		int x4 = (int)(x + FishLength) / 50;
		int y4 = (int)(y + FishWidth) / 50;
		if (vectorFish.size() == 0) {
			break;
		}
		if ((*j)->fish_x<0 || (*j)->fish_x>Length
			|| (*j)->fish_y<0 || (*j)->fish_y>Width) {
			j = vectorFish.erase(j);
		}
		else if ((*j)->attack < 10 && (mp->map[y1][x1] || mp->map[y2][x2]
			|| mp->map[y3][x3] || mp->map[y4][x4])) {
			j = vectorFish.erase(j);
		}
		else j++;
	}
}

//碰撞检测
void catBullet(Cat& cat) {
	static int musicCounter3 = 0;
	for (auto i = vectorBullet.begin(); i != vectorBullet.end(); ) {
		if (vectorBullet.size() == 0) {
			break;
		}
		if (abs((*i)->bullet_y + BulletWidth / 2 + 5 - cat.catY - CatWidth / 2) <= BulletWidth / 2 + CatWidth / 2 - 15 &&
			abs((*i)->bullet_x + BulletLength / 2 - cat.catX - CatLength / 2) <= BulletLength / 2 + CatLength / 2 - 5) {
			cat.catRed(dd);
			if (level == 3) {
				cat.catRed(dd);
			}
			cat.hurt = 200;
			if (play && cat.catHealth > 0) {
				musicCounter3++;
				if (musicCounter3 >= 3) {
					musicCounter3 = 0;
					mciSendString("close catMusic", NULL, 0, NULL);
					mciSendString("open music\\猫叫.mp3 alias catMusic", NULL, 0, NULL);
					mciSendString("play catMusic", NULL, 0, NULL);
				}
			}
			i = vectorBullet.erase(i);
		}
		else i++;
	}
}

void catBullet2(Cat& cat) {
	static int musicCounter4 = 0;
	for (auto i = vectorBullet.begin(); i != vectorBullet.end(); ) {
		if (vectorBullet.size() == 0) {
			break;
		}
		if (abs((*i)->bullet_y + BulletWidth / 2 + 5 - cat.catY - CatWidth / 2) <= BulletWidth / 2 + CatWidth / 2 - 15 &&
			abs((*i)->bullet_x + BulletLength / 2 - cat.catX - CatLength / 2) <= BulletLength / 2 + CatLength / 2 - 5) {
			cat.catRed(dd * 3);
			cat.hurt = 200;
			if (play && cat.catHealth > 0) {
				musicCounter4++;
				if (musicCounter4 >= 3) {
					musicCounter4 = 0;
					mciSendString("close catMusic", NULL, 0, NULL);
					mciSendString("open music\\猫叫.mp3 alias catMusic", NULL, 0, NULL);
					mciSendString("play catMusic", NULL, 0, NULL);
				}
			}
			i = vectorBullet.erase(i);
		}
		else i++;
	}
}

void littleSpriteFish(LittleSprite& p, Cat& cat,bool flag) {
	if (p.died) {
		return;
	}
	static int musicCounter1 = 0;
	for (auto& num : p.nums) {
		for (auto i = vectorFish.begin(); i != vectorFish.end(); ) {
			if (vectorFish.size() == 0) {
				break;
			}
			if (abs((*i)->fish_x + FishLength / 2 - num.point.x - p.length / 2) <= FishLength / 2 + p.length / 2 - 10
				&& abs((*i)->fish_y + FishWidth / 2 - num.point.y - p.width / 2) <= FishWidth / 2 + p.width / 2 - 5)
			{
				num.blood.bloodLength -= (*i)->attack;
				if (cat.catEnergy < 100.0) cat.catSkill(5);//积蓄能量槽
				if (play&&flag) {
					musicCounter1++;
					if (musicCounter1 >= 3) {
						musicCounter1 = 0;
						mciSendString("close hitMusic", NULL, 0, NULL);
						mciSendString("open music\\击中.mp3 alias hitMusic", NULL, 0, NULL);
						mciSendString("play hitMusic", NULL, 0, NULL);
					}
				}
				i = vectorFish.erase(i);
			}
			else i++;
		}
	}
}

void bossFish(Boss& p, Cat& cat) {
	if (p.died) {
		return;
	}
	static int musicCounter2 = 0;
	for (auto i = vectorFish.begin(); i != vectorFish.end(); ) {
		if (vectorFish.size() == 0) {
			break;
		}
		if (p.kind == 1) {
			if (abs((*i)->fish_x + FishLength / 2 - p.node.point.x - BossLength1 / 2 - 10) <= FishLength / 2 + BossLength1 / 5 - 10
				&& abs((*i)->fish_y + FishWidth / 2 - p.node.point.y - BossWidth1 / 2) <= FishWidth / 2 - 5 + BossWidth1 / 2) {
				p.node.blood.bloodLength -= (*i)->attack;
				if (cat.catEnergy < 100.0) cat.catSkill(5);//积蓄能量槽
				musicCounter2++;
				if (play) {
					if (musicCounter2 >= 3) {
						musicCounter2 = 0;
						mciSendString("close hitMusic", NULL, 0, NULL);
						mciSendString("open music\\击中.mp3 alias hitMusic", NULL, 0, NULL);
						mciSendString("play hitMusic", NULL, 0, NULL);
					}
				}
				i = vectorFish.erase(i);
			}
			else i++;
		}
		else {
			if (abs((*i)->fish_x + FishLength / 2 - p.node.point.x - 50 - BossLength2 / 3) <= FishLength / 2 + BossLength2 / 4
				&& abs((*i)->fish_y + FishWidth / 2 - 5 - p.node.point.y - BossWidth2 / 2) <= FishWidth / 2 - 5 + BossWidth2 / 2 - 15) {
				p.node.blood.bloodLength -= (*i)->attack;
				if (cat.catEnergy < 100.0) cat.catSkill(5);//积蓄能量槽
				if (play) {
					musicCounter2++;
					if (musicCounter2 >= 3) {
						musicCounter2 = 0;
						mciSendString("close hitMusic", NULL, 0, NULL);
						mciSendString("open music\\击中.mp3 alias hitMusic", NULL, 0, NULL);
						mciSendString("play hitMusic", NULL, 0, NULL);
					}
				}
				i = vectorFish.erase(i);
			}
			else i++;
		}
	}
}

//小怪射击
void littleSpriteShoot(Cat cat, LittleSprite& p) {
	for (auto i = p.nums.begin(); i != p.nums.end(); i++) {
		if (p.nums.size() == 0) {
			break;
		}
		i->isShoot++;
		if (i->isShoot == 150) {
			i->isShoot = 0;
			addBullet(i->point.x, i->point.y, cat);
		}
	}
}

//boss攻击
void boss_shoot1(Cat cat, Boss& p) {//南瓜头的
	if (p.died) return;
	p.node.isShoot++;
	if (p.node.isShoot >= 100 && p.node.isShoot <= 300) {
		if (p.node.isShoot % 60 == 0) {
			bossShoot9(cat, p);//五连射
		}
	}
	if (p.node.isShoot >= 350 && p.node.isShoot <= 500) {
		if (p.node.isShoot % 20 == 0) {
			bossShoot4(p);//十字
		}
	}
	if (p.node.isShoot >= 500 && p.node.isShoot <= 750) {
		if (p.node.isShoot % 20 == 0) {
			bossShoot5(p);//米字
		}
	}
	if (p.node.isShoot >= 850 && p.node.isShoot <= 1050) {
		if (p.node.isShoot % 50 == 0) {
			bossShoot2(cat, p);//圆
		}
	}
	if (p.node.isShoot == 1051) {
		p.node.isShoot = 0;
	}

}

void boss_shoot2(Cat cat, Boss& p) {//死神的
	static float jiao = 1;
	if (p.died) return;
	p.node.isShoot++;
	if (p.node.isShoot >= 100 && p.node.isShoot <= 300) {
		if (p.node.isShoot % 60 == 0) {
			bossShoot1(cat, p);//三连射
		}
	}
	if (p.node.isShoot >= 350 && p.node.isShoot <= 500) {
		if (p.node.isShoot % 40 == 0) {
			bossShoot2(cat, p);//圆
		}
	}

	if (p.node.isShoot >= 500 && p.node.isShoot <= 980) {
		if (p.node.isShoot % 30 == 0) {
			bossShoot3(jiao, p);//螺旋
			jiao += 22.5;
		}
	}
	if (p.node.isShoot == 1) {
		jiao = 1;
	}

	if (p.node.isShoot >= 1050 && p.node.isShoot <= 1500) {
		if (p.node.isShoot % 20 == 0) {
			bossShoot6();//行
		}
	}
	if (p.node.isShoot >= 1100 && p.node.isShoot <= 1650) {
		if (p.node.isShoot % 20 == 0) {
			bossShoot7();//列
		}
	}
	//散花
	if (p.node.isShoot >= 2100 && vectorBullet.size() <= 0) {
		bossShoot4(p);
	}
	if (p.node.isShoot == 2150 && vectorBullet.size() <= 4) {
		bossShoot8(p);
	}
	if (p.node.isShoot == 2300) {
		p.node.isShoot = 0;
	}
}

//boss的攻击
void bossShoot1(Cat cat, Boss b) {
	float x1 = b.node.point.x;
	float y1 = b.node.point.y;
	float x2 = cat.catX;
	float y2 = cat.catY;
	float j, jj;
	if (x2 == x1) {
		if (y1 < y2) j = 90;
		else j = 270;
	}
	else {
		float k = (y1 - y2) / (x1 - x2);
		j = atan(k) * 180.0 / 3.14;
		if (j > 0 && x1 > x2 || j < 0 && x1 > x2) {
			j += 180;
		}
	}
	for (int i = -1; i <= 1; i++) {
		Bullet* p1 = new Bullet(b.node.point.x, b.node.point.y, 2);
		jj = j + (float)i * 30;
		if (jj < 0)jj += 360;
		p1->setDirection2(jj);
		vectorBullet.push_back(p1);
	}
}

void bossShoot2(Cat cat, Boss b) {
	float x1 = b.node.point.x;
	float y1 = b.node.point.y;
	for (int i = 1; i <= 360; i += 22.5) {
		Bullet* p1 = new Bullet(x1, y1, 2);
		p1->setDirection2(i);
		vectorBullet.push_back(p1);
	}
}

void bossShoot3(float a, Boss b) {
	Bullet* p1 = new Bullet(b.node.point.x, b.node.point.y, 2);
	p1->setDirection2(a);
	vectorBullet.push_back(p1);
}

void bossShoot4(Boss b) {
	float x1 = b.node.point.x;
	float y1 = b.node.point.y;

	Bullet* p1 = new Bullet(x1, y1, 2);
	p1->setDirection(x1 + 1, y1);
	vectorBullet.push_back(p1);
	Bullet* p2 = new Bullet(x1, y1, 2);
	p2->setDirection(x1 - 1, y1);
	vectorBullet.push_back(p2);
	Bullet* p3 = new Bullet(x1, y1, 2);
	p3->setDirection(x1, y1 + 1);
	vectorBullet.push_back(p3);
	Bullet* p4 = new Bullet(x1, y1, 2);
	p4->setDirection(x1, y1 - 1);
	vectorBullet.push_back(p4);
}

void bossShoot5(Boss b) {
	float x1 = b.node.point.x;
	float y1 = b.node.point.y;

	Bullet* p1 = new Bullet(x1, y1, 2);
	p1->setDirection(x1 + 1, y1);
	vectorBullet.push_back(p1);
	Bullet* p2 = new Bullet(x1, y1, 2);
	p2->setDirection(x1 - 1, y1);
	vectorBullet.push_back(p2);
	Bullet* p3 = new Bullet(x1, y1, 2);
	p3->setDirection(x1, y1 + 1);
	vectorBullet.push_back(p3);
	Bullet* p4 = new Bullet(x1, y1, 2);
	p4->setDirection(x1, y1 - 1);
	vectorBullet.push_back(p4);
	Bullet* p5 = new Bullet(x1, y1, 2);
	p5->setDirection(x1 + 1, y1 + 1);
	vectorBullet.push_back(p5);
	Bullet* p6 = new Bullet(x1, y1, 2);
	p6->setDirection(x1 - 1, y1 + 1);
	vectorBullet.push_back(p6);
	Bullet* p7 = new Bullet(x1, y1, 2);
	p7->setDirection(x1 - 1, y1 - 1);
	vectorBullet.push_back(p7);
	Bullet* p8 = new Bullet(x1, y1, 2);
	p8->setDirection(x1 + 1, y1 - 1);
	vectorBullet.push_back(p8);
}

void bossShoot6() {
	int kuan[4] = { 100,250,350,500 };
	for (int i = 0; i <= 2; i += 2) {
		Bullet* p1 = new Bullet(0, kuan[i], 2);
		p1->setDirection(1, kuan[i]);
		vectorBullet.push_back(p1);
	}
	for (int i = 1; i <= 3; i += 2) {
		Bullet* p1 = new Bullet(Length, kuan[i], 2);
		p1->setDirection(Length - 1, kuan[i]);
		vectorBullet.push_back(p1);
	}
}

void bossShoot7() {
	int chang[5] = { 5,350,550,750,Length - BulletLength - 5 };
	for (int i = 0; i <= 4; i += 1) {//要改!!!!!
		if (i % 2) {
			Bullet* p1 = new Bullet(chang[i], 565, 2);
			p1->setDirection(chang[i], 565 - 1);
			vectorBullet.push_back(p1);
		}
		else {
			Bullet* p1 = new Bullet(chang[i], 0, 2);
			p1->setDirection(chang[i], 1);
			vectorBullet.push_back(p1);
		}
	}
}

void bossShoot8(Boss b) {
	int num = vectorBullet.size();
	for (int i = 0; i < num; i++) {
		for (int j = 1; j <= 360; j += 22.5) {
			Bullet* p1 = new Bullet(vectorBullet[i]->bullet_x, vectorBullet[i]->bullet_y, 2);
			p1->setDirection2(j);
			vectorBullet.push_back(p1);
		}
	}

}

void bossShoot9(Cat cat, Boss b) {
	float x1 = b.node.point.x;
	float y1 = b.node.point.y;
	float x2 = cat.catX;
	float y2 = cat.catY;
	float j, jj;
	if (x2 == x1) {
		if (y1 < y2) j = 90;
		else j = 270;
	}
	else {
		float k = (y1 - y2) / (x1 - x2);
		j = atan(k) * 180.0 / 3.14;
		if (j > 0 && x1 > x2 || j < 0 && x1 > x2) {
			j += 180;
		}
	}
	for (int i = -2; i <= 2; i++) {
		Bullet* p1 = new Bullet(b.node.point.x, b.node.point.y, 2);
		jj = j + (float)i * 20;
		if (jj < 0)jj += 360;
		p1->setDirection2(jj);
		vectorBullet.push_back(p1);
	}
}

void setdd(float d) {
	dd = d;
}

void buff(CatStore& store, Cat& cat) {
	//跳出商店界面循环后，判断有没有增加buff
	if (store.buff_guantou == 0 && store.bufftime_guantou > 0) {
		store.buff_guantou = 1;//防止多次修改
		//减少小怪伤害
		setdd(dd/2);
	}
	if (store.bufftime_guantou > 0) {
		putimage(200, 550, &buffguantous, NOTSRCERASE);
		putimage(200, 550, &buffguantou, SRCINVERT);
		store.bufftime_guantou -= 0.1;
		if (store.bufftime_guantou <= 0) {
			store.bufftime_guantou = 0;
			store.buff_guantou = 0;//buff时间结束，设定变为初始值
			//小怪伤害变为初始值
			setdd(2*dd);
		}
	}
	if (store.buff_leaf == 0 && store.bufftime_leaf > 0) {
		store.buff_leaf = 1;
		cat.catSetSpeed(3);
	}
	if (store.bufftime_leaf > 0) {
		putimage(250, 550, &buffleafs, NOTSRCERASE);
		putimage(250, 550, &buffleaf, SRCINVERT);
		store.bufftime_leaf -= 0.1;
		if (store.bufftime_leaf <= 0) {
			store.bufftime_leaf = 0;
			store.buff_leaf = 0;
			cat.catSetSpeed(2);
		}
	}
	if (store.foodnum > 0) {
		while (store.foodnum > 0) {
			store.foodnum--;
			cat.catRed(25);
			cat.catBlue(50);
		}
	}
	if (store.buff_milk== 0 && store.bufftime_milk > 0) {
		store.buff_milk = 1;//防止多次修改
		//提高子弹移速
		v_fish=4;
	}
	if (store.bufftime_milk > 0) {
		putimage(300, 534, &buffmilks, NOTSRCERASE);
		putimage(300, 534, &buffmilk, SRCINVERT);
		store.bufftime_milk -= 0.1;
		if (store.bufftime_milk <= 0) {
			store.bufftime_milk = 0;
			store.buff_milk = 0;//buff时间结束，设定变为初始值
			v_fish = 2;
		}
	}

}

void storeInfo1(CatStore& store) {
	IMAGE storetip;
	loadimage(&storetip, _T("pic\\storetip.jpg"), 150, 63);
	if (store.openstore == 0) {
		putimage(930, 540, &storetip);
	}
}

void clearBullet() {
	vectorBullet.clear();
	vectorFish.clear();
}
void stopPage() {
	IMAGE page;
	loadimage(&page, _T("pic\\stoppage.jpg"), 1100, 600);
	putimage(0, 0, &page);
}

void setv(float v) {
	v_fish = v;
}