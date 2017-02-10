//Quicksort implementation.
#include<iostream>
#include<vector>
template<typename T>
void printVector(std::vector<T> myVector) {
    for (int i = 0; i < myVector.size(); i++){
        std::cout << myVector.at(i) << " ";
    }
    std::cout << "\n";
}
template<typename T>
void swap(std::vector<T>& myVector, int k, int small) {
    int temp;
    temp = myVector.at(k);
    myVector.at(k) = myVector.at(small);
    myVector.at(small) = temp;
}
template<typename T>
int partition(std::vector<T>& myVector, int i, int j) {
    int pivot = myVector.at(j);
    int small = i - 1;

    for(int k = i; k < j; k++) {
        if(myVector.at(k) <= pivot) {
            small++;
            swap(myVector, k, small);
        }
    }

    swap(myVector, j, small + 1);
    std::cout << "Pivot = " << myVector.at(small + 1) << "\n";
    printVector(myVector);
    return small + 1;
}
template<typename T>
void quickSort(std::vector<T>& myVector, int i, int j) {
    if(i < j) {
        int pos = partition(myVector, i, j);
        quickSort(myVector, i, pos - 1);
        quickSort(myVector, pos + 1, j);
    }
}
std::vector<int> createTestVector(){
    std::vector<int> myVector;
    myVector.push_back(9);
    myVector.push_back(2);
    myVector.push_back(7);
    myVector.push_back(4);
    myVector.push_back(5);
    myVector.push_back(6);
    myVector.push_back(3);
    myVector.push_back(8);
    myVector.push_back(1);
    myVector.push_back(10);
    return myVector;
}
