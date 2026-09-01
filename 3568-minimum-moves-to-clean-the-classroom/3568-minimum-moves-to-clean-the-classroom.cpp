class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector id(m, vector<int>(n));
        int sx, sy, cnt = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(classroom[i][j] == 'S') {
                    sx = i;
                    sy = j;
                }
                else if(classroom[i][j] == 'L') {
                    id[i][j] = 1 << cnt++;
                }

            }
        }
        vector bestEnergy(m, vector(n, vector<int>(1 << cnt, -1)));
        bestEnergy[sx][sy][0] = energy;
        struct Info {
            int x, y, mask, e, steps;
        };
        queue<Info> q;
        q.push({sx, sy, 0, energy, 0});
        while(!q.empty()) {
            Info t = q.front();
            q.pop();
            if(t.mask == (1 << cnt) - 1) return t.steps;
            if(t.e == 0) continue;
            for(auto [dr, dc] : dir) {
                int nr = t.x + dr;
                int nc = t.y + dc;
                if(nr < 0 || nr >= m || nc < 0 || nc >=n || classroom[nr][nc] == 'X') continue;
                int ne = classroom[nr][nc] == 'R' ? energy : t.e - 1;
                int nmask = t.mask | id[nr][nc];
                if(ne > bestEnergy[nr][nc][nmask]) {
                    bestEnergy[nr][nc][nmask] = ne;
                    q.push({nr, nc, nmask, ne, t.steps+1});
                }
            }
        }
        return -1;
    }
};