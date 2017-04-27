#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int dp[1003][1003],s[1003][1003];
/*之所以声明两个数组dp和s，是因为我们
通过动态规划所能优化的最优解dp只能是含
有特定的一个数的结果（即dp数组所求出来
的是包含那个数的最优解），但是我们所需
要的最终的结果并不一定要包含这个数，所
以才另外开一个数组s来求取了i列j行时的最优解*/
struct node{
    int A,B;
}h[1003];

bool cmp(node a,node b){
    return a.B > b.B;
}

int main()
{
    int N,M;
    scanf("%d%d",&N,&M);
    for(int i = 1;i <= N;i++){
        scanf("%d",&h[i].A);
    }
    for(int i = 1;i <= N;i++){
        scanf("%d",&h[i].B);
    }
    sort(h + 1,h + N + 1,cmp);
    //先做预处理，按照B的大小排序
    for(int i  = 0;i < N;i++){
            s[0][i] = 0;
    }
    for(int i  = 0;i < N;i++){
            s[i][0] = 0;
    }
    //对记录最大值的数组初始化
    for(int i  = 1;i <= M;i++){
        for(int j = 1;j <= N;j++){//先按照行，再按照列来遍历，便于处理
            dp[i][j] = s[i -1][j - 1] + max(0,h[j].A - (i - 1) * h[j].B);
            /*dp[i][j]表示取i列j行这个数字时的解，
            由于有每行每列取不超过一个数的限制，所
            以在取i列j行之前一定是取i-1列j-1行的数
            字才能保证最优解，这个位置*/
            s[i][j] = max(s[i][j - 1],dp[i][j]);
            /*但是对于求取i列j行的最优解，我们必须
            将那一行最优情况求出，但是又由于在某一
            行式子保持递减，所以我们需要考虑来做比
            较的可能是最优解的只有i列j-1行的数字，
            所以将s[i][j - 1]与dp[i][j]求一个最大值
            即可*/
        }
    }
    int sum = 0;
    for(int i = 1;i <= M;i++) sum = max(sum,s[i][N]);
    /*因为有上面dp过程的预处理，所以s[i][n]都是取了那
    第i列的最优解，所以直接考虑最后一行，求最大值即可*/
    printf("%d\n",sum);
    return 0;
}
