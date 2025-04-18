WITH
  UserToFriends AS (
    SELECT user1_id AS user_id, user2_id AS friend_id FROM Friendship
    UNION ALL
    SELECT user2_id AS user_id, user1_id AS friend_id FROM friendship
  )
SELECT FriendLikes.page_id AS recommended_page
FROM UserToFriends
LEFT JOIN Likes AS FriendLikes
  ON (UserToFriends.friend_id = FriendLikes.user_id)
LEFT JOIN Likes AS UserLikes
  ON (
    UserToFriends.user_id = UserLikes.user_id
    AND FriendLikes.page_id = UserLikes.page_id)
WHERE
  UserToFriends.user_id = 1
  AND UserLikes.page_id IS NULL
  AND FriendLikes.page_id IS NOT NULL
GROUP BY 1;
