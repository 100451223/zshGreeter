#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_MESSAGES 256
#define MAX_NAME_LEN 32
#define GREET_PATH "/home/vadu/projects/zshGreeter"

int main(){
    DIR *d;
    struct dirent *dir;

    char **msg = (char **)malloc(MAX_MESSAGES*sizeof(char *));

    int i = 0;
    d = opendir(GREET_PATH);
    if(d){
    	while ((dir=readdir(d))!=NULL){
	    
	    if(strstr(dir->d_name, "greet_v_")!=NULL){
		msg[i] = (char *)malloc(MAX_NAME_LEN*sizeof(char));
	        strcpy(msg[i], dir->d_name);
	        i++;
	    }
    	}
    } else {
    	perror("Couldn't open directory");
    }
    closedir(d);

    int lower = 0;
    int upper = i;

    srand(time(0));

    int num = (rand()%(upper-lower))+lower;
    char command[100];
    sprintf(command, "cat "GREET_PATH"/%s", msg[num]);
    system(command);

    return 0;
}
