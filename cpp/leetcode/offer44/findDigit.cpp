#include <iostream>
#include <string>

class Solution
{
public:
    int findNthDigit(int n)
    {
        int digit = 1;
        long start = 1;
        long count = 9;
        while(n > count)
        {
            n -= count;
            digit += 1;
            start *= 10;
            count = 9*digit*start;
        }
        int number = start + (n-1)/digit;
        std::string num = std::to_string(number);
        int res = num[(n-1)%digit] - '0';
        return res;
    }
};

int main(void)
{
    Solution l;
    
    std::cout << l.findNthDigit(1000000) << std::endl;

    return 0;
}
