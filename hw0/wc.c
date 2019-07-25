#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
  if(argc == 1){
    char buffer[1024];

    int lineCount, wordCount, byteCount, flag;
    wordCount = byteCount = lineCount = flag = 0;

    while(fgets(buffer, sizeof(buffer), stdin)){
      if(buffer[0] == '#') break;
      if(buffer[0] != '\0') wordCount++;

      lineCount++;
      byteCount += strlen(buffer);

      int i = 0;
      while(buffer[i] != '\0'){
        if(buffer[i] == ' ' || buffer[i] == '\t')
          flag = 1;
        else if(flag == 1){
          flag = 0;
          wordCount++;
        }
        i++;
      }
    }

    printf(" %d  %d %d\n", lineCount, wordCount, byteCount);
  }

	if(argc == 2){
		FILE* file;
		if((file = fopen(argv[1], "r")) == NULL){
			printf("Can't open the file!");
			return;	
		}
		
		char ch;
		int wordCount, byteCount, lineCount, flag;
		wordCount = byteCount = lineCount = flag = 0;

		ch = getc(file);
		while(ch != EOF){
			byteCount++;
			if(ch == '\n') lineCount++;
			
			if(ch == ' ' || ch == '\t' || ch == '\n')
				flag = 1;			
			else if(flag == 1){
				flag = 0;
				wordCount++;
			}			

			ch = getc(file);
		}
		printf(" %d  %d %d %s\n", lineCount,wordCount, byteCount, argv[1]);

		fclose(file);
  }
	
	return 0;
}
