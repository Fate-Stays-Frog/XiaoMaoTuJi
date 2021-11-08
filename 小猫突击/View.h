#ifndef VIEW_H
#define VIEW_H
#include"LittleSprite.h"
#include"Boss.h"
#include"Bullet.h"
#include"Fish.h"
#include"Map.h"

//��ʾ�ӵ�
void showBullet();
void showFishLs(LittleSprite);
void showFishLs2(LittleSprite);
void showFishB(Boss);

//��Ч�ӵ�����ɵ�ɾ��
void deleteBullet(Map*);

//�����ӵ�
void addBullet(float, float, Cat);
void addFish(Cat&, MOUSEMSG);
void addFish2(Cat&, int, LittleSprite);
void addFish3(Cat&, int, Boss);

//èè����
void catAoligeiLs(Cat&, int, LittleSprite);
void catAoligeiB(Cat&, int, Boss);

//��ײ���
void catBullet(Cat&);
void littleSpriteFish(LittleSprite&, Cat&, bool flag);
void bossFish(Boss&, Cat&);

//�����
void littleSpriteShoot(Cat, LittleSprite&);

//boss����
void boss_shoot1(Cat, Boss&);//�Ϲϵ�ר������
void boss_shoot2(Cat, Boss&);//�����ר������

//boss�Ĵ���

void bossShoot1(Cat, Boss);//������
void bossShoot2(Cat, Boss);//Բ��ɢ
void bossShoot3(float, Boss);//������ɢ
void bossShoot4(Boss);//ʮ����
void bossShoot5(Boss);//������
void bossShoot6();//ƽ���� ��
void bossShoot7();//ƽ���� ��
void bossShoot8(Boss);//��Ůɢ��
void bossShoot9(Cat, Boss);//������

//�̵�Ĵ���
void buff(CatStore&, Cat&);
void storeInfo1(CatStore&);
void loadBuff();

//��յ���
void clearBullet();

//��ͣҳ��
void stopPage();

//�����ӵ��ٶ�
void setv(float v);

void catBullet2(Cat&);

#endif //VIEW_H