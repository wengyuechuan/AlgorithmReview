#include<iostream>
#include <vector>
using namespace std;
#define NUMBER 5

//用于存储维度的数组
vector<int> p(NUMBER,0);
int s[NUMBER+1][NUMBER+1];
//递归方法实现矩阵连乘
//注意这里i是从1开始的，那么也就认为p[i]是矩阵i的第二维，第一维是p[i-1]
int recurMatrixChain(int i,int j)
{
    if(i==j) return 0;
    int u=recurMatrixChain(i,i)+recurMatrixChain(i+1,j)+p[i-1]*p[i]*p[j];
    
    for(int k=i+1;k<j;k++)
    {
        int tmp=recurMatrixChain(i,k)+recurMatrixChain(k+1,j)+p[i-1]*p[k]*p[j];
        if(tmp<u)
        {
            u=tmp;
            s[i][j]=k;
        }
    }
    return u;
}

//利用动态规划的思路进行求解
//这个也需要重新复习一下
int MatrixChain()
{
    int dp[NUMBER-1][NUMBER-1];
    //初始化dp数组
    for(int i=0;i<NUMBER;i++)
    {
        dp[i][i]=0;
    }
    //确定遍历顺序
    //首先确定有4个点
    //p.size()=5
    //推导这个过程十分的复杂，对于数感特别差的我来说，但是还是想明白了，真的不容易啊
    for(int r=0;r<p.size()-2;r++)
    {
        for(int i=0;i<p.size()-2-r;i++)
        {
            int j=i+r+1;
            dp[i][j]=dp[i+1][j]+p[i]*p[i+1]*p[j+1];
            for(int k=i;k<j;k++)
            {
                int temp=dp[i][k]+dp[k+1][j]+p[i]*p[k+1]*p[j+1];
                if(temp<dp[i][j])
                {
                    dp[i][j]=temp;
                    s[i][j]=k;
                }
            }
        }
    }
    return dp[0][NUMBER-2];
}
int main(int argc, char* argv[])
{
    p={10,100,5,50,30};
    int result=recurMatrixChain(1,4);
    cout<<result<<endl;

    int result_1=MatrixChain();
    cout<<result_1<<endl;
    return 0;
}
