#pragma once
#ifndef __LEVEL_CONFIG_H__
#define __LEVEL_CONFIG_H__

#include <vector>
#include "cocos2d.h"
#include "CardConfig.h"

class LevelConfig
{
private:
	int _levelId;
	std::vector<CardConfig> _playfieldCards;
	std::vector<CardConfig> _stackCards;
	friend class LevelConfigLoader;

public:
	int getLevelId() const { return _levelId; }
	const std::vector<CardConfig>& getPlayfieldCards() const { return _playfieldCards; }
	const std::vector<CardConfig>& getStackCards() const { return _stackCards; }
};

#endif // __LEVEL_CONFIG_H__