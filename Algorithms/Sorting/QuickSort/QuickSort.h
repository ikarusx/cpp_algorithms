
#pragma once

#include <vector>
//#include <memory>
#include <iostream>

template<typename T, typename CMP = std::less<T>>
class QuickSort
{
public:
	QuickSort(std::vector<T> & arr) : mVector(std::move(arr))
	{
		sort();
	}

	std::vector<T> &getSorted()
	{
		return mVector;
	}

private:
	std::vector<T> &mVector;
	CMP mCmp;

	void SwapElements(int index1, int index2)
	{
		T temp = mVector.at(index1);

		mVector[index1] = mVector.at(index2);
		mVector[index2] = temp;
	}

	void sort()
	{
		QSort(0, mVector.size() - 1);
	}

	void QSort(int lIndex, int rIndex)
	{
		if ((rIndex - lIndex) <= 0)
		{
			return;
		}

		int pivotIndex = Partition(lIndex, rIndex, rIndex);
		QSort(lIndex, pivotIndex - 1);
		QSort(pivotIndex + 1, rIndex);
	}

	int Partition(int lIndex, int rIndex, int pivotIndex)
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
	//int Partition(int lIndex, int rIndex, int pivotIndex)
	//{
	//	if ((rIndex - lIndex) <= 0)
	//	{
	//		return 0;
	//	}
	//	// first put the pivot to be the last element in the range
	//	if (rIndex != pivotIndex)
	//	{
	//		SwapElements(rIndex, pivotIndex);
	//	}
	//	T pivot = mVector.at(rIndex);

	//	--rIndex;

	//	int currLeft = lIndex;
	//	int currRight = rIndex;

	//	while (currLeft <= currRight)
	//	{
	//		while (currLeft < rIndex && mVector.at(currLeft) < pivot)
	//			//while (currLeft < rIndex && mCmp(mVector.at(currLeft), pivot))
	//		{
	//			++currLeft;
	//		}
	//		while (currRight > lIndex && mVector.at(currRight) > pivot)
	//			//while (currRight > lIndex && mCmp(mVector.at(currRight), pivot))
	//		{
	//			--currRight;
	//		}

	//		if (currLeft <= currRight)
	//		{
	//			SwapElements(currLeft, currRight);
	//			++currLeft;
	//			--currRight;
	//		}
	//	}
	//	/*if (pivotIndex != currRight + 1)
	//	{
	//	SwapElements(pivotIndex, currRight + 1);
	//	}*/

	//	Partition(lIndex, currRight, currRight);
	//	Partition(currLeft, rIndex, rIndex);

	//	return currRight + 1;
	//}
};

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