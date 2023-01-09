struct Seed {
  int p;
  int g;
  Seed(int p, int g) : p(p), g(g) {}
};

class Solution {
 public:
  int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
    int ans = 0;
    int time = 0;
    vector<Seed> seeds;

    for (int i = 0; i < plantTime.size(); ++i)
      seeds.emplace_back(plantTime[i], growTime[i]);

    sort(begin(seeds), end(seeds),
         [](const auto& a, const auto& b) { return a.g > b.g; });

    for (const auto& [p, g] : seeds) {
      time += p;
      ans = max(ans, time + g);
    }

    return ans;
  }
};
