#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int i, j, fd;
  fd = open("image.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);
  char buffer[20];
  int rgb[3];
  snprintf(buffer, sizeof(buffer), "P3 600 600 255\n");
  write(fd, buffer, sizeof(buffer));
  for (i = 0; i < 600; i++){
    for (j = 0; j < 600; j++){
      rgb[0] = i % 256;
      rgb[1] = j % 256;
      snprintf(buffer, sizeof(buffer), "%d %d %d\n", rgb[0], rgb[1], 0);
      printf("%s\n", buffer);
      write(fd, buffer, sizeof(buffer));
    }
  }
  close(fd);
  /* code */
  return 0;
}
