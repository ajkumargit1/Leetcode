class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n=courses.size();

        sort(courses.begin(),courses.end(),[&](vector<int>&a,vector<int>&b){
            return a[1] < b[1];
        });
        int global_time=0;
        int ans=0;
        priority_queue<int>pq;
        for(auto it:courses)
        {
            int duration=it[0];
            int last_day=it[1];
            global_time+=duration;
            pq.push(duration);
            ans++;

            if(global_time > last_day)
            {
                global_time-=pq.top();
                pq.pop();
                ans--;
            }
        }

        return ans;
    }
};