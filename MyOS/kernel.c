/*
* THESE ARE COLOR CODES THAT APPLY FOR LINES 12, 14, AND 16
*
* 0x04 is red
* 0x07 is white
* 0x02 is green
*/
#include "kernel.h"

static char* vidmem=(char*)0xb8000;
int cleared=0;

long double add(long double x, long double y){return x+y;}
long double sub(long double x, long double y){return x-y;}
long double mul(long double x, long double y){return x*y;}
long double div(long double x, long double y){return x/y;}

kmain(){
  clear_screen();
  print("\n1: print works                                                                 ", 0x02);
  print("\n2: clear screen works                                                          ", 0x02);
  if(abs(2)==abs(-2)){
    print("\n3: abs works                                                                   ", 0x02);
  }
  else
  {
    print("\n3: abs failed                                                                  ", 0x02);
    return 1;
  }
  if(get_ascii_code('A')==(uint16_t)'A'){
    print("\n4: get_ascii_code_works                                                        ", 0x02);
  }
  else{
    print("\n4: get_ascii_code failed                                                     ", 0x02);
  }
  char s[3];
  itoa(25, s);
  print(strcat("\n", s), 0x02);
  k_delay(1);
  clear_screen();
  print("User>", 0x02);
}

int abs(int x){
  if(x>=0){
    return x;
  }
  else{
    return -x;
  }
}

unsigned int print(char* message, int color){
  static int col;
  int since_newline=0;
  int i=0;
  static int j=0;
  if(cleared==1){
    cleared=0;
    j=0;
  }
  unsigned int length;
  while(message[i]!=0){
    /*if(message[i]=='\n'){
      j=j+130-since_newline;
      since_newline=0;
    }*/
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

uint16_t get_ascii_code(char c){
  return (uint16_t) c;
}


void reverse(char s[])
 {
     int i, j;
     char c;
 
     for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
         c = s[i];
         s[i] = s[j];
         s[j] = c;
     }
 }


 void itoa(int n, char s[])
 {
     int i;
     int sign;
 
     if ((sign = n) < 0)  /* record sign */
         n = -n;          /* make n positive */
     i = 0;
     do {       /* generate digits in reverse order */
         s[i++] = n % 10 + '0';   /* get next digit */
     } while ((n /= 10) > 0);     /* delete it */
     if (sign < 0)
         s[i++] = '-';
     s[i] = '\0';
     reverse(s);
 }


int strcmp(const char* s1, const char* s2){
  while(*s1==*s2)
    s1++, s2++;
  return *(const unsigned char*)s1-*(const unsigned char*)s2;
}

char* strcat(char* dest, const char* src){
  char* tmp=dest;
  while(*dest)dest++;
  while((*dest++=*src++)!=0);
  return tmp;
}


void terminal_scroll(){
  int i;
  for(i=0; i<VGA_HEIGHT; i++){
    int m;
    for(m=0; m<80; m++){
      vidmem[i*80+m]=vidmem[(i+1)*80+m];
    }
    terminal_row--;
  }
  terminal_row=VGA_HEIGHT-1;
}
