WITH
  DistinctLogins AS (
    SELECT DISTINCT * FROM Logins
  ),
  RankedLogins AS (
    SELECT
      *,
      DENSE_RANK() OVER(
        PARTITION BY id
        ORDER BY login_date
      ) AS `rank`
    FROM DistinctLogins
  ),
  RankedLoginsWithGroupId AS (
    SELECT
      *,
      DATE_ADD(login_date, INTERVAL -`rank` DAY) AS group_id
    FROM RankedLogins
  )
SELECT DISTINCT
  id,
  Accounts.name
FROM RankedLoginsWithGroupId
INNER JOIN Accounts
  USING (id)
GROUP BY Accounts.id, RankedLoginsWithGroupId.group_id
HAVING COUNT(*) >= 5
ORDER BY 1;
