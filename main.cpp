#include<vector>
#include"quicksort.h"
#include <iostream>
int main(){
    std::vector<int> myVector = createTestVector();
    printVector(myVector);
    quickSort(myVector,0,9);
}
