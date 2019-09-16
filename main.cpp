#include <iostream>
#include <vector>
using namespace std;


//merge two sorted vectors
void mergeSortedLists( vector<int>& a, vector<int>& tmp, int left, int middle, int right){
    int sorted [right - left + 1];
    int i = left;
    int j = middle + 1;
    int index = 0;
    while (i <= middle && j <= right){
        if(a[i]<a[j]){
            sorted[index] = a[i];
            index = index + 1;
            i = i + 1;
        } else{
            sorted[index] = a[j];
            index = index + 1;
            j = j + 1;
        }
    }
    //if number in second half completed, but in first half remains
    while (i <=middle){
        sorted[index] = a[i];
        index = index + 1;
        i = i + 1;
    }
    //if number in first half completed, but in second half remains
    while (j <= right){
        sorted[index] = a[j];
        index = index + 1;
        j = j + 1;
    }
    for(int k = left, q= 0; k <= right; k++,q++){
        a[k] = sorted[q];
    }
};

// function declarations
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right){
    if(left<right){
        int mid = (left + right) / 2;
        mergeSort(a,tmp,left,mid);
        mergeSort(a, tmp,mid + 1, right);
        mergeSortedLists(a,tmp,left,mid,right);
    }
};

int main() {

    // get input: first is random seed, second is vector length
    int seed, length;
    cin >> seed >> length;
    srand(seed);

    vector<int> v(length);  // vector to be sorted
    vector<int> t(length);  // temporary workspace
    // unit test for merge
    //balabala
    // initialize and print input
    for(int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // sort v
    mergeSort(v,t,0,length - 1);

    // print output
    for(int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // check output, make sure it's sorted
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }

    return 0;
}


