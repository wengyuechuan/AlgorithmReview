#include<iostream>
#include <vector>
using namespace std;

/**
 * \brief 最优三角形路径问题
 * \param triangle 三角形数组
 * \return 最优值
 */
int BestTriangleTrial(vector<vector<int>> triangle)
{
    int length=triangle.size();
    //dp数组
    vector<vector<int>> dp(length,vector<int>(length,0));

    dp[0][0]=triangle[0][0];
    //第一层循环表示层数
    for(int i=2;i<=length;i++)
    {
        dp[i-1][0]=dp[i-2][0]+triangle[i-1][0];
        dp[i-1][triangle[i-1].size()-1]=dp[i-2][triangle[i-2].size()-1]+triangle[i-1][triangle[i-1].size()-1];
        for(int j=1;j<i-1;j++)
        {
            dp[i-1][j]=min(dp[i-2][j-1]+triangle[i-1][j],dp[i-2][j]+triangle[i-1][j]);
        }
    }

    int min=dp[length-1][0];
    for(int i=1;i<triangle.size();i++)
    {
        if(dp[length-1][i]<min)
        {
            min=dp[length-1][i];
        }
    }
    return min;
}
int main(int argc, char* argv[])
{
    vector<vector<int>> test={{2},{6,2},{1,8,4},{1,5,6,8}};
    int result=BestTriangleTrial(test);
    cout<<result;
    return 0;
}
