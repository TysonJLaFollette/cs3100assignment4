#include<vector>
#include"quicksort.h"
#include <iostream>
#include <atomic>
#include "threadpool.h"
#include "threadedquicksort.h"
#include "analysis.h"
#include <functional>
#include <algorithm>
#include "threadedsearch.h"

void doStuff(){
    for (int i = 0; i < 100000; i++){
        int blah = 0;
        blah += i;
    }
}
int main(){
    //serial search
    std::vector<int> myVector;
    myVector = createTestVector(10000);
    std::function<void()> serialFunc = [&myVector](){std::sort (myVector.begin(), myVector.end());};
    std::cout << "std::sort : " << timeFunction(serialFunc).count() << "ms.\n";

    //4 threaded search
    ThreadPool fourPool(4);
    int jobCount4 =0;
    std::vector<int> myVector2;
    myVector2 = createTestVector(10000);
    std::function<void()> fourThreadedFunc = [&myVector2,&fourPool,&jobCount4](){threadedQuickSort(myVector2,0,9999, fourPool,jobCount4);};
    std::cout << "4 threaded function: " << timeFunction(fourThreadedFunc).count() << "ms.\n";
    fourPool.stop();

    //8 threaded search
    ThreadPool eightPool(8);
    int jobCount8 = 0;
    std::vector<int> myVector3;
    myVector3 = createTestVector(10000);
    std::function<void()> eightThreadedFunc = [&myVector3,&eightPool,&jobCount8](){threadedQuickSort(myVector3,0,9999, eightPool,jobCount8);};
    std::cout << "8 threaded function: " << timeFunction(eightThreadedFunc).count() << "ms.\n";
    eightPool.stop();

    //linear search
    std::vector<int>myVector4;
    myVector4 = createTestVector(10000);
    std::function<void()> searchFunc = [myVector4](){std::find(myVector4.begin(),myVector4.end(),20);};
    std::cout << "Standard find finished in: " << timeFunction(searchFunc).count() << "ms.\n";

    //threaded linear search
    ThreadPool fivePool(5);
    std::vector<int> myVector5;
    myVector5 = createTestVector(10000);
    std::function<void()> threadSearchFunc = [myVector5,&fivePool](){threadedSearch(myVector5,fivePool,20);fivePool.stop();};
    std::cout << "Threaded linear search finished in: " << timeFunction(threadSearchFunc).count() << "ms.\n";
}
