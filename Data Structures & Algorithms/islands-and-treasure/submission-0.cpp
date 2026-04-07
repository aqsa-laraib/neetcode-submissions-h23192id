class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    q.push({i,j});
                }
            }
        }
        int dx[]={-1,0,1,0};
        int dy[]={0,1,0,-1};
        while(!q.empty()){
            auto front=q.front();
            int i=front.first;
            int j=front.second;
            q.pop();
            for(int d=0;d<4;d++){
                int ni=i+dx[d];
                int nj=j+dy[d];
                if(ni>=0 && ni<n && nj>=0 && nj<m){
                    if(grid[ni][nj]!=-1){
                        if(grid[i][j]+1<grid[ni][nj]){
                            grid[ni][nj]=grid[i][j]+1;
                            q.push({ni,nj});
                        }
                    }
                }
            }
        }
    }
};
