WITH
  RankedUserActivity AS (
    SELECT
      *,
      COUNT(*) OVER(PARTITION BY username) AS `count`,
      RANK() OVER(
        PARTITION BY username
        ORDER BY endDate DESC
      ) AS `rank`
    FROM UserActivity
  )
SELECT
  username,
  activity,
  startDate,
  endDate
FROM RankedUserActivity
WHERE `count` = 1 OR `rank` = 2;
