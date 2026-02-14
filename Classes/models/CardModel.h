#pragma once
#ifndef __CARD_MODEL_H__
#define __CARD_MODEL_H__

#include "cocos2d.h"
#include "configs/models/CardConfig.h"

class CardModel
{
private:
	const int _instanceId;
	const CardConfig& _config;
	bool _isFaceUp;
	bool _isRemoved;
	Area _currentArea;
	int _index;
	cocos2d::Vec2 _currentPos;

public:
	CardModel(const CardConfig& config);
	CardModel() = delete;
	CardModel(const CardModel&) = delete;

	void setFaceUp(bool faceUp);
	bool isFaceUp() const;

	void setRemoved(bool removed);
	bool isRemoved() const;

	void setCurrentArea(Area area);
	Area getCurrentArea() const;

	void setCurrentPos(cocos2d::Vec2 pos);
	cocos2d::Vec2 getCurrentPos() const;

	void setIndex(int index);
	int getIndex() const;

	int getInstanceId() const;
};

#endif // __CARD_MODEL_H__
