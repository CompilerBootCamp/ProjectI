//comment
var g_real_val : real;
var g_real_val_init : real is 3.14;
//wrong - var g_real_val_init : real is 5; < Type is another. it is not Assignment!
//wrong - var g_real_val_init : real is g_real_val + 5; < var in init

var g_int_val : integer;
var g_int_val_init : integer is 0;


var g_bool_val : boolean;
var g_bool_val_init : boolean is false;
//wrong - var g_bool_val_init : boolean is 5; Type is another.it is not Assignment!
//wrong - var g_bool_val_init : boolean is 0; Type is another. it is not Assignment!
var g_bool_val_init_true  is 1 < 5;

routine func_without_body_and_type();

routine ret_real() : real is
ret_real := g_real_val_init;
end;

routine ret_real1() : real is
ret_real1 := 0.0;
end;

routine ret_int() : real is
ret_int := g_int_val_init; end;

routine ret_int2() : real is
ret_int2 := g_int_val; end;

routine ret_int1() : real is
ret_int1 := 1; end;

routine ret_bool() : bool
 is
  ret_bool := false;
 end;

routine ret_bool1() : bool
 is
  return := g_bool_val;
 end;

type 
Record_type is 
    record 
        var arr : array [20] integer;
        var r_val : real is 5.0;
	var bool : boolean;
	var rec : record is
		var int is 1;
	end;
    end; //type Record_type


type Array is array[1] boolean;
//wrong - type Array is array[0] boolean; < zero in size

type Array_RT is array[2 + 3] Record_type;

type Array_arr is array[2] Array;
//wrong - type Array_arr is array[g_int_val*2] Array;

type Array_arr is array[9*8 + 1] Array_RT;
//wrong - type Array_arr is array[ret_int1()] Array_RT; < call in size
//wrong - type Array_arr is array[1.0] Array_RT; < real in size
//wrong - type Array_arr is array[1/5] Array_RT; < zero in size
//wrong - type Array_arr is array[ 1 < 3] Array_RT; < bool in size

routine ret_Array(arr : Array) : Array
 is 
  ret_Array := arr;
end;

routine ret_Array1(arr : Array) : Array
 is
  arr[1] := false;
//wrong -   arr[0] := false;
  ret_Array1 := arr;
end;

routine ret_Array2(arr : Array) : array[1] boolean
 is 
  ret_Array2 := arr;
end;

//wrong -routine ret_Array2(arr : Array) : array[2] boolean
//wrong - is 
//wrong -  ret_Array2 := arr; < Type is another
//wrong - end;

//wrong -routine ret_Array2(arr : Array) : array[1] boolean
//wrong - is 
//wrong -  ret_Array2 := arr;
//wrong -  arr[1] = false; < after return
//wrong - end;

//wrong -routine ret_Array2(arr : Array) : array[1] boolean
//wrong - is 
//wrong -  ret_Array2 := arr;
//wrong -  g_int_val = 1; < after return
//wrong - end;

routine ret_Array3(arr : array[] boolean) : array[1] boolean
 is 
  ret_Array3 := arr;
end;

routine ret_Array4(arr : array[] boolean) : array[] boolean
 is 
  ret_Array4 := arr;
end;

routine get_Record_type(rec : Record_type) 
is
 rec.rec.int := 0;
end;

routine ret_Record_type_field(rec : Record_type) : int 
is
  ret_Record_type_field := rec.rec.int;
end;

type Record_type is
record is
 var R : record is
  var R : record is
   var R : record is
    var R : array[1+1-1] real;
    end;
   end;
  end;
 end;
end;//type

routine get_R(R : Record_type) : int
is
 get_R := R.R.R.R.R[1];
end;

routine set_R(R : Record_type) : boolean
is
 R.R.R.R.R[1] := true;
 set_R := 1;
//wrong - set_R := 5;
end;


routine do_nothing(a: integer, b : real, c : boolean)
is
end;

routine do_nothing_not_ret(a: integer, b : real, c : boolean)
is
//wrong - do_nothing_not_ret:= 1;
end;

//wrong -routine do_nothing(a: integer, b : real, c : boolean) : boolean 
//wrong -is < where is return !!!
//wrong -end;


routine fun_call_other()
is
 do_nothing(1, 5.0, false);
//wrong - do_nothing(1, 5, false);
//wrong - do_nothing(1, 5.0, 1);
//wrong - do_nothing(6.0, 5.0, 0);
//wrong - do_nothing(1, 5.0);
end;


routine fun_loop()
is
 var arr : array [55] integer;
 for i in -1-1 .. 8*5  //without reverse may be))
  loop
    if i >= 1 and i <= 2
	then
	  arr[i-1] := i;
	  arr[i] := arr[i] + i;
	  arr[i*2] := true;
	  arr[i*7/2] := g_int_val;
	else
	end; //if
  end;//for
  
  while 1 < arr [9] 
   loop
   end;

  var i is 0;

   while 1 < arr [9] or arr[1] = 88;
   loop
	arr[i+1] := -1;
   end;
end;

//wrong - for i in 0 .. g_int_val < var in size
//wrong - for i in 0 .. true < bool in size


routine fun_loop1(a: array [] integer)
is
	for i in 1 .. -1
	loop
	 a[i] := true; //wrong - runtime when i = -1
	 g_real_val_init = a[i+1];
	 g_int_val = 1;
	 var local_arr : array[55] integer;
	 var local_int is false;
	 local_int := local_int and false;
	 local_int = g_int_val; //wrong - runtime ?????
//wrong - local_int := local_int and 1; << 1 is not bool
	end;//for
end;


routine fun_loop2(a: array [] integer)
is
	for i in 1 .. -1
	loop
		while 1 < a [9]  and a[i] = 1
		loop
		 i := i + 1; //wrong - runtime ?????
		end;
	end;//for
end;


routine fun_loop3(a: array [] integer)
is

	while 1 < a [9]  and a[1] = 1
	loop
	  for i in 1 .. 1
	  loop
		a [9] := a[i];
	  end;

	  for i in 1 .. 1
	  loop
		i := i + i;
		a [i] := a[i+1];
	  end;

	  while 1 < a [9]  or a[1] = 1
	  loop
		a [9] := i;
		a [i] := 1;
	  end;
	end;
end;



routine fun_loop3(a: array [] integer)
is

	while 1 < a [9]  and a[1] = 1
	loop
	  for i in 1 .. 1
	  loop
		a [9] := a[i];
	  end;

	  for i in 1 .. 1
	  loop
		i := i + i;
		a [i] := a[i+1];
	  end;
//wrong - i := 0

	  while 1 < a [9]  or a[1] = 1
	  loop
		a [9] := i;
		a [i] := 1;
	  end;
	end;
end;


routine ret_from_loop(a: array [] integer)
 : boolean
is
	var a is 3.3;
//wrong - a < 9.0; < expression without Assignment
//wrong - a[0+1] + 1; < expression without Assignment
	while 1 < a [9]  and a[1] = 1
	loop
		if a[1] = 0 then
		 ret_from_loop := 0; //wrong - ?????
		end;
//wrong -	if 5 then << incopatible
//wrong -	if 0 then << incopatible
//wrong -	if 0.0 then << incopatible
	  end;
ret_from_loop := 1.0; //wrong - ?????
//wrong - ret_from_loop := 5; << incompatible
end;


var global is false;

routine check(global : int)
is
	global := 3;
end;

routine check1(global : boolean)
is
	global := false;
end;


routine check2(global : boolean)
is
	var global is 33;
	global := 10.0;
end;







 
