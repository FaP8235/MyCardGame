#pragma once
#ifndef __GAME_MODEL_H__
#define __GAME_MODEL_H__


#include "models/CardModel.h"
#include "models/PlayfieldModel.h"
#include "models/StackModel.h"
#include "configs/models/CardConfig.h"
#include "configs/models/LevelConfig.h"
#include "cocos2d.h"

class GameModel
{
private:
	PlayfieldModel* _playfield;
	StackModel* _stack;
	CardModel* _hand;
	StackModel* _discard;
	GameStateType _gameState;
	cocos2d::Vec2 _stackPos;
	cocos2d::Vec2 _handPos;

public:
	void init(const LevelConfig& config);

	PlayfieldModel* getPlayfield();

	StackModel* getStack();

	CardModel* getHand();

	StackModel* getDiscard();

	GameStateType checkGameResult();
};

#endif // __GAME_MODEL_H__
