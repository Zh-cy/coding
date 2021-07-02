#include <iostream>
#include <vector>
#include <set>


class Solution
{
public:
    vector<string> permutation(string s)
    {
        recurs(s, 0);
        return res;
    }
    
    void recurs(string s, int x)
    {
        if (x == s.size()-1)
            res.push_back(s);
        // to prevent string having same character e.g. "abbcdee"
        set<char> st;
        for(int i=x; i<s.size(); i++)
        {
            // check if s[i] is already in the set 
            if (st.count(s[i])==1)
                continue;
            st.insert(s[i]);
            swap(s[i], s[x]);
            recurs(s, x+1);
            // backtracking it needs to be back to the previous status
            swap(s[i], s[x]);
        }
    }

private:
    vector<string> res;
}
