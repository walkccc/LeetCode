class Solution {
 public:
  int findRotateSteps(string ring, string key) {
    return dfs(ring, key, 0, {}) + key.length();
  }

 private:
  // Returns the number of rotates of ring to match key[index..n).
  int dfs(const string& ring, const string& key, int index,
          unordered_map<string, int>&& mem) {
    if (index == key.length())
      return 0;
    // Add the index to prevent duplication.
    const string hashKey = ring + to_string(index);
    if (const auto it = mem.find(hashKey); it != mem.cend())
      return it->second;

    int ans = INT_MAX;

    // For each ring[i] == key[index], we rotate the ring to match the ring[i]
    // with the key[index], then recursively match the newRing with the
    // key[index + 1..n).
    for (size_t i = 0; i < ring.length(); ++i)
      if (ring[i] == key[index]) {
        const int minRotates = min(i, ring.length() - i);
        const string& newRing = ring.substr(i) + ring.substr(0, i);
        const int remainingRotates =
            dfs(newRing, key, index + 1, std::move(mem));
        ans = min(ans, minRotates + remainingRotates);
      }

    return mem[hashKey] = ans;
  }
};
