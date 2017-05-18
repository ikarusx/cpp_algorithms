
#pragma once

#include <vector>
#include <iostream>

template<typename T, typename CMP = std::less<T>>
class MergeSort
{
public:
	MergeSort(std::vector<T> & arr);

	std::vector<T> &getSorted();

private:
	std::vector<T> &mVector;
	CMP mCmp;

	void SwapElements(int index1, int index2);

	void sort();

	void MSort(int lIndex, int rIndex);

	void Merge(int lIndex, int rIndex);
};

//public:
template<typename T, typename CMP>
inline MergeSort<T, CMP>::MergeSort(std::vector<T>& arr) : mVector(std::move(arr))
{
	sort();
}

template<typename T, typename CMP>
std::vector<T> & MergeSort<T, CMP>::getSorted()
{
	return mVector;
}

//private:
template<typename T, typename CMP>
void MergeSort<T, CMP>::SwapElements(int index1, int index2)
{
	T temp = mVector.at(index1);

	mVector[index1] = mVector.at(index2);
	mVector[index2] = temp;
}

template<typename T, typename CMP>
void MergeSort<T, CMP>::sort()
{
	MSort(0, mVector.size() - 1);
}

template<typename T, typename CMP>
void MergeSort<T, CMP>::MSort(int lIndex, int rIndex)
{
	if (lIndex >= rIndex)
	{
		return;
	}

	int midIndex = (lIndex + rIndex) >> 1;

	MSort(lIndex, midIndex);
	MSort(midIndex + 1, rIndex);

	Merge(lIndex, rIndex);
}

template<typename T, typename CMP>
void MergeSort<T, CMP>::Merge(int lIndex, int rIndex)
{
	if (lIndex >= rIndex)
	{
		return;
	}

	int midIndex = ((lIndex + rIndex) >> 1) - lIndex;

	int currIndex = lIndex;
	int mergeLeft = 0;
	int mergeRight = midIndex + 1;

	std::vector<T> tempVec;

	tempVec.reserve(lIndex + rIndex + 1);

	for (int i = lIndex; i <= rIndex; ++i)
	{
		tempVec.push_back(mVector[i]);
	}

	while (mergeLeft <= midIndex || (mergeRight + lIndex) <= rIndex)
	{
		if ((mergeRight + lIndex) > rIndex ||
			(mergeLeft <= midIndex && mCmp(tempVec.at(mergeLeft), tempVec.at(mergeRight))))
		{
			mVector[currIndex++] = tempVec[mergeLeft++];
		}
		else
		{
			mVector[currIndex++] = tempVec[mergeRight++];
		}
	}
}

void testingMergeSort()
{
	std::vector<int> testVec =
		//{ 34, 12, 30, 59, 0, -8, 21, 8, 16, -40, 30 };
	{ 12, 30, 59, 0, -8, 21, 8, 22, 30 };

	MergeSort<int, std::less<int>> mySort(testVec);

	for (int i = 0; i < (int)testVec.size(); ++i)
	{
		std::cout << testVec[i] << std::endl;
	}

	std::cout << std::endl;
}