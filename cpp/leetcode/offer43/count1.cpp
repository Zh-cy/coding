#include <iostream>

using namespace std;

int countDigitOne(int n)
{
    if (n<10)
        return 1;
    int digit = 1;
    int low = 0;
    int cur = n%10;
    int high = n/10;
    int res = 0;
    while (cur!=0 || high!=0)
    {
        if (cur == 0)
            res += high*digit;
        else if (cur == 1)
            res += high*digit + low + 1;
        else
            res += (high + 1)*digit;
        if (digit == 1000000000)
            break;
        digit *= 10;
        low = n % digit;
        high = n/digit/10;
        cur = n/digit%10;
    }
    return res;
}


int main(void)
{
    cout << countDigitOne(1410065408) << endl;
    return 0;
}
