/*
 * 线性时间选择，相对于原本的算法的优化
 */
#include <algorithm>
#include<iostream>
#include <vector>
using namespace std;
/**
 * \brief 根据数据x进行划分，返回x在数组中的位置
 * \param array 待寻序列
 * \param left 区间最左侧
 * \param right 区间最右侧
 * \param x 待查元素
 * \return 返回x在数组中的位置
 */
int Partition(vector<int> array,int left,int right,int x)
{
    //和第一个位置交换
    for(int i=left;i<=right;i++)
    {
        if(array[i]==x)
        {
            swap(array[left],array[i]);
            break;
        }
    }

    int i=left+1;
    int j=right;

    while(i<=j)
    {
        while(i<=j && array[i]<=x)
        {
            i++;
        }
        while(i<=j && array[j]>=x)
        {
            j--;
        }
        if(i<j)
        {
            swap(array[i],array[j]);
        }
    }
    swap(array[left],array[j]);
    return j;
}

int Select(vector<int> array,int left,int right,int k)
{
    //当数量小于75的情况，则直接排序返回我们需要的值
    if(right-left<75)
    {
        sort(array.begin()+left,array.begin()+right+1);

        return array[left+k-1];
    }

    //当数量大于75的情况，则采用每5个一排序，然后再进行排序
    for(int i=0;i<(right-left-4)/5;i++)
    {
        //每5个一组进行排序
        sort(array.begin()+left+5*i,array.begin()+left+5*i+5);

        //将中位数换到前面几位
        swap(array[left+i],array[left+i*5+2]);
    }

    //继续求他们的中位数
    int x=Select(array,left,left+(right-left-4)/5,(right-left-4)/(5*2)+1);

    //根据这个中位数继续做划分
    int r=Partition(array,left,right,x);

    //判断当前的res在第几个位置
    int res=r-left+1;

    if(res>k)
    {
        return Select(array,left,r-1,k);
    }else
    {
        return Select(array,r+1,right,k-res);
    }
}
vector<int> test;
int main(){

    srand((int)time(0));
    int index=0;

    while(index<100000)
    {
        int num=rand() % RAND_MAX * (rand() % 100); //生成大随机数
        test.push_back(num);
        index++;
    }
    
    cout<<endl<<endl;
    cout<<"第 66666 小的元素为 "<<Select(test,0,99999,66666)<<endl;

    return 0;
}
