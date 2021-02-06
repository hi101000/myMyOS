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

int rmItem(dict dic, int idx){
    Dictionary dictionary_to_test=Dictionary((uint16_t*)"\0", (uint16_t*)"\0");
    if(dic.d[idx].key!=dictionary_to_test.key && dic.d[idx].val!=dictionary_to_test.val)
        dic.d[idx]=Dictionary((uint16_t*)"\0", (uint16_t*)"\0");
        return 0;
    return idx;
}

void changeItem(dict dic, int idx, uint16_t* key, uint16_t* val){
    dic.d[idx]=Dictionary(key, val);
}   