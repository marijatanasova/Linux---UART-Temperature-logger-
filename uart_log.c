#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <termios.h>
#include <time.h>

int main()
{
    int serial_port = open("/dev/ttyACM0", O_RDWR);
    
    if (serial_port < 0) {
        printf("Error opening serial port\n");
        return 1;
    }

struct termios tty;
    tcgetattr(serial_port, &tty);
    cfsetspeed(&tty, B115200);
    tcsetattr(serial_port, TCSANOW, &tty);
FILE *log_file = fopen("uart_temp.log", "a");
    if (log_file == NULL) {
        printf("Error opening log file\n");
        return 1;
    }

char buffer[256];
    
    while(1) {
        int bytes = read(serial_port, buffer, sizeof(buffer)-1);
        if (bytes > 0) {
            buffer[bytes] = '\0';
            time_t now = time(NULL);
            char *timestamp = ctime(&now);
            timestamp[strlen(timestamp)-1] = '\0';
            fprintf(log_file, "[%s] %s", timestamp, buffer);
            fflush(log_file);
            printf("[%s] %s", timestamp, buffer);
        }
    }

fclose(log_file);
    close(serial_port);
    return 0;
}

