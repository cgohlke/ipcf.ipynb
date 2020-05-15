/* fft2d.h

Header file for the `fft2d library by Takuya Ooura 
<http://www.kurims.kyoto-u.ac.jp/~ooura/fft.html>`_.

*/

#ifndef FFT2D_H
#define FFT2D_H

#ifdef __cplusplus
extern "C" {
#endif

int *alloc_1d_int(int n1);
void free_1d_int(int *i);
double *alloc_1d_double(int n1);
void free_1d_double(double *d);
int **alloc_2d_int(int n1, int n2);
void free_2d_int(int **ii);
double **alloc_2d_double(int n1, int n2);
void free_2d_double(double **dd);
int ***alloc_3d_int(int n1, int n2, int n3);
void free_3d_int(int ***iii);
double ***alloc_3d_double(int n1, int n2, int n3);
void free_3d_double(double ***ddd);

void cdft(int, int, double *, int *, double *);
void rdft(int, int, double *, int *, double *);
void ddct(int, int, double *, int *, double *);
void ddst(int, int, double *, int *, double *);
void dfct(int, double *, double *, int *, double *);
void dfst(int, double *, double *, int *, double *);

void cdft2d(int, int, int, double **, double *, int *, double *);
void rdft2d(int, int, int, double **, double *, int *, double *);
void rdft2dsort(int, int, int, double **);
void ddct2d(int, int, int, double **, double *, int *, double *);
void ddst2d(int, int, int, double **, double *, int *, double *);

void cdft3d(int, int, int, int, double ***, double *, int *, double *);
void rdft3d(int, int, int, int, double ***, double *, int *, double *);
void rdft3dsort(int, int, int, int, double ***);
void ddct3d(int, int, int, int, double ***, double *, int *, double *);
void ddst3d(int, int, int, int, double ***, double *, int *, double *);

void ddct8x8s(int isgn, double **a);
void ddct16x16s(int isgn, double **a);

#ifdef __cplusplus
}
#endif

#endif /* FFT2D_H */