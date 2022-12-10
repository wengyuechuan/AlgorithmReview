#include<iostream>
#include <vector>
using namespace std;

void InsertSort(vector<int> &array)
{
    int temp=0;
    
    /*
     * 第一层循环，先选择待排的数字
     * 第二层循环，已经排好序的序列
     */
    for(int i=1;i<array.size();i++)
    {
        int Comparecount=0;
        temp=array[i];
        int j;
        for(j=i-1;j>=0;j--)
        {
            if(temp<array[j])
            {
                //向后覆盖
                array[j+1]=array[j];
                Comparecount++;
            }else
            {
                break;
            }
        }
        cout<<i<<" Compare count:"<<Comparecount<<endl;
        array[j+1]=temp;//完成了排序
    }
}

int main(int argc, char* argv[])
{
    vector<int> test={9,8,7,6,5,4,3,2,1,0};
    InsertSort(test);
    for(auto i : test)
    {
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}
