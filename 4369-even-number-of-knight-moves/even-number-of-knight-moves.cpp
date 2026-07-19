class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        return abs((target[1]-target[0])-(start[1]-start[0]))%2==0;
    }
};