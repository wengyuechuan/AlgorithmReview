/*
 * 最长公共子序列问题，因为这里有套用的leetcode模板，所以这里也涌过来
 * 参考：
 * 1.代码随想录：https://www.programmercarl.com/1143.%E6%9C%80%E9%95%BF%E5%85%AC%E5%85%B1%E5%AD%90%E5%BA%8F%E5%88%97.html#%E6%80%9D%E8%B7%AF
 * 2.b站某位大神的讲解:https://www.bilibili.com/video/BV1S3411e7C8/?spm_id_from=333.337.search-card.all.click&vd_source=b7e534bd93c0324ad6556e779ede5f5e
 * 3.leetcode链接:https://leetcode.cn/problems/longest-common-subsequence/
 */

#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
        for(int i=1;i<=text1.size();i++)
        {
            for(int j=1;j<=text2.size();j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    dp[i][j]=dp[i-1][j-1]+1;
                }else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[text1.size()][text2.size()];//得到结果
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    string test1="abcde";
    string test2="ace";

    int result=s.longestCommonSubsequence(test1,test2);

    cout<<result;
    return 0;
}
