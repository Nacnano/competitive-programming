class Solution {
public:
    int cnt[255];
    string customSortString(string order, string s) {

        string answer="";
        for(int i=0;s[i];i++) cnt[s[i]]++;
        for(int i=0;order[i];i++)
        {
            while(cnt[order[i]]>0)
            {
                answer+=order[i];
                cnt[order[i]]-=1;
            }
        }
        for(int i=0;s[i] && !cnt[s[i]];i++) answer+=s[i];
        
        return answer;
    }
};
