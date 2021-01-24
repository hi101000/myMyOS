#include "../lib/encryption.h"

char* caesar(int key, char* str){
    int idx=0;
    while(str[idx]){
        str[idx]=(char)(((int)str[idx])+key);
    }
    return str;
}

char* super(char* s, int move, const char* key){
    int idx=0;
    s=caesar(move, s);
    reverse(s);
    char* buf;
    strcpy(buf, s);
    while(buf[idx]){
        s[idx]=buf[idx];
        s[idx+1]=key[idx];
        idx+=2;
    }
    strcat(s, key);
    return s;
}

char* xor(char inpString[], char key) 
{ 
    // Define XOR key 
    // Any character value will work 
    char xorKey = key; 
  
    // calculate length of input string 
    int len = strlen(inpString); 
  
    // perform XOR operation of key 
    // with every caracter in string 
    for (int i = 0; i < len; i++) 
    { 
        inpString[i] = inpString[i] ^ xorKey; 
    } 
    return inpString;
}