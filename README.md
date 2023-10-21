### How to use
```bash
cd src  
make  
./program
```
1. **CREATE TABLE table_name (column_1 int, column_2 varchar, column_3 double)** -
*Creates file table_name.bin in dir tables/*
2. **INSERT INTO table_name (0, string, 0.0)**  

3. **SELECT * FROM table_name**

#### Examples:
CREATE TABLE students (id int, name varchar, mark double)  
INSERT INTO students VALUES (0, masha, 10.0)  
SELECT * FROM students  
INSERT INTO students VALUES (1, lev, 8.6)  
SELECT * FROM students  

