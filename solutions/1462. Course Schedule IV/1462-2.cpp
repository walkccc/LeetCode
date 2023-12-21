class Solution {
 public:
  vector<bool> checkIfPrerequisite(int numCourses,
                                   vector<vector<int>>& prerequisites,
                                   vector<vector<int>>& queries) {
    vector<bool> ans;
    // isPrerequisite[i][j] := true if course i is a prerequisite of course j
    vector<vector<bool>> isPrerequisite(numCourses, vector<bool>(numCourses));

    for (const vector<int>& prerequisite : prerequisites) {
      const int u = prerequisite[0];
      const int v = prerequisite[1];
      isPrerequisite[u][v] = true;
    }

    for (int k = 0; k < numCourses; ++k)
      for (int i = 0; i < numCourses; ++i)
        for (int j = 0; j < numCourses; ++j)
          isPrerequisite[i][j] = isPrerequisite[i][j] ||
                                 (isPrerequisite[i][k] && isPrerequisite[k][j]);

    for (const vector<int>& query : queries) {
      const int u = query[0];
      const int v = query[1];
      ans.push_back(isPrerequisite[u][v]);
    }

    return ans;
  }
};
