# Similar to 608. Tree Node
SELECT DISTINCT Parent.N,
  (
    CASE
      WHEN Parent.P IS NULL THEN 'Root'
      WHEN Parent.P IS NOT NULL AND Child.P IS NOT NULL THEN 'Inner'
      WHEN Parent.P IS NOT NULL AND Child.P IS NULL THEN 'Leaf'
    END
  ) AS type
FROM Tree AS Parent
LEFT JOIN Tree AS Child
  ON (Parent.N = Child.P)
ORDER BY 1;
