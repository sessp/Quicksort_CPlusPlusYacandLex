# Sorting Program Yac and Lex

Uses flex, bison, and gcc

A simple interpreter that can accept a list of numbers of any length, and then outputs that list in sorted order.

1. Compile file with
      lex hello.l
      yacc -d hello.y
      cc lex.yy.c y.tab.c -o hello
2. Run program with ./hello
