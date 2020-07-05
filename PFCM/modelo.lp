\ENCODING=ISO-8859-1
\Problem name: IloCplex

Minimize
 obj: X(0) + 13 X(1) + X(2) + 9 X(3) + 5 X(4) + 5 X(5) + 3 X(6) + X(7) + 2 X(8)
Subject To
 DEM(0): - X(0) - X(1)  = -8
 DEM(1): - X(2) - X(3)  = -6
 DEM(2): X(0) + X(2) - X(4)  = 0
 DEM(3): X(1) - X(5) + X(6) + X(7)  = 7
 DEM(4): X(3) + X(5) - X(6) + X(8)  = 7
 DEM(5): X(4) - X(7) - X(8)  = 0
Bounds
 2 <= X(0) <= 4
 0 <= X(1) <= 6
 1 <= X(2) <= 4
 0 <= X(3) <= 3
 0 <= X(4) <= 8
 0 <= X(5) <= 3
 0 <= X(6) <= 2
 0 <= X(7) <= 5
 0 <= X(8) <= 5
End
