#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>

int writeLog(const char * log){
    //printf("%s\n", log);
    int charge = -1;
    
    FILE *fptr = fopen("/etc/bat_log.log", "a");
    if (fptr == NULL) {
        perror("Error opening log file");
        return -1;
    }
    FILE *bptr = fopen("/sys/class/power_supply/BAT0/capacity", "r");
    if (bptr == NULL) {
        perror("Error reading battery capacity");
        return -1;
    }
    fscanf(bptr, "%d", &charge);

    time_t currentTime;
    time(&currentTime);
    struct tm *localTime = localtime(&currentTime);

    int year = localTime->tm_year + 1900; 
    int month = localTime->tm_mon + 1;    
    int day = localTime->tm_mday;
    int hour = localTime->tm_hour;
    int minute = localTime->tm_min;
    // printf("%d-%02d-%02d %02d:%02d %s-Charge level:%d", 
    //        year, month, day, hour, minute, log, charge);
    fprintf(fptr, "%d-%02d-%02d %02d:%02d %s-Charge level:%d%%\n", 
           year, month, day, hour, minute, log, charge);

    fclose(fptr);
    fclose(bptr);
    return 0;
}

int main(int argc, char * argv[]){
    int opt;
    int ret = 0;
    while ((opt = getopt(argc, argv, "absr")) != -1) {
        switch (opt) {
        case 'a':
            ret = writeLog("AC");
            break;
        case 'b':
            ret = writeLog("Battery");
            break;
        case 's':
            ret = writeLog("Suspend");
            break;
        case 'r':
            ret = writeLog("Resume");
            break;
        default: /* '?' */
            fprintf(stderr, "Usage: %s [-a] [-b] [-s] [-r]\n", argv[0]);
            exit(1);
        }
    }    

    if(ret == -1)
        printf("Logging Failed\n");

    return 0;
}