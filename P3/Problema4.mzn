% Problema 4 del Proyecto 3 de Inteligencia Artificial


int : k = 3;
int : n = 6;
int: aux = k + 2;
int: m = ceil(n / aux); % Cantidad minima de ascensores

array[1..m,1..n] of var bool: asc; % Matriz con el minimo de Ascensores y los pisos

constraint forall(i in 1..m)(asc[i][1] = true); % Fijo en todos los ascensores el primer piso
constraint forall(i in 1..m)(asc[i][n] = true); % Fijo en todos los ascensores el ultimo piso
constraint forall(i in 1..n-1,j in i..n)(exists(l in 1..m)((asc[l][i]=true) /\ (asc[l][j]=true)));


solve satisfy;
 