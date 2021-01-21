bits 32
section   .text
  align   4
  dd      0x1BADB002
  dd      0x00
  dd      - (0x1BADB002+0x00)


global start
extern kmain ;gets defined in kernel.c

start:
  cli        ;clear all interrupts
  call kmain ;call kmain
  hlt        ;halt execution
