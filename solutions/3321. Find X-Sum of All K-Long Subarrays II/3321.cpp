class Solution {
 public:
  // Same as 3318. Find X-Sum of All K-Long Subarrays I
  vector<long long> findXSum(vector<int>& nums, int k, int x) {
    vector<long long> ans;
    long windowSum = 0;
    unordered_map<int, int> count;
    multiset<pair<int, int>> top;  // the top x elements
    multiset<pair<int, int>> bot;  // the rest of the elements

    // Updates the count of num by freq and the window sum accordingly.
    auto update = [&count, &top, &bot, &windowSum](int num, int freq) -> void {
      if (count[num] > 0) {  // Clean up the old count.
        if (auto it = bot.find({count[num], num}); it != bot.end()) {
          bot.erase(it);
        } else {
          it = top.find({count[num], num});
          top.erase(it);
          windowSum -= static_cast<long>(num) * count[num];
        }
      }
      count[num] += freq;
      if (count[num] > 0)
        bot.insert({count[num], num});
    };

    for (int i = 0; i < nums.size(); ++i) {
      update(nums[i], 1);
      if (i >= k)
        update(nums[i - k], -1);
      // Move the bottom elements to the top if needed.
      while (!bot.empty() && top.size() < x) {
        const auto [countB, b] = *bot.rbegin();
        bot.erase(--bot.end());
        top.insert({countB, b});
        windowSum += static_cast<long>(b) * countB;
      }
      // Swap the bottom and top elements if needed.
      while (!bot.empty() && *bot.rbegin() > *top.begin()) {
        const auto [countB, b] = *bot.rbegin();
        const auto [countT, t] = *top.begin();
        bot.erase(--bot.end());
        top.erase(top.begin());
        bot.insert({countT, t});
        top.insert({countB, b});
        windowSum += static_cast<long>(b) * countB;
        windowSum -= static_cast<long>(t) * countT;
      }
      if (i >= k - 1)
        ans.push_back(windowSum);
    }

    return ans;
  }
};
