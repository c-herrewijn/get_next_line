# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int main(void)
{
    char    *file;
    int     fd;
    int     readnr;
    char    buff[1000];
    
    file = "./file.txt";
    fd = open(file, O_RDONLY);

    readnr = read(fd, buff, 10);
    printf("readnr: %d\n", readnr);
    printf("line: %s\n", buff);
    
    readnr = read(fd, buff, 10);
    printf("readnr: %d\n", readnr);
    printf("line: %s\n", buff);
    
    readnr = read(fd, buff, 10);
    printf("readnr: %d\n", readnr);
    printf("line: %s\n", buff);
    
    readnr = read(fd, buff, 10);
    printf("readnr: %d\n", readnr);
    printf("line: %s\n", buff);

    return (0);
}
