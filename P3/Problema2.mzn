include "alldifferent.mzn";

% Problema 2 del Proyecto 3 de Inteligencia Artificial


array[0..6,0..6] of var 1..7: tab; % Tablero de juego
% Caminos
array[0..6] of var 1..7: c1;
array[0..6] of var 1..7: c2;
array[0..6] of var 1..7: c3;
array[0..6] of var 1..7: c4;
array[0..6] of var 1..7: c5;
array[0..6] of var 1..7: c6;
array[0..6] of var 1..7: c7;

% Restricciones de valores iniciales
constraint tab[0,2] = 2;
constraint tab[0,4] = 4;
constraint tab[1,1] = 5;
constraint tab[1,5] = 2;
constraint tab[2,6] = 6;
constraint tab[3,1] = 7;
constraint tab[3,5] = 5;
constraint tab[4,6] = 7;
constraint tab[5,1] = 6;
constraint tab[5,5] = 4;
constraint tab[6,2] = 1;
constraint tab[6,4] = 2;

% Restricciones de c1
constraint c1[0] = tab[0,0];
constraint c1[1] = tab[0,1];
constraint c1[2] = tab[0,2];
constraint c1[3] = tab[0,3];
constraint c1[4] = tab[1,3];
constraint c1[5] = tab[1,4];
constraint c1[6] = tab[2,4];

% Restricciones de c2
constraint c2[0] = tab[0,6];
constraint c2[1] = tab[0,5];
constraint c2[2] = tab[0,4];
constraint c2[3] = tab[1,5];
constraint c2[4] = tab[2,5];
constraint c2[5] = tab[3,3];
constraint c2[6] = tab[3,4];

% Restricciones de c3
constraint c3[0] = tab[1,0];
constraint c3[1] = tab[1,1];
constraint c3[2] = tab[2,0];
constraint c3[3] = tab[3,0];
constraint c3[4] = tab[4,0];
constraint c3[5] = tab[5,0];
constraint c3[6] = tab[5,1];

% Restricciones de c4
constraint c4[0] = tab[1,2];
constraint c4[1] = tab[2,1];
constraint c4[2] = tab[2,2];
constraint c4[3] = tab[2,3];
constraint c4[4] = tab[3,1];
constraint c4[5] = tab[3,2];
constraint c4[6] = tab[4,2];

% Restricciones de c5
constraint c5[0] = tab[1,6];
constraint c5[1] = tab[2,6];
constraint c5[2] = tab[3,5];
constraint c5[3] = tab[3,6];
constraint c5[4] = tab[4,6];
constraint c5[5] = tab[5,6];
constraint c5[6] = tab[6,6];

% Restricciones de c6
constraint c6[0] = tab[4,1];
constraint c6[1] = tab[5,2];
constraint c6[2] = tab[4,3];
constraint c6[3] = tab[5,3];
constraint c6[4] = tab[5,4];
constraint c6[5] = tab[4,4];
constraint c6[6] = tab[4,5];

% Restricciones de c7
constraint c7[0] = tab[6,0];
constraint c7[1] = tab[6,1];
constraint c7[2] = tab[6,2];
constraint c7[3] = tab[6,3];
constraint c7[4] = tab[6,4];
constraint c7[5] = tab[5,5];
constraint c7[6] = tab[6,5];

% Restriccion de filas
constraint forall (i in 0..6) (
              alldifferent( [ tab[i,j] | j in 0..6 ]) );

% Restriccion de columnas
constraint forall (j in 0..6) (
              alldifferent( [ tab[i,j] | i in 0..6 ]) );

% Restricciones de caminos
constraint alldifferent( [c1[i] | i in 0..6]);
constraint alldifferent( [c2[i] | i in 0..6]);
constraint alldifferent( [c3[i] | i in 0..6]);
constraint alldifferent( [c4[i] | i in 0..6]);
constraint alldifferent( [c5[i] | i in 0..6]);
constraint alldifferent( [c6[i] | i in 0..6]);
constraint alldifferent( [c7[i] | i in 0..6]);


solve satisfy;

output [ show_int(1,tab[i,j]) ++ " " ++ "" ++
          if j == 6 /\ i != 6 then "\n" else "" endif
          | i,j in 0..6 ] ++ ["\n"];