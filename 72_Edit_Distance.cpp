//������������word1,word2���ҵ���word1ת��Ϊword2����Ҫ�����ٲ�������
//����minimal edit distance����������Ϊ��������
//1�� ����һ���ַ�
//2�� ɾ��һ���ַ�
//3�� �滻һ���ַ�
//˼·����̬�滮
//dp(i, j) = min{dp(i-1, j)+1, dp(i, j-1)+1, dp(i-1, j-1)+(word1[i]==word2[j]?0:1)}
//���Ϸֱ��Ӧɾ����������滻����

#define INF 1000000
class Solution {
public:
    int minDistance(string word1, string word2) {
		if(word1.length() == 0)
			return word2.length();
		if(word2.length() == 0)
			return word1.length();
		int len1 = word1.length();
		int len2 = word2.length();
		int **dp = new int*[len1+1];
		for(int i=0; i<=len1; i++)
			dp[i] = new int[len2+1];
		for(int i=0; i<=len1; i++)
			for(int j=0; j<=len2; j++)
				dp[i][j] = INF;
		dp[0][0] = 0;
		for(int i=0; i<=len1; i++) {
			for(int j=0; j<=len2; j++) {
				if(i>0)
					dp[i][j] = min(dp[i-1][j]+1, dp[i][j]);
				if(j>0)
					dp[i][j] = min(dp[i][j-1]+1, dp[i][j]);
				if(i>0 && j>0)
					dp[i][j] = min(dp[i][j], dp[i-1][j-1]+(word1[i-1]==word2[j-1]?0:1));
			}
		}
		return dp[len1][len2];
    }
};