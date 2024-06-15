# How to run:
```
g++ -o calc main.cpp basic_calc.cpp postfix_calc.cpp
./calc
```

## Postfix Problems to try:

2 3 4 * +
= 14

3 4 * 2 5 * +
= 22

4 5 7 2 + - *
= -16

3 4 + 2 * 7 /
=2

5 7 + 62 - *
= Error : insufficient operands for the last operator.

4 2 3 5 1 - + * +
=18

4 2 + 3 5 1 - * +
=18

## Infix Problems to try:

(3.4+5) * 2.3 / (2.3+1.2)
= 5.52