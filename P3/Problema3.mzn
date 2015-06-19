include "alldifferent.mzn";

% Problema 3 del Proyecto 3 de Inteligencia Artificial

% Simbolos del problema
var 0..9: A; var 0..9: B; var 0..9: C;
var 0..9: D; var 0..9: E; var 0..9: F;
var 0..9: G; var 0..9: H; var 0..9: I;
var 0..9: J;

% Variables auxiliares para el calculo de los denominadores
var int: v1; var int: v2; var int: salida;

constraint alldifferent([A,B,C,D,E,F,G,H,I]);
constraint v1 = A*10000 + B*1000 + C*100 + D*10 + E;
constraint v2 =	F*10000 + G*1000 + H*100 + I*10 + J;
constraint salida = v1-v2;
constraint salida > 0;
solve minimize v1-v2;

output ["A=",show(A),"\t B=",show(B),"\t C=",show(C),"\t D=",show(D),"\t E=",show(E),
		"\t F=",show(F),"\t G=",show(G), "\t H=",show(H),"\t I=",show(I),
		"\t Numero=",show(salida)];
