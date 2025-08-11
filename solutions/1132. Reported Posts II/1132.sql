WITH
  DailyPercents AS (
    SELECT (
        COUNT(DISTINCT Removals.post_id) / COUNT(DISTINCT Actions.post_id)
      ) * 100 AS percent
    FROM Actions
    LEFT JOIN Removals
      USING (post_id)
    WHERE Actions.extra = 'spam'
    GROUP BY Actions.action_date
  )
SELECT ROUND(AVG(percent), 2) AS average_daily_percent
FROM DailyPercents;
