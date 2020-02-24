#include "vector.h"
#include "test.h"
#include <stdio.h>
#include <stdlib.h>

ADTErr VectorCreateTest()
{
	Vector *v=VectorCreate(0,0);
	if(NULL!=v)
	{
		return ERR_OK;
	}
	else
	{
		return ERR_GENERAL;
	}
}
