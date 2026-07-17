#include <stdio.h>
#include <time.h>

int main()
{
    FILE *logFile;
    time_t currentTime;

    currentTime = time(NULL);

    logFile = fopen("audit.log", "a");

    if(logFile == NULL)
    {
        printf("Error opening log file.\n");
        return 1;
    }

    fprintf(logFile, "User Login Recorded at: %s", ctime(&currentTime));

    fclose(logFile);

    printf("Audit log entry added successfully.\n");

    return 0;
}
