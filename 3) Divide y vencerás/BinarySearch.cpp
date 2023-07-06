#include <iostream>
using namespace std;

int binarySearch(int* arr, int left, int right, int objective) {
    if (left <= right) {
	    int mid = left + (right - left) / 2;
	    if (arr[mid] == objective) { return mid; }
	    if (arr[mid] < objective) return binarySearch(arr, mid + 1, right, objective);
	    else return binarySearch(arr, left, mid - 1, objective);
	    
    }
    return -1;
}

void ComputeResult(int result) {
    if (result == -1) cout << "Element not found" << endl;
    else cout << "Element found in the position: " << result << endl;  
}

int main() {
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int sizeArr = sizeof array/ sizeof array[0];
    int object  = 4;
    int result  = binarySearch(array, 0, sizeArr - 1, object);
    ComputeResult(result);
     

    return 0;
}