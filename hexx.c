#include <stdlib.h>
#include <stdio.h>

#define FILE_NAME argv[1]


#define MAX_SIZE (1024*1024*1024)

static inline void fail(char *msg){fprintf(stderr,msg);exit(1);}
 int main(int argc,char **argv){
 
	FILE* fp = fopen(FILE_NAME,"rb");
	
	if(!fp)fail("Err: file opening failed\n");
	
	
    char *data = calloc(MAX_SIZE,sizeof(char));
	
	if(!data)fail("Err: alloc data failed\n");
	
	
	
	
	
    int i =  0;
	unsigned int offset_counter = 0;
	while(!feof(fp)){
		
		if(i% 10 == 0){
			puts("");
			printf("%5d--- ",offset_counter);
			offset_counter += 10;
		}
		data[i] = fgetc(fp);
	    printf("%5x ",data[i]);	
		
		
		i++;
	}
 
    fclose(fp);
	

	
	if(argc > 2){
		fp = fopen(FILE_NAME,"wb");
		while(1){
		int offset,value;
		printf(" \nEnter offset to change : ");
		scanf("%d",&offset);
		
		if(offset == 9999)break;
	
		
		
		printf(" \nEnter value : ");
		scanf("%d",&value);
		
		data[offset] = value;
		
	  }
	  int j;
	  for(j=0;j<i;j++)
		  fputc(data[j],fp);
	  
	
	fclose(fp);
	}
 
   
 
  return 0;
 }

