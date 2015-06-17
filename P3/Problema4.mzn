% Problema 4 del Proyecto 3 de Inteligencia Artificial


int : k = 3;
int : n = 6;
int: aux = k + 2;
int: m = ceil(n / aux); % Cantidad minima de ascensores

array[0..m,0..n] of var bool: asc; % Matriz con el minimo de Ascensores y los pisos

constraint forall(i in 0..m)(asc[i,0] = true); % Fijo en todos los ascensores el primer piso
constraint forall(i in 0..m)(asc[i,n-1] = true); % Fijo en todos los ascensores el ultimo piso
%constraint forall(i in 0..n,j in 0..n)(exists(l in 0..m)((asc[l,i]=true) /\ (asc[l,j]=true)));

constraint forall(i in 0..n)(exists(j in 0..m) ( asc[j,i] == true));


solve satisfy;
output[ show_int(1,asc[i,j]) ++ " " ++ "" ++
          if j == n-1 /\ i != m-1 then "\n" else "" endif
          | i in 0..m-1,j in 0..n-1 ] ++ ["\n"];