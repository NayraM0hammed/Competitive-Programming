
// leetcode sumbission template
class Solution {
public:
    
    string s="aeiou";
    int dp[50][26];
    
    int Count(int idx,char pre,int sz){
        if(idx==sz)
            return 1;
        
        if(dp[idx][pre-'a'] != -1)
            return dp[idx][pre-'a'];
        
        int val=0;
    
        for(int i=0;i<s.size();i++)
                if(s[i]>=pre)
                    val+=Count(idx+1,s[i],sz);
        
        
        return dp[idx][pre-'a'] = val;
    }
    
    int countVowelStrings(int n) {
    
        memset( dp, -1, sizeof(dp));
        
        int ans=0;
        
        for(int i = 0; i < s.size() ; i++)
            ans += Count(1,s[i],n);
            
            return ans;
    }
    
};
