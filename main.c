#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
typedef struct {
  uint32_t rows, cols;

  float *data;
} Mat;

void mat_print(Mat m){
  for(size_t i = 0; i<m.rows; ++i){
    for(size_t j = 0; j<m.cols; ++j){
      printf(" %f", m.data[i*m.cols + j]);
    }
    printf("\n");
  }
}

void mat_mul(Mat c, Mat a, Mat b){
  for(size_t i = 0; i < c.rows; ++i){
    for(size_t j = 0; j < c.cols; ++j){
      uint32_t c_ix = i*c.cols + j;
      c.data[c_ix] = 0.0f;

      for(size_t k = 0; k < a.cols; ++k){
        c.data[c_ix] += a.data[i * a.cols + k] * b.data[k * b.cols + j];
      }
    }
  }
}

int main(void){
  Mat  a = {.rows = 2, .cols = 2, .data = (float[]){1,2,3,4}};
  Mat  b = {.rows = 2, .cols = 2, .data = (float[]){4,3,2,1}};
  Mat  c = {.rows = 2, .cols = 2, .data = (float[4]){0}};
  
  mat_mul( c, a, b);
  mat_print(c); 
  return 0;
}
