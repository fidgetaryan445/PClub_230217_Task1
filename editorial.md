For Keshav's to gain maximum profit ,  we need to identify which column in the given matrix has the largest contiguous subarray sum. To find this sum Kadane's Algorithm can be  to find the subarray sum in each column in O(N) time, thus solving the entire problem in O(N×M) time complexity. 

The Kadane's Algorithm starts with 2 variables: one to track the maximum sum at the current index and another to store the global maximum sum encountered during the iteration. If the sum of the current maximum and the current element is less than the current element itself, we update the current maximum to be the current element. 
Also if  at any point the current maximum sum exceeds the global maximum, we update the global maximum.

Here’s the psuedo-code :
```
kadane(arr)
    current_max = arr[0];
    global_max = arr[0] ;
    for all elements in arr (excpet for arr[0]) 
        current_max = max(arr[i], current_max + arr[i])
        if current_max > global_max:
            global_max = current_max
    return global_max
```


 
