#include "lib/stdint.h"
typedef struct{
    uint16_t key;
    uint64_t* val;
} Dictionary;

typedef struct{Dictionary x[1000000];} dict;

void addItem(dict dic, int idx, uint16_t key, uint64_t* val){
    Dictionary d;
    d.key=key;
    d.val=val;
    dic.x[idx]=d;
}

void rmItem(dict dic, int idx){
    Dictionary d;
    char* null="\0";
    d.key=(uint16_t)'\0';
    d.val=(uint64_t*)null;
    dic.x[idx]=d;
}

void changeItem(dict dic, int idx, uint16_t key, uint64_t* val){
    Dictionary d;
    d.key=key;
    d.val=val;
    dic.x[idx]=d;
}   