#include "kernel.h"
#include "lib/encryption.h"
#include "drivers/kbd.h"

static char* vidmem=(char*)0xb8000;
int cleared=0;

int row;
int col;

long double add(long double x, long double y){return x+y;}
long double sub(long double x, long double y){return x-y;}
long double mul(long double x, long double y){return x*y;}
long double div(long double x, long double y){return x/y;}

kmain(){
  clear_screen();
  print("1: print works", 0x02);
  print("\n2: \\n works", 0x02);
  print("\n3: clear screen works", 0x02);
  if(abs(2)==abs(-2)){
    print("\n4: abs works", 0x02);
  }
  else
  {
    print("\n4: abs failed", 0x02);
    return 1;
  }
  if(get_ascii_code('A')==(uint16_t)'A'){
    print("\n5: get_ascii_code_works", 0x02);
  }
  else{
    print("\n5: get_ascii_code failed", 0x02);
    return 1;
  }
  print("\n6: itoa works", 0x02);
  print("\n7: ascii_to_char works", 0x02);
  if('\0'==(char*)0 and '\0'==(char)'\000' and (char*)0=='\000'){
    print("\n8: NULL works", 0x02);
  }
  k_delay(5);
  clear_screen();
  print("$>", 0x02);
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
  static int since_newline=0;
  int i=0;
  static int j=0;
  int z=j;
  if(cleared==1){
    cleared=0;
    j=0;
  }
  unsigned int length;
  while(message[i]!=0){
    if(message[i]=='\n'){
      while(since_newline >= 159){
        since_newline -= 161;
      }
      z = j+(159-since_newline);
      while(z>j){
        vidmem[j]=' ';
        vidmem[j+1]=0x00;
        j+=2;
      }
      since_newline=0;
      i++;
      length++;
    }
    else{
      vidmem[j]=message[i];
      vidmem[j+1]=color;
      i++;
      j=j+2;
      length++;
      since_newline+=2;
    }
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

void strcpy(char *source, char* destination)
{
    while (*source != '\0')
    {
      *destination = *source;
      destination++;
      source++;
    }
 
    *destination = '\0';
}

char* strcat(char* dest, const char* src){
  char* tmp=dest;
  while(*dest)dest++;
  while((*dest++=*src++)!=0);
  return tmp;
}


void scroll(){
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

char ascii_to_char(uint16_t code){
  return (char) code;
}

void delay(int i) {
    int c = 1 , d = 1 ;

    for ( c = 1; c <= 5000*i; c++) {
        for ( d = 1; d <= 5000*i; d ++) {
            asm("nop");
        }
    }
}