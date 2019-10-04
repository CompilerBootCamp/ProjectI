#include "stdbool.h"

float realVal1;
float realVal2 = 3.14159; /* В I сделать объявляение переменной БЕЗ явного указания типа */

typedef struct Data_child {
    int arr[20];
	int size;
} Data_child;

typedef Data_child Data;

bool bubble_sort(int *arr, int size)
{
    int i;
    int buf;
    char swap_cnt = 0;
    bool retVal = false;

    i = 0;

    if (size == 0)
    {
        retVal = false;
    } else {
        while (i < size)
        {
            if ( ((i + 1) != size) && (arr[i] > arr[i + 1]) )
            {
                buf = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = buf;
                swap_cnt = 1;
            }
            i++;
            if (i == size && swap_cnt == 1)
            {
                swap_cnt = 0;
                i = 0;
            }
            retVal = true;
        }
	}
    return retVal;
}
	
bool func_without_params (void) {
    return true;	
}
	
void func_without_body_and_type (void) {

}

int main (int* arr) {
    int size = 20;/* В I сделать объявляение переменной БЕЗ явного указания типа */
    Data data1;
    Data data2;

    data1.size = 20;
    data2.size = 20;
    
    for(int i = 1; i <= 20; i++) {
        data1.arr[i] = i % 5;
    }

    for(int i = 20; i >= 1; i--) {
        data2.arr[i] = i % 7;
    }

    bubble_sort(data1.arr, data1.size);
    bubble_sort(data2.arr, data2.size);	

    if (func_without_params()) {
        func_without_body_and_type();
    }

    return 0;
}
