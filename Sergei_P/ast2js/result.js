var realVal1={};
var realVal2=((3.14159*1+4)^(true+(((4)))));
function bubble_sort(arr,size){ var bubble_sort=undefined
var i=((0));
var buf={};
var swap_cnt=((0));
var retVal=((false));
if(((((size==0))))){
retVal=((false))
}{
while(((((i<size))))){
if(((((((((((i+1)))!=size)))) && ((((arr[((i))]>arr[((i+1))])))))))){
buf=((arr[((i))]))
arr=(arr===undefined?{}:arr);arr[((i))]=((arr[((i+1))]))
arr=(arr===undefined?{}:arr);arr[((i+1))]=((buf))
swap_cnt=((1))
}

i=((i+1))
if((((((((i==size)))) && ((((swap_cnt==1)))))))){
swap_cnt=((0))
i=((0))
}

retVal=((true))
}

}

bubble_sort_arr=((retVal))
return bubble_sort;}

function func_without_params(){ var func_without_params=undefined
func_without_params=((true))
return func_without_params;}

function func_without_body_and_type(){ var func_without_body_and_type=undefined
return func_without_body_and_type;}

function main(arr){ var main=undefined
var size=((20));
var data1={};
var data2={};
data1=(data1===undefined?{}:data1);data1.size=((20))
data2=(data2===undefined?{}:data2);data2.size=((20))
var i={};
for(var i=((1));i<=((20));i++){
data1=(data1===undefined?{}:data1);data1.arr=(data1.arr===undefined?{}:data1.arr);data1.arr[((i))]=((i%5))
}

for(var i=((1));i>=((20));i--){
data2=(data2===undefined?{}:data2);data2.arr=(data2.arr===undefined?{}:data2.arr);data2.arr[((i))]=((i%7))
}

bubble_sort(((data1.arr)),((data1.size)))
bubble_sort(((data2.arr)),((data2.size)))
if(((((func_without_params))))){
func_without_body_and_type()
}

main=((0))
return main;}

