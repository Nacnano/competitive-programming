class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int l=1, r=1;
        vector<int> answer ((int)nums.size(),1);
        for(int i=0;i<(int)nums.size();i++)
        {
            answer[i]*=l;
            l*=nums[i];
            answer[(int)nums.size()-1-i]*=r;
            r*=nums[(int)nums.size()-1-i];
        }
        return answer;
    }
};
