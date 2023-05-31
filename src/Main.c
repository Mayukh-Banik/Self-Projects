// #include "npArrayDef.h"
#include "includeStatements.h"
#include "functions.h"

#define MAX_BUFFER 1024
static ArrayList* savedArrays = NULL;
static ArrayList* tempArrays = NULL;

void sigint_handler(int signum);
void sigio_handler(int signum);
void sigsegv_handler(int signum);
void exitGracefully(int exitNumber);

static char* INITPRINTOUT = "FUNCTIONALITY: ";

int main(int argc, char* argv[])
{
    printf("%s", INITPRINTOUT);
    fflush(stdout);
    savedArrays = calloc(1, sizeof(ArrayList));
    tempArrays = calloc(1, sizeof(ArrayList));

    // Sets Up the Input Reader
    sigset_t mask;
    sigemptyset(&mask);

    struct sigaction sa;
    sa.sa_handler = &sigint_handler;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGINT, &sa, NULL);

    sa.sa_handler = &sigio_handler;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGIO, &sa, NULL);

    sa.sa_handler = &sigsegv_handler;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGSEGV, &sa, NULL);

    int flags = fcntl(STDIN_FILENO, F_GETFL);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_ASYNC | O_NONBLOCK);
    if (fcntl(STDIN_FILENO, F_SETOWN, getpid()) == -1)
    {
        perror("set owner error");
        exit(EXIT_FAILURE);
    }
    while (1)
    { 
        fprintf(stdout, "> ");
        fflush(stdout);
        sigsuspend(&mask);
    }
    return 0;
}

void sigsegv_handler(int signum)
{ 
    exit(-2);
}

void sigint_handler(int signum)
{
    exit(1);
}

void sigio_handler(int signum)
{
    char readBuffer[MAX_BUFFER];
    int readCount = read(STDIN_FILENO, readBuffer, MAX_BUFFER);
    if (readCount == -1)
    {
        if (errno == EBADF || errno == EFAULT)
        {
            exitGracefully(-3);
        }
        return; 
    }
    if (readCount == 0)
    {
        exitGracefully(0);
    }
    
}

void exitGracefully(int exitNumber)
{
    exit(exitNumber);
}