MULTIPLE TABLES
Inner Joins
Let’s revisit how we joined orders and customers. For every possible value of customer_id in orders, there was a corresponding row of customers with the same customer_id.

What if that wasn’t true?

For instance, imagine that our customers table was out of date, and was missing any information on customer 11. If that customer had an order in orders, what would happen when we joined the tables?

When we perform a simple JOIN (often called an inner join) our result only includes rows that match our ON condition.

Consider the following animation, which illustrates an inner join of two tables on table1.c2 = table2.c2:

Animation of an Inner Join

The first and last rows have matching values of c2. The middle rows do not match. The final result has all values from the first and last rows but does not include the non-matching middle row.




Left Joins
What if we want to combine two tables and keep some of the un-matched rows?

SQL lets us do this through a command called LEFT JOIN. A left join will keep all rows from the first table, regardless of whether there is a matching row in the second table.

Consider the following animation:

Animation of a Left Join

The first and last rows have matching values of c2. The middle rows do not match. The final result will keep all rows of the first table but will omit the un-matched row from the second table.

This animation represents a table operation produced by the following command:

SELECT *
FROM table1
LEFT JOIN table2
  ON table1.c2 = table2.c2;
The first line selects all columns from both tables.
The second line selects table1 (the “left” table).
The third line performs a LEFT JOIN on table2 (the “right” table).
The fourth line tells SQL how to perform the join (by looking for matching values in column c2).