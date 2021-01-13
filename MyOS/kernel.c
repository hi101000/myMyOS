/*
* THESE ARE COLOR CODES THAT APPLY FOR LINES 12, 14, AND 16
*
* 0x04 is red
* 0x07 is white
* 0x02 is green
*/

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef unsigned long long uint64_t;
typedef char* string;
typedef const char* str;

#define elif else if
#define VGA_ADDRESS 0xB8000
#define BUFSIZE 2200
#define infinite while(1)

enum vga_color {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    GREY,
    DARK_GREY,
    BRIGHT_BLUE,
    BRIGHT_GREEN,
    BRIGHT_CYAN,
    BRIGHT_RED,
    BRIGHT_MAGENTA,
    YELLOW,
    WHITE,
};

char* vidmem=(char*)0xb8000;

#define WHITE 0x07 
#define RED   0x04 
#define GREEN 0x02 

uint64_t strlen(const char* str);
void clear_screen();
unsigned int print(const char* message, int color);
void k_delay(int seconds);
int abs(int x);

int cleared=0;

long double add(long double x, long double y){return x+y;}
long double sub(long double x, long double y){return x-y;}
long double mul(long double x, long double y){return x*y;}
long double div(long double x, long double y){return x/y;}

kmain(){
  clear_screen();
  print("1: print works    ", 0x02);
  print("2: clear screen works    ", 0x02);
  if(abs(2)==abs(-2)){
    print("3: abs works    ", 0x02);
  }
  else
  {
    print("3: abs failed", 0x02);
    return 1;
  }
  
}

int abs(int x){
  if(x>=0){
    return x;
  }
  else{
    return -x;
  }
}

unsigned int print(const char* message, int color){
  int i=0;
  static int j=0;
  if(cleared==1){
    cleared=0;
    j=0;
  }
  unsigned int length;
  while(message[i]!=0){
    vidmem[j]=message[i];
    vidmem[j+1]=color;
    i++;
    j=j+2;
    length ++;
  }
  return length;
}

void clear_screen() // clear the entire text screen
{
	unsigned int i=0;
	while(i < (80*25*2))
	{
		vidmem[i]=' ';
		i++;
		vidmem[i]=BLACK;
		i++;
	};
  cleared=1;
};

void k_delay(int seconds){
	unsigned long int count=99999999,i,j;
	unsigned long long int instruct=0;
	
	for(i=0;i<seconds;i++){
	    for(j=0;j<count;j++){instruct++;};
	}
}

uint64_t strlen(const char* str)
{
  uint64_t length = 0;
  while(str[length])
    length++;
  return length;
}
