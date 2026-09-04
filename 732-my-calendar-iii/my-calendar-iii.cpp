class MyCalendarThree {
    map<int,int>mp;
public:
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        mp[startTime]++;
        mp[endTime]--;

        int curr=0;
        int maxi=0;
        for(auto& [time,value] : mp)
        {
            curr+=value;
            maxi=max(maxi,curr);
        }
        return maxi;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(startTime,endTime);
 */