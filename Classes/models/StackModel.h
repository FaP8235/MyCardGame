#pragma once
#pragma once
#ifndef __STACK_MODEL_H__
#define __STACK_MODEL_H__

#include <stack>
#include "models/CardModel.h"

class StackModel
{
private:
	std::stack<CardModel*> _cards;

public:
	CardModel* top();

	void push(CardModel* card);

	CardModel* pop();

	bool isEmpty() const;
};


#endif  // __PLAYFIELD_MODEL_H__