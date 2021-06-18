#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void r(vector<int> &v, char* num, int len, int index)
{
    if (index == len-1)
    {
        for (int i=0; i<10; i++)
        {
            num[index] = i + '0';
            v.push_back(atoi(num));
        }
        return;
    }
    for (int i=0; i<10; i++)
    {
        num[index] = i + '0';
        r(v, num, len, index+1);
    }
}

int main(void)
{
    int n = 1;
    vector<int> v;
    char* num = new char[n+1];
    memset(num, '0', n);
    num[n] = '\0';
    r(v, num, n, 0);
    
    delete[] num;
    for(auto i:v)
        cout << i << endl;

    return 0;
}
