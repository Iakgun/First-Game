#include "Robot.h"



Robot::Robot()
{
}


Robot::~Robot()
{
}

bool Robot::init(){
	bool ret = false;

	do{
		CC_BREAK_IF(!ActionSprite::initWithSpriteFrameName("robot_idle_00.png"));

		CallFunc *callbackIdle = CallFunc::create(std::bind(&Robot::idle, this));

		// ����idle�����У����������ú󷴸�����
		Animation *idle = createAnimation("robot_idle_%02d.png", 5, 12);
		setIdleAction(RepeatForever::create(Animate::create(idle)));

		// ����walk�����ߣ�������ͬ�����ú󷴸�����
		Animation *walk = createAnimation("robot_walk_%02d.png", 6, 20);
		setWalkAction(RepeatForever::create(Animate::create(walk)));

		// ����attact�����������������ź�ص���idle����
		Animation *attack = createAnimation("robot_attack_%02d.png", 5, 12);
		setAttackAction(Sequence::create(Animate::create(attack), callbackIdle, NULL));

		// ����hurt�����ˣ����������ź�ص���idle����
		Animation *hurt = createAnimation("robot_hurt_%02d.png", 3, 12);
		setHurtAction(Sequence::create(Animate::create(hurt), callbackIdle, NULL));

		// ����knockout�������������������ź����κε���
		Animation *knockout = createAnimation("robot_knockout_%02d.png", 5, 12);
		setKnockoutAction(Sequence::create(Animate::create(knockout), NULL));

		setATK(20); // ������
		setHP(100); // ����ֵ
		setVelocity(1); // �ƶ��ٶ�
		setDirection(Point::ZERO); // �ƶ�����

		ret = true;
	} while (0);

	return ret;
}