#define NULL ((void *)0)
#include "lib/stdint.h"

void* start=(void*)0x54FF;
void* end=(void*)0x65FF;
int end1=0x65FF;
int current=0x54FF;
void* current_addr=(void*)0x54FF;

void* malloc(unsigned long long size){
	if(size<(end1-current) && current_addr<end){
		void* ret=current_addr;
		current+=size;
		current_addr+=size;
	}
}
