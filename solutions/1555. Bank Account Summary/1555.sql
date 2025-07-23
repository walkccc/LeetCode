WITH
  UpdatedUsers AS (
    SELECT
      Users.user_id,
      Users.user_name,
      Users.credit + SUM(
        CASE
          WHEN Users.user_id = Transactions.paid_by THEN -Transactions.amount
          WHEN Users.user_id = Transactions.paid_to THEN Transactions.amount
          ELSE 0
        END
      ) AS credit
    FROM Users
    LEFT JOIN Transactions
      ON (Users.user_id IN (Transactions.paid_by, Transactions.paid_to))
    GROUP BY 1
  )
SELECT
  *,
  IF(credit < 0, 'Yes', 'No') AS credit_limit_breached
FROM UpdatedUsers;