#pragma once

template<size_t arraySize, class T>
size_t SizeofArray(T(&arr)[arraySize])
{
	return arraySize;
}
