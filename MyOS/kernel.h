#ifndef _KERNEL_H
#define _KERNEL_H 1
#define MAX_ROWS 25
#define MAX_COLS 80
#include "lib/stdint.h"

static uint16_t terminal_col;
static uint16_t terminal_row;
static const int VGA_HEIGHT=25;

typedef char* str;

#define elif else if
#define BUFSIZE 2200
#define infinite while(1)

enum vga_color {
    BLACK=0,
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

typedef union{
    uint64_t i;
    uint8_t* s;
    long double d;
} dynamic;

#define LG 0x07 
#define R 0x04 
#define G 0x02 
#define B 0x01
#define C 0x03

uint64_t strlen(const char* str);
void clear_screen();
unsigned int print(char* message, int color);
void k_delay(int seconds);
int abs(int x);
uint16_t get_ascii_code(char c);
void itoa(int n, char s[]);
int strcmp(const char* s1, const char* s2);
char* strcat(char* dest, const char* src);
char ascii_to_char(uint16_t code);
void strcpy(char *source, char* destination);
int get_terminal_row();
int get_terminal_col();
void reverse(char s[]);
void delay(int i);
void memcpy(char* src, char* dest, int bytes);
#endif