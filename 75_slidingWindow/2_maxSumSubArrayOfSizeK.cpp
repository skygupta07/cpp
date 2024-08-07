#include <iostream>
using namespace std;
int main(){
    int arr[]={2,4,7,8,10,1,5,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;

    int maxSum = INT_MIN;
    int maxIdx = -1;

    // i batata hai ki window kaha se leke kaha tak jaa sakti hai...i.e.
    // uska starting point kya hai...

    for (int i=0; i <= n-k; i++){  // O(n-k)
        int windowSum = 0;
        for (int j=i; j <= i+k-1; j++){  // window size controller (k times)
            windowSum += arr[j];
        }

        // update windowSum and maxIdx
        if (windowSum > maxSum){
            maxSum = windowSum;
            maxIdx = i;
        }
    }
    // total = O(n-k+1)*k
    cout<<"max sum subArray of size k is: "<<maxSum<<endl;

    // printing which window element added this max sum..
    for (int p=maxIdx; p<(maxIdx+k); p++){
        cout<<arr[p]<<" ";
    }
    cout<<endl;
}    




/*

better rehta hai... i<= n-1 , wali condition...

->i pointer telling ki mera window kaha se lekar kaha tak jaa sakta hai..
-> j controlling search area to be of window length
-> current window ke khatam hote hi aur nayi window search karne ke se pehle apne 
maxsum ko update kar do

but iss brute force mai humne sabka sum dubara dubara nikala jabki unme se KAAFI elements
next window mai common they

-> so use sliding window...

*/