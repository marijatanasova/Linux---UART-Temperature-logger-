#include <stdio.h>
#include <time.h>
int main()
{

FILE *file = fopen("temperature.log", "a");
if(file == NULL)
{
printf("Error opening file\n");
return 1;
}

time_t now = time(NULL);
char *timestamp = ctime(&now);

fprintf(file, "%s Temp 25.5C\n", timestamp);

fclose(file);
printf("Data written to file\n");
return 0;
}
