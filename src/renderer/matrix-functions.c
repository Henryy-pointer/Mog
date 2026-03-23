#include "renderer.h"

void vec_x_matrix_affine(Vec4 *vec, Matrix4x4 *mat){

  float x = vec->vec4[0];
  float y = vec->vec4[1];
  float z = vec->vec4[2];
  float w = vec->vec4[3];

  vec->vec4[0] = mat->m[0] * x + mat->m[1] * y + mat->m[2] * z + mat->m[3] * w;
  vec->vec4[1] = mat->m[4] * x + mat->m[5] * y + mat->m[6] * z + mat->m[7] * w;
  vec->vec4[2] = mat->m[8] * x + mat->m[9] * y + mat->m[10] * z + mat->m[11] * w;
}

void vec_x_matrix_projective(Vec4 *vec, Matrix4x4 *mat){
  float x = vec->vec4[0];
  float y = vec->vec4[1];
  float z = vec->vec4[2];
  float w = vec->vec4[3];

  vec->vec4[0] = mat->m[0] * x + mat->m[1] * y + mat->m[2] * z + mat->m[3] * w;
  vec->vec4[1] = mat->m[4] * x + mat->m[5] * y + mat->m[6] * z + mat->m[7] * w;
  vec->vec4[2] = mat->m[8] * x + mat->m[9] * y + mat->m[10] * z + mat->m[11] * w;
  vec->vec4[3] = mat->m[12] * x + mat->m[13] * y + mat->m[14] * z + mat->m[15] * w;

}

Matrix4x4 matrix_multiplication(Matrix4x4 *matrix1, Matrix4x4 *matrix2){
  Matrix4x4 result;
  const float *m1 = matrix1->m;
  const float *m2 = matrix2->m;
  float *r = result.m;
  
  //Row 0
  r[0] = m1[0] * m2[0]  +  m1[1] * m2[4]  +  m1[2] * m2[8]  +  m1[3] * m2[12]; 
  r[1] = m1[0] * m2[1]  +  m1[1] * m2[5]  +  m1[2] * m2[9]  +  m1[3] * m2[13];
  r[2] = m1[0] * m2[2]  +  m1[1] * m2[6]  +  m1[2] * m2[10] +  m1[3] * m2[14];
  r[3] = m1[0] * m2[3]  +  m1[1] * m2[7]  +  m1[2] * m2[11] +  m1[3] * m2[15];

  //Row 1
  r[4] = m1[4] * m2[0]  +  m1[5] * m2[4]  + m1[6] *  m2[8]  +  m1[7] * m2[12];
  r[5] = m1[4] * m2[1]  +  m1[5] * m2[5]  + m1[6] *  m2[9]  +  m1[7] * m2[13];
  r[6] = m1[4] * m2[2]  +  m1[5] * m2[6]  + m1[6] *  m2[10] +  m1[7] * m2[14];
  r[7] = m1[4] * m2[3]  +  m1[5] * m2[7]  + m1[6] *  m2[11] +  m1[7] * m2[15];

  //Row 2
  r[8] = m1[8] * m2[0]  +  m1[9] * m2[4]  +  m1[10]* m2[8]  +  m1[11]* m2[12]; 
  r[9] = m1[8] * m2[1]  +  m1[9] * m2[5]  +  m1[10]* m2[9]  +  m1[11]* m2[13];
  r[10]= m1[8] * m2[2]  +  m1[9] * m2[6]  +  m1[10]* m2[10] +  m1[11]* m2[14];
  r[11]= m1[8] * m2[3]  +  m1[9] * m2[7]  +  m1[10]* m2[11] +  m1[11]* m2[15];

  //Row 3
  r[12]= m1[12]* m2[0]  +  m1[13]* m2[4]  + m1[14]*  m2[8]  +  m1[15]* m2[12];
  r[13]= m1[12]* m2[1]  +  m1[13]* m2[5]  + m1[14]*  m2[9]  +  m1[15]* m2[13];
  r[14]= m1[12]* m2[2]  +  m1[13]* m2[6]  + m1[14]*  m2[10] +  m1[15]* m2[14];
  r[15]= m1[12]* m2[3]  +  m1[13]* m2[7]  + m1[14]*  m2[11] +  m1[15]* m2[15];

  return result;
}

Matrix4x4 matrix_addition(Matrix4x4 *matrix1, Matrix4x4 *matrix2){
  Matrix4x4 result;
  const float *m1 = matrix1->m;
  const float *m2 = matrix2->m;
  float *r = result.m;

  r[0] = m1[0]+m2[0]; r[1] = m1[1]+m2[1]; r[2] = m1[2]+m2[2]; r[3] = m1[3]+m2[3]; 
  r[4] = m1[4]+m2[4]; r[5] = m1[5]+m2[5]; r[6] = m1[6]+m2[6]; r[7] = m1[7]+m2[7];
  r[8] = m1[8]+m2[8]; r[9] = m1[9]+m2[9]; r[10] = m1[10]+m2[10]; r[11] = m1[11]+m2[11];
  r[12] = m1[12]+m2[12]; r[13] = m1[13]+m2[13]; r[14] = m1[14]+m2[14]; r[15] = m1[15]+m2[15];

  return result;
}

Matrix4x4 matrix_subtraction(Matrix4x4 *matrix1, Matrix4x4 *matrix2){
  Matrix4x4 result;
  const float *m1 = matrix1->m;
  const float *m2 = matrix2->m;
  float *r = result.m;

  r[0] = m1[0]-m2[0]; r[1] = m1[1]-m2[1]; r[2] = m1[2]-m2[2]; r[3] = m1[3]-m2[3];
  r[4] = m1[4]-m2[4]; r[5] = m1[5]-m2[5]; r[6] = m1[6]-m2[6]; r[7] = m1[7]-m2[7];
  r[8] = m1[8]-m2[8]; r[9] = m1[9]-m2[9]; r[10] = m1[10]-m2[10]; r[11] = m1[11]-m2[11];
  r[12] = m1[12]-m2[12]; r[13] = m1[13]-m2[13]; r[14] = m1[14]-m2[14]; r[15] = m1[15]-m2[15];

  return result;
}
