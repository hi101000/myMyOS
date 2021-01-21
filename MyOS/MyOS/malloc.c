#define NULL ((void *)0)

typedef long Align;
union header{
	struct{
		union header* ptr;
		unsigned size;
	} s;
	Align x;
};

typedef union header Header;

static Header base;
static Header *freep=NULL;

void* malloc(unsigned nbytes){
	
}
