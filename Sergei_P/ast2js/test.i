var realVal1 : real;
var realVal2 is 3.14159 * 1 + 4 xor true + (4);
type Data_child is record
	var arr : array [20] integer;
	var size : integer;
end;
type Data is Data_child;
type bubble_sort_arr is array [] integer;
routine bubble_sort (arr : bubble_sort_arr, size : integer) : boolean is
	var i is 0;
	var buf : integer;
	var swap_cnt is 0;
	var retVal is false;
	if (size = 0) then 
		retVal := false;
	else
		while (i < size) loop
			if ( ((i + 1) /= size) and (arr[i] > arr[i + 1]) ) then
				buf := arr[i];
				arr[i] := arr[i + 1];
				arr[i + 1] := buf;
				swap_cnt := 1;				
			end;
			i := i + 1;
			if ( (i = size) and (swap_cnt = 1) ) then
				swap_cnt := 0;
				i := 0;
			end;
			retVal := true;
		end;
	end;
	bubble_sort_arr := retVal;
end;
routine func_without_params : boolean is
	func_without_params := true;
end;
routine func_without_body_and_type;
routine main (arr : bubble_sort_arr) : integer is
	var size is 20;
	var data1 : Data;
	var data2 : Data;
	data1.size := 20;
	data2.size := 20;
	var i : Integer;
	for i in 1..20 loop
		data1.arr[i] := i % 5;
	end;
	for i in reverse 1..20 loop
		data2.arr[i] := i % 7;
	end;
	bubble_sort(data1.arr, data1.size);
	bubble_sort(data2.arr, data2.size);
	if (func_without_params) then
		func_without_body_and_type();
	end;
	main := 0;
end;
