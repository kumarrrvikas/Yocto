#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define WR_VALUE _IOW('a', 'a', int32_t *)
#define RD_VALUE _IOR('a', 'b', int32_t *)

int main()
{
        int fd;
        int32_t Read_value, Write_value;

        printf("\nUser Code: Opening Driver\n");
        fd = open("/dev/ioctl", O_RDWR);
        if (fd < 0)
        {
                printf("User Code: Cannot open device file...\n");
                return 0;
        }
        /* Take value from user and write to file */
        printf("Value range 0-2147483647\n");
        printf("User Code: Enter the Number to send\n");
        scanf("%d", &Write_value);
        printf("User Code: Writing Number to Driver\n");
        ioctl(fd, WR_VALUE, (int32_t *)&Write_value);

        /* Read the value from file and print it */
        printf("User Code: Reading Number from Driver\n");
        ioctl(fd, RD_VALUE, (int32_t *)&Read_value);
        printf("User Code: Number is %d\n", Read_value);

        /* Close the driver */
        printf("User Code: Closing Driver\n");
        close(fd);
}
