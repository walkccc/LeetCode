WITH
  SuspiciousAccountToMonth AS (
    SELECT
      Transactions.account_id,
      DATE_FORMAT(Transactions.day, '%Y%m') AS month,
      Accounts.max_income
    FROM Transactions
    INNER JOIN Accounts
      USING (account_id)
    WHERE Transactions.type = 'Creditor'
    GROUP BY 1, 2
    HAVING SUM(Transactions.amount) > Accounts.max_income
  )
SELECT DISTINCT CurrMonth.account_id
FROM SuspiciousAccountToMonth AS CurrMonth
INNER JOIN SuspiciousAccountToMonth AS NextMonth
  USING (account_id)
WHERE PERIOD_DIFF(NextMonth.month, CurrMonth.month) = 1;
