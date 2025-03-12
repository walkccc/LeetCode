class Solution {
 public:
  long long maxProfit(vector<int>& workers, vector<vector<int>>& tasks) {
    long totalProfit = 0;
    int maxRemainingProfit = 0;
    unordered_map<int, vector<int>> skillToProfits;

    for (const vector<int>& task : tasks) {
      const int skill = task[0];
      const int profit = task[1];
      skillToProfits[skill].push_back(profit);
    }

    for (auto& [_, profits] : skillToProfits)
      ranges::sort(profits, greater<int>());

    for (const int workerSkill : workers)
      if (skillToProfits.contains(workerSkill) &&
          !skillToProfits[workerSkill].empty()) {
        const int profit = skillToProfits[workerSkill][0];
        skillToProfits[workerSkill].erase(skillToProfits[workerSkill].begin());
        totalProfit += profit;
      }

    for (const auto& [_, profits] : skillToProfits)
      if (!profits.empty())
        maxRemainingProfit = max(maxRemainingProfit, profits[0]);

    return totalProfit + maxRemainingProfit;
  }
};
