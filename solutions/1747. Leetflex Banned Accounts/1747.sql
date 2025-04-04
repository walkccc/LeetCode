WITH
  LogInfoNeighbors AS (
    SELECT
      *,
      LEAD(ip_address) OVER(
        PARTITION BY account_id
        ORDER BY login
      ) AS next_ip_address,
      LEAD(login) OVER(
        PARTITION BY account_id
        ORDER BY login
      ) next_login
    FROM LogInfo
  )
SELECT DISTINCT account_id
FROM LogInfoNeighbors
WHERE
  next_login <= logout
  AND ip_address != next_ip_address;
