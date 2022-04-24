class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> odd, even, answer;
        for(auto x: nums)
        {
            if(x%2) odd.push_back(x);
            else even.push_back(x);
        }
        int it1=0, it2=0;
        for(int i=0;i<(int)nums.size();i++)
        {
            if(i%2) answer.push_back(odd[it1++]);
            else answer.push_back(even[it2++]);
        }
        
        return answer;
    }
};
