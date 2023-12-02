class Solution {
 public:
  int longestCommonSubpath(int n, vector<vector<int>>& paths) {
    int l = 0;
    int r = paths[0].size();

    while (l < r) {
      const int m = l + (r - l + 1) / 2;
      if (checkCommonSubpath(paths, m))
        l = m;
      else
        r = m - 1;
    }

    return l;
  }

  constexpr static long kMod = 8'417'508'174'513;
  constexpr static long kBase = 165'131;

  // Returns true if there's a common subpath of length m for all the paths.
  bool checkCommonSubpath(const vector<vector<int>>& paths, int m) {
    vector<unordered_set<long>> hashSets;

    // Calculate the hash values for subpaths of length m for every path.
    for (const vector<int>& path : paths)
      hashSets.push_back(rabinKarp(path, m));

    // Check if there is a common subpath of length m.
    for (const long subpathHash : hashSets[0])
      if (ranges::all_of(hashSets,
                         [subpathHash](const unordered_set<long>& hashSet) {
        return hashSet.count(subpathHash);
      }))
        return true;

    return false;
  }

  // Returns the hash values for subpaths of length m in the path.
  unordered_set<long> rabinKarp(const vector<int>& path, int m) {
    unordered_set<long> hashes;
    long maxPower = 1;
    long hash = 0;
    for (int i = 0; i < path.size(); ++i) {
      hash = (hash * kBase + path[i]) % kMod;
      if (i >= m)
        hash = (hash - path[i - m] * maxPower % kMod + kMod) % kMod;
      else
        maxPower = maxPower * kBase % kMod;
      if (i >= m - 1)
        hashes.insert(hash);
    }
    return hashes;
  }
};
