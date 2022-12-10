#include<iostream>
#include <vector>
using namespace std;

int RandomizedPartition(vector<int> array,int left, int right)
{
    int randomNum=rand()%(right-left+1)+left; //设置随机数
    
    int temp=array[randomNum];//当前被选择的变量

    int i=left,j=right;

    int tmp;

    while(i<=j)
    {
        while(i<=j && array[i]<=temp)
        {
            i++;
        }
        while(i<=j && array[j]>=temp)
        {
            j--;
        }

        if(i<j)
        {
            tmp=array[i];
            array[i]=array[j];
            array[j]=tmp;

            i++;
            j--;
        }
    }
    array[randomNum]=array[j];
    array[j]=temp;
    return j;
}

/**
 * \brief 寻找第k小的元素的值
 * \param array 待寻数组
 * \param left 左侧的点
 * \param right 右侧的点
 * \param k 需要寻找的第k小的元素
 * \return 返回第k小的元素的值
 */
int SearchTheNLeastElement(vector<int> array,int left,int right,int k)
{
    if(right==left) return array[left];

    int tmp=RandomizedPartition(array,left,right);

    int index=tmp-left+1; //这个是有多少个值
    //这里注意和快排不一样的是我们这里右边界是tmp
    if(k<=index) return SearchTheNLeastElement(array,left,tmp,k);
    else
    {
        return SearchTheNLeastElement(array,tmp+1,right,k-index);
    }
    
}
int main(int argc, char* argv[])
{
    vector<int> array={1,2,3,4,5,6,7,8,9,10};
    int result=SearchTheNLeastElement(array,0,array.size()-1,4);

    cout<<result<<endl;
    return 0;
}
