#include <stddef.h>
typedef struct {
  size_t rows, cols;

  float *data;
} Mat;

int main(void){
  Mat  a = {.rows = 2, .cols = 2, .data = (float[]){1,2,3,4}};
  return 0;
}
