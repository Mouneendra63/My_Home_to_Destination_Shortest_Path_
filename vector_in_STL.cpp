#include<vector>
#include<iostream>
using namespace std;

int main()
{
    vector<int>vec;
    for(int i=0;i<10;i++)
    {
        vec.emplace_back(i);
    }
    for (auto it:vec)
    {
        cout<<it;
    }
}