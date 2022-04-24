class Solution {
public:
    int maxProfit(vector<int>& prices){
        
        int last=1e9, ret=0;
        for(auto x:prices)
        {
            if(last!=1e9) ret=max(ret,x-last);
            if(x<last) last=x;
        }
        return ret;
    }
};
