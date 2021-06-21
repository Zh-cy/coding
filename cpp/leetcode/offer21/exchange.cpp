#include <iostream>
#include <vector>

using namespace std;

// slow, fast pointers, all start from 0
vector<int> exchange1(vector<int>& nums)
{
    int len = nums.size();
    if (len == 0)
        return nums;
    int slow = 0, fast = 0;
    while (slow < len && nums[slow]%2 == 1)
    {
        ++slow;
        ++fast;
    }
    while(1)
    {
        while(fast < len && nums[fast]%2 == 0)
            ++fast;
        if (fast == len)
            return nums;
        int temp = nums[fast];
        nums[fast] = nums[slow];
        nums[slow] = temp;
        while(slow < len && nums[len]%2 == 1)
            ++slow;
    }
    return nums;
}

// left, right pointers, left starts from 0, right starts from end of vector
vector<int> exchange2(vector<int>& nums)
{
    int len = nums.size();
    if (len == 0)
        return nums;
    int left = 0, right = len-1;
    while(left!=right)
    {
        while(left != right && nums[left]%2 == 1)
            ++left;
        if(left == right)
            return nums;
        while(right != left && nums[right]%2 == 0)
            --right;
        if(right == left)
            return nums;
        int temp = nums[right];
        nums[right] = nums[left];
        nums[left] = temp;
    }
    return nums;
}
