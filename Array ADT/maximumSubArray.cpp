#include <iostream>
#include <vector>
using namespace std;

// Given an integer array nums, find the subarray with the largest sum, and return its sum.

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.

// Printing sub array
void printSubArray(vector<int> nums)
{
    for (int start = 0; start < nums.size(); start++)
    {
        for (int end = start; end < nums.size(); end++)
        {
            for (int i = start; i <= end; i++)
                cout << nums[i];
            cout << " ";
        }
        cout << endl;
    }
}

// Finding Maximum of Sub Array using Brute Force
int maxSubArrayBruteForce(vector<int> nums)
{
    int maxSum = INT32_MIN;
    for (int start = 0; start < nums.size(); start++)
    {
        int currentSum = 0;
        for (int end = start; end < nums.size(); end++)
        {
            currentSum += nums[end];
            maxSum = max(maxSum, currentSum);
        }
    }
    return maxSum;
}

// Finding Maxium of Sub Array using Kadane's Algorithm
// Kandane's algorithm says that if we add any higher negative value to any number
// it will always gives negative ans that's why whenever our sum get's less than 0
// make the sum value 0
int maxSubArrayKadanesAlgo(vector<int> nums)
{
    int maxSum = INT32_MIN, currentSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        currentSum += nums[i];
        maxSum = max(currentSum, maxSum);

        if (currentSum < 0)
            currentSum = 0;
    }
    return maxSum;
}
int main()
{
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // printSubArray(nums);
    cout << maxSubArrayKadanesAlgo(nums);
}