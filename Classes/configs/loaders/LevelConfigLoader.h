#pragma once
#ifndef __LEVEL_CONFIG_LOADER_H__
#define __LEVEL_CONFIG_LOADER_H__

#include "cocos2d.h"
#include "json/document.h"
#include "platform/CCFileUtils.h"
#include "configs/models/CardConfig.h"
#include "configs/models/LevelConfig.h"
#include "vector"
#include "string"

class LevelConfigLoader
{
private:
	const std::string _levelConfigPath;
	int _lastLoadedLevelId;
	int _instanceCounter;	// 用于为当前关卡的每个卡牌分配唯一id
	std::vector<CardConfig> _parse(const rapidjson::Value& data);

public:
	LevelConfigLoader();
	std::unique_ptr<LevelConfig> loadLevelConfig(int levelId);
};

#endif // __LEVEL_CONFIG_LOADER_H__