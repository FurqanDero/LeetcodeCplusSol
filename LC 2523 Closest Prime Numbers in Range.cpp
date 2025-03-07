//Given two positive integers left and right, find the two integers num1 and num2 such that:

//left <= num1 < num2 <= right .
//Both num1 and num2 are prime numbers.
//num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
//Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].
//Example 1:

//Input: left = 10, right = 19
//Output: [11,13]
//Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
//The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
//Since 11 is smaller than 17, we return the first pair.
//Example 2:

//Input: left = 4, right = 6
//Output: [-1,-1]
//Explanation: There exists only one prime number in the given range, so the conditions cannot be satisfied.
// Constraints:

//1 <= left <= right <= 106
//Answer
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        int cnt=0;
        bool st[right+1];
        memset (st,0,sizeof st);
        int prime[right+1];
        for (int i=2;i<=right;++i){
            if (!st[i]){
                prime [cnt++]=i;
            }
            for (int j=0;prime[j]<=right/i;++j){
                st[prime[j]*i]=true;
                if(i%prime[j]==0){
                    break;
                }
            }
        }
        int i=-1, j=-1;
        for (int k=0;k<cnt;++k){
            if(prime[k]>= left && prime[k]<=right){
                if(i==-1){
                    i=k;
                }
                j=k;
            }
        }
        vector<int> ans={-1,-1};
        if(i==j || i==-1) return ans;
        int mi=1<<30;
        for (int k=i;k<j;++k){
            int d=prime[k+1]-prime[k];
            if (d<mi){
                mi=d;
                ans[0]=prime[k];
                ans[1]=prime[k+1];
            }
        }
        return ans;
    }
};
