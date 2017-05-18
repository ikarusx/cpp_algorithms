
#pragma once

#include <vector>
#include <iostream>

template<typename T, typename CMP = std::less<T>>
class QuickSort
{
public:
	QuickSort(std::vector<T> & arr);

	std::vector<T> &getSorted();

private:
	std::vector<T> &mVector;
	CMP mCmp;

	void SwapElements(int index1, int index2);

	void sort();

	void QSort(int lIndex, int rIndex);

	int Partition(int lIndex, int rIndex, int pivotIndex);
};

//public:
template<typename T, typename CMP>
QuickSort<T, CMP>::QuickSort(std::vector<T> & arr) : mVector(std::move(arr))
{
	sort();
}

template<typename T, typename CMP>
std::vector<T> & QuickSort<T, CMP>::getSorted()
{
	return mVector;
}

//private:
template<typename T, typename CMP>
void QuickSort<T, CMP>::SwapElements(int index1, int index2)
{
	T temp = mVector.at(index1);

	mVector[index1] = mVector.at(index2);
	mVector[index2] = temp;
}

template<typename T, typename CMP>
void QuickSort<T, CMP>::sort()
{
	QSort(0, mVector.size() - 1);
}

template<typename T, typename CMP>
void QuickSort<T, CMP>::QSort(int lIndex, int rIndex)
{
	if ((rIndex - lIndex) <= 0)
	{
		return;
	}

	int pivotIndex = Partition(lIndex, rIndex, rIndex);

	QSort(lIndex, pivotIndex - 1);
	QSort(pivotIndex + 1, rIndex);
}

template<typename T, typename CMP>
int QuickSort<T, CMP>::Partition(int lIndex, int rIndex, int pivotIndex)
{
	// first put the pivot to be the last element in the range
	if (rIndex != pivotIndex)
	{
		SwapElements(rIndex, pivotIndex);
	}

	T pivot = mVector.at(rIndex);
	int currLeft = lIndex;
	int currRight = rIndex - 1;

	while (true)
	{
		while (currLeft < rIndex && mCmp(mVector.at(currLeft), pivot))
		{
			++currLeft;
		}
		while (currRight > lIndex && !mCmp(mVector.at(currRight), pivot))
		{
			--currRight;
		}
		if (currLeft >= currRight)
		{
			break;
		}

		SwapElements(currLeft, currRight);
	}
	if (rIndex != currLeft)
	{
		SwapElements(rIndex, currLeft);
	}

	return currLeft;
}

void testingQuickSort()
{
	std::vector<int> testVec =
	//{ 34, 12, 30, 59, 0, -8, 21, 8, 16, -40, 30 };
	{ 12, 30, 59, 0, -8, 21, 8, 22, 30 };

	QuickSort<int, std::less<int>> mySort(testVec);

	for (int i = 0; i < (int)testVec.size(); ++i)
	{
		std::cout << testVec[i] << std::endl;
	}
	
	std::cout << std::endl;
}