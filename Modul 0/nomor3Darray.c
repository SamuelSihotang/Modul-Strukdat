#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

// Struktur ADT DynamicArray

typedef struct dynamicarr_t {
    char *_arr;
    unsigned _size, _capacity;
} DynamicArray;

// Prototipe fungsi

void dArray_init(DynamicArray *darray);
bool dArray_isEmpty(DynamicArray *darray);
void dArray_pushBack(DynamicArray *darray, char value);
void dArray_popBack(DynamicArray *darray);
char  dArray_back(DynamicArray *darray);
char  dArray_front(DynamicArray *darray);
void dArray_setAt(DynamicArray *darray, unsigned index, char value);
char  dArray_getAt(DynamicArray *darray, unsigned index);

// Definisi fungsi

void dArray_init(DynamicArray *darray)
{
    darray->_capacity = 2u;
    darray->_size = 0u;
    darray->_arr = (char*) malloc(sizeof(char) * 2);
}

bool dArray_isEmpty(DynamicArray *darray) {
    return (darray->_size == 0);
}

void dArray_pushBack(DynamicArray *darray, char value)
{
    if (darray->_size + 1 > darray->_capacity) {
        unsigned it;
        darray->_capacity *= 2;
        if(darray->_capacity > 100){
            darray->_capacity = 100;    
        }
        char *newArr = (char*) malloc(sizeof(char) * darray->_capacity);

        for (it=0; it < darray->_size; ++it)
            newArr[it] = darray->_arr[it];
        
        char *oldArray = darray->_arr;
        darray->_arr = newArr;
        free(oldArray);
    }
    if(darray->_size <= 100){
        darray->_arr[darray->_size++] = value;
    } 
}

void dArray_popBack(DynamicArray *darray) {
    if (!dArray_isEmpty(darray)) darray->_size--;
    else return;
}

char dArray_back(DynamicArray *darray) {
    if (!dArray_isEmpty(darray))
        return darray->_arr[darray->_size-1];
    else return 0;
}

char dArray_front(DynamicArray *darray) {
    if (!dArray_isEmpty(darray))
        return darray->_arr[0];
    else return 0;
}

void dArray_setAt(DynamicArray *darray, unsigned index, char value)
{
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size)
            darray->_arr[darray->_size-1] = value;
        else
            darray->_arr[index] = value;
    }
}

char dArray_getAt(DynamicArray *darray, unsigned index)
{
    if (!dArray_isEmpty(darray)) {
        if (index >= darray->_size)
            return darray->_arr[darray->_size-1];
        else
            return darray->_arr[index];
    }
}

void getString(DynamicArray *arr){
    int temp = 0;
    char check;
    while(1){
        temp = scanf("%c", &check);
        if(temp == EOF || temp == ' '){
            break;
        }
        dArray_pushBack(arr, check);
    }
    dArray_pushBack(arr, '\0');
}

void print(DynamicArray *arr){
    for(int i = 0; i < 101; ++i){
        printf("%c", arr->_arr[i]);
    }
}
/* Gunakan ini untuk mempersingkat penulisan kode */

#define d_init dArray_init
#define d_isEmpty dArray_isEmpty
#define d_pushBack dArray_pushBack
#define d_popBack dArray_popBack
#define d_back dArray_back
#define d_front dArray_front
#define d_setAt dArray_setAt
#define d_getAt dArray_getAt
#define MAX 100 //gajadi

int main(){
    // Buat objek DynamicArray
    DynamicArray myArray;

    // PENTING! Jangan lupa diinisialisasi
    dArray_init(&myArray);

    getString(&myArray);

    print(&myArray);
}