#include <stdexcept>

#include "stdafx.h"
#include "SimpleMath.h"

SimpleMath::SimpleMath() {}
SimpleMath::~SimpleMath() {}

float SimpleMath::add(float x, float y)
{
    return x + y;
}

int SimpleMath::divide(int a, int b)
{
    if (b == 0)
        throw std::logic_error("divide by zero.");

    return a / b;
}