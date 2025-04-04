WITH
  RankedFriends AS (
    SELECT
      activity,
      RANK() OVER(ORDER BY COUNT(id) ASC) AS rank_asc,
      RANK() OVER(ORDER BY COUNT(id) DESC) AS rank_desc
    FROM Friends
    GROUP BY 1
  )
SELECT activity
FROM RankedFriends
WHERE rank_asc > 1 AND rank_desc > 1;
