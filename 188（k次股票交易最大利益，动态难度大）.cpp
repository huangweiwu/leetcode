#include<iostream>
#include<sstream>
#include<vector>
#include<set>
#include<string>
#include<string.h>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<stdarg.h>
#include<queue>
#include <stdint.h>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

// 给定一组股票的价格，最多进行k次买卖，求最大利润
//	思路：动态规划
//		如果k >= len / 2，则直接用贪心算法即可
//		如果k < len / 2，则用动态规划
//		用currentProfit保存相邻两个结点能获取的利润，runningProfit保存从结点j到i的最大利润，preMaxPorfit保存上一轮到结点i-1的最大利润
//			maxProfitSoFar保存第m轮中每个到点i，最多交易m次所能获得的最大利润
//			如果runningProfit + currentProfit > preMaxProfit，则更新runningProfit，否则runningProfit = preMaxProfit
//			并将ruuningProfit与maxProfitSoFar[i-1]来更新maxProfitSoFar[i]
//			记住在更新maxProfitSoFar之前先保存preMaxProfit

int maxProfit(int k, vector<int>& prices) {
    int len = prices.size();
    if (len < 2) return 0;

    int maxProfit = 0;

    //simple case where we just need to find the maximum climb in prices among all the pairs
    if (k >= len / 2)
    {
        for (int i = 1; i < len; i++)
        {
            maxProfit += max(0, prices[i] - prices[i-1]);
        }
        return maxProfit;
    }

    //Dynamic Programming case where we need to maximize our profit

    //keeps track of maximum profit so far at each index. On any index 'i' the value is max profit that we gained
    //by dealing stock that came before 'i'. After any 'm' iterations, this array holds max profit on index 'i' if we had
    //only 'i' stock values and 'm' possible deals.
    vector<int> maxProfitSoFar(len+1, 0); 

    //calculates the difference between the very current and previous stock price
    int currentProfit = 0;

    //keeps track of our current balance.
    int runningProfit = 0;

    //it backs up the value of max profit after doing 'm-1' deals until index 'i' before updating it to 
    //the value of doing 'm' deals until index i.
    int prevMaxProfit = 0;

    //k iterations for k deals - after each round mapxProfitSoFar holds the max profit for 'j' possible deals
    for (int j = 0; j < k; j++)
    {
        //resetting our balance for new iteration
        runningProfit = 0;

        //initializing with the last max profit we are going to start the next iteration with indexes after this.
        prevMaxProfit = maxProfitSoFar[j]; 

        //we don't need to start from the beginning eveytime since we would face "the simple case" (above) and the profit 
        //is already calculated. It means that number of deals is greater than the 'len'
        for (int i = j+1; i < len; i++)
        {
            //	what is the immediate different of the current two prices.
            currentProfit = prices[i] - prices[i-1];

            //is it better to do this deal? or should we stick to what we did with one less deal and see what future holds!
			//	要么runningProfit = runningProfit + currentProfit，则在第m轮中比第m-1轮多交易了一次
			//	要么runningProfit = preMaxProfit，则在第m轮中依旧交易了m-1次
            runningProfit = max(runningProfit + currentProfit, prevMaxProfit); 

            //	backing up max value with one less deal to compare in the next round
            prevMaxProfit = maxProfitSoFar[i]; 

            //	updating max profit so far by asking if we gained more profit with last deal or we didn't gain anything more
            maxProfitSoFar[i] = max(runningProfit, maxProfitSoFar[i-1]); 
        }
    }

    //well the last item in the MaxProfitSoFar after k iterations holds max profit of 'k' deals of 'len' items.
    return maxProfitSoFar[len-1];
}

int main() {
	//Solution so;
	
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);

	

	TreeNode* head1 = new TreeNode(1);
	//head1->left = new TreeNode(2);
	head1->left = new TreeNode(2);
	head1->left->left = new TreeNode(2);
	
	TreeLinkNode* root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	int a[6] = {3, 2, 6, 5, 0, 3};
	vector<int> v(a, a+6);
	cout << maxProfit(2, v);
	
	system("pause");
	return 0;
}