include "alldifferent.mzn";

% Problema 5 del Proyecto 3 de Inteligencia Artificial

set of int: rangoi = 0..5;
set of int: rangoj = 0..9;

array[rangoi,rangoj] of var 1..12: tab; % Tablero de juego
array[0..12] of var int: a1;
% array[0..2] of var int: a2;

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

constraint forall(i in 0..4) (f1[i] = 1);
constraint forall(i in 0..4) (f2[i] = 2);
constraint forall(i in 0..4) (f3[i] = 3);
constraint forall(i in 0..4) (f4[i] = 4);
constraint forall(i in 0..4) (f5[i] = 5);
constraint forall(i in 0..4) (f6[i] = 6);
constraint forall(i in 0..4) (f7[i] = 7);
constraint forall(i in 0..4) (f8[i] = 8);
constraint forall(i in 0..4) (f9[i] = 9);
constraint forall(i in 0..4) (f10[i] = 10);
constraint forall(i in 0..4) (f11[i] = 11);
constraint forall(i in 0..4) (f12[i] = 12);

constraint  exists(i in rangoi,j in rangoj)((
			((f1[0]=tab[i,j])/\(f1[1]=tab[i-1,j])/\(f1[2]=tab[i-1,j+1])/\(f1[3]=tab[i+1,j])/\(f1[4]=tab[i,j-1]))\/
			((f1[0]=tab[i,j])/\(f1[1]=tab[i+1,j])/\(f1[2]=tab[i+1,j-1])/\(f1[3]=tab[i-1,j])/\(f1[4]=tab[i,j+1]))\/
			((f1[0]=tab[i,j])/\(f1[1]=tab[i,j-1])/\(f1[2]=tab[i-1,j-1])/\(f1[3]=tab[i,j+1])/\(f1[4]=tab[i+1,j]))\/
			((f1[0]=tab[i,j])/\(f1[1]=tab[i,j+1])/\(f1[2]=tab[i+1,j+1])/\(f1[3]=tab[i,j-1])/\(f1[4]=tab[i-1,j]))\/
			((f1[0]=tab[i,j])/\(f1[1]=tab[i-1,j])/\(f1[2]=tab[i,j+1])/\(f1[3]=tab[i+1,j])/\(f1[4]=tab[i-1,j-1]))\/
			((f1[0]=tab[i,j])/\(f1[1]=tab[i+1,j])/\(f1[2]=tab[i,j-1])/\(f1[3]=tab[i-1,j])/\(f1[4]=tab[i+1,j+1]))\/
			((f1[0]=tab[i,j])/\(f1[1]=tab[i,j-1])/\(f1[2]=tab[i-1,j])/\(f1[3]=tab[i,j+1])/\(f1[4]=tab[i+1,j-1]))\/
			((f1[0]=tab[i,j])/\(f1[1]=tab[i,j+1])/\(f1[2]=tab[i+1,j])/\(f1[3]=tab[i,j-1])/\(f1[4]=tab[i-1,j+1])))/\(i1=i)/\(j1=j));

constraint  exists(i in rangoi,j in rangoj) ((((tab[i+1,j]=f2[0])/\(tab[i+2,j]=f2[1])/\(tab[i+3,j]=f2[2])/\(tab[i+4,j]=f2[3])/\(tab[i,j]=f2[4]))\/
			((tab[i,j]=f2[0])/\(tab[i,j+2]=f2[1])/\(tab[i,j+3]=f2[2])/\(tab[i,j+4]=f2[3])/\(tab[i,j]=f2[4])))/\ (i2 = i) /\ (j2 = j));

constraint  exists(i in rangoi,j in rangoj)(((
			(f3[0]=tab[i,j])/\(f3[1]=tab[i+1,j])/\(f3[2]=tab[i+2,j])/\(f3[3]=tab[i+3,j])/\(f3[4]=tab[i+3,j+1]))\/
			((f3[0]=tab[i,j])/\(f3[1]=tab[i+1,j])/\(f3[2]=tab[i+2,j])/\(f3[3]=tab[i+3,j])/\(f3[4]=tab[i,j-1]))\/
			((f3[0]=tab[i,j])/\(f3[1]=tab[i,j+1])/\(f3[2]=tab[i,j+2])/\(f3[3]=tab[i,j+3])/\(f3[4]=tab[i-1,j+3]))\/
			((f3[0]=tab[i,j])/\(f3[1]=tab[i,j+1])/\(f3[2]=tab[i,j+2])/\(f3[3]=tab[i,j+3])/\(f3[4]=tab[i+1,j]))\/
			((f3[0]=tab[i,j])/\(f3[1]=tab[i+1,j])/\(f3[2]=tab[i+2,j])/\(f3[3]=tab[i+3,j])/\(f3[4]=tab[i+3,j-1]))\/
			((f3[0]=tab[i,j])/\(f3[1]=tab[i+1,j])/\(f3[2]=tab[i+2,j])/\(f3[3]=tab[i+3,j])/\(f3[4]=tab[i,j+1]))\/
			((f3[0]=tab[i,j])/\(f3[1]=tab[i,j+1])/\(f3[2]=tab[i,j+2])/\(f3[3]=tab[i,j+3])/\(f3[4]=tab[i+1,j+3]))\/
			((f3[0]=tab[i,j])/\(f3[1]=tab[i,j+1])/\(f3[2]=tab[i,j+2])/\(f3[3]=tab[i,j+3])/\(f3[4]=tab[i-1,j])))/\(i3=i)/\(j3=j));


constraint  exists(i in rangoi,j in rangoj)((
			((f4[0]=tab[i,j])/\(f4[1]=tab[i,j+1])/\(f4[2]=tab[i,j+2])/\(f4[3]=tab[i+1,j+2])/\(f4[4]=tab[i+1,j+3]))\/
			((f4[0]=tab[i,j])/\(f4[1]=tab[i,j+1])/\(f4[2]=tab[i,j+2])/\(f4[3]=tab[i-1,j])/\(f4[4]=tab[i-1,j-1]))\/
			((f4[0]=tab[i,j])/\(f4[1]=tab[i+1,j])/\(f4[2]=tab[i+2,j])/\(f4[3]=tab[i,j+1])/\(f4[4]=tab[i-1,j+1]))\/
			((f4[0]=tab[i,j])/\(f4[1]=tab[i+1,j])/\(f4[2]=tab[i+2,j])/\(f4[3]=tab[i+2,j-1])/\(f4[4]=tab[i+3,j-1]))\/
			((f4[0]=tab[i,j])/\(f4[1]=tab[i,j+1])/\(f4[2]=tab[i,j+2])/\(f4[3]=tab[i-1,j+2])/\(f4[4]=tab[i-1,j+3]))\/
			((f4[0]=tab[i,j])/\(f4[1]=tab[i,j+1])/\(f4[2]=tab[i,j+2])/\(f4[3]=tab[i+1,j])/\(f4[4]=tab[i+1,j-1]))\/
			((f4[0]=tab[i,j])/\(f4[1]=tab[i+1,j])/\(f4[2]=tab[i+2,j])/\(f4[3]=tab[i,j-1])/\(f4[4]=tab[i-1,j-1]))\/
			((f4[0]=tab[i,j])/\(f4[1]=tab[i+1,j])/\(f4[2]=tab[i+2,j])/\(f4[3]=tab[i+2,j+1])/\(f4[4]=tab[i+3,j+1])))/\(i4=i)/\(j4=j));

constraint  exists(i in rangoi,j in rangoj)((((f5[0]=tab[i,j])/\(f5[1]=tab[i,j+1])/\(f5[2]=tab[i+1,j])/\(f5[3]=tab[i+1,j+1])/\(f5[4]=tab[i-1,j+1]))\/
			((f5[0]=tab[i,j])/\(f5[1]=tab[i,j+1])/\(f5[2]=tab[i+1,j])/\(f5[3]=tab[i+1,j+1])/\(f5[4]=tab[i,j-1]))\/
			((f5[0]=tab[i,j])/\(f5[1]=tab[i,j+1])/\(f5[2]=tab[i+1,j])/\(f5[3]=tab[i+1,j+1])/\(f5[4]=tab[i+2,j+1]))\/
			((f5[0]=tab[i,j])/\(f5[1]=tab[i,j+1])/\(f5[2]=tab[i+1,j])/\(f5[3]=tab[i+1,j+1])/\(f5[4]=tab[i-1,j]))\/
			((f5[0]=tab[i,j])/\(f5[1]=tab[i,j+1])/\(f5[2]=tab[i+1,j])/\(f5[3]=tab[i+1,j+1])/\(f5[4]=tab[i+1,j-1]))\/
			((f5[0]=tab[i,j])/\(f5[1]=tab[i,j+1])/\(f5[2]=tab[i+1,j])/\(f5[3]=tab[i+1,j+1])/\(f5[4]=tab[i,j+2]))\/
			((f5[0]=tab[i,j])/\(f5[1]=tab[i,j+1])/\(f5[2]=tab[i+1,j])/\(f5[3]=tab[i+1,j+1])/\(f5[4]=tab[i+2,j]))\/
			((f5[0]=tab[i,j])/\(f5[1]=tab[i,j+1])/\(f5[2]=tab[i+1,j])/\(f5[3]=tab[i+1,j+1])/\(f5[4]=tab[i+1,j+2])))/\(i5=i)/\(j5=j));

constraint  exists(i in rangoi,j in rangoj)((((f6[0]=tab[i,j])/\(f6[1]=tab[i+1,j])/\(f6[2]=tab[i-1,j-1])/\(f6[3]=tab[i-1,j])/\(f6[4]=tab[i-1,j+1]))\/
			((f6[0]=tab[i,j])/\(f6[1]=tab[i+1,j])/\(f6[2]=tab[i+2,j-1])/\(f6[3]=tab[i+2,j])/\(f6[4]=tab[i+2,j+1]))\/
			((f6[0]=tab[i,j])/\(f6[1]=tab[i,j+1])/\(f6[2]=tab[i-1,j+2])/\(f6[3]=tab[i,j+2])/\(f6[4]=tab[i+1,j+2]))\/
			((f6[0]=tab[i,j])/\(f6[1]=tab[i,j+1])/\(f6[2]=tab[i-1,j-1])/\(f6[3]=tab[i,j-1])/\(f6[4]=tab[i+1,j-1])))/\(i6=i)/\(j6=j));

constraint  exists(i in rangoi,j in rangoj)((((f7[0]=tab[i,j])/\(f7[1]=tab[i,j-1])/\(f7[2]=tab[i,j+1])/\(f7[3]=tab[i-1,j-1])/\(f7[4]=tab[i-1,j+1]))\/
			((f7[0]=tab[i,j])/\(f7[1]=tab[i,j-1])/\(f7[2]=tab[i,j+1])/\(f7[3]=tab[i+1,j-1])/\(f7[4]=tab[i+1,j+1]))\/
			((f7[0]=tab[i,j])/\(f7[1]=tab[i-1,j])/\(f7[2]=tab[i+1,j])/\(f7[3]=tab[i-1,j+1])/\(f7[4]=tab[i+1,j+1]))\/
			((f7[0]=tab[i,j])/\(f7[1]=tab[i-1,j])/\(f7[2]=tab[i+1,j])/\(f7[3]=tab[i-1,j-1])/\(f7[4]=tab[i+1,j-1])))/\(i7=i)/\(j7=j));

constraint exists(i in rangoi,j in rangoj)((((f8[0]=tab[i8,j8])/\(f8[1]=tab[i8-1,j8])/\(f8[2]=tab[i8+1,j8])/\(f8[3]=tab[i8-1,j8+1])/\(f8[4]=tab[i8-1,j8+2]))\/
			((f8[0]=tab[i8,j8])/\(f8[1]=tab[i8-1,j8])/\(f8[2]=tab[i8+1,j8])/\(f8[3]=tab[i8+1,j8-2])/\(f8[4]=tab[i8+1,j8-1]))\/
			((f8[0]=tab[i8,j8])/\(f8[1]=tab[i8-1,j8])/\(f8[2]=tab[i8+1,j8])/\(f8[3]=tab[i8-1,j8-2])/\(f8[4]=tab[i8-1,j8-1]))\/
			((f8[0]=tab[i8,j8])/\(f8[1]=tab[i8-1,j8])/\(f8[2]=tab[i8+1,j8])/\(f8[3]=tab[i8+1,j8+1])/\(f8[4]=tab[i8+1,j8+2])))/\(i8=i)/\(j8=j));

constraint exists(i in rangoi,j in rangoj)((((f9[0]=tab[i,j])/\(f9[1]=tab[i+1,j])/\(f9[2]=tab[i+1,j+1])/\(f9[3]=tab[i+2,j+1])/\(f9[4]=tab[i+2,j+2]))\/
			((f9[0]=tab[i,j])/\(f9[1]=tab[i+1,j])/\(f9[2]=tab[i+1,j-1])/\(f9[3]=tab[i+2,j-1])/\(f9[4]=tab[i+2,j-2]))\/
			((f9[0]=tab[i,j])/\(f9[1]=tab[i,j-1])/\(f9[2]=tab[i+1,j-1])/\(f9[3]=tab[i+1,j-2])/\(f9[4]=tab[i+2,j-2]))\/
			((f9[0]=tab[i,j])/\(f9[1]=tab[i,j+1])/\(f9[2]=tab[i+1,j+1])/\(f9[3]=tab[i+1,j+2])/\(f9[4]=tab[i+2,j+2])))/\(i9=i)/\(j9=j));

constraint exists(i in rangoi,j in rangoj)((((f10[0]=tab[i,j])/\(f10[1]=tab[i-1,j])/\(f10[2]=tab[i+1,j])
                  /\(f10[3]=tab[i,j-1])/\(f10[4]=tab[i,j+1])))/\(i10=i)/\(j10=j));

constraint  exists(i in rangoi,j in rangoj)(
			(((f11[0]=tab[i,j])/\(f11[1]=tab[i+1,j])/\(f11[2]=tab[i+2,j])/\(f11[3]=tab[i+3,j])/\(f11[4]=tab[i+1,j-1]))\/
			((f11[0]=tab[i,j])/\(f11[1]=tab[i+1,j])/\(f11[2]=tab[i+2,j])/\(f11[3]=tab[i+3,j])/\(f11[4]=tab[i+2,j+1]))\/
			((f11[0]=tab[i,j])/\(f11[1]=tab[i,j+1])/\(f11[2]=tab[i,j+2])/\(f11[3]=tab[i,j+3])/\(f11[4]=tab[i-1,j+2]))\/
			((f11[0]=tab[i,j])/\(f11[1]=tab[i,j+1])/\(f11[2]=tab[i,j+2])/\(f11[3]=tab[i,j+3])/\(f11[4]=tab[i+1,j+1]))\/
			((f11[0]=tab[i,j])/\(f11[1]=tab[i+1,j])/\(f11[2]=tab[i+2,j])/\(f11[3]=tab[i+3,j])/\(f11[4]=tab[i+1,j+1]))\/
			((f11[0]=tab[i,j])/\(f11[1]=tab[i+1,j])/\(f11[2]=tab[i+2,j])/\(f11[3]=tab[i+3,j])/\(f11[4]=tab[i+2,j-1]))\/
			((f11[0]=tab[i,j])/\(f11[1]=tab[i,j+1])/\(f11[2]=tab[i,j+2])/\(f11[3]=tab[i,j+3])/\(f11[4]=tab[i+1,j+2]))\/
			((f11[0]=tab[i,j])/\(f11[1]=tab[i,j+1])/\(f11[2]=tab[i,j+2])/\(f11[3]=tab[i,j+3])/\(f11[4]=tab[i-1,j+1])))/\(i11=i)/\(j11=j));

constraint  exists(i in rangoi,j in rangoj)(
			(((f12[0]=tab[i,j])/\(f12[1]=tab[i,j+1])/\(f12[2]=tab[i,j+2])/\(f12[3]=tab[i-1,j+2])/\(f12[4]=tab[i+1,j]))\/
			((f12[0]=tab[i,j])/\(f12[1]=tab[i+1,j])/\(f12[2]=tab[i+2,j])/\(f12[3]=tab[i+2,j-1])/\(f12[4]=tab[i,j+1]))\/
			((f12[0]=tab[i,j])/\(f12[1]=tab[i,j+1])/\(f12[2]=tab[i,j+2])/\(f12[3]=tab[i+1,j+2])/\(f12[4]=tab[i-1,j]))\/
			((f12[0]=tab[i,j])/\(f12[1]=tab[i+1,j])/\(f12[2]=tab[i+2,j])/\(f12[3]=tab[i+2,j+1])/\(f12[4]=tab[i,j-1])))/\(i12=i)/\(j12=j));

constraint a1[0] = tab[i1,j1];
constraint a1[1] = tab[i3,j2];
constraint a1[2] = tab[i3,j3];
constraint a1[3] = tab[i4,j4];
constraint a1[4] = tab[i5,j5];
constraint a1[5] = tab[i6,j6];
constraint a1[6] = tab[i7,j7];
constraint a1[7] = tab[i8,j8];
constraint a1[8] = tab[i9,j9];
constraint a1[9] = tab[i10,j10];
constraint a1[10] = tab[i11,j11];
constraint a1[11] = tab[i12,j12];

% constraint a2[0] = tab[i4,j4];
% constraint a2[1] = tab[i5,j5];
% constraint a2[2] =tab[i7,j7];
% constraint (alldifferent([a2[i] |i in 0..2]));
constraint (alldifferent([a1[i] |i in 0..12]));

solve satisfy;
output[ show_int(1,tab[i,j]) ++ " " ++ "" ++
          if j == 9 /\ i != 5 then "\n" else "" endif
          | i in rangoi,j in rangoj ] ++ ["\n"];