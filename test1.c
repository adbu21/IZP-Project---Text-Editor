//             Autor: Adam Buchta
//                 19.10.2018
//          Project 1 - TEXT EDITOR

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    FILE *commandFile;
    FILE *inputFile;
    commandFile = fopen(argv[1], "r");

    char command[150];
    char line[1001];


    while (fscanf(commandFile, "%149s", command) != EOF){
        if(command == "q"){   // command g, will terminate any other on-going actions
            printf("Breaking now!!!\n");
            break;
        }
        if(command == "n"){   // command n, will printout one line, then will continue onto the next command
            while (fscanf(inputFile, "%1000s", line) != '\n'){
                printf(line);
                printf("\n");
            }
            continue;
        }

    }



}
