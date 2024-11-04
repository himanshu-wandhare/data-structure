#include <iostream>
#include <vector>
using namespace std;

vector<int> divisionMethod(vector<int> &nums) // O(n)
{
    int p = 1;
    for (int num : nums)
    {
        p *= num;
    }
    vector<int> ans;
    for (int num : nums)
    {
        ans.push_back(p / num);
    }
    return ans;
}

vector<int> bruteForce(vector<int> &nums) // O(n^2)
{
    vector<int> ans(nums.size(), 1);
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < nums.size(); j++)
        {
            if (i != j)
                ans[i] *= nums[j];
        }
    }
    return ans;
}

vector<int> mostOptimalMethod(vector<int> &nums) // Time: O(n)  Space: O(1)
{
    int size = nums.size();
    vector<int> ans(size, 1);

    for (int i = 1; i < size; i++)
    {
        ans[i] = ans[i - 1] * nums[i - 1];
    }

    int suffix = 1;
    for (int i = size - 2; i >= 0; i--)
    {
        suffix *= nums[i + 1];
        ans[i] *= suffix;
    }
    return ans;
}

int main()
{
    vector<int> nums{1, 2, 3, 4};
    // vector<int> ans = divisionMethod(nums);
    vector<int> ans = bruteForce(nums);

    for (int x : ans)
    {
        cout << x << " ";
    }
}