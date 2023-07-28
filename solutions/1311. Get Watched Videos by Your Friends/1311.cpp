class Solution {
 public:
  vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                        vector<vector<int>>& friends, int id,
                                        int level) {
    vector<string> ans;
    vector<bool> visited(friends.size());
    visited[id] = true;
    queue<int> queue{{id}};
    unordered_map<string, int> count;
    set<pair<int, string>> freqAndVideo;

    for (int i = 0; i < level; ++i)
      for (int j = queue.size(); j > 0; --j) {
        for (int f : friends[queue.front()])
          if (visited[f] == false) {
            visited[f] = true;
            queue.push(f);
          }
        queue.pop();
      }

    for (int i = queue.size(); i > 0; --i) {
      for (const string& video : watchedVideos[queue.front()])
        ++count[video];
      queue.pop();
    }

    for (const auto& [video, freq] : count)
      freqAndVideo.insert({freq, video});

    for (const auto& [_, video] : freqAndVideo)
      ans.push_back(video);

    return ans;
  }
};
