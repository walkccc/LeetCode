SELECT
  Books.book_id,
  ANY_VALUE(Books.name) AS name
FROM Books
LEFT JOIN Orders
  ON (
    Books.book_id = Orders.book_id
    AND Orders.dispatch_date BETWEEN '2018-06-23' AND '2019-06-23')
WHERE DATEDIFF('2019-06-23', Books.available_from) > 30
GROUP BY 1
HAVING IFNULL(SUM(Orders.quantity), 0) < 10;
