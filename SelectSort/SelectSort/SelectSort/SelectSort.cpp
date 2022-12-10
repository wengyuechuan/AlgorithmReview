#include<iostream>
#include <vector>
using namespace std;
//选择排序
void SelectSort(vector<int> &a)
{
    int temp=0;
    int tempVal=0;
    //这里可以减少一次，因为剩下来的元素一定是最后一个了
    for(int i=0;i<a.size()-1;i++)
    {
        temp=i;
        for(int j=i;j<a.size();j++)
        {
            if(a[j]<a[temp])
            {
                temp=j;
            }
        }
        tempVal=a[i];
        a[i]=a[temp];
        a[temp]=tempVal;
    }
}
int main(int argc, char* argv[])
{
    vector<int> test={3,5,1,23,5,7,8,3};
    SelectSort(test);
    for(auto i:test)
    {
        cout<<i<<" ";
    }
    return 0;
}
