#ifndef _DICT_H
#define _DICT_H 1
#include "lib/stdint.h"
class Dictionary{
public:
   uint16_t* key;
   uint16_t* val;
   Dictionary(uint16_t* dictkey, uint16_t* value){
       key=dictkey;
       val=value;
   }
};

typedef Dictionary* dict;

void addItem(dict d, int idx, uint16_t* key, uint16_t* val){
    d[idx]=Dictionary(key, val);
}

void rmItem(dict d, int idx){
    d[idx]=Dictionary((uint16_t*)"\0", (uint16_t*)"\0");
}

void changeItem(dict d, int idx, uint16_t* key, uint16_t* val){
    d[idx]=Dictionary(key, val);
}

#endif