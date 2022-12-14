#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include <errno.h>
char write_buf[4000];
char read_buf[4000];
int main()
{
	int fd;
	char option;

	fd = open("/dev/my-app", O_RDWR);
	if (fd < 0)
	{
		printf("Cannot open device file...\n");
		return 0;
	}

	printf("Data Reading ...\n");
	read(fd, read_buf, 4000);
	printf("Data reading Done!\n\n");
	printf("Previous Data = %s\n\n", read_buf);

	printf("Do you want to write [Y/N]");
	scanf(" %c", &option);
	printf("You choose option is = %c\n", option);

	if (option == 'Y' || option == 'y')
	{
		printf("Enter the string to write into driver : ");
		scanf(" %[^\t\n]s", write_buf);
		printf("Data Writing ...\n");
		write(fd, write_buf, strlen(write_buf) + 1);
		printf("Data writing Done!\n\n");

		printf("Data Reading ...\n");
		read(fd, read_buf, 4000);
		printf("Data reading Done!\n\n");
		printf("Your data = %s\n\n", read_buf);
	}
	printf("Closing file....\n");
	close(fd);
	return 0;
}
