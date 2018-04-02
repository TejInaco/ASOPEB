/* 
 * File:   main.c
 * Author: notus
 *
 * Created on 12 de Março de 2018, 16:15
 *  gcc -Wall -o main_1b main_1_b.c
 */

#include <stdio.h>
#include <string.h>

#define COMMAND_SIZE 100

int main() {
    
    char command[COMMAND_SIZE];
    const char delim[]= "" ;
    char* command_token;
    
    printf("Enter the shell command: ");
    fgets( command, sizeof(command) , stdin);
    printf( "\nCommand tokens:" );
     
    command_token = strtok(command, delim);
    
    while( command_token != NULL ){
        printf( "\n%s" , command_token );
        command_token = strtok( NULL , delim);
    }
    return (0);
}

