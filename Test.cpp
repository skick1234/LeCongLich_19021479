#include <iostream> 

using namespace std; 


int calcSum(int arr[], int n, int k) { 
    int sum = 0; 
  
    // Consider first subarray of size k 
    // Store the sum of elements 
    for (int i = 0; i < k; i++) 
        sum += arr[i]; 
  
    // Print the current sum 
    cout << sum << " "; 
  
    // Consider every subarray of size k 
    // Remove first element and add current 
    // element to the window 
    for (int i = k; i < n; i++) { 
          
        // Add the element which enters 
        // into the window and substract 
        // the element which pops out from 
        // the window of the size K 
        sum = (sum - arr[i - k]) + arr[i]; 
          
        // Print the sum of subarray 
        cout << sum << " "; 
    } 
} 
  

int main() { 
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++) cin >> A[i];
    int k;
    cin >> k;
    
    calcSum(A, n, k); 
  
    return 0; 
} 