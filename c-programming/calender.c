#include <stdio.h>
#include <stdlib.h>

int get_1st_weekday (int year)
{
int day;
day = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
return day;
}
int main()
{
    system("color 3f");
    int year, month, day, dayInMonth, weekdays=0, startingDay;
    printf("\n Enter year: ");
    scanf("%d", &year);

    char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December",};
    int monthday[]={31,28,31,30,31,30,31,31,30,31,30,31};

    if((year%4==0&&year%100!=0) || year %400 == 0)
        monthday[1] = 29;

    startingDay = get_1st_weekday (year);

    for(month = 0; month<12; month++)
    {
        dayInMonth=monthday[month];
        printf("\n\n...............%s...............\n", months[month]);
        printf("\n Sun  Mon  Tue  Wed  Thurs  Fri  Sat\n");

        for (weekdays = 0; weekdays < startingDay; weekdays++)
        printf("     ");

        for(day=1; day <=dayInMonth; day++)
        {
            printf("%5d", day);

            if(++weekdays>6)
            {
                printf("\n");
                weekdays=0;
            }
            startingDay = weekdays;
        }
    }
}
