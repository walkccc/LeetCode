WITH
  SevenDayPostCounts AS (
    SELECT
      Post1.user_id,
      COUNT(*) AS post_count
    FROM Posts AS Post1
    INNER JOIN Posts AS Post2
      USING (user_id)
    WHERE Post2.post_date BETWEEN Post1.post_date AND DATE_ADD(Post1.post_date, INTERVAL 6 DAY)
    GROUP BY Post1.user_id, Post1.post_id
  ),
  AverageWeeklyPosts AS (
    SELECT
      user_id,
      COUNT(*) / 4 AS avg_weekly_posts
    FROM Posts
    WHERE post_date BETWEEN '2024-02-01' AND '2024-02-28'
    GROUP BY 1
  )
SELECT
  SevenDayPostCounts.user_id,
  MAX(SevenDayPostCounts.post_count) AS max_7day_posts,
  AverageWeeklyPosts.avg_weekly_posts
FROM SevenDayPostCounts
INNER JOIN AverageWeeklyPosts
  USING (user_id)
GROUP BY 1
HAVING max_7day_posts >= avg_weekly_posts * 2
ORDER BY 1;
