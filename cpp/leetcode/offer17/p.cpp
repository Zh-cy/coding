#include <iostream>
#include <queue>
#include <set>
#include <cstring>

using namespace std;

// e.g. '0123'->'123' 
// '0' or '0000'... is not printed, but it exits
void printnum(char* num)
{
    bool ifprint = false;
    int len = strlen(num);
    for (int i=0; i<len; i++)
    {
        if (!ifprint && num[i] != '0')
            ifprint = true;
        if (ifprint)
            cout << num[i];
    }
    cout << endl;
}


void r(char* num, int len, int index)
{
    if (index == len-1)
    {
        for (int i=0; i<10; i++)
        {
            num[index] = i + '0';
            printnum(num);
        }
        return;
    }
    for (int i=0; i<10; i++)
    {
        num[index] = i + '0';
        r(num, len, index+1);
    }
}

int main(void)
{
    int n = 1;
    char* num = new char[n+1];
    memset(num, '0', n);
    num[n] = '\0';
    r(num, n, 0);
    
    delete[] num;
    
    return 0;
}
