class Tweet {
  public int id;
  public int time;
  public Tweet next = null;
  public Tweet(int id, int time) {
    this.id = id;
    this.time = time;
  }
}

class User {
  private int id;
  public Set<Integer> followeeIds = new HashSet<>();
  public Tweet tweetHead = null;

  public User(int id) {
    this.id = id;
    follow(id); // follow himself
  }

  public void follow(int followeeId) {
    followeeIds.add(followeeId);
  }

  public void unfollow(int followeeId) {
    followeeIds.remove(followeeId);
  }

  public void post(int tweetId, int time) {
    final Tweet oldTweetHead = tweetHead;
    tweetHead = new Tweet(tweetId, time);
    tweetHead.next = oldTweetHead;
  }
}

class Twitter {
  /** Compose a new tweet. */
  public void postTweet(int userId, int tweetId) {
    users.putIfAbsent(userId, new User(userId));
    users.get(userId).post(tweetId, time++);
  }

  /**
   * Retrieve the 10 most recent tweet ids in the user's news feed. Each item in
   * the news feed must be posted by users who the user followed or by the user
   * herself. Tweets must be ordered from most recent to least recent.
   */
  public List<Integer> getNewsFeed(int userId) {
    if (!users.containsKey(userId))
      return new ArrayList<>();

    List<Integer> newsFeed = new ArrayList<>();
    Queue<Tweet> maxHeap = new PriorityQueue<>((a, b) -> b.time - a.time);

    for (final int followeeId : users.get(userId).followeeIds) {
      Tweet tweetHead = users.get(followeeId).tweetHead;
      if (tweetHead != null)
        maxHeap.offer(tweetHead);
    }

    int count = 0;
    while (!maxHeap.isEmpty() && count++ < 10) {
      Tweet tweet = maxHeap.poll();
      newsFeed.add(tweet.id);
      if (tweet.next != null)
        maxHeap.offer(tweet.next);
    }

    return newsFeed;
  }

  /**
   * Follower follows a followee.
   * If the operation is invalid, it should be a no-op.
   */
  public void follow(int followerId, int followeeId) {
    if (followerId == followeeId)
      return;
    users.putIfAbsent(followerId, new User(followerId));
    users.putIfAbsent(followeeId, new User(followeeId));
    users.get(followerId).follow(followeeId);
  }

  /**
   * Follower unfollows a followee.
   * If the operation is invalid, it should be a no-op.
   */
  public void unfollow(int followerId, int followeeId) {
    if (followerId == followeeId)
      return;
    if (users.containsKey(followerId) && users.containsKey(followeeId))
      users.get(followerId).unfollow(followeeId);
  }

  private int time = 0;
  private Map<Integer, User> users = new HashMap<>(); // {userId: User}
}
