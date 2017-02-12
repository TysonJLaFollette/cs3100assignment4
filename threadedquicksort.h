//Quicksort implementation.
#include<iostream>
#include<vector>
#include "threadsafequeue.h"
#include "threadpool.h"

template<typename T>
void threadedQuickSort(std::vector<T>& myVector, int i, int j,ThreadPool& pool,int& jobCount) {
    if(i < j) {
        int pos = partition(myVector, i, j);
        jobCount++;
        jobCount++;
        threadedQuickSort(myVector, i, pos - 1,pool,jobCount);
        threadedQuickSort(myVector, pos + 1, j,pool,jobCount);
    }
    jobCount--;
}


//std::function<void()> myFunc = [&myVector, pos, low, high,&pool](){threadedQuickSort(myVector, low, pos - 1, pool);};
  //      pool.post(myFunc);
