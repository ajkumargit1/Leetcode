class Solution {
public:
    string getPermutation(int n, int k) {
        int fact=1;
        vector<int>nums;
        for(int i=1;i<n;i++)
        {
            fact*=i;
            nums.push_back(i);
        }
        nums.push_back(n);
        k=k-1;
        string res="";
        while(true){

            res=res+to_string(nums[k/fact]);
            nums.erase(nums.begin()+(k/fact));
            if(res.size()==n) break;
            k=k%fact;
            fact=fact/nums.size();
        }

        return res;
    }
};