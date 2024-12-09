struct Tweet {
  int id;
  int time;
  Tweet* next = nullptr;
};

struct User {
  int id;
  unordered_set<int> followeeIds;
  Tweet* tweetHead = nullptr;

  User() {}

  User(int id) : id(id) {
    follow(id);
  }

  void follow(int followeeId) {
    followeeIds.insert(followeeId);
  }

  void unfollow(int followeeId) {
    followeeIds.erase(followeeId);
  }

  void post(int tweetId, int time) {
    Tweet* oldTweetHead = tweetHead;
    tweetHead = new Tweet(tweetId, time);
    tweetHead->next = oldTweetHead;
  }
};

class Twitter {
 public:
  /** Compose a new tweet. */
  void postTweet(int userId, int tweetId) {
    if (!users.contains(userId))
      users[userId] = User(userId);
    users[userId].post(tweetId, time++);
  }

  /**
   * Retrieve the 10 most recent tweet ids in the user's news feed. Each item in
   * the news feed must be posted by users who the user followed or by the user
   * herself. Tweets must be ordered from most recent to least recent.
   */
  vector<int> getNewsFeed(int userId) {
    if (!users.contains(userId))
      return {};

    vector<int> newsFeed;

    auto compare = [](const Tweet* a, const Tweet* b) {
      return a->time < b->time;
    };
    priority_queue<Tweet*, vector<Tweet*>, decltype(compare)> maxHeap(compare);

    for (const int followeeId : users[userId].followeeIds) {
      Tweet* tweetHead = users[followeeId].tweetHead;
      if (tweetHead != nullptr)
        maxHeap.push(tweetHead);
    }

    int count = 0;
    while (!maxHeap.empty() && count++ < 10) {
      Tweet* tweet = maxHeap.top();
      maxHeap.pop();
      newsFeed.push_back(tweet->id);
      if (tweet->next)
        maxHeap.push(tweet->next);
    }

    return newsFeed;
  }

  /**
   * Follower follows a followee.
   * If the operation is invalid, it should be a no-op.
   */
  void follow(int followerId, int followeeId) {
    if (followerId == followeeId)
      return;
    if (!users.contains(followerId))
      users[followerId] = User(followerId);
    if (!users.contains(followeeId))
      users[followeeId] = User(followeeId);
    users[followerId].follow(followeeId);
  }

  /**
   * Follower unfollows a followee.
   * If the operation is invalid, it should be a no-op.
   */
  void unfollow(int followerId, int followeeId) {
    if (followerId == followeeId)
      return;
    if (const auto it = users.find(followerId);
        it != users.cend() && users.contains(followeeId))
      it->second.unfollow(followeeId);
  }

 private:
  int time = 0;
  unordered_map<int, User> users;  // {userId: User}
};
