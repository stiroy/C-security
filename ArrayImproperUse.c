#include <stdio.h>

struct list{
    size_t size;
    void** list;
};
typedef struct list List;

char GetValue(List list, int place){
    return list->data[place]; // 10 12 
}

int main(){

    

    return 0;
}