include "alldifferent.mzn";

% Problema 1 del Proyecto 3 de Inteligencia Artificial

% Simbolos del problema
var int: A; var int: B; var int: C;
var int: D; var int: E; var int: F;
var int: G; var int: H; var int: I;

% Variables auxiliares para el calculo de los denominadores
var int: d1; var int: d2; var int: d3;

constraint alldifferent([A,B,C,D,E,F,G,H,I]);
constraint (A>0) /\ (B>0) /\ (C>0) /\ (D>0) /\ (E>0) /\ (F>0) /\ (G>0) /\ (H>0) /\ (I>0);
constraint d1 = B*C;
constraint d2 = E*F;
constraint d3 = H*I;
constraint A/d1 + D/d2 + G/d3 = 1; 
solve satisfy;

output ["A=",show(A),"\t B=",show(B),"\t C=",show(C),"\t D=",show(D),"\t E=",show(E),"\t F=",show(F),"\t G=",show(G),
         "\t H=",show(H),"\t I=",show(I)];
