#include <iostream>

using namespace std;

bool isNumber(string s)
{
    int index = 0;
    int len = s.size();
    while(s[index]==' ')
        ++index;
    bool point = false;
    bool euler = false;
    bool num = false;
    for (; index<len; index++)
    {
        // s[index] is number
        if(s[index]-'0'>=0 && s[index]-'0'<=9)
            num = true;
        
        // s[index] is '+'/'-', then it must be at the begining or after 'e'/'E'
        else if(s[index] == '+' || s[index] == '-')
        {
            if ((!num && !euler && !point) || (index!=0 && s[index-1]=='e'||s[index-1]=='E'))
                continue;
            else
                return false;
        }
        
        else if(s[index] == '.' && !euler && !point)
            point = true;

        else if ((s[index] == 'e' || s[index] == 'E') && !euler && num)
        {
            euler = true;
            // if no number after 'e'/'E' it is also false, so here check number again
            num = false;
        }
        // s[index] is blank, after removing all blank, check if index is len
        else if(s[index] == ' ')
        {
            while(s[index] == ' ' && (index < len))
                ++index;
            return num && index==len;
        }
        else
            return false;
    }
    // if no number, here is false; if number exists, here is true
    return num;
}

int main(void)
{
    string s1 = "e9";
    string s2 = "1 ";
    string s3 = " ";
    string s4 = ".1";
    string s5 = ".";
    string s6 = "-1E-16";
    string s7 = "1a3.14";
    string s8 = "1.2.3";
    string s9 = "+-5";
    string s10 = "12e+5.4";
    string s11 = " 0";
    string s12 = "3.";
    string s13 = ".1.";
    string s14 = " .9";
    string s15 = ".9";
    string s16 = "+.8";
    string s17 = "1e.";
    string s18 = "4.";
    string s19 = "-.";
    string s20 = "..";
    string s21 = ".+";
    string s22 = ".e";
    string s23 = "3.e3";
    string s24 = "46.e3";
    string s25 = "92e1740e91";
    
    if (isNumber(s1))
        cout << "It is number." << endl;
    else
        cout << "It isn't number" << endl;

    return 0;
}
