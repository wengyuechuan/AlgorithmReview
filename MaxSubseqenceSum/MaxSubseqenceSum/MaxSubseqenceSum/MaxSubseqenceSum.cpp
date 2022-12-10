/*
 * 最大字段和
 */
#include<iostream>
#include <vector>
using namespace std;

//枚举方法来实现算法
//时间复杂度O(n**3)
int MaxSubsequenceSum_1(const vector<int> a)
{
    int ThisSum,MaxSum;
    MaxSum=0;

    for(int i=0;i<a.size();i++)
    {
        for(int j=i;j<a.size();j++)
        {
            ThisSum=0;
            for(int k=i;k<=j;k++)
            {
                ThisSum+=a[k];
            }
            if(ThisSum>MaxSum)
            {
                MaxSum=ThisSum;
            }
        }
    }
    return MaxSum;
}

//不回头的算法，在循环的过程中计算结果
//时间复杂度O(n**2)
int MaxSubsequenceSum_2(const vector<int> a)
{
    int ThisSum,MaxSum;
    MaxSum=0;
    for(int i=0;i<a.size();i++)
    {
        ThisSum=0;
        for(int j=i;j<a.size();j++)
        {
            ThisSum+=a[j];
            if(ThisSum>MaxSum)
            {
                MaxSum=ThisSum;
            }
        }
    }
    return MaxSum;
}

//分治法
//后面分治法的篇章再返回来接着写
int MaxSubsequenceSum_3(const vector<int> a)
{
    
    return 0;
}

//一种线性检索的思路
int MaxSubsequenceSum_4(const vector<int> a)
{
    int ThisSum,MaxSum;
    ThisSum=0;
    MaxSum=0;

    for(int i=0;i<a.size();i++)
    {
        ThisSum+=a[i];
        if(ThisSum>MaxSum)
        {
            MaxSum=ThisSum;
        }else if(ThisSum<0)
        {
            ThisSum=0;
        }
    }
    return MaxSum;
}
int main(int argc, char* argv[])
{
    vector<int> test={-2,11,-4,13,-5,-2};
    int result_1=MaxSubsequenceSum_1(test);
    int result_2=MaxSubsequenceSum_2(test);
    int result_3=MaxSubsequenceSum_3(test);
    int result_4=MaxSubsequenceSum_4(test);
    cout<<result_1<<endl;
    cout<<result_2<<endl;
    cout<<result_3<<endl;
    cout<<result_4<<endl;
    return 0;
}
