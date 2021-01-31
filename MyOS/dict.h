#ifndef _DICT_H
#define _DICT_H 1
#include "lib/stdint.h"
class Dictionary;

void addItem(dict dic, int idx, uint16_t* key, uint16_t* val);

void rmItem(dict dic, int idx);

void changeItem(dict dic, int idx, uint16_t* key, uint16_t* val);

#endif