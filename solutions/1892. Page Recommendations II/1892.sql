WITH
  UserToFriends AS (
    SELECT user1_id AS user_id, user2_id AS friend_id FROM Friendship
    UNION ALL
    SELECT user2_id AS user_id, user1_id AS friend_id FROM friendship
  )
SELECT
  UserToFriends.user_id,
  FriendLikes.page_id,
  COUNT(DISTINCT UserToFriends.friend_id) AS friends_likes
FROM UserToFriends
LEFT JOIN Likes AS FriendLikes
  ON (UserToFriends.friend_id = FriendLikes.user_id)
LEFT JOIN Likes AS UserLikes
  ON (
    UserToFriends.user_id = UserLikes.user_id
    AND FriendLikes.page_id = UserLikes.page_id)
WHERE UserLikes.page_id IS NULL
GROUP BY 1, 2;
