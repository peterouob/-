//
// Created by 林庭楷 on 2024/9/3.
//
#include "iostream"
#include "map"
int T;
using namespace std;
int main()
{
    cin >> T;
    while (T--)
    {
        string s;
        cin >> s;
        map<char, int> mp;
        for (auto x : s)
        {
            mp[x]++;
        }
        if (mp['A'] > mp['B'])
            puts("A");
        else
            puts("B");
    }
}