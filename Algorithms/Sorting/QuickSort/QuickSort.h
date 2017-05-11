
#pragma once

#include <vector>
//#include <memory>

template<typename T, size_t size>
class QuickSort
{
public:
	QuickSort(std::vector<T> && arr) : mVector(std::move(arr))
	{
		sort();
	}

	std::vector<T> &getSorted()
	{
		return mVector;
	}

	void sort()
	{
		QSort(0, mVector.size() -1);
	}

	void QSort(int lIndex, int rIndex)
	{
		if ((rIndex - lIndex) <= 0)
		{
			return;
		}

		int pivotIndex = Partition(lIndex, rIndex, mVector[lIndex]);
		QSort(lIndex, pivotIndex - 1);
		QSort(pivotIndex + 1 , rIndex);
	}

	int Partition(int lIndex, int rIndex, T pivot)
	{
		int currLeft = lIndex;
		int currRight = rIndex;


	}

private:
	std::vector<T> mVector;

	void SwapElements(int index1, int index2)
	{
		T temp = mVector.at(index1);

		mVector[index1] = mVector.at(index2);
		mVector[index2] = temp;
	}
};
