class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        int skl_sz=req_skills.size();
        int p_size=people.size();
        map<string,int>mp;
        for(int i=0;i<skl_sz;i++)
        {
            mp[req_skills[i]]=i;
        }
        vector<int>p_mask(p_size,0);
        for(int i=0;i<p_size;i++)
        {
            for(int j=0;j<people[i].size();j++)
            {
                p_mask[i]|=(1<<mp[people[i][j]]);
            }
        }
        vector<long long>dp(1<<skl_sz,-1);
        //dp[skill_mask] = team_mask
        //index (skill_mask): A bitmask representing a specific combination of skills.
        //value (team_mask): A long long bitmask representing the smallest possible roster of people needed to cover those exact skills.
        dp[0]=0;

        for(int i=0;i<p_size;i++)
        {
            int ppl_mask=p_mask[i];
            if(ppl_mask==0) continue;

            for(int mask=0;mask<(1<<skl_sz);mask++)
            {
                if(dp[mask]==-1) continue;

                int new_skill_mask=mask|ppl_mask;
                long long new_team_mask=dp[mask]|(1LL<<i);

                if(dp[new_skill_mask]==-1 || __builtin_popcountll(new_team_mask)<__builtin_popcountll(dp[new_skill_mask]))
                dp[new_skill_mask]=new_team_mask;
            }
        }

        //answer constrction 
        long long winner_mask=dp[(1<<skl_sz)-1];
        vector<int>ans;
        for(int i=0;i<p_size;i++)
        {
            if((winner_mask & (1LL<<i)) !=0)
            ans.push_back(i);
        }

        return ans;
    }
};