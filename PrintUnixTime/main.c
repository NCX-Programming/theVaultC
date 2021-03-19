//theVaultC/PrintUnixTime "main.c"
//Copyright (C) 2021 NinjaCheetah
//Copyright (C) 2021 NCX-Programming
#include <stdio.h>
#include <time.h>
// Declare variables
int UnixTime;
// Code start
int main(void){
  UnixTime=time(0);
  printf("Time in seconds since 1 January 1970: %d\n",UnixTime);
  return(0);
}
