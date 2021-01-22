#include "lib/stdint.h"

static uint16_t terminal_col;
static uint16_t terminal_row;
static const int VGA_HEIGHT=25;


typedef short bool;
#define false 0
#define true 1
typedef char* string;

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

#define WHITE 0x07 
#define RED   0x04 
#define GREEN 0x02 

uint64_t strlen(const char* str);
void clear_screen();
unsigned int print(char* message, int color);
void k_delay(int seconds);
int abs(int x);
uint16_t get_ascii_code(char c);
void itoa(int n, char s[]);
int strcmp(const char* s1, const char* s2);
char* strcat(char* dest, const char* src);
void terminal_scroll();