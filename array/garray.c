#include "garray.h"

/**
 * @brief Creates a new empty array 
 * @return an empty GArray struct with space for 1000 records
*/
GArray newGArray(){
    void **buffer = malloc(sizeof(void*)*1000);
    GArray arr = {buffer, 1000, 0};
    return arr;
}

/**
 * @brief duplicates the size of the array
*/
GArray expandGArray(GArray arr){
    arr.size*=2;
    arr.data = realloc(arr.data, arr.size);
    if(arr.data ==NULL){
        arr.size = 0;
    }
    return arr;
}

/**
 * @brief Inserts an element at the end of the array
*/
GArray GArrayPush(GArray arr, void* data){
    if(arr.size<=arr.last_index+1){
        arr = expandGArray(arr);
    }
    arr.data[arr.last_index++]=data;
    return arr;
}

/**
 * @brief Deletes the last element of the array
*/
GArray GArrayPop(GArray arr, DestructorFunction f){
    if(arr.last_index==0) return arr;
    void* last_data = arr.data[arr.last_index-1];
    arr.last_index--;
    f(last_data);
    return arr;
}

/**
 * @brief Inserts the data in the array at the given index and shifts the rest of elements to the right
*/
GArray GArrayInsert(GArray arr, size_t index, void* data){
    if(index>arr.last_index || index < 0) return arr;
    if(arr.size<=arr.last_index+1){
        arr = expandGArray(arr);
    }
    void* aux = arr.data[index];
    arr.data[index++] = data;
    for(;index<=arr.last_index;index++){
        void* next = arr.data[index];
        arr.data[index]=aux;
        aux=next;
    }
    arr.last_index++;
    return arr;
}

/**
 * @brief Inserts the data in the array at the given index, 
 * freeing and overwriting the previous element at that position
*/
GArray GArrayUpdate(GArray arr, size_t index, void* data, DestructorFunction f){
    if(index>=arr.last_index || index < 0) return arr;
    void* aux = arr.data[index];
    arr.data[index] = data;
    f(aux);
    return arr;
}

/**
 * @brief Deletes the element at the given index and shifts the rest of elements to the left
*/
GArray GArrayDelete(GArray arr, size_t index, DestructorFunction f){
    if(index>=arr.last_index || index < 0) return arr;
    void* aux = arr.data[index];
    f(aux);
    for(;index<arr.last_index;index++){
        void* next = arr.data[index+1];
        arr.data[index]=next;
    }
    arr.last_index--;
    return arr;
}



void merge(void** arr, int left, int mid, int right, ComparisonFunction comp){
    int i,j,k;
    int n1 = mid-left+1, n2=right-mid;
    void* L[n1];
    void* R[n2];
    for(i=0;i<n1;i++){
        L[i]=arr[left+i];
    }
    for(j=0;j<n2;j++){
        R[j]=arr[mid+j+1];
    }
    i=0; j=0; k=left;
    while(i<n1 && j<n2){
        if(comp(L[i],R[j])<0){
            arr[k++]=L[i++];
        }else{
            arr[k++]=R[j++];
        }
    }
    while(i<n1){
        arr[k++]=L[i++];
    }
    while(j<n2){
        arr[k++]=R[j++];
    }
}

void mergeSort(void** arr, int left, int right, ComparisonFunction comp){
    if(left<right){
        int mid = (left+right)/2;
        mergeSort(arr, left, mid, comp);
        mergeSort(arr, mid+1, right, comp);
        merge(arr, left, mid, right, comp);
    }
}

/**
 * @brief Sorts the array acording to some comparison function
*/
GArray GArraySort(GArray arr, ComparisonFunction comp){
    mergeSort(arr.data, 0, arr.last_index, comp);
    return arr;
}

/**
 * @brief Maps the parsing function to the array
*/
void GArrayMap(GArray arr, ParsingFunction parse){
    for(int i=0; i<arr.last_index;i++){
        parse(arr.data[i]);
    }
}