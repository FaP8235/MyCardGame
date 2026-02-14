#include "LevelConfigLoader.h"
#include "cocos2d.h"

std::vector<CardConfig> LevelConfigLoader::_parse(const rapidjson::Value& data)
{
	std::vector<CardConfig> configs;
	if (!data.IsArray()) return configs;
	for (const auto& item : data.GetArray())
	{
		CardConfig config;
		config.instanceId = _instanceCounter++;
		config.suit = static_cast<CardSuitType>(item["CardSuit"].GetInt());
		config.face = static_cast<CardFaceType>(item["CardFace"].GetInt());
		config.position.set(item["pos"]["x"].GetFloat(), item["pos"]["y"].GetFloat());
		configs.emplace_back(config);
	}
	return configs;
}


LevelConfigLoader::LevelConfigLoader()
	: _levelConfigPath("res/config")
	, _lastLoadedLevelId(0)
	, _instanceCounter(0)
{
}

std::unique_ptr<LevelConfig> LevelConfigLoader::loadLevelConfig(int levelId)
{
	// 检查重复加载
	if (levelId == _lastLoadedLevelId)
	{
		return nullptr;
	}
	
	// 拼接完整路径
	std::string levelFileName = cocos2d::StringUtils::format("level_%d.json", levelId);
	std::string levelFilePath = _levelConfigPath + levelFileName;

	// 读取并解析
	std::string content = cocos2d::FileUtils::getInstance()->getStringFromFile(levelFilePath);
	if (content.empty())
	{
		return nullptr;
	}
	
	rapidjson::Document doc;
	doc.Parse(content.c_str());
	if (doc.HasParseError())
	{
		return nullptr;
	}

	// 更新状态
	_lastLoadedLevelId = levelId;

	// 实例化配置对象
	auto levelConfig = std::make_unique<LevelConfig>();
	levelConfig->_levelId = levelId;

	if (doc.HasMember("Playfield"))
	{
		levelConfig->_playfieldCards = _parse(doc["Playfield"]);
	}

	if (doc.HasMember("Stack"))
	{
		levelConfig->_stackCards = _parse(doc["Stack"]);
	}
	return levelConfig;
}



