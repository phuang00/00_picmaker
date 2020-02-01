#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
  int i, j;
  FILE * fp;
  fp = fopen("image.ppm", "w");
  fprintf(fp, "P3\n768 768\n255\n");
  for (i = 0; i < 768; i++){
    for (j = 0; j < 768; j++){
      if (i < 128){
        fprintf(fp, "%d %d %d\n", 255, 0, i * 2);
      }
      else if (i < 256){
        fprintf(fp, "%d %d %d\n", 511 - i * 2, 0, 255);
      }
      else if (i < 384){
        fprintf(fp, "%d %d %d\n", 0, (i * 2), 255);
      }
      else if (i < 512){
        fprintf(fp, "%d %d %d\n", 0, 255, 1023 - i * 2);
      }
      else if (i < 640){
        fprintf(fp, "%d %d %d\n", i * 2 % 256, 255, 0);
      }
      else{
        fprintf(fp, "%d %d %d\n", 255, 1535 - i * 2, 0);
        printf("%d\n", 1535 - i * 2);
      }
    }
  }
  fclose(fp);
  /* code */
  return 0;
}
