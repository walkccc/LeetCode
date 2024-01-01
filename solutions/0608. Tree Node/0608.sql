SELECT DISTINCT Parent.id,
  (
    CASE
      WHEN Parent.p_id IS NULL THEN 'Root'
      WHEN Parent.p_id IS NOT NULL AND Child.p_id IS NOT NULL THEN 'Inner'
      WHEN Parent.p_id IS NOT NULL AND Child.p_id IS NULL THEN 'Leaf'
    END
  ) AS type
FROM Tree AS Parent
LEFT JOIN Tree AS Child
  ON (Parent.id = Child.p_id);
