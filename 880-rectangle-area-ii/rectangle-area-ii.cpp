class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        long long MOD = 1e9 + 7;
        
        vector<int> x_coords;
        for (auto& rect : rectangles) {
            x_coords.push_back(rect[0]); 
            x_coords.push_back(rect[2]); 
        }
        sort(x_coords.begin(), x_coords.end());
        
        long long total_area = 0;
    
        for (int i = 0; i < x_coords.size() - 1; i++) {
            int x_curr = x_coords[i];
            int x_next = x_coords[i+1];
            
            long long width = x_next - x_curr;
            
            if (width == 0) continue; 

            vector<pair<int, int>> active_y_ranges;
            for (auto& rect : rectangles) {
                if (rect[0] <= x_curr && rect[2] >= x_next) {
                    active_y_ranges.push_back({rect[1], rect[3]});
                }
            }
            
            sort(active_y_ranges.begin(), active_y_ranges.end());
            
            long long true_height = 0;
            long long current_bottom = -1;
            long long current_top = -1;
            
            for (auto& y_range : active_y_ranges) {
                long long y1 = y_range.first;
                long long y2 = y_range.second;
                
                if (current_bottom == -1) {
                    current_bottom = y1;
                    current_top = y2;
                } 
                else if (y1 <= current_top) {
                    current_top = max(current_top, y2);
                } 
                else {
                    true_height += (current_top - current_bottom);
                    current_bottom = y1;
                    current_top = y2;
                }
            }
            
            if (current_bottom != -1) {
                true_height += (current_top - current_bottom);
            }

            long long strip_area = (width * true_height) % MOD;
            total_area = (total_area + strip_area) % MOD;
        }
        
        return total_area;
    }
};