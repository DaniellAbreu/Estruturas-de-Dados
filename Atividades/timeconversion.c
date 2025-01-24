#include <stdio.h>
#include <string.h>

const char *timeConversion(char time12[], char time24[]){
    int hour, min, sec;
    char period[3];

    sscanf(time12, "%d:%d:%d%s", &hour, &min, &sec, period);

    if(strcmp(period, "PM") == 0 && hour != 12){
        hour += 12;
    }
    else if(strcmp(period, "AM") == 0 && hour == 12){
        hour = 0;
    }

    sprintf(time24, "%02d:%02d:%02d", hour, min, sec);

    return time24;
}


int main(){
    char time12[11], time24[9];

    scanf("%s", time12);

    timeConversion(time12, time24);
    
    printf("%s\n", time24);

    return 0;
}