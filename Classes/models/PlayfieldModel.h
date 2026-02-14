#pragma once
#ifndef __PLAYFIELD_MODEL_H__
#define __PLAYFIELD_MODEL_H__

#include <vector>
#include "models/CardModel.h"

class PlayfieldModel
{
private:
	std::vector<CardModel*> _cardModels;
	std::vector<std::vector<int>> _coverIndices;
	std::vector<int> _coverCounts;

public:
	PlayfieldModel(std::vector<CardModel*>& cardModels);
	void addCard(CardModel* card);
	CardModel* removeCard(int instanceId);
	std::vector<CardModel*> getClickableCards();
	bool isEmpty() const;
};


#endif  // __PLAYFIELD_MODEL_H__