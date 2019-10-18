type arr is array[ 11 ] integer;
type rec is record
	var qq : real;
	var aa : integer;
	var bb : boolean;
end;

var a: arr;
var s: integer is 33;
var rer : rec;
var r : real;

routine fun1(x:integer):integer is
var s:integer is 0;
rer.aa := 12;
	rer.aa := 12;
	fun1 := s + x;
end;

routine g2(x:integer):integer is
var s:integer;
  s := fun1(x);
  if s = 8 then
   x := 0;
   s := 1;
  else 
   x := 1;
   s := 0;
  end;

 for i in 1 .. 7 loop 
    a[i]:= 0;
    s := a[i];
   end;


  while(s > 10) loop
    s := s + 1;
    a[i]:= 0;
     if s = 8 then
	   x := 0;
	   s := 1;
	  else 
	   x := 1;
	   s := 0;
	  end;
   end;


 g2:= 0;
end;