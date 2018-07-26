// My program made 84 corrections instead 
// of the 70 that was listed as the answer

#include <stdio.h>

int main(){
	
	int corrections = 0;
	char c;
	char lastChar = 'i';
	
	FILE* badFile = fopen("green_eggs_and_ham_text_with_errors.txt", "r");
	
	if(badFile == NULL){
		return 1;
	}
	
	FILE* newFile = fopen("green_eggs_and_hame_text_corrected.txt", "w");
	
	fseek(badFile, 1, SEEK_SET);
	
	while(fscanf(badFile, "%c", &c) != EOF){
		
		if((lastChar == 'i') && (c == ' ' || c == '-')){
			fprintf(newFile, "I");
			corrections++;
		}else{
			fprintf(newFile, "%c", lastChar);
		}
		lastChar = c;
	}
	
	printf("Number of corrections: %d", corrections);
	
}