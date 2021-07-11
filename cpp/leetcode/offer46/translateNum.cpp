#include <iostream>
#include <string>


//1.dynamic planning time:O(n) place:O(n)
//2.from end to beginning = from beginning to end, for every digit do the calculation time O(n), place O(1)


// 2.
int translateNum(int num)
{
    int pre = 1, cur = 1, res = 1;
    int number = num%10;
    num /= 10;
    while(num%10 != 0 || num/10 !=0)
    {
        if (num%10 == 1 || (num%10 == 2 && number >= 0 && number <= 5))
            res = cur + pre;
        else
            res = cur;
        pre = cur;
        cur = res;
        number = num%10;
        num /= 10;
    }
    return res;
}


int main(void)
{
    int res = translateNum(12251);
    std::cout << res << std::endl;    
    return 0;
}
