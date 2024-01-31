class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        
        if(grid[0][0]==1)
            return -1;
            
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        q.push({{0,0},1});
        grid[0][0]=1;
        vector<int>drow={-1,-1,0,1,1,1,0,-1};
        vector<int>dcol={0,1,1,1,0,-1,-1,-1};
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                int r=q.front().first.first;
                int c=q.front().first.second;
                int dis=q.front().second;
                q.pop();
                if(r==m-1 && c==n-1)
                    return dis;
                for(int i=0;i<8;i++){
                    int nr=r+drow[i];
                    int nc=c+dcol[i];
                    if(nr>=0 && nr<m&& nc>=0 && nc<n && grid[nr][nc]==0){
                        q.push({{nr,nc},dis+1});
                        grid[nr][nc]=1;
                    }
                }
                
            }
        }
        return -1;
    }
};