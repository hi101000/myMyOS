#include "../lib/random.h"

uint64_t randint(uint64_t seed, int max){
	seed+=100;
	seed=seed/4;
	seed=seed*10;
	seed+=1234;
	long double ret=seed/3.5;
	ret=ret*3.5+ret;
	ret=ret/3.14159265358979323846;
	if(ret>max){
		while(ret>max)
			ret=ret/max;
	}
	return ret;
}


char* choice(char* list[], uint64_t seed){
	int max=strlen(list);
	choice=randint(seed, max);
	return choice;
}
