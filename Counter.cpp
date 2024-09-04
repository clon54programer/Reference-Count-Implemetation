#include "Counter.h"

void Counter::AumentCount()
{
	this->count += 1;
}

void Counter::DecrementCount() { this->count -= 1; }

bool Counter::IsZeroCounter() const { return this->count <= 0 ? true : false; }