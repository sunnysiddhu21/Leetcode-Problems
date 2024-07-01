class Solution {
public:
    void solve(int i, vector<vector<int>>& adjL, vector<int>& vis) {
        vis[i] = 1;
        for (auto adj : adjL[i]) {
            if (vis[adj] == -1) {
                solve(adj, adjL, vis);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<vector<int>> adjL(n);

        for (int i = 0; i < n; ++i) {
            for (auto key : rooms[i]) {
                adjL[i].push_back(key);
            }
        }

        vector<int> vis(n, -1);
        solve(0, adjL, vis);

        for (int i = 0; i < n; ++i) {
            if (vis[i] == -1) {
                return false;
            }
        }

        return true;
    }
};
