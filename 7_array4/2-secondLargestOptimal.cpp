#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    int largest = arr[0];
	    int slargest = -1;
	    for (int i=1; i<n; i++){
	        if (arr[i]>largest){
	            slargest = largest;
	            largest = arr[i]; // largest mai aa jaega ab arr[i] element
	        }
	        else if (arr[i]>slargest && arr[i]<largest){
	            slargest = arr[i];
	        }
	    }
	    return slargest;
	}
};



int main(){

}