WITH
  UserToAmount AS (
    SELECT
      user_id,
      spend_date,
      CASE
        WHEN COUNT(DISTINCT platform) = 2 THEN 'both'
        ELSE platform
      END AS platform,
      SUM(amount) AS amount
    FROM Spending
    GROUP BY 1, 2
  ),
  DateAndPlatforms AS (
    SELECT DISTINCT(spend_date), 'desktop' AS platform
    FROM Spending
    UNION ALL
    SELECT DISTINCT(spend_date), 'mobile' AS platform
    FROM Spending
    UNION ALL
    SELECT DISTINCT(spend_date), 'both' AS platform
    FROM Spending
  )
SELECT
  DateAndPlatforms.spend_date,
  DateAndPlatforms.platform,
  IFNULL(SUM(UserToAmount.amount), 0) AS total_amount,
  COUNT(DISTINCT UserToAmount.user_id) AS total_users
FROM DateAndPlatforms
LEFT JOIN UserToAmount
  USING (spend_date, platform)
GROUP BY 1, 2;
