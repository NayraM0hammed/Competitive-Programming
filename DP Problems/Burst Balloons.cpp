#define sz(s) (int(s.size()))
#define MemS(s, x) memset(s, x, sizeof(s))
class Solution {
public:
    int dp[303][303];
    int Max_Cost(int st,int ed,vector<int>&v){
        
        if(st > ed)
            return 0;

        if(dp[st][ed]!= -1)
            return dp[st][ed];   

        int op = 0;
        for(int i = st; i <= ed ;i++){
            int cost = v[i] *  v[st-1] * v[ed+1];
            op = max(op,cost + Max_Cost(st, i-1,v) + Max_Cost(i+1, ed, v));
        }

        return dp[st][ed] = op;     
    }
    int maxCoins(vector<int>& nums) {
        MemS(dp,-1);
        nums.insert(nums.begin(),1);
        nums.insert(nums.end(),1);
        return Max_Cost(1,sz(nums)-2,nums);      
    }
};
