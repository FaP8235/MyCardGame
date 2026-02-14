#include "models/StackModel.h"

CardModel* StackModel::top()
{
	return _cards.top();
}

void StackModel::push(CardModel* card)
{
	_cards.push(card);
}


CardModel* StackModel::pop()
{
	CardModel* card = _cards.top();
	_cards.pop();
	return card;
}

bool StackModel::isEmpty() const
{
	return _cards.empty();
}
