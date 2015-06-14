include "alldifferent.mzn";

% Problema 2 del Proyecto 3 de Inteligencia Artificial


array[0..6,0..6] of var 1..7: tab; % Tablero de juego


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



% Restriccion de filas
constraint forall (i in 0..6) (
              alldifferent( [ tab[i,j] | j in 0..6 ]) );

% Restriccion de columnas
constraint forall (j in 0..6) (
              alldifferent( [ tab[i,j] | i in 0..6 ]) );

% Restriccion de caminos 


                           
                              


solve satisfy;

output [ show_int(1,tab[i,j]) ++ " " ++ "" ++
          if j == 6 /\ i != 6 then "\n" else "" endif
          | i,j in 0..6 ] ++ ["\n"];