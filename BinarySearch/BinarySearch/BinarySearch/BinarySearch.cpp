#include<iostream>
#include <vector>
using namespace std;
int BinarySearch(const vector<int> array,const int x)
{
    int left=0;
    int right=array.size()-1;
    int middle=0;
    
    //循环条件使用等于
    while(left<=right)
    {
        middle=left+(right-left)/2;

        if(array[middle]==x)
        {
            return middle;
        }else if(array[middle]>x)
        {
            left=middle+1;
        }else
        {
            //因为此时区间包含了右侧节点，所以说，如果我们不在中点存在的话，那么就直接向左侧一个单位寻找就好
            right=middle-1;
        }
    }
    return -1;
}
//递归写法
int BinarySearchRecurtion(const vector<int> array,int left,int right,int x)
{
    int middle=left+(right-left)/2;
    //此时没有找到
    if(left>right || right >= 10 || left<0)
    {
        return -1;
    }
    
    if(array[middle]>x)
    {
        return BinarySearchRecurtion(array,left,middle-1,x);
    }else if(array[middle]<x)
    {
        return BinarySearchRecurtion(array,middle+1,right,x);
    }else if(array[middle]==x)
    {
        return middle;
    }
}
int main(int argc, char* argv[])
{
    const vector<int> test={1,2,3,4,5,6,7,12,34,56};

    const int result=BinarySearch(test,5);
    const int result1=BinarySearch(test,11);

    const int result2=BinarySearchRecurtion(test,0,test.size()-1,5);
    int result3;
    result3=BinarySearchRecurtion(test,0,test.size()-1,100);
    cout<<result<<endl;
    cout<<result1<<endl;

    cout<<result2<<endl;
    cout<<result3<<endl;
    return 0;
}
