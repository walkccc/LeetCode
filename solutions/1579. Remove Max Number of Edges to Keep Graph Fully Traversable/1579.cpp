class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        
        vector<int> rootA(n + 1);
        vector<int> rootB(n + 1);
        for (int i = 1; i <= n; i++) {
            rootA[i] = i;
            rootB[i] = i;
        }

        int res = 0;
        int aliceEdges = 0;
        int bobEdges = 0;

        
        for (auto& edge : edges) {
            if (edge[0] == 3) {
                if (uni(edge[1], edge[2], rootA)) {
                    aliceEdges++;
                    if (uni(edge[1], edge[2], rootB)) {
                        bobEdges++;
                    }
                } else {
                    res++;
                }
            }
        }

        vector<int> rootA_copy = rootA;

        
        for (auto& edge : edges) {
            if (edge[0] == 1) {
                if (uni(edge[1], edge[2], rootA)) {
                    aliceEdges++;
                } else {
                    res++;
                }
            }
        }

        
        rootA = rootA_copy;
        for (auto& edge : edges) {
            if (edge[0] == 2) {
                if (uni(edge[1], edge[2], rootB)) {
                    bobEdges++;
                } else {
                    res++;
                }
            }
        }

        return (aliceEdges == bobEdges && aliceEdges == n - 1) ? res : -1;
    }

    bool uni(int a, int b, vector<int>& root) {
        int rootA = find(a, root);
        int rootB = find(b, root);
        if (rootA == rootB) {
            return false;
        }
        root[rootA] = rootB;
        return true;
    }

    int find(int a, vector<int>& root) {
        if (root[a] != a) {
            root[a] = find(root[a], root);
        }
        return root[a];
    }
};