WITH
  RECURSIVE Fridays AS (
    SELECT 1 AS week_of_month, '2023-11-03' AS purchase_date
    UNION ALL
    SELECT week_of_month + 1, DATE_ADD(purchase_date, INTERVAL 7 DAY)
    FROM Fridays
    WHERE week_of_month < 4
  ),
  Memberships AS (
    SELECT 'Premium' AS membership
    UNION ALL
    SELECT 'VIP'
  )
SELECT
  Fridays.week_of_month,
  Memberships.membership,
  IFNULL(SUM(Purchases.amount_spend), 0) AS total_amount
FROM Fridays
CROSS JOIN Memberships
LEFT JOIN Users
  ON (Memberships.membership = Users.membership)
LEFT JOIN Purchases
  ON (
    Fridays.purchase_date = Purchases.purchase_date
    AND Users.user_id = Purchases.user_id)
GROUP BY 1, 2
ORDER BY 1, 2;
