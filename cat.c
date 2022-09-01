#include <stdlib.h>
#include <stdio.h>

 int main(int argc,char **argv){
 
  FILE *fp = fopen(argv[1],"r");
  if(!fp){puts("can not open file");exit(1);}
  
  while(!feof(fp)) 
   printf("%c",fgetc(fp));
  
   fclose(fp);
  
  return 0;
 }