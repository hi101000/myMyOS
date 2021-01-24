#define NULL ((void *)0)
#include "lib/stdint.h"

static void* start=(void*)0x54FF;
static void* end=(void*)0x65FF;
static int end1=0x65FF;
static int current=0x54FF;
static void* current_addr=(void*)0x54FF;

void* malloc(unsigned long long size){
	if(size<(end1-current) && current_addr<end){
		void* ret=current_addr;
		current+=size;
		current_addr+=size;
	}
}
