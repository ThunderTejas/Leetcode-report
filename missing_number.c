#include <stdio.h>

int missingNumber(int nums[], int numsSize) {
    int ans = 0;

    // XOR all elements in the array
    for (int i = 0; i < numsSize; i++) {
        ans ^= nums[i];
    }

    // XOR all numbers from 0 to numsSize
    for (int i = 0; i <= numsSize; i++) {
        ans ^= i;
    }

    return ans;
}


