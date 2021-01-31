#ifndef _DICT_H
#define _DICT_H 1
#include "lib/stdint.h"
class Dictionary;

typedef Dictionary* dict;

void addItem(dict d, int idx, uint16_t* key, uint16_t* val);

void rmItem(dict d, int idx);

void changeItem(dict d, int idx, uint16_t* key, uint16_t* val);

#endif