#include "models/PlayfieldModel.h"

PlayfieldModel::PlayfieldModel(std::vector<CardModel*>& cardModels)
{
	_cardModels = cardModels;
}

void PlayfieldModel::addCard(CardModel* card)
{
	if (card)
	{	
		card->setIndex(_cardModels.size());
		if (!_cardModels.empty())
		{
			for (const auto& cardModel : _cardModels)
			{
				// TODO: 在isCardCovered()中检查当前card是否遮蔽原有card
				if (isCardCovered(card, cardModel))
				{
					_coverIndices.emplace_back(card->getIndex(), cardModel->getIndex());
					_coverCounts[cardModel->getIndex()]++;
				}
			}
		}
		card->setCurrentArea(Area::PLAYFIELD);
		_cardModels.emplace_back(card);
	}
}

CardModel* PlayfieldModel::removeCard(int instanceId)
{
	CardModel* card = nullptr;
	for (auto it = _cardModels.begin(); it != _cardModels.end(); it++)
	{
		if ((*it)->getInstanceId() == instanceId)
		{
			// 移除数组
			card = (*it);
			_cardModels.erase(it);
			
		}
	}



	for (const auto& coverIndex : _coverIndices)
	{
		if (!card)	break;
		if (coverIndex[0] == card->getIndex()) 
		{
			_coverCounts[coverIndex[1]]--;
		}
	}

	return card;
}

std::vector<CardModel*> PlayfieldModel::getClickableCards()
{
	std::vector<CardModel*> clickableCards;

	// 预分配内存以提高性能
	clickableCards.reserve(_cardModels.size() / 3);
	for (auto& cardModel : _cardModels)
	{
		if (!cardModel->isRemoved() && _coverCounts[cardModel->getIndex()] == 0)
		{
			clickableCards.emplace_back(cardModel);
		}
	}
	return clickableCards;
}

bool PlayfieldModel::isEmpty() const
{
	return _cardModels.empty();
}
