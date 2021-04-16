/*theVaultC/PrintUnixTime "main.c"
Copyright (C) 2021 NinjaCheetah
Copyright (C) 2021 NCX-Programming
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.*/
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
