# Write your MySQL query statement below

select max(salary) as SecondHighestSalary
FROM Employee
where salary < (
    select max(salary) 
FROM Employee
);