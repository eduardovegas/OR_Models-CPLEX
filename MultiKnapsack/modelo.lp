\ENCODING=ISO-8859-1
\Problem name: IloCplex

Maximize
 obj: 40 X(0)(0) + 40 X(0)(1) + 40 X(0)(2) + 40 X(0)(3) + 10 X(1)(0)
      + 10 X(1)(1) + 10 X(1)(2) + 10 X(1)(3) + 20 X(2)(0) + 20 X(2)(1)
      + 20 X(2)(2) + 20 X(2)(3) + 18 X(3)(0) + 18 X(3)(1) + 18 X(3)(2)
      + 18 X(3)(3) + 9 X(4)(0) + 9 X(4)(1) + 9 X(4)(2) + 9 X(4)(3) + 33 X(5)(0)
      + 33 X(5)(1) + 33 X(5)(2) + 33 X(5)(3) + 58 X(6)(0) + 58 X(6)(1)
      + 58 X(6)(2) + 58 X(6)(3) + 60 X(7)(0) + 60 X(7)(1) + 60 X(7)(2)
      + 60 X(7)(3) + 44 X(8)(0) + 44 X(8)(1) + 44 X(8)(2) + 44 X(8)(3)
      + 28 X(9)(0) + 28 X(9)(1) + 28 X(9)(2) + 28 X(9)(3)
Subject To
 COV(0): X(0)(0) + X(0)(1) + X(0)(2) + X(0)(3) <= 1
 COV(1): X(1)(0) + X(1)(1) + X(1)(2) + X(1)(3) <= 1
 COV(2): X(2)(0) + X(2)(1) + X(2)(2) + X(2)(3) <= 1
 COV(3): X(3)(0) + X(3)(1) + X(3)(2) + X(3)(3) <= 1
 COV(4): X(4)(0) + X(4)(1) + X(4)(2) + X(4)(3) <= 1
 COV(5): X(5)(0) + X(5)(1) + X(5)(2) + X(5)(3) <= 1
 COV(6): X(6)(0) + X(6)(1) + X(6)(2) + X(6)(3) <= 1
 COV(7): X(7)(0) + X(7)(1) + X(7)(2) + X(7)(3) <= 1
 COV(8): X(8)(0) + X(8)(1) + X(8)(2) + X(8)(3) <= 1
 COV(9): X(9)(0) + X(9)(1) + X(9)(2) + X(9)(3) <= 1
 CAP(0): 20 X(0)(0) + 5 X(1)(0) + 15 X(2)(0) + 22 X(3)(0) + 5 X(4)(0)
         + 25 X(5)(0) + 35 X(6)(0) + 50 X(7)(0) + 22 X(8)(0) + 17 X(9)(0) <= 33
 CAP(1): 20 X(0)(1) + 5 X(1)(1) + 15 X(2)(1) + 22 X(3)(1) + 5 X(4)(1)
         + 25 X(5)(1) + 35 X(6)(1) + 50 X(7)(1) + 22 X(8)(1) + 17 X(9)(1) <= 35
 CAP(2): 20 X(0)(2) + 5 X(1)(2) + 15 X(2)(2) + 22 X(3)(2) + 5 X(4)(2)
         + 25 X(5)(2) + 35 X(6)(2) + 50 X(7)(2) + 22 X(8)(2) + 17 X(9)(2) <= 30
 CAP(3): 20 X(0)(3) + 5 X(1)(3) + 15 X(2)(3) + 22 X(3)(3) + 5 X(4)(3)
         + 25 X(5)(3) + 35 X(6)(3) + 50 X(7)(3) + 22 X(8)(3) + 17 X(9)(3) <= 28
Bounds
 0 <= X(0)(0) <= 1
 0 <= X(0)(1) <= 1
 0 <= X(0)(2) <= 1
 0 <= X(0)(3) <= 1
 0 <= X(1)(0) <= 1
 0 <= X(1)(1) <= 1
 0 <= X(1)(2) <= 1
 0 <= X(1)(3) <= 1
 0 <= X(2)(0) <= 1
 0 <= X(2)(1) <= 1
 0 <= X(2)(2) <= 1
 0 <= X(2)(3) <= 1
 0 <= X(3)(0) <= 1
 0 <= X(3)(1) <= 1
 0 <= X(3)(2) <= 1
 0 <= X(3)(3) <= 1
 0 <= X(4)(0) <= 1
 0 <= X(4)(1) <= 1
 0 <= X(4)(2) <= 1
 0 <= X(4)(3) <= 1
 0 <= X(5)(0) <= 1
 0 <= X(5)(1) <= 1
 0 <= X(5)(2) <= 1
 0 <= X(5)(3) <= 1
 0 <= X(6)(0) <= 1
 0 <= X(6)(1) <= 1
 0 <= X(6)(2) <= 1
 0 <= X(6)(3) <= 1
 0 <= X(7)(0) <= 1
 0 <= X(7)(1) <= 1
 0 <= X(7)(2) <= 1
 0 <= X(7)(3) <= 1
 0 <= X(8)(0) <= 1
 0 <= X(8)(1) <= 1
 0 <= X(8)(2) <= 1
 0 <= X(8)(3) <= 1
 0 <= X(9)(0) <= 1
 0 <= X(9)(1) <= 1
 0 <= X(9)(2) <= 1
 0 <= X(9)(3) <= 1
Binaries
 X(0)(0)  X(0)(1)  X(0)(2)  X(0)(3)  X(1)(0)  X(1)(1)  X(1)(2)  X(1)(3) 
 X(2)(0)  X(2)(1)  X(2)(2)  X(2)(3)  X(3)(0)  X(3)(1)  X(3)(2)  X(3)(3) 
 X(4)(0)  X(4)(1)  X(4)(2)  X(4)(3)  X(5)(0)  X(5)(1)  X(5)(2)  X(5)(3) 
 X(6)(0)  X(6)(1)  X(6)(2)  X(6)(3)  X(7)(0)  X(7)(1)  X(7)(2)  X(7)(3) 
 X(8)(0)  X(8)(1)  X(8)(2)  X(8)(3)  X(9)(0)  X(9)(1)  X(9)(2)  X(9)(3) 
End
