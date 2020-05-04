//             Autor: Adam Buchta
//                 19.10.2018
//          Project 1 - TEXT EDITOR

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[]){
    FILE *commandFile;
    commandFile = fopen(argv[1], "r");

    char iCon[1001]; //content
    char bCon[1001];
    char aCon[1001];
    int iEx = 0; //exist
    int bEx = 0;
    int aEx = 0;
    int rEx = 0;
    int eEx = 0;
    char command[1001];
    char line[1001];
    int nN; // N number
    int dN;
    int gX;
    //int commandCounter = 0;

    while (fgets(command, 1000, commandFile) != NULL){
        //commandCounter++;
        printf("Nacetl command:%s", command);
        //fscanf(stdin, "%1000s", &line); // !
        //printf("Je tu neco? %s \n", line);
        if(*command == 'q'){   // command q (quit), will terminate any other on-going actions
            printf("Breaking now!!!\n");
            break;
        }
        if(*command == 'i'){   // iCONTENT, will input a line of CONTENT before the actual line with '\n'
            memmove(command, command+1, strlen(command));   // removing first character of string, leaving only CONTENT
            strcpy(iCon, command);
            iEx=1;
            continue;
        }
        if(*command == 'b'){    //bCONTENT, will input a line of CONTENT before the actual line without '\n'
            memmove(command, command+1, strlen(command));
            strcpy(bCon, command);
            bCon[strcspn(bCon, "\n")] = 0; //removes the '\n' character
            bEx = 1;
            continue;
        }
        if(*command == 'a'){
            memmove(command, command+1, strlen(command));
            strcpy(aCon, command);
            aEx = 1;
            continue;
        }
        if(*command=='r'){
            rEx = 1;
        }
        if(*command=='e'){
            eEx = 1;
        }
        if(*command == 'n'){   // command n, program will determine if it should printout one line or more
            nN = command[1];
            if(nN >=50 && nN <=57){  // command nN, will printout N lines
                nN=nN-50+2;
                for(int i=0; i<nN;i++){
                    fgets(line, 1000, stdin);
                    printf("%s", line);
                }
                continue;
            }
            else{           //command n, will printout one line
                fgets(line, 1000, stdin);
                if(iEx==1){
                    strcat(iCon, line);
                    strcpy(line, iCon);
                    iEx=0;
                    strcpy(iCon, "");
                }
                if(bEx==1){
                    strcat(bCon, line);
                    strcpy(line, bCon);
                    bEx=0;
                    strcpy(bCon, "");
                }
                if(aEx==1){
                    line[strcspn(line, "\r\n")] = 0;
                    strcat(line, aCon);
                    aEx=0;
                    strcpy(aCon, "");
                }
                if(rEx==1){
                    line[strcspn(line, "\r\n")] = 0;
                    rEx=0;
                }
                if(eEx==1){
                    strcat(line, "\n");
                    eEx=0;
                }
                printf("%s", line);
                continue;
            }
        }
        if(*command=='d'){
            dN = command[1];
            if(dN >=50 && dN <=57){  // command dN, will remove N lines
                dN=dN-50+2;
                for(int i=0; i<dN;i++){
                    fgets(line, 1000, stdin);
                }
                continue;
            }
            else{ // command d, will remove 1 line
            fgets(line, 1000, stdin);
            continue;
            }
        }
        if(*command=='g'){
            memmove(command, command+1, strlen(command));
            gX = command[1];
            fclose(commandFile);
            commandFile = fopen(argv[1], "r");
            for(int i=1;i<gX;i++){
                fgets(command, 1000, commandFile);
            }
           // commandCounter=0;
            continue;
        }







    }



}
