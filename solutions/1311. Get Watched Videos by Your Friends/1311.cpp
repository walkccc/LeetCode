class Solution {
 public:
  vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos,
                                        vector<vector<int>>& friends, int id,
                                        int level) {
    vector<string> ans;
    queue<int> q{{id}};
    vector<bool> seen(friends.size());
    seen[id] = true;
    unordered_map<string, int> count;
    set<pair<int, string>> freqAndVideo;

    for (int i = 0; i < level; ++i)
      for (int sz = q.size(); sz > 0; --sz) {
        for (const int friend_ : friends[q.front()])
          if (!seen[friend_]) {
            seen[friend_] = true;
            q.push(friend_);
          }
        q.pop();
      }

    for (int i = q.size(); i > 0; --i) {
      for (const string& video : watchedVideos[q.front()])
        ++count[video];
      q.pop();
    }

    for (const auto& [video, freq] : count)
      freqAndVideo.insert({freq, video});

    for (const auto& [_, video] : freqAndVideo)
      ans.push_back(video);

    return ans;
  }
};
