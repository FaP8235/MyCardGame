#include "models/CardModel.h"


CardModel::CardModel(const CardConfig& config)
	: _config(config)
	, _instanceId(config.instanceId)
	, _isFaceUp(false)
	, _isRemoved(false)
	, _currentArea(Area::NONE)
	, _index(-1)
	, _currentPos(config.position)
{
}

void CardModel::setFaceUp(bool faceUp)
{
	_isFaceUp = faceUp;
}

bool CardModel::isFaceUp() const
{
	return _isFaceUp;
}

void CardModel::setRemoved(bool removed)
{
	_isRemoved = removed;
}

bool CardModel::isRemoved() const
{
	return _isRemoved;
}

void CardModel::setCurrentArea(Area area)
{
	_currentArea = area;
}

Area CardModel::getCurrentArea() const
{
	return _currentArea;
}

void CardModel::setCurrentPos(cocos2d::Vec2 pos)
{
	_currentPos = pos;
}

cocos2d::Vec2 CardModel::getCurrentPos() const
{
	return _currentPos;
}

void CardModel::setIndex(int index)
{
	if (_currentArea == Area::PLAYFIELD)
	{
		_index = index;
	}
}

int CardModel::getIndex() const
{
	return _index;
}

int CardModel::getInstanceId() const
{
	return _instanceId;
}
