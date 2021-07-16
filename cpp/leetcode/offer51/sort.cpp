#include <iostream>
#include <vector>


int sort(int l, int r, std::vector<int>& nums, std::vector<int>& tmp)
{
    if (l >= r) return 0;
    int m = (l + r)/2;
    int res = sort(l, m, nums, tmp) + sort(m+1, r, nums, tmp);
    for (int i=l; i<=r; i++)
        tmp[i] = nums[i];
    int i=l, j=m+1, index=l;
    while(i!=m+1 || j!=r+1)
    {
        if (i==m+1)
        {
            nums[index] = tmp[j];
            ++j;
        }
        else if (j==r+1 || tmp[i] <= tmp[j])
        {
            nums[index] = tmp[i];
            ++i;
        }
        else if (tmp[i]>tmp[j])
        {
            nums[index] = tmp[j];
            ++j;
            res += m-i+1;
        }
        ++index;
    }
    return res;
}

int reversePairs(std::vector<int>& nums)
{
    std::vector<int> tmp(nums.size());
    return sort(0, nums.size()-1, nums, tmp);
}

int main()
{
    std::vector<int> v = {7,5,6,4};
    int a = reversePairs(v);
    std::cout << a << std::endl;
}
