#pragma once
#include <stdlib.h>

int random(int min, int max)
{
	return min + rand() % (max + 1 - min);
}