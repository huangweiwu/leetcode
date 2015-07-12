#include<iostream>
#include<vector>
using namespace std;

#define MAX 100000000
bool v[MAX];

class Solution {
public:
    int countPrimes(int n) {
		int count = 0;
		for(int i=0; i<n; i++)
			v[i] = true;
		for(int i=2; i<n; i++) {
			if(v[i]) {
				count++;
				if(i < sqrt(n)) {
				for(int j=i*i; j<n; j+=i) {
					v[j] = 0;
				}
			}
			}
		}
		return count;
    }
};

int main() {
	Solution so;
	cout << so.countPrimes(499979) << endl;

	system("pause");
	return 0;
}