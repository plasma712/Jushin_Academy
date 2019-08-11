#pragma once

#ifndef __FUNCTOR_H__

template <typename T>
class CLess
{
public:
	bool operator()(T pObjectA, T pObjectB)
	{
		return pObjectA->GetInfo().fY < pObjectB->GetInfo().fY;
	}
};

#define __FUNCTOR_H__
#endif
