#include <vector>
#include <iostream>


int singleNumber(std::vector<int>& nums)
{
    int a = 0, b = 0;
    for (int num:nums)
    {
        b = (b^num) & ~a;
        a = (a^num) & ~b;
    }
    return b;
}

int main(void)
{
    std::vector<int> nums {3, 4, 3, 3};
    int res = singleNumber(nums);
    std::cout << res << std::endl;
}
