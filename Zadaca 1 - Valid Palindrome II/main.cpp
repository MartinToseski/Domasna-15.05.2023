#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s)
    {
        int left = 0, right = s.size()-1;
        while(left < right)
        {
            if (s[left] == s[right])
            {
                left++;
                right--;
            }
            else
                return checkPalindrome(s, left+1, right) || checkPalindrome(s, left, right-1);
        }
        return true;
    }

    bool checkPalindrome(string s, int L, int R)
    {
        while(L < R)
        {
            if (s[L] == s[R])
            {
                L++;
                R--;
            }
            else
                return false;
        }
        return true;
    }
};

int main()
{
    string s;
    cin >> s;

    Solution obj;
    cout << obj.validPalindrome(s);
}
