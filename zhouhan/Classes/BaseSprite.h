/* #include "cocos2d.h"

typedef enum {
 ACTION_STATE_NONE = 0,
 ACTION_STATE_IDLE,
 ACTION_STATE_WALK,
 ACTION_STATE_ATTACK,
 ACTION_STATE_HURT,
 ACTION_STATE_DEAD
}ActionState;
 
class BaseSprite : public cocos2d::Sprite
{
public:
 BaseSprite(void);
 ~BaseSprite(void);
 void runIdleAction();
 void runWalkAction();
 void runAttackAction();
 void runHurtAction();
 void runDeadAction();
 CC_SYNTHESIZE_RETAIN(cocos2d::Action*, m_pIdleAction, IdleAction);
 CC_SYNTHESIZE_RETAIN(cocos2d::Action*, m_pWalkAction, WalkAction);
 CC_SYNTHESIZE_RETAIN(cocos2d::Action*, m_pAttackAction, AttackAction);
 CC_SYNTHESIZE_RETAIN(cocos2d::Action*, m_pHurtAction, HurtAction);
 CC_SYNTHESIZE_RETAIN(cocos2d::Action*, m_pDeadAction, DeadAction);
 CC_SYNTHESIZE(ActionState, m_currActionState, CurrActionState);
 cocos2d::CallFunc* createIdleCallbackFunc();
protected:
 static cocos2d::Animation* createAnimation(const char* formatStr, int frameCount, int fps);
private:
 bool changeState(ActionState actionState);
};*/
/*#include "cocos2d.h"

typedef enum {
    ACTION_STATE_NONE = 0,
    ACTION_STATE_IDLE,
    ACTION_STATE_WALK,
    ACTION_STATE_ATTACK,
    ACTION_STATE_HURT,
    ACTION_STATE_KNOCKOUT,
} ActionState;

class ActionSprite : public cocos2d::Sprite
{
public:
    ActionSprite();
    ~ActionSprite();

    void idle();
    void walk(cocos2d::Point direction);
    void attack();
    void hurt(int damage);
    void knockout();

    // ����ÿ��״̬������get/set����
    CC_SYNTHESIZE_RETAIN(cocos2d::Action*, _idleAction, IdleAction);
    CC_SYNTHESIZE_RETAIN(cocos2d::Action*, _attackAction, AttackAction);
    CC_SYNTHESIZE_RETAIN(cocos2d::Action*, _hurtAction, HurtAction);
    CC_SYNTHESIZE_RETAIN(cocos2d::Action*, _knockoutAction, KnockoutAction);
    CC_SYNTHESIZE_RETAIN(cocos2d::Action*, _walkAction, WalkAction);

    // ����ĵ�ǰ״̬
   CC_SYNTHESIZE(ActionState, _currentState, ActionState);

    CC_SYNTHESIZE(float, _velocity, Velocity); // �ƶ��ٶ�
    CC_SYNTHESIZE(cocos2d::Point, _direction, Direction); // �ƶ�����������
    CC_SYNTHESIZE(unsigned int, _hp, HP); // ����ֵ
    CC_SYNTHESIZE(unsigned int, _atk, ATK); // ������

protected:
    // ����һ������״̬�����ķ���
    // fmt   - ״̬��ͼƬ����ʽ(�鿴pd_sprites.plist,ÿ��״̬��ʽ������hero_idle_xx.png)
    // count - ״̬ͼƬ���е�����
    // fps   - �����Ĳ���֡��
    static cocos2d::Animation *createAnimation(const char *fmt, int count, float fps);

private:
    // �л���Ա�ĵ�ǰ״̬
    bool _changeState(ActionState state);
};  */
#include "cocos2d.h"

typedef enum {
	ACTION_STATE_NONE = 0,
	ACTION_STATE_IDLE,
	ACTION_STATE_WALK,
	
}ActionState;

typedef struct _BoundingBox
{
	cocos2d::Rect actual;
	cocos2d::Rect original;
}BoundingBox;

class BaseSprite : public cocos2d::Sprite
{
public:
	BaseSprite();
	~BaseSprite();

	void runIdleAction();
	void runWalkAction();
	
	

	CC_SYNTHESIZE_RETAIN(cocos2d::Action*, m_pIdleAction, IdleAction);
	CC_SYNTHESIZE_RETAIN(cocos2d::Action*, m_pWalkAction, WalkAction);
	

	CC_SYNTHESIZE(ActionState, m_currActionState, CurrActionState);
	CC_SYNTHESIZE(cocos2d::Point, m_fVelocity, Velocity);//�ٶ�


	CC_SYNTHESIZE(BoundingBox, m_bodyBox, BodyBox);
	CC_SYNTHESIZE(BoundingBox, m_hitBox, HitBox);

	virtual void setPosition(const cocos2d::Point &position);

	cocos2d::CallFunc* createIdleCallbackFunc();

	virtual bool isLive();

protected:
	static cocos2d::Animation* createAnimation(const char* formatStr, int frameCount, int fps);


	BoundingBox createBoundingBox(cocos2d::Point origin, cocos2d::Size size);
	void updateBoxes();

private:
	bool changeState(ActionState actionState);
};
