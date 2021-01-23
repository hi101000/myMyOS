bits 32
section   .text
  align   4
  dd      0x1BADB002
  dd      0x00
  dd      - (0x1BADB002+0x00)


global start
extern kmain ;gets defined in kernel.c

shutdown:
  mov ax, 0x1000
  mov ax, ss
  mov sp, 0xf000
  mov ax, 0x5307
  mov bx, 0x0001
  mov cx, 0x0003
  int 0x15
 
  ret

start:
  cli        ;clear all interrupts
  call kmain ;call kmain
  hlt        ;halt the cpu
  ;call shutdown       ;shutdown
