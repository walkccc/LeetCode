WITH
  RankedRelations AS (
    SELECT
      User1.user_id AS user1_id,
      User2.user_id AS user2_id,
      RANK() OVER(ORDER BY COUNT(User1.follower_id) DESC) AS `rank`
    FROM Relations AS User1
    INNER JOIN Relations AS User2
      USING (follower_id)
    WHERE User1.user_id < User2.user_id
    GROUP BY 1, 2
  )
SELECT user1_id, user2_id
FROM RankedRelations
WHERE `rank` = 1;
