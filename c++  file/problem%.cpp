
#include <bits/stdc++.h>
using namespace std;
char a[1005][1005];
bool vis[1005][1005];
vector<pair<int,int>>d ={{-1,0},{0,1},{1,0},{0,-1}};
int n,m;
bool valid(int i,int j){
    if(i<0 || i>=n || j<0|| j>=m)
    {
        return false;
    }
    if(a[i][j] !='.')
    {
        return false;
    }
    if (vis[i][j]){
        return false;
    }
    return true;
}
void bfs(int si,int sj,int &r_count) {
    queue<pair<int,int>>q;
    q.push({si,sj});
    vis[si][sj]=true;

    while(!q.empty()) {
        int ci=q.front().first;
        int cj=q.front().second;
        q.pop();
        r_count++;

        for(int i=0;i<4;i++){
            int ni=ci+d[i].first;
            int nj=cj+d[i].second;
           if (valid(ni, nj)){
                vis[ni][nj]=true;
                q.push({ni,nj});
            }
        }
    }
}

int main() {
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        cin>>a[i][j];
        }
    }

    vector<int>r_sizes;

    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            if(a[i][j]=='.' && !vis[i][j]){
                
                int r_count = 0;
                bfs(i, j,r_count);
                r_sizes.push_back(r_count);
            }
        }
    }

    if (r_sizes.empty()) {
        cout<< 0 <<endl;
    } else {
        sort(r_sizes.begin(), r_sizes.end());
        for (int size : r_sizes){
            cout<<size<< " ";
        }
        cout<<endl;
    }
    return 0;
}

