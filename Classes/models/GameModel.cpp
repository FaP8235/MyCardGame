#include "GameModel.h"

void GameModel::init(const LevelConfig& config)
{
	// 调用PlayfieldModel的构造方法，传入LevelConfig中的_playfieldCards构造_playfield

	// 调用StackModel的构造方法，传入LevelConfig中的_stackfieldCards构造_stackfield

	// 指定_stack和_hand在UI中的显示点位

	// 将_stack顶第一张牌出栈交给_hand
}

PlayfieldModel* GameModel::getPlayfield()
{
	return _playfield;
}

StackModel* GameModel::getStack()
{
	return _stack;
}

CardModel* GameModel::getHand()
{
	return _hand;
}

StackModel* GameModel::getDiscard()
{
	return _discard;
}

GameStateType GameModel::checkGameResult()
{
	if (_playfield->isEmpty())
	{
		_gameState = GameStateType::WIN;
	}
	else if (_stack->isEmpty() && !_playfield->isEmpty())
	{
		_gameState = GameStateType::GAMEOVER;
	}
	return _gameState;
}
