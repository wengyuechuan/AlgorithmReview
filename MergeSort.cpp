#include <algorithm>
#include<iostream>
#include<fstream>
#include <sstream>
#include<string>
using namespace std;
/**
 * \brief 打印结果
 * \param a 数组
 * \param len 数组长度
 */
void PrintResult(int *a,int len);

/**
 * \brief 归并排序
 * \param a 需要进行排序的数组
 * \param len 数组的长度
*/
void MergeSort(int *a,int len);

/**
 * \brief 将左右两个部分进行归并
 * \param a 需要归并的数组
 * \param left 左值
 * \param mid 中值
 * \param right 右值
 */
void Merge(int *a,int left,int mid,int right);

int main(int argc, char* argv[])
{
    ifstream infile("mergesort.in");
    if(!infile)
    {
        cout<<"file open error!"<<endl;
        return 0;
    }
    string s;//读入数据使用的
    getline(infile,s);
    int N=0;//这里是长度
    istringstream string_to_num(s);
    string_to_num>>N;//输出成功

    int *a =new int[N]; //分配堆区内存

    getline(infile,s);
    istringstream string_to_num2(s);//定义一个文件输入流
    for(int i=0;i<N;i++)
    {
        string_to_num2>>a[i];//这里进行输出
    }
    MergeSort(a,N);
    ofstream outfile("mergesort.out");
    for (int k=0;k<N;k++)
    {
        outfile<<a[k]<<" ";
    }
    outfile.close();
    infile.close();
    delete a;
    return 0;
}

void PrintResult(int *a,int len)
{
    for(int i=0;i<len;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void MergeSort(int *a,int len)
{
    if(!a)
    {
        return;//当a为空的时候，直接结束
    }

    //需要设置每次进行的跨度 也就是步长
    int step=1;
    while(step<len)
    {
        //这里每次以2倍的步长来跳步
        for(int i=0;i<len;i+=2*step)
        {
            int left=i;
            int middle=left+step-1;//这里可以认为是中值 或者是可以为 (right-left)/2+left 这里的作用其实是防止溢出
            if(middle>=len-1)
            {
                break;
            }
            int right=left+2*step-1;
            if(right>=len-1)
            {
                right=len-1;
            }
            Merge(a,left,middle,right);
        }
        step*=2;//让步长乘2完成任务
    }
}
void Merge(int *a,int left,int mid,int right)
{
    int *temp=new int[right-left+1];
    int l=left;
    int m=mid+1;
    int i=0;

    while(l<=mid && m<=right)
    {
        if(a[l]<a[m])
        {
            temp[i]=a[l];
            l++;
        }else
        {
            temp[i]=a[m];
            m++;
        }
        i++;
    }
    
    while(l<=mid)
    {
        temp[i]=a[l];
        l++;
        i++;
    }
    while(m<=right)
    {
        temp[i]=a[m];
        m++;
        i++;
    }

    for(int j=0;j<right-left+1;j++)
    {
        a[left+j]=temp[j];
    }
    delete temp;
}