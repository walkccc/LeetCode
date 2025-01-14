WITH
  TwoWayFriends AS (
    SELECT user_id1 AS user_id, user_id2 AS friend_id FROM Friends
    UNION ALL
    SELECT user_id2, user_id1 FROM Friends
  ),
  UserToMutualFriend AS (
    SELECT
      User1.user_id,
      User2.user_id AS friend_id
    FROM TwoWayFriends AS User1
    INNER JOIN TwoWayFriends AS User2
      USING (friend_id)
    WHERE User1.user_id != User2.user_id
  )
SELECT Friends.* FROM Friends
LEFT JOIN UserToMutualFriend
  ON (
    Friends.user_id1 = UserToMutualFriend.user_id
    AND Friends.user_id2 = UserToMutualFriend.friend_id)
WHERE UserToMutualFriend.friend_id IS NULL
ORDER BY 1, 2;
