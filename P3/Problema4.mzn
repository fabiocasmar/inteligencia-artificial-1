% Problema 4 del Proyecto 3 de Inteligencia Artificial

int : k = 5;
int : n = 8;
int : m = 3;

array[0..m,0..n] of var 0..1: asc; % Matriz con el minimo de Ascensores y los pisos

constraint forall(i in 0..m-1)(asc[i,0] = 1); % Fijo en todos los ascensores el primer piso
constraint forall(i in 0..m-1)(asc[i,n-1] = 1); % Fijo en todos los ascensores el ultimo piso

constraint forall(i,j in 0..n-1 where i < j)(exists(l in 0..m-1)((asc[l,i]=1) /\ (asc[l,j]=1)));

% Nos aseguramos de que cada fila tenga exactamente k+2 1s.
constraint forall(i in 0..m-1)((sum (j in 0..n-1) (asc[i,j])) = k+2);

solve satisfy;

output[ show_int(1,asc[i,j]) ++ " " ++ "" ++
          if j == n-1 /\ i != m-1 then "\n" else "" endif
          | i in 0..m-1,j in 0..n-1 ] ++ ["\n"];