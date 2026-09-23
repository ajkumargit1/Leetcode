class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int n=rectangles.size();
        unordered_set<string>corners;
        int minX=INT_MAX,minY=INT_MAX;
        int maxX=INT_MIN,maxY=INT_MIN;

        long long running_area=0;
        for(const auto &rect:rectangles){
            int x1=rect[0],y1=rect[1];
            int x2=rect[2],y2=rect[3];
            running_area+=1LL*(x2-x1)*(y2-y1);

            minX=min(minX,x1);
            minY=min(minY,y1);
            maxX=max(maxX,x2);
            maxY=max(maxY,y2);

            //new_co-ord
            string c1=to_string(x1)+","+to_string(y1);
            string c2=to_string(x2)+","+to_string(y1);
            string c3=to_string(x1)+","+to_string(y2);
            string c4=to_string(x2)+","+to_string(y2);

            string arr[]={c1,c2,c3,c4};
            for(auto it:arr)
            {
                if(!corners.count(it)){
                    corners.insert(it);
                }
                else corners.erase(it);
            }
        }
        if(corners.size()!=4) return false;

        string expected_c1 = to_string(minX) + "," + to_string(minY);
        string expected_c2 = to_string(minX) + "," + to_string(maxY);
        string expected_c3 = to_string(maxX) + "," + to_string(minY);
        string expected_c4 = to_string(maxX) + "," + to_string(maxY);

        if (!corners.count(expected_c1) || !corners.count(expected_c2) ||
            !corners.count(expected_c3) || !corners.count(expected_c4)) {
            return false;
        }

        long long boundingArea = (long long)(maxX - minX) * (maxY - minY);
        
        return running_area == boundingArea;
    }
};