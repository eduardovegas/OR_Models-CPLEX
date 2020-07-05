\ENCODING=ISO-8859-1
\Problem name: IloCplex

Minimize
 obj: 10 Y(0) + 7 Y(1) + 14 Y(2) + 8 Y(3) + 2 Y(4)
Subject To
 COV(0): Y(0) >= 1
 COV(1): Y(0) >= 1
 COV(2): Y(1) >= 1
 COV(3): Y(1) + Y(2) + Y(3) >= 1
 COV(4): Y(2) + Y(3) >= 1
 COV(5): Y(2) + Y(4) >= 1
Bounds
 0 <= Y(0) <= 1
 0 <= Y(1) <= 1
 0 <= Y(2) <= 1
 0 <= Y(3) <= 1
 0 <= Y(4) <= 1
Binaries
 Y(0)  Y(1)  Y(2)  Y(3)  Y(4) 
End
