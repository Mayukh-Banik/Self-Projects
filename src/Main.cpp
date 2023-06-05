#include "includes.h"
#include "classes.h"

void sigint_handler(int signum);
void sigio_handler(int signum);
void sigsegv_handler(int signum);
void exitGracefully(int exitNumber);

static const char* INITPRINTOUT = "FUNCTIONALITY: \n";
using namespace std;
int main(int argc, char* argv[])
{
    cout << INITPRINTOUT;
    // Sets Up the Input Reader
    sigset_t mask;
    sigemptyset(&mask);

    struct sigaction sa;
    sa.sa_handler = &sigint_handler;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGINT, &sa, nullptr);

    sa.sa_handler = &sigio_handler;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGIO, &sa, nullptr);

    sa.sa_handler = &sigsegv_handler;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGSEGV, &sa, nullptr);

    int flags = fcntl(STDIN_FILENO, F_GETFL);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_ASYNC | O_NONBLOCK);
    if (fcntl(STDIN_FILENO, F_SETOWN, getpid()) == -1)
    {
        perror("set owner error");
        exit(EXIT_FAILURE);
    }
    while (true)
    { 
        cout << "> ";
        cout.flush();
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
    exit(-1);
}

void sigio_handler(int signum)
{
    string input;
    getline(cin, input);
    istringstream iss(input);
    string word;
    vector<vector<string>> stringVector;

    while (iss >> word) 
    {
        if (word[0] == '-') 
        {
            vector<string> newVector;
            newVector.push_back(word);
            stringVector.push_back(newVector);
        }
        else if (!stringVector.empty()) 
        {
            stringVector.back().push_back(word);
        }
        else
        {
            vector<string> newVector;
            newVector.push_back(word);
            stringVector.push_back(newVector);
        }
    }

    for (const auto& vec : stringVector) 
    {
        for (const auto& str : vec) 
        {
            cout << str << " ";
        }
        cout << endl;
    }

}

void exitGracefully(int exitNumber)
{
    exit(exitNumber);
}
