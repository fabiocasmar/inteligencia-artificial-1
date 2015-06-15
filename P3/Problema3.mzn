include "alldifferent.mzn";

% Problema 3 del Proyecto 3 de Inteligencia Artificial

% Simbolos del problema
var int: A; var int: B; var int: C;
var int: D; var int: E; var int: F;
var int: G; var int: H; var int: I;

% Variables auxiliares para el calculo de los denominadores
var int: v1; var int: v2; var int: salida;

constraint alldifferent([A,B,C,D,E,F,G,H,I]);
constraint (A>=0) /\ (A<10) /\ (B>=0) /\ (B<10) /\ (C>=0) /\ (C<10) /\ (D>=0) /\ (D<10) /\ (E>=0) /\ (E<10) /\ (F>=0) /\ (F<10) /\ (G>=0) /\ (G<10) /\ (H>=0) /\ (H<10) /\ (I>=0) /\ (I<10);
constraint v1 = A*10000 + B*1000 + C*100 + D*10 + E*1;
constraint v2 =			  F*1000 + G*100 + H*10 + I*1;
constraint salida = v1-v2;
constraint salida > 0;
solve minimize v1-v2;

output ["A=",show(A),"\t B=",show(B),"\t C=",show(C),"\t D=",show(D),"\t E=",show(E),
		"\t F=",show(F),"\t G=",show(G), "\t H=",show(H),"\t I=",show(I),
		"\t Numero=",show(salida)];
