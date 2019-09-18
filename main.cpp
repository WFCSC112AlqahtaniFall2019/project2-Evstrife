#include <iostream>
#include <vector>
using namespace std;
/*
 * Author: Siyu Wu
 * Date: 2019/9/18
 * Project2: Use recursion to implement Merge Sort
 */

//merge two sorted vectors
void mergeSortedLists( vector<int>& a, vector<int>& tmp, int left, int middle, int right){
    tmp.resize(right - left + 1);       //resize the temporary vector to the size of vector a
    int i = left;                           //initialize the first index of left half vector
    int j = middle + 1;                     //initialize the first index of right half vector
    int index = 0;
    while (i <= middle && j <= right){      //as long as there's element remain in left or right vector,
        if(a[i]<a[j]){                      //merge the smaller element into the temporary vector
            tmp[index] = a[i];
            index = index + 1;
            i = i + 1;
        } else{
            tmp[index] = a[j];
            index = index + 1;
            j = j + 1;
        }
    }
    //if number in second half completed, but in first half remains
    while (i <=middle){
        tmp[index] = a[i];
        index = index + 1;
        i = i + 1;
    }
    //if number in first half completed, but in second half remains
    while (j <= right){
        tmp[index] = a[j];
        index = index + 1;
        j = j + 1;
    }
    for(int k = left, q= 0; k <= right; k++,q++){
        a[k] = tmp[q];
    }
};

// function declarations
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right){
    if(left<right){
        int mid = (left + right) / 2;   //initialize the middle index
        mergeSort(a,tmp,left,mid);      //sort the left half of the vectors
        mergeSort(a, tmp,mid + 1, right);   //sort the right half of the vectors
        mergeSortedLists(a,tmp,left,mid,right); //merge two sorted vectors
    }
};

int main() {
    // unit test for merge
    vector<int> testV1(5);
    testV1 = {5,4,3,2,1};
    vector<int> resultV1(5);
    resultV1 = {1,2,3,4,5};
    vector<int> tmp1(5);
    cout << "Unit Test Start"<<endl;
    cout << "The expected answer is: ";     //print expected answer
    for(int i = 0; i < resultV1.size(); i++) {
        cout << resultV1.at(i) << '\t';
    }
    cout << endl;
    cout << "The unit rest result is: ";        //print actual result
    mergeSort(testV1,tmp1,0,testV1.size() - 1);
    for(int i = 0; i < testV1.size(); i++) {
        cout << testV1.at(i) << '\t';
    }
    cout <<endl;
    if(testV1 == resultV1){             //check if the result match the expected answer
        cout << "Unit test passed" << endl;
    } else{
        cout<< "Unit test failed" <<endl;
    }

    // get input: first is random seed, second is vector length
    int seed, length;
    cout << "Please enter seed and length:"<<endl;
    cin >> seed >> length;
    srand(seed);

    vector<int> v(length);  // vector to be sorted
    vector<int> t(length);  // temporary workspace

    // initialize and print input
    cout << "The input vector is:"<<endl;
    for(int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // sort v
    mergeSort(v,t,0,length - 1);

    // print output
    cout << "The output vector is:"<<endl;
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


