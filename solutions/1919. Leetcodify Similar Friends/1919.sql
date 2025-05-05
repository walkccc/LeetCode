SELECT DISTINCT
  Listen1.user_id AS user1_id,
  Listen2.user_id AS user2_id
FROM Listens AS Listen1
INNER JOIN Listens AS Listen2
  USING (song_id, day)
WHERE
  Listen1.user_id < Listen2.user_id
  AND EXISTS(
    SELECT * FROM Friendship
    WHERE
      Listen1.user_id = Friendship.user1_id
      AND Listen2.user_id = Friendship.user2_id)
GROUP BY Listen1.user_id, Listen2.user_id, Listen1.day
HAVING COUNT(DISTINCT Listen1.song_id) >= 3
