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

typedef struct dict{Dictionary d[100000000];} dict;

void addItem(dict dic, int idx, uint16_t* key, uint16_t* val){
    dic.d[idx]=Dictionary(key, val);
}

void rmItem(dict dic, int idx){
    dic.d[idx]=Dictionary((uint16_t*)"\0", (uint16_t*)"\0");
}

void changeItem(dict dic, int idx, uint16_t* key, uint16_t* val){
    dic.d[idx]=Dictionary(key, val);
}