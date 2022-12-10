#include<iostream>
#include <vector>
using namespace std;

/**
 * \brief 进行分段的算法
 * \param array 待排序列
 * \param left 左边界
 * \param right 右侧边界
 * \return 返回分段的点的位置
 */
int Partition(vector<int> &array,int left,int right)
{
    //ppt上给出的算法是i和j全部从0开始向后运行，但是更好的肯定是左侧一个点，右侧一个点，这样比较好。
    int temp=array[left];
    int i=left+1;
    int j=right;
    while(i<=j)
    {
        //保证左侧的一定小于temp
        while(i<=j && array[i]<=temp)
        {
            i++;
        }
        //保证右侧的一定大于等于temp
        while(i<=j && array[j]>=temp)
        {
            j--;
        }
        if(i<j)
        {
            int tmp=array[i];
            array[i]=array[j];
            array[j]=tmp;
            i++;
            j--;
        }
    }
    //一定最后选择的是
    array[left]=array[j];
    array[j]=temp;

    return j;
}
void QuickSort(vector<int> &array, int left,int right)
{
    if(left<right)
    {
        int p=Partition(array,left,right);
        QuickSort(array,left,p-1);
        QuickSort(array,p+1,right);
    }
}
int main(int argc, char* argv[])
{
    vector<int> test={2,3,5,6,2,1,3,5,67,7,3,2,1,3,5,7};

    QuickSort(test,0,test.size()-1);

    for(auto i: test)
    {
        cout<<i<<" ";
    }
    return 0;
}
