#include "DataStructure.h"
#include <iostream>

template <class K>
bool stackpush<K>::Push(DataStructure<K> * pDs, const K& data)
{
	if (pDs->m_iIndex > pDs->LEN - 2)
	{
		std::cout << "overflow" << std::endl;
		return false;
	}
	pDs->arr[++(pDs->m_iIndex)] = data;
	return true;
}
template <class K>
bool stackpush<K>::operator()(DataStructure<K> * pDs, const K& data)
{
	if (pDs->m_iIndex > pDs->LEN - 2)
	{
		std::cout << "overflow" << std::endl;
		return false;
	}
	pDs->arr[++(pDs->m_iIndex)] = data;
	return true;
}

template <class K>
K stackpop<K>::Pop(DataStructure<K> * pDs)
{
	K rn = pDs->arr[pDs->m_iIndex];
	pDs->m_iIndex--;
	return rn;
}
template <class K>
K stackpop<K>::operator()(DataStructure<K> * pDs)
{
	K rn = pDs->arr[pDs->m_iIndex];
	pDs->m_iIndex--;
	return rn;
}
template <class K>
bool stackempty<K>::Empty(DataStructure<K> * pDs)
{
	if (pDs->m_iIndex == -1)
		return true;
	return false;
}
template <class K>
bool stackempty<K>::operator()(DataStructure<K> * pDs)
{
	if (pDs->m_iIndex == -1)
		return true;
	return false;
}
template <class K>
void stackprint<K>::Print(DataStructure<K> * pDs)
{
	for(int i=0; i<=pDs->m_iIndex; i++)
	{
		std::cout << pDs->arr[i] << std::endl;
	}
}
template <class K>
void stackprint<K>::operator()(DataStructure<K> * pDs)
{
	for (int i = 0; i <= pDs->m_iIndex; i++)
	{
		std::cout << pDs->arr[i] << std::endl;
	}
}
