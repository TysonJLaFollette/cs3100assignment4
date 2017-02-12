//threaded linear search
void findInVector(std::vector<int> myVector, int first, int last, int whatToFind){
    bool found = false;
    for (int i = first; i < last; i++){
        if (myVector.at(i) == whatToFind){
            found = true;
        }
    }
    if(found == true){
        std::cout << "Found it!";
    }
    else{
        std::cout << "Not Found.";
    }
}
void threadedSearch(std::vector<int> myVector, ThreadPool& pool, int whatToFind){
    int len = myVector.size();
    int partitionSize = len / pool.getNumThreads();
    for (int i = 0; i < 4; i++){
        std::function<void()> myFunc = [myVector,i,whatToFind,partitionSize](){findInVector(myVector,i*partitionSize,(i+1)*partitionSize,whatToFind);};
        pool.post(myFunc);
    }
}
