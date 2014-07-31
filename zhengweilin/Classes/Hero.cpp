#include "Hero.h"


Hero::Hero()
{
}


Hero::~Hero()
{
}

bool Hero::init(){
	bool ret = false;

	do{

		CallFunc *callbackIdle = CallFunc::create(std::bind(&Hero::idle, this));
		CC_BREAK_IF(!this->initWithSpriteFrameName("hero_idle_00.png"));
		
		//����idle�����У����������ú󷴸�����
		Animation *idle = createAnimation("hero_idle_%02d.png", 6, 12);
		setIdleAction(RepeatForever::create(Animate::create(idle)));

		// ����walk�����ߣ�������ͬ�����ú󷴸�����
		Animation *walk = createAnimation("hero_walk_%02d.png", 7, 12);
		setWalkAction(RepeatForever::create(Animate::create(walk)));

		// ����attact�����������������ź�ص���idle����
		Animation *attack = createAnimation("hero_attack_00_%02d.png", 3, 12);
		setAttackAction(Sequence::create(Animate::create(attack), callbackIdle, NULL));

		// ����hurt�����ˣ����������ź�ص���idle����
		Animation *hurt = createAnimation("hero_hurt_%02d.png", 3, 12);
		setHurtAction(Sequence::create(Animate::create(hurt), callbackIdle, NULL));

		// ����knockout�������������������ź����κε���
		Animation *knockout = createAnimation("hero_knockout_%02d.png", 5, 12);
		setKnockoutAction(Sequence::create(Animate::create(knockout), NULL));
	
		setATK(20);
		setHP(100);
		setVelocity(1);
		setDirection(Point::ZERO);

		ret = true;
	} while (0);

	return ret;
}




