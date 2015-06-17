include "alldifferent.mzn";

% Problema 5 del Proyecto 3 de Inteligencia Artificial


array[0..5,0..9] of var 1..12: tab; % Tablero de juego

% Figuras
array[0..4] of var 1..1: f1;
array[0..4] of var 2..2: f2;
array[0..4] of var 3..3: f3;
array[0..4] of var 4..4: f4;
array[0..4] of var 5..5: f5;
array[0..4] of var 6..6: f6;
array[0..4] of var 7..7: f7;
array[0..4] of var 8..8: f8;
array[0..4] of var 9..9: f9;
array[0..4] of var 10..10: f10;
array[0..4] of var 11..11: f11;
array[0..4] of var 12..12: f12;
var int: i1;
var int: i2; 
var int: i3;
var int: i4; 
var int: i5; 
var int: i6;
var int: i7; 
var int: i8; 
var int: i9;
var int: i10;
var int: i11;
var int: i12;
var int: j1;
var int: j2; 
var int: j3;
var int: j4; 
var int: j5; 
var int: j6;
var int: j7; 
var int: j8; 
var int: j9;
var int: j10;
var int: j11;
var int: j12;

constraint  ((f1[0]=tab[i1,j1])/\(f1[1]=tab[i1-1,j1])/\(f1[2]=tab[i1-1,j1+1])/\(f1[3]=tab[i1+1,j1])/\(f1[4]=tab[i1,j1-1]))\/
			((f1[0]=tab[i1,j1])/\(f1[1]=tab[i1+1,j1])/\(f1[2]=tab[i1+1,j1-1])/\(f1[3]=tab[i1-1,j1])/\(f1[4]=tab[i1,j1+1]))\/
			((f1[0]=tab[i1,j1])/\(f1[1]=tab[i1,j1-1])/\(f1[2]=tab[i1-1,j1-1])/\(f1[3]=tab[i1,j1+1])/\(f1[4]=tab[i1+1,j1]))\/
			((f1[0]=tab[i1,j1])/\(f1[1]=tab[i1,j1+1])/\(f1[2]=tab[i1+1,j1+1])/\(f1[3]=tab[i1,j1-1])/\(f1[4]=tab[i1-1,j1]));

constraint  ((f2[0]=tab[i2+1,j2])/\(f2[1]=tab[i2+2,j2])/\(f2[2]=tab[i2+3,j2])/\(f2[3]=tab[i2+4,j2])/\(f2[4]=tab[i2,j2]))\/
			((f2[0]=tab[i2,j2+1])/\(f2[1]=tab[i2,j2+2])/\(f2[2]=tab[i2,j2+3])/\(f2[3]=tab[i2,j2+4])/\(f2[4]=tab[i2,j2]));

constraint  ((f3[0]=tab[i3,j3])/\(f3[1]=tab[i3+1,j3])/\(f3[2]=tab[i3+2,j3])/\(f3[3]=tab[i3+3,j3])/\(f3[4]=tab[i3+3,j3+1]))\/
			((f3[0]=tab[i3,j3])/\(f3[1]=tab[i3+1,j3])/\(f3[2]=tab[i3+2,j3])/\(f3[3]=tab[i3+3,j3])/\(f3[4]=tab[i3,j3-1]))\/
			((f3[0]=tab[i3,j3])/\(f3[1]=tab[i3,j3+1])/\(f3[2]=tab[i3,j3+2])/\(f3[3]=tab[i3,j3+3])/\(f3[4]=tab[i3-1,j3+3]))\/
			((f3[0]=tab[i3,j3])/\(f3[1]=tab[i3,j3+1])/\(f3[2]=tab[i3,j3+2])/\(f3[3]=tab[i3,j3+3])/\(f3[4]=tab[i3+1,j3]));

constraint  ((f4[0]=tab[i4,j4])/\(f4[1]=tab[i4,j4+1])/\(f4[2]=tab[i4,j4+2])/\(f4[3]=tab[i4+1,j4+2])/\(f4[4]=tab[i4+1,j4+3]))\/
			((f4[0]=tab[i4,j4])/\(f4[1]=tab[i4,j4+1])/\(f4[2]=tab[i4,j4+2])/\(f4[3]=tab[i4-1,j4])/\(f4[4]=tab[i4-1,j4-1]))\/
			((f4[0]=tab[i4,j4])/\(f4[1]=tab[i4+1,j4])/\(f4[2]=tab[i4+2,j4])/\(f4[3]=tab[i4,j4+1])/\(f4[4]=tab[i4-1,j4+1]))\/
			((f4[0]=tab[i4,j4])/\(f4[1]=tab[i4+1,j4])/\(f4[2]=tab[i4+2,j4])/\(f4[3]=tab[i4+2,j4-1])/\(f4[4]=tab[i4+3,j4-1]));

constraint  ((f5[0]=tab[i5,j5])/\(f5[1]=tab[i5,j5+1])/\(f5[2]=tab[i5+1,j5])/\(f5[3]=tab[i5+1,j5+1])/\(f5[4]=tab[i5-1,j5+1]))\/
			((f5[0]=tab[i5,j5])/\(f5[1]=tab[i5,j5+1])/\(f5[2]=tab[i5+1,j5])/\(f5[3]=tab[i5+1,j5+1])/\(f5[4]=tab[i5,j5-1]))\/
			((f5[0]=tab[i5,j5])/\(f5[1]=tab[i5,j5+1])/\(f5[2]=tab[i5+1,j5])/\(f5[3]=tab[i5+1,j5+1])/\(f5[4]=tab[i5+2,j5]))\/
			((f5[0]=tab[i5,j5])/\(f5[1]=tab[i5,j5+1])/\(f5[2]=tab[i5+1,j5])/\(f5[3]=tab[i5+1,j5+1])/\(f5[4]=tab[i5+1,j5+2]));

constraint  ((f6[0]=tab[i6,j6])/\(f6[1]=tab[i6+1,j6])/\(f6[2]=tab[i6-1,j6-1])/\(f6[3]=tab[i6-1,j6])/\(f6[4]=tab[i6-1,j6+1]))\/
			((f6[0]=tab[i6,j6])/\(f6[1]=tab[i6+1,j6])/\(f6[2]=tab[i6+2,j6-1])/\(f6[3]=tab[i6+2,j6])/\(f6[4]=tab[i6+2,j6+1]))\/
			((f6[0]=tab[i6,j6])/\(f6[1]=tab[i6,j6+1])/\(f6[2]=tab[i6-1,j6+2])/\(f6[3]=tab[i6,j6+2])/\(f6[4]=tab[i6+1,j6+2]))\/
			((f6[0]=tab[i6,j6])/\(f6[1]=tab[i6,j6+1])/\(f6[2]=tab[i6-1,j6-1])/\(f6[3]=tab[i6,j6-1])/\(f6[4]=tab[i6+1,j6-1]));

constraint  ((f7[0]=tab[i7,j7])/\(f7[1]=tab[i7,j7-1])/\(f7[2]=tab[i7,j7+1])/\(f7[3]=tab[i7-1,j7-1])/\(f7[4]=tab[i7-1,j7+1]))\/
			((f7[0]=tab[i7,j7])/\(f7[1]=tab[i7,j7-1])/\(f7[2]=tab[i7,j7+1])/\(f7[3]=tab[i7+1,j7-1])/\(f7[4]=tab[i7+1,j7+1]))\/
			((f7[0]=tab[i7,j7])/\(f7[1]=tab[i7-1,j7])/\(f7[2]=tab[i7+1,j7])/\(f7[3]=tab[i7-1,j7+1])/\(f7[4]=tab[i7+1,j7+1]))\/
			((f7[0]=tab[i7,j7])/\(f7[1]=tab[i7-1,j7])/\(f7[2]=tab[i7+1,j7])/\(f7[3]=tab[i7-1,j7-1])/\(f7[4]=tab[i7+1,j7-1]));

constraint  ((f8[0]=tab[i8,j8])/\(f8[1]=tab[i8-1,j8])/\(f8[2]=tab[i8+1,j8])/\(f8[3]=tab[i8-1,j8+1])/\(f8[4]=tab[i8-1,j8+2]))\/
			((f8[0]=tab[i8,j8])/\(f8[1]=tab[i8-1,j8])/\(f8[2]=tab[i8+1,j8])/\(f8[3]=tab[i8+1,j8-2])/\(f8[4]=tab[i8+1,j8-1]))\/
			((f8[0]=tab[i8,j8])/\(f8[1]=tab[i8-1,j8])/\(f8[2]=tab[i8+1,j8])/\(f8[3]=tab[i8-1,j8-2])/\(f8[4]=tab[i8-1,j8-1]))\/
			((f8[0]=tab[i8,j8])/\(f8[1]=tab[i8-1,j8])/\(f8[2]=tab[i8+1,j8])/\(f8[3]=tab[i8+1,j8+1])/\(f8[4]=tab[i8+1,j8+2]));

constraint  ((f9[0]=tab[i9,j9])/\(f9[1]=tab[i9+1,j9])/\(f9[2]=tab[i9+1,j9+1])/\(f9[3]=tab[i9+2,j9+1])/\(f9[4]=tab[i9+2,j9+2]))\/
			((f9[0]=tab[i9,j9])/\(f9[1]=tab[i9+1,j9])/\(f9[2]=tab[i9+1,j9-1])/\(f9[3]=tab[i9+2,j9-1])/\(f9[4]=tab[i9+2,j9-2]))\/
			((f9[0]=tab[i9,j9])/\(f9[1]=tab[i9,j9-1])/\(f9[2]=tab[i9+1,j9-1])/\(f9[3]=tab[i9+1,j9-2])/\(f9[4]=tab[i9+2,j9-2]))\/
			((f9[0]=tab[i9,j9])/\(f9[1]=tab[i9,j9+1])/\(f9[2]=tab[i9+1,j9+1])/\(f9[3]=tab[i9+1,j9+2])/\(f9[4]=tab[i9+2,j9+2]));

constraint  ((f10[0]=tab[i10,j10])/\(f10[1]=tab[i10-1,j10])/\(f10[2]=tab[i10+1,j10])/\(f10[3]=tab[i10,j10-1])/\(f10[4]=tab[i10,j10+1]));

constraint  ((f11[0]=tab[i11,j11])/\(f11[1]=tab[i11+1,j11])/\(f11[2]=tab[i11+2,j11])/\(f11[3]=tab[i11+3,j11])/\(f11[4]=tab[i11+1,j11-1]))\/
			((f11[0]=tab[i11,j11])/\(f11[1]=tab[i11+1,j11])/\(f11[2]=tab[i11+2,j11])/\(f11[3]=tab[i11+3,j11])/\(f11[4]=tab[i11+2,j11+1]))\/
			((f11[0]=tab[i11,j11])/\(f11[1]=tab[i11,j11+1])/\(f11[2]=tab[i11,j11+2])/\(f11[3]=tab[i11,j11+3])/\(f11[4]=tab[i11-1,j11+2]))\/
			((f11[0]=tab[i11,j11])/\(f11[1]=tab[i11,j11+1])/\(f11[2]=tab[i11,j11+2])/\(f11[3]=tab[i11,j11+3])/\(f11[4]=tab[i11+1,j11+1]));

constraint  (((f12[0]=tab[i12,j12])/\(f12[1]=tab[i12,j12+1])/\(f12[2]=tab[i12,j12+2])/\(f12[3]=tab[i12-1,j12+2])/\(f12[4]=tab[i12+1,j12]))\/
			((f12[0]=tab[i12,j12])/\(f12[1]=tab[i12+1,j12])/\(f12[2]=tab[i12+2,j12])/\(f12[3]=tab[i12+2,j12-1])/\(f12[4]=tab[i12,j12+1])));

% constraint aux = (f1++f2);


% constraint tab[i1,j1]!=tab[i2,j2];
% constraint tab[i2,j2]!=tab[i3,j3];
% constraint tab[i3,j3]!=tab[i4,j4];
% constraint tab[i4,j4]!=tab[i5,j5];
% constraint tab[i5,j5]!=tab[i6,j6];
% constraint tab[i6,j6]!=tab[i7,j7];
% constraint tab[i7,j7]!=tab[i8,j8];
% constraint tab[i8,j8]!=tab[i9,j9];
% constraint tab[i9,j9]!=tab[i10,j10];
% constraint tab[i10,j10]!=tab[i11,j11];
% constraint tab[i11,j11]!=tab[i12,j12];

% constraint alldifferent ([ aux[i] | i in 0..30]);

solve satisfy;
output[ show_int(1,tab[i,j]) | i in 0..5,j in 0..9];