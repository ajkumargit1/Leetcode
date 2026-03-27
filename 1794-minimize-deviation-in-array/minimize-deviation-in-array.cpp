class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
         priority_queue<int> pq; 
        int mini = INT_MAX;
        int res= INT_MAX;

        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                pq.push(nums[i]);
                mini = min(mini,nums[i]);
            }
            else{
                pq.push(nums[i]*2);
                mini = min(mini,nums[i]*2);
            }
        }
        while(!pq.empty()){
            int upar = pq.top();
            pq.pop();
            res = min(res,upar-mini);
            if(upar%2!=0){
                break;
            }
            mini = min(mini,upar/2);
            pq.push(upar/2);
        }
        return res;
    }
};