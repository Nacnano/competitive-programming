class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l=0, r=(int)nums.size()-1;
        vector<int> answer;
        while(l<=r)
        {
            if(abs(nums[l])>abs(nums[r])) answer.push_back(nums[l]*nums[l++]);
            else answer.push_back(nums[r]*nums[r--]);
        }
        reverse(answer.begin(),answer.end());
        return answer;
    }
};
