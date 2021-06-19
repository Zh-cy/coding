#include <string>
#include <climits>
#include <iostream>

using namespace std;

int str2int(string str)
{
    int index = 0;
    // delete space in the begining
    while (str[index] == ' ')
        ++index;
    // if empty string return 0
    if (index == str.size())
        return 0;
    int res = 0;
    int sign = 1;
    // boundary is 214748364
    int bound = INT_MAX / 10;
    
    if (str[index] == '-' || str[index] == '+')
    {
        sign = str[index]=='+'?1:-1;
        ++index;
    }

    while (str[index]-'0'>=0 && str[index]-'0'<=9)
    {
        // if res == 2147483648, no matter sign is + or -, return INT_MIN/INT_MAX
        if (res > bound || res == bound && str[index]>'7')
            return sign==-1?INT_MIN:INT_MAX;
        res = res*10 + (str[index]-'0');
        ++index;        
    }
    return sign==-1?-res:res;
}

int main(void)
{
    string s1 = "+1";
    string s2 = "-1";
    string s3 = " 0 + 1";
    string s4 = " 0012  1234 tr";
    string s5 = "asf 1234";
    string s6 = "2147483647";
    string s7 = "2147483648";
    string s8 = "-2147483648";
    string s9 = "-2147483649";
    string s10 = "012 2+3";
    
    cout << "string is: " << s1 << "   integer is: " << str2int(s1) << endl;
    cout << "string is: " << s2 << "   integer is: " << str2int(s2) << endl;
    cout << "string is: " << s3 << "   integer is: " << str2int(s3) << endl;
    cout << "string is: " << s4 << "   integer is: " << str2int(s4) << endl;
    cout << "string is: " << s5 << "   integer is: " << str2int(s5) << endl;
    cout << "string is: " << s6 << "   integer is: " << str2int(s6) << endl;
    cout << "string is: " << s7 << "   integer is: " << str2int(s7) << endl;
    cout << "string is: " << s8 << "   integer is: " << str2int(s8) << endl;
    cout << "string is: " << s9 << "   integer is: " << str2int(s9) << endl;
    cout << "string is: " << s10 << "   integer is: " << str2int(s10) << endl;
    return 0;
}
