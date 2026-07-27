class Solution {
private:
    bool check(int i,int j,int n,int m) {
        if(i>=0 && i<n && j>=0 && j<m) return true; 
        return false;
    }
    
    void dfs(int i,int j,vector<vector<char>>& grid, vector<vector<int>>& visited) {
       stack<pair<int,int>>st;
       st.push({i,j});
       int n = grid.size();
       int m = grid[0].size();
       visited[i][j] = true;
       vector<pair<int,int>>dir = {{0,1},{0,-1},{1,0},{-1,0}};
       while(!st.empty()) {
          auto [si,sj] = st.top();
          st.pop();
          for(auto& d: dir) {
            int nr = si + d.first;
            int nc = sj + d.second;
            if(check(nr,nc,n,m) && grid[nr][nc]=='1') {
                if(visited[nr][nc]) continue;
                st.push({nr,nc});
                visited[nr][nc] = true;
            }
          }
       }
       return;
    }


public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
        int ans = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(!visited[i][j] && grid[i][j]=='1') {
                    ans+=1;
                    dfs(i,j,grid,visited);
                }
            }
        }
        return ans;
    }
};
