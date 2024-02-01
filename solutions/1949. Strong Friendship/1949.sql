WITH
  TwoWayFriendship AS (
    SELECT user1_id AS user_id, user2_id AS friend_id FROM Friendship
    UNION ALL
    SELECT user2_id, user1_id FROM Friendship
  )
SELECT
  User1.user_id AS user1_id,
  User2.user_id AS user2_id,
  COUNT(*) AS common_friend
FROM TwoWayFriendship AS User1
INNER JOIN TwoWayFriendship AS User2
  ON (
    User1.friend_id = User2.friend_id
    AND User1.user_id < User2.user_id)
WHERE EXISTS (
  SELECT *
  FROM Friendship
  WHERE
    Friendship.user1_id = User1.user_id
    AND Friendship.user2_id = User2.user_id
)
GROUP BY 1, 2
HAVING common_friend >= 3;
