#define NULL ((void *)0)

long double squrt(long double x){
     long double i=0;
     if(x<0){return ((long double*)NULL)[0];}
     if (x=0){return 0;}
     while(i<=x){
          if(i*i==x){
               return i;
          }
          i+=0.0000000000000000000000000000000000001;
     }
     return ((long double*)NULL)[0];
}
      
