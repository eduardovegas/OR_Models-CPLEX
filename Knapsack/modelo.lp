\ENCODING=ISO-8859-1
\Problem name: IloCplex

Maximize
 obj: 40 X(0) + 10 X(1) + 20 X(2) + 18 X(3) + 9 X(4) + 33 X(5) + 58 X(6)
      + 60 X(7) + 44 X(8) + 28 X(9)
Subject To
 CAP: 20 X(0) + 5 X(1) + 15 X(2) + 22 X(3) + 5 X(4) + 25 X(5) + 35 X(6)
      + 50 X(7) + 22 X(8) + 17 X(9) <= 135
Bounds
 0 <= X(0) <= 1
 0 <= X(1) <= 1
 0 <= X(2) <= 1
 0 <= X(3) <= 1
 0 <= X(4) <= 1
 0 <= X(5) <= 1
 0 <= X(6) <= 1
 0 <= X(7) <= 1
 0 <= X(8) <= 1
 0 <= X(9) <= 1
Binaries
 X(0)  X(1)  X(2)  X(3)  X(4)  X(5)  X(6)  X(7)  X(8)  X(9) 
End
