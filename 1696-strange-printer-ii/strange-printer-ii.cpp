class Solution {
public:
    bool isPrintable(vector<vector<int>>& targetGrid) {
        int rows=targetGrid.size();
        int cols=targetGrid[0].size();
        const int max_col=61;

        vector<int>top(max_col,rows),bottom(max_col,-1),
        left(max_col,cols),right(max_col,-1);
        vector<bool>seen(max_col,false);
        int col_cnt=0;

        for(int i=0;i<rows;i++)
        {
            for(int j=0;j<cols;j++)
            {
                int color=targetGrid[i][j];
                if(!seen[color]){
                    seen[color]=true;
                    col_cnt++;
                }
                top[color]=min(top[color],i);
                bottom[color]=max(bottom[color],i);
                left[color]=min(left[color],j);
                right[color]=max(right[color],j);
            }
        }

        vector<vector<bool>>adj(max_col,vector<bool>(max_col,false));
        vector<int>indegree(max_col,0);

        for(int clr=1;clr<max_col;clr++)
        {
            if(!seen[clr]) continue;

            for(int r=top[clr];r<=bottom[clr];r++)
            {
                for(int c=left[clr];c<=right[clr];c++)
                {
                    int over_color=targetGrid[r][c];
                    if(over_color!=clr && !adj[clr][over_color])
                    {
                        adj[clr][over_color]=true;
                        indegree[over_color]++;
                    }
                }
            }
        }

        queue<int>q;
        for(int i=1;i<max_col;i++)
        {
            if(seen[i] && indegree[i]==0) q.push(i);
        }
        int printed=0;

        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            printed++;

            for(int next=1;next<max_col;next++)
            {
                if(adj[curr][next])
                {
                    indegree[next]--;
                    if(indegree[next]==0)
                    q.push(next);
                }
            }
        }

        return  printed==col_cnt;
    }
};