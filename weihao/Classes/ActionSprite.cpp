#include "ActionSprite.h"

ActionSprite::ActionSprite()
{
	_idleAction = NULL;
	_attackAction = NULL;
	_walkAction = NULL;
	_runAction = NULL;
	_runAttackAction = NULL;
	_jumpAction = NULL;
	_jumpAttackAction = NULL;
	_hurtAction = NULL;
	_knockedOutAction = NULL;
	_jumpNum = 0;
}

ActionSprite::~ActionSprite()
{

}

Animation* ActionSprite::animationWithPrefix(std::string prefix, int startFrameIdx, int frameCount, float delay){
	int idxCount = frameCount + startFrameIdx;
	Vector<SpriteFrame*> frames;
	char name[50];
	SpriteFrame* frame;
	for (int i = startFrameIdx; i < idxCount; i++){
		sprintf(name, "%s_%02d.png", prefix.c_str(), i);
		frame = SpriteFrameCache::getInstance()->getSpriteFrameByName(name);
		frames.pushBack(frame);
	}
	return Animation::createWithSpriteFrames(frames, delay);
}

void ActionSprite::update(float dt)
{
	if (_actionState == kActionStateWalk || _actionState == kActionStateRun)
	{
		_desiredPosition = ccpAdd(this->getPosition(), ccpMult(_velocity, dt));
	}
}

void ActionSprite::idle()
{
	if (_actionState != kActionStateIdle)
	{
		this->stopAllActions();
		this->runAction(_idleAction);
		_actionState = kActionStateIdle;
		_velocity = Vec2::ZERO;
		_jumpNum = 0;
	}
}

void ActionSprite::walkWithDirection(Vec2 direction)
{
	if (_actionState == kActionStateIdle)
	{
		this->stopAllActions();
		this->runAction(_walkAction);
		_actionState = kActionStateWalk;
	}
	if (_actionState == kActionStateWalk)
	{
		_velocity = ccp(direction.x * _walkSpeed, direction.y * _walkSpeed);
		if (_velocity.x >= 0)
		{
			this->setScaleX(1.0);
		}
		else
		{
			this->setScaleX(-1.0);
		}
	}
}

void ActionSprite::attack()
{
	if (_actionState == kActionStateIdle || _actionState == kActionStateWalk)
	{
		this->stopAllActions();
		this->runAction(_attackAction);
		_actionState = kActionStateAttack;
	}
	if (_actionState == kActionStateJump)
	{
		this->stopAllActions();
		this->runAction(_jumpAttackAction);
		_actionState = kActionStateAttack;
	}
	if (_actionState == kActionStateRun)
	{
		this->stopAllActions();
		this->runAction(_runAttackAction);
		_actionState = kActionStateAttack;
	}
}

void ActionSprite::runWithDirection(Vec2 direction)
{
	if (_actionState == kActionStateIdle)
	{
		this->stopAllActions();
		this->runAction(_runAction);
		_actionState = kActionStateRun;
	}
	if (_actionState == kActionStateRun)
	{
		_velocity = ccp(direction.x * _runSpeed, direction.y * _runSpeed);
		if (_velocity.x >= 0)
		{
			this->setScaleX(1.0);
		}
		else
		{
			this->setScaleX(-1.0);
		}
	}
}

void ActionSprite::jump()
{
	if (_actionState == kActionStateIdle || _actionState == kActionStateWalk || _jumpNum < _jumpNumLimit)
	{
		this->stopAllActions();
		this->runAction(_jumpAction);
		_actionState = kActionStateJump;
		_jumpNum++;
	}
}