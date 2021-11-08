#ifndef VIEW_H
#define VIEW_H
#include"LittleSprite.h"
#include"Boss.h"
#include"Bullet.h"
#include"Fish.h"
#include"Map.h"

//显示子弹
void showBullet();
void showFishLs(LittleSprite);
void showFishLs2(LittleSprite);
void showFishB(Boss);

//无效子弹或鱼干的删除
void deleteBullet(Map*);

//补充子弹
void addBullet(float, float, Cat);
void addFish(Cat&, MOUSEMSG);
void addFish2(Cat&, int, LittleSprite);
void addFish3(Cat&, int, Boss);

//猫猫大招
void catAoligeiLs(Cat&, int, LittleSprite);
void catAoligeiB(Cat&, int, Boss);

//碰撞检测
void catBullet(Cat&);
void littleSpriteFish(LittleSprite&, Cat&, bool flag);
void bossFish(Boss&, Cat&);

//怪射击
void littleSpriteShoot(Cat, LittleSprite&);

//boss攻击
void boss_shoot1(Cat, Boss&);//南瓜的专属攻击
void boss_shoot2(Cat, Boss&);//死神的专属攻击

//boss的大招

void bossShoot1(Cat, Boss);//三连射
void bossShoot2(Cat, Boss);//圆扩散
void bossShoot3(float, Boss);//螺旋扩散
void bossShoot4(Boss);//十字形
void bossShoot5(Boss);//米字形
void bossShoot6();//平行线 行
void bossShoot7();//平行线 列
void bossShoot8(Boss);//天女散花
void bossShoot9(Cat, Boss);//五连射

//商店的代码
void buff(CatStore&, Cat&);
void storeInfo1(CatStore&);
void loadBuff();

//清空弹夹
void clearBullet();

//暂停页面
void stopPage();

//控制子弹速度
void setv(float v);

void catBullet2(Cat&);

#endif //VIEW_H