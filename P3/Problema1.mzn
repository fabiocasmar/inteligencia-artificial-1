include "alldifferent.mzn";

% Problema 1 del Proyecto 3 de Inteligencia Artificial

% Simbolos del problema
var 1..9: A; var 1..9: B; var 1..9: C;
var 1..9: D; var 1..9: E; var 1..9: F;
var 1..9: G; var 1..9: H; var 1..9: I;

% Variables auxiliares para el calculo de los denominadores
var int: d1; var int: d2; var int: d3;

constraint alldifferent([A,B,C,D,E,F,G,H,I]);
constraint d1 = B*C;
constraint d2 = E*F;
constraint d3 = H*I;
constraint A/d1 + D/d2 + G/d3 = 1; 
solve satisfy;

output ["A=",show(A),"\t B=",show(B),"\t C=",show(C),"\t D=",show(D),"\t E=",show(E),"\t F=",show(F),"\t G=",show(G),
         "\t H=",show(H),"\t I=",show(I)];
