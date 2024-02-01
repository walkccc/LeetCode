struct Creator {
  long popularity;  // the popularity sum
  string videoId;   // the video id that has the maximum view
  int maxView;      // the maximum view of the creator
};

class Solution {
 public:
  vector<vector<string>> mostPopularCreator(vector<string>& creators,
                                            vector<string>& ids,
                                            vector<int>& views) {
    vector<vector<string>> ans;
    unordered_map<string, Creator> nameToCreator;
    long maxPopularity = 0;

    for (int i = 0; i < creators.size(); ++i) {
      if (!nameToCreator.count(creators[i])) {
        nameToCreator[creators[i]] = Creator{
            .popularity = views[i],
            .videoId = ids[i],
            .maxView = views[i],
        };
        maxPopularity = max(maxPopularity, static_cast<long>(views[i]));
        continue;
      }
      Creator& creator = nameToCreator[creators[i]];
      creator.popularity += views[i];
      maxPopularity = max(maxPopularity, static_cast<long>(creator.popularity));
      if (creator.maxView < views[i] ||
          creator.maxView == views[i] && creator.videoId > ids[i]) {
        creator.videoId = ids[i];
        creator.maxView = views[i];
      }
    }

    for (const auto& [name, creator] : nameToCreator)
      if (creator.popularity == maxPopularity)
        ans.push_back({name, creator.videoId});

    return ans;
  }
};
