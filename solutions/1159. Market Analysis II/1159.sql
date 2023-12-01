WITH
  RankedOrders AS (
    SELECT
      Orders.seller_id,
      RANK() OVER(
        PARTITION BY Orders.seller_id
        ORDER BY Orders.order_date
      ) AS `rank`,
      Items.item_brand
    FROM Orders
    INNER JOIN Items
      USING (item_id)
  )
SELECT
  user_id AS seller_id,
  CASE
    WHEN Users.favorite_brand = RankedOrders.item_brand THEN 'yes'
    ELSE 'no'
  END AS 2nd_item_fav_brand
FROM Users
LEFT JOIN RankedOrders
  ON (Users.user_id = RankedOrders.seller_id AND RankedOrders.`rank` = 2);
