class Solution {
public:
    vector<bool> transformStr(string s, vector<string>& strs) {
        int n=s.size();
        vector<int>s0_pos;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            s0_pos.push_back(i);
        }
        int tot0=s0_pos.size();
        int tot1=n-tot0;

        vector<bool>ans;
        for(auto &target:strs)
        {
            int cnt1=0,cnt0=0;
            for(int i=0;i<target.size();i++)
            {
                if(target[i]=='0')
                cnt0++;
                if(target[i]=='1') cnt1++;
            }
            if(cnt1>tot1 || cnt0>tot0)
            {
                ans.push_back(false);
                continue;
            }

            int req0=tot0-cnt0;
            string temp=target;
            int zr_placed=0;
            for(int i=0;i<temp.size();i++)
            {
                if(temp[i]=='?')
                {
                    if(zr_placed<req0)
                    {
                        temp[i]='0';
                        zr_placed++;
                    }
                    else temp[i]='1';
                }
            }

            vector<int>zr_pos;
            for(int i=0;i<n;i++)
            {
                if(temp[i]=='0') zr_pos.push_back(i);
            }

            bool hmm=true;
            for(int i=0;i<s0_pos.size();i++)
            {
                if(s0_pos[i]<zr_pos[i])
                {
                    hmm=false;
                    break;
                }
            }

            ans.push_back(hmm);

        }

        return ans;
    }
};