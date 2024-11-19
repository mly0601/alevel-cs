#include <stdio.h>

int main(){
	int list[] = {25,34,7,41,19,5,98};
	int length = sizeof(list) / sizeof(list[0]);
	int temp;
	int inner_loop = length - 1;
	// bubble sort
	for(int i = 0;i < length - 1;i++){
		for(int j = 0;j < inner_loop;j++){
			if(list[j] > list[j+1]){
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp; 		
			}
		}
		inner_loop -= 1;
	}
	for(int x = 0;x < length;x++){
		printf("%d\n",list[x]);
	}
	return 0;
}
