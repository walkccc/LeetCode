WITH
  TwoWayFriends AS (
    SELECT user1, user2 FROM Friends
    UNION ALL
    SELECT user2, user1 FROM Friends
  )
SELECT
  user1,
  ROUND(
    100 * (
      COUNT(DISTINCT user2) / (COUNT(*) OVER ())
    ),
    2
  ) AS percentage_popularity
FROM TwoWayFriends
GROUP BY 1
ORDER BY 1;
