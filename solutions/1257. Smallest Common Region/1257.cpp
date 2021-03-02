class Solution {
 public:
  string findSmallestRegion(vector<vector<string>>& regions, string region1,
                            string region2) {
    unordered_map<string, string> parent;
    unordered_set<string> ancestors;  // region1's ancestors

    for (const auto& region : regions)
      for (int i = 1; i < region.size(); ++i)
        parent[region[i]] = region[0];

    // insert all of region1's ancestors
    while (region1 != "") {
      ancestors.insert(region1);
      region1 = parent[region1];  // region1 becomes "" in the end
    }

    // go up from region2 until meet any of region1's ancestors
    while (!ancestors.count(region2))
      region2 = parent[region2];

    return region2;
  }
};
