#ifndef SORT_
#define SORT_

#include <iostream> 
#include <vector>
#include <list>

using namespace std;

template <class T>
class Sorts{
    private:
        void copyArray(vector<T>&vec, vector<T>&tmp, int low, int high);
        void mergeArray(vector<T>&vec, vector<T>&tmp, int low, int mid, int high);
        void mergeSplit(vector<T>&vec, vector<T>&tmp, int low, int high);
    public:
        void ordenaMerge(vector<T>&vec);
};

template <class T>
void Sorts<T>::copyArray(vector<T>&vec, vector<T>&tmp, int low, int high){
    for(int i = low; i <= high; i++){
        vec[i] = tmp[i];
    }
}

template <class T>
void Sorts<T>::mergeArray(vector<T>&vec, vector<T>&tmp, int low, int mid, int high){
    int i, j, k;
    i = low; j = mid + 1; k = low;

    while(i <= mid && j <= high){
        if(vec[i] < vec[j]){
            tmp[k] = vec[i];
            i++;
        }
        else{
            tmp[k] = vec[j];
            j++;
        }
        k++;
    }
    if(i > mid){
        for(; j <= high; j++){
            tmp[k++] = vec[j];
        }
    }
    else{
        for(; i <= mid; i++){
            tmp[k++] = vec[i];
        }
    }
}

template <class T>
void Sorts<T>::mergeSplit(vector<T>&vec, vector<T>&tmp, int low, int high){
    int mid;

    if ((high - low) < 1){
        return;
    }
    mid = (high + low) / 2;
    mergeSplit(vec, tmp, low, mid);
    mergeSplit(vec, tmp, mid + 1, high);
    mergeArray(vec, tmp, low, mid, high);
    copyArray(vec, tmp, low, high);
}

template <class T>
void Sorts<T>::ordenaMerge(vector<T>&vec){
    vector<T> tmp(vec.size());
    mergeSplit(vec, tmp, 0, vec.size() - 1);
}

#endif