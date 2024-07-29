// Given a string S, the task is to print all the duplicate characters with their occurrences in the given string.

// Example:

// Input: S = “geeksforgeeks”
// Output:
// e, count = 4
// g, count = 2
// k, count = 2
// s, count = 2

#include <bits/stdc++.h>
using namespace std;

void printDuplicates(string str)
{
    unordered_map<char,int> count;
    for(int i=0;i<str.size();i++)
    {
        count[str[i]]++;
    }

    for(auto &it: count)
    {
        if(it.second>1)
        {
            cout<<"Letter '"<<it.first<<"' appears "<<it.second<<" times."<<endl;
        }
    }
}

int main()
{
    string str = "test string";
    printDuplicates(str);
    return 0;
}