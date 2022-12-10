#include<iostream>
#include <vector>
using namespace std;

/**
 * \brief 合并函数，合并两个数组
 * \param array 数组
 * \param left 最左端点
 * \param middle 中间端点
 * \param right 最右端点
 */
void merge(vector<int> &array,int left,int middle,int right)
{
    int n1=middle-left+1; // 左侧序列的长度
    int n2=right-middle;  // 右侧序列的长度
    
    //两个中间数组
    vector<int> tempLeft;
    vector<int> tempRight;

    for(int i=left;i<=middle;i++)
    {
        tempLeft.push_back(array[i]);
    }
    for(int j=middle+1;j<=right;j++)
    {
        tempRight.push_back(array[j]);
    }

    int indexi=0,indexj=0;
    int i=left;
    for(;i<=right;i++)
    {
        if(indexi == tempLeft.size())
        {
            //左侧的已经到达结尾
            array[i]=tempRight[indexj];
            indexj++;
        }else if(indexj==tempRight.size())
        {
            //右侧已经到达结尾
            array[i]=tempLeft[indexi];
            indexi++;
        }else if(tempLeft[indexi]<=tempRight[indexj])
        {
            array[i]=tempLeft[indexi];
            indexi++;
        }else
        {
            array[i]=tempRight[indexj];
            indexj++;
        }
    }
    
    
}
/**
 * \brief 归并排序
 * \param array 待排序列
 * \param beginLoc 起始排序位置
 * \param endLoc 结束排序位置
 */
void mergeSort(vector<int> &array,int beginLoc,int endLoc)
{
    if (beginLoc < endLoc)
    {
        int middle=beginLoc+(endLoc-beginLoc)/2;

        //将待排序列分割成两个部分，然后递归调用
        mergeSort(array,beginLoc,middle);
        mergeSort(array,middle+1,endLoc);

        //合并
        merge(array,beginLoc,middle,endLoc);
    }
}

int main(int argc, char* argv[])
{
    vector<int> test={2,3,5,3,1,5,6,7,2,1,3,5,6,2,1,4};
    mergeSort(test,0,test.size()-1);

    for(auto i : test)
    {
        cout<<i<<" ";
    }

    cout<<endl;
    return 0;
}
