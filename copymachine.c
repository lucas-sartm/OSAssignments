/*Operating systems class' first assigment by Lucas Sartori*/

#include <unistd.h>
#include <fcntl.h>

int main(void) {
    
    const char openingMessage[] = "\nGot file: ";
    const char errorMessage[] = "\nYou did something wrong or either file doesn't exist. Check specifications.\n";
    const char welcomeMessage[] = "File to be opened and read: \n";
    const char writeMessage[] = "\nFile to be opened and written: \n";
    write(1, welcomeMessage, sizeof(welcomeMessage)-1);
    
    char fileName[512];
    
    /*I'm using a buffer here but there must be better ways...*/
    read(STDIN_FILENO, fileName, 512);
    
    int i = 0;
    int inputNameSize = 0;
    
    /*swaps newline char for end of string char on fileName
    and gets the proper string inputNameSize*/
    for (i=0; i<512; i++){
        inputNameSize++;
        if (fileName[i] == 10){
            fileName[i] = '\0';
            break;
        }
    }
    
    
    write(1, openingMessage, sizeof(openingMessage)-1);
    write(1, fileName, inputNameSize);
    
    int input = open(fileName, O_RDONLY, 0644);
    
    if ((int)input == -1){
        write(1, errorMessage, sizeof(errorMessage)-1);
        return 0;
    }
    
    
    write(1, writeMessage, sizeof(writeMessage)-1);
    
    char outputName[512];
    
    /*I'm using a buffer here but there must be better ways...*/
    read(STDIN_FILENO, outputName, 512);
    
    int outputSize = 0;
    /*swaps newline char for end of string char on fileName
    and gets the proper string inputNameSize*/
    for (i=0; i<512; i++){
        outputSize++;
        if (outputName[i] == 10){
            outputName[i] = '\0';
            break;
        }
    }
    
    int output = open(outputName, O_WRONLY | O_CREAT, 0644);
    


    char content;
    // printf ("\nsize: %d\n", realSize);

    off_t fsize;

    fsize = lseek (input, 0, SEEK_END);

    for (i=0; i<fsize; i++){ //I need the file descriptor to be set at 0 here...
    
        printf("%c", content);
        read (input, &content, sizeof(content));



        write (output, &content, sizeof(content));
    
    }



    // fopen(fileName, "w+");
    
    return 0;
}   