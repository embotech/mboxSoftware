/* This file was automatically generated by CasADi.
   The CasADi copyright holders make no ownership claim of its contents. */
#ifdef __cplusplus
extern "C" {
#endif

/* How to prefix internal symbols */
#ifdef CASADI_CODEGEN_PREFIX
  #define CASADI_NAMESPACE_CONCAT(NS, ID) _CASADI_NAMESPACE_CONCAT(NS, ID)
  #define _CASADI_NAMESPACE_CONCAT(NS, ID) NS ## ID
  #define CASADI_PREFIX(ID) CASADI_NAMESPACE_CONCAT(CODEGEN_PREFIX, ID)
#else
  #define CASADI_PREFIX(ID) nlp3minError_DTVs_d42f_casadi_ ## ID
#endif

#include <math.h>

#ifndef casadi_real
#define casadi_real double
#endif

#ifndef casadi_int
#define casadi_int int
#endif

/* Add prefix to internal symbols */
#define casadi_f0 CASADI_PREFIX(f0)
#define casadi_f1 CASADI_PREFIX(f1)
#define casadi_f2 CASADI_PREFIX(f2)
#define casadi_f3 CASADI_PREFIX(f3)
#define casadi_f4 CASADI_PREFIX(f4)
#define casadi_f5 CASADI_PREFIX(f5)
#define casadi_f6 CASADI_PREFIX(f6)
#define casadi_f7 CASADI_PREFIX(f7)
#define casadi_f8 CASADI_PREFIX(f8)
#define casadi_f9 CASADI_PREFIX(f9)
#define casadi_s0 CASADI_PREFIX(s0)
#define casadi_s1 CASADI_PREFIX(s1)
#define casadi_s10 CASADI_PREFIX(s10)
#define casadi_s11 CASADI_PREFIX(s11)
#define casadi_s12 CASADI_PREFIX(s12)
#define casadi_s13 CASADI_PREFIX(s13)
#define casadi_s14 CASADI_PREFIX(s14)
#define casadi_s2 CASADI_PREFIX(s2)
#define casadi_s3 CASADI_PREFIX(s3)
#define casadi_s4 CASADI_PREFIX(s4)
#define casadi_s5 CASADI_PREFIX(s5)
#define casadi_s6 CASADI_PREFIX(s6)
#define casadi_s7 CASADI_PREFIX(s7)
#define casadi_s8 CASADI_PREFIX(s8)
#define casadi_s9 CASADI_PREFIX(s9)
#define casadi_sq CASADI_PREFIX(sq)

/* Symbol visibility in DLLs */
#if 0
  #if defined(_WIN32) || defined(__WIN32__) || defined(__CYGWIN__)
    #if defined(STATIC_LINKED)
      #define CASADI_SYMBOL_EXPORT
    #else
      #define __declspec(dllexport)
    #endif
  #elif defined(__GNUC__) && defined(GCC_HASCLASSVISIBILITY)
    #define __attribute__ ((visibility ("default")))
  #else
    #define CASADI_SYMBOL_EXPORT
  #endif
#endif

casadi_real casadi_sq(casadi_real x) { return x*x;}

static const casadi_int casadi_s0[19] = {15, 1, 0, 15, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14};
static const casadi_int casadi_s1[6] = {2, 1, 0, 2, 0, 1};
static const casadi_int casadi_s2[3] = {0, 0, 0};
static const casadi_int casadi_s3[5] = {1, 1, 0, 1, 0};
static const casadi_int casadi_s4[23] = {1, 15, 0, 1, 2, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 0, 0, 0, 0, 0};
static const casadi_int casadi_s5[23] = {2, 15, 0, 0, 0, 0, 0, 2, 3, 4, 4, 5, 5, 5, 5, 5, 5, 5, 0, 1, 1, 1, 0};
static const casadi_int casadi_s6[15] = {11, 1, 0, 11, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
static const casadi_int casadi_s7[8] = {4, 1, 0, 4, 0, 1, 2, 3};
static const casadi_int casadi_s8[17] = {4, 11, 0, 1, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 2, 3};
static const casadi_int casadi_s9[37] = {11, 11, 0, 1, 2, 3, 7, 9, 11, 13, 16, 19, 23, 23, 10, 10, 10, 0, 1, 2, 10, 7, 10, 8, 10, 9, 10, 0, 3, 10, 1, 3, 10, 0, 2, 3, 10};
static const casadi_int casadi_s10[7] = {3, 1, 0, 3, 0, 1, 2};
static const casadi_int casadi_s11[27] = {3, 15, 0, 1, 1, 1, 1, 3, 4, 5, 5, 6, 6, 6, 7, 8, 9, 9, 0, 1, 2, 2, 2, 1, 0, 0, 0};
static const casadi_int casadi_s12[10] = {6, 1, 0, 6, 0, 1, 2, 3, 4, 5};
static const casadi_int casadi_s13[16] = {1, 11, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 2, 2, 0, 0};
static const casadi_int casadi_s14[18] = {2, 11, 0, 0, 0, 0, 0, 1, 1, 1, 2, 3, 4, 4, 0, 1, 1, 1};

/* nlp3minError_DTVs_d42f_objective_1:(i0[15],i1[2],i2[],i3[])->(o0,o1[1x15,5nz]) */
static int casadi_f0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a10, a11, a12, a2, a3, a4, a5, a6, a7, a8, a9;
    a0=125000.;
    a1=arg[0]? arg[0][0] : 0;
    a2=casadi_sq(a1);
    a2=(a0*a2);
    a3=1.0000000000000001e-005;
    a4=arg[0]? arg[0][14] : 0;
    a4=(a3*a4);
    a5=arg[0]? arg[0][1] : 0;
    a6=(a4*a5);
    a7=(a6*a5);
    a8=arg[0]? arg[0][2] : 0;
    a9=(a4*a8);
    a10=(a9*a8);
    a7=(a7+a10);
    a10=arg[0]? arg[0][3] : 0;
    a11=(a4*a10);
    a12=(a11*a10);
    a7=(a7+a12);
    a2=(a2+a7);
    if (res[0]!=0) res[0][0]=a2;
    a1=(a1+a1);
    a0=(a0*a1);
    if (res[1]!=0) res[1][0]=a0;
    a0=(a4*a5);
    a6=(a6+a0);
    if (res[1]!=0) res[1][1]=a6;
    a6=(a4*a8);
    a9=(a9+a6);
    if (res[1]!=0) res[1][2]=a9;
    a4=(a4*a10);
    a11=(a11+a4);
    if (res[1]!=0) res[1][3]=a11;
    a10=casadi_sq(a10);
    a8=casadi_sq(a8);
    a10=(a10+a8);
    a5=casadi_sq(a5);
    a10=(a10+a5);
    a3=(a3*a10);
    if (res[1]!=0) res[1][4]=a3;
    return 0;
}

int nlp3minError_DTVs_d42f_objective_1(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
    return casadi_f0(arg, res, iw, w, mem);
}

const casadi_int* nlp3minError_DTVs_d42f_objective_1_sparsity_out(casadi_int i) {
    switch (i) {
        case 0: return casadi_s3;
        case 1: return casadi_s4;
        default: return 0;
    }
}

/* nlp3minError_DTVs_d42f_inequalities_1:(i0[15],i1[2],i2[],i3[])->(o0[2],o1[2x15,5nz]) */
static int casadi_f1(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a2, a3, a4, a5, a6, a7;
    a0=arg[0]? arg[0][4] : 0;
    a1=arg[1]? arg[1][1] : 0;
    a2=1.;
    a3=1.1000000000000000e-004;
    a4=arg[0]? arg[0][8] : 0;
    a3=(a3*a4);
    a3=(a2-a3);
    a3=(a1*a3);
    a3=(a0-a3);
    if (res[0]!=0) res[0][0]=a3;
    a3=arg[1]? arg[1][0] : 0;
    a4=casadi_sq(a0);
    a5=arg[0]? arg[0][5] : 0;
    a6=casadi_sq(a5);
    a4=(a4+a6);
    a6=arg[0]? arg[0][6] : 0;
    a7=casadi_sq(a6);
    a4=(a4+a7);
    a4=sqrt(a4);
    a7=(a3*a4);
    a7=(a7-a0);
    if (res[0]!=0) res[0][1]=a7;
    if (res[1]!=0) res[1][0]=a2;
    a0=(a0/a4);
    a0=(a3*a0);
    a2=-1.;
    a0=(a0+a2);
    if (res[1]!=0) res[1][1]=a0;
    a5=(a5/a4);
    a5=(a3*a5);
    if (res[1]!=0) res[1][2]=a5;
    a6=(a6/a4);
    a3=(a3*a6);
    if (res[1]!=0) res[1][3]=a3;
    a3=-1.1000000000000000e-004;
    a3=(a3*a1);
    a3=(-a3);
    if (res[1]!=0) res[1][4]=a3;
    return 0;
}

int nlp3minError_DTVs_d42f_inequalities_1(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
    return casadi_f1(arg, res, iw, w, mem);
}

const casadi_int* nlp3minError_DTVs_d42f_inequalities_1_sparsity_out(casadi_int i) {
    switch (i) {
        case 0: return casadi_s1;
        case 1: return casadi_s5;
        default: return 0;
    }
}

/* nlp3minError_DTVs_d42f_dynamics_0rd_0:(i0[11],i1[4],i2[2])->(o0[11]) */
static int casadi_f2(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a2, a3, a4, a5, a6;
    a0=arg[0]? arg[0][10] : 0;
    a1=arg[1]? arg[1][1] : 0;
    a1=(a0*a1);
    if (res[0]!=0) res[0][0]=a1;
    a1=arg[1]? arg[1][2] : 0;
    a1=(a0*a1);
    if (res[0]!=0) res[0][1]=a1;
    a1=arg[1]? arg[1][3] : 0;
    a1=(a0*a1);
    if (res[0]!=0) res[0][2]=a1;
    a1=-3.4166666666666666e-005;
    a2=arg[0]? arg[0][0] : 0;
    a3=casadi_sq(a2);
    a4=arg[0]? arg[0][1] : 0;
    a5=casadi_sq(a4);
    a3=(a3+a5);
    a5=arg[0]? arg[0][2] : 0;
    a6=casadi_sq(a5);
    a3=(a3+a6);
    a3=sqrt(a3);
    a1=(a1*a3);
    a1=(a0*a1);
    if (res[0]!=0) res[0][3]=a1;
    a1=arg[0]? arg[0][7] : 0;
    a1=(a0*a1);
    if (res[0]!=0) res[0][4]=a1;
    a1=arg[0]? arg[0][8] : 0;
    a1=(a0*a1);
    if (res[0]!=0) res[0][5]=a1;
    a1=arg[0]? arg[0][9] : 0;
    a1=(a0*a1);
    if (res[0]!=0) res[0][6]=a1;
    a1=-9.8066499999999994e+000;
    a3=arg[0]? arg[0][3] : 0;
    a6=(a2/a3);
    a1=(a1+a6);
    a1=(a0*a1);
    if (res[0]!=0) res[0][7]=a1;
    a4=(a4/a3);
    a4=(a0*a4);
    if (res[0]!=0) res[0][8]=a4;
    a5=(a5/a3);
    a3=2000.;
    a2=(a2/a3);
    a5=(a5-a2);
    a0=(a0*a5);
    if (res[0]!=0) res[0][9]=a0;
    a0=0.;
    if (res[0]!=0) res[0][10]=a0;
    return 0;
}

int nlp3minError_DTVs_d42f_dynamics_0rd_0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
    return casadi_f2(arg, res, iw, w, mem);
}

const casadi_int* nlp3minError_DTVs_d42f_dynamics_0rd_0_sparsity_out(casadi_int i) {
    switch (i) {
        case 0: return casadi_s6;
        default: return 0;
    }
}

/* nlp3minError_DTVs_d42f_dynamics_0:(i0[11],i1[4],i2[2])->(o0[11],o1[4x11,3nz],o2[11x11,23nz]) */
static int casadi_f3(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a2, a3, a4, a5, a6, a7, a8, a9;
    a0=arg[0]? arg[0][10] : 0;
    a1=arg[1]? arg[1][1] : 0;
    a2=(a0*a1);
    if (res[0]!=0) res[0][0]=a2;
    a2=arg[1]? arg[1][2] : 0;
    a3=(a0*a2);
    if (res[0]!=0) res[0][1]=a3;
    a3=arg[1]? arg[1][3] : 0;
    a4=(a0*a3);
    if (res[0]!=0) res[0][2]=a4;
    a4=-3.4166666666666666e-005;
    a5=arg[0]? arg[0][0] : 0;
    a6=casadi_sq(a5);
    a7=arg[0]? arg[0][1] : 0;
    a8=casadi_sq(a7);
    a6=(a6+a8);
    a8=arg[0]? arg[0][2] : 0;
    a9=casadi_sq(a8);
    a6=(a6+a9);
    a6=sqrt(a6);
    a9=(a4*a6);
    a10=(a0*a9);
    if (res[0]!=0) res[0][3]=a10;
    a10=arg[0]? arg[0][7] : 0;
    a11=(a0*a10);
    if (res[0]!=0) res[0][4]=a11;
    a11=arg[0]? arg[0][8] : 0;
    a12=(a0*a11);
    if (res[0]!=0) res[0][5]=a12;
    a12=arg[0]? arg[0][9] : 0;
    a13=(a0*a12);
    if (res[0]!=0) res[0][6]=a13;
    a13=-9.8066499999999994e+000;
    a14=arg[0]? arg[0][3] : 0;
    a15=(a5/a14);
    a13=(a13+a15);
    a16=(a0*a13);
    if (res[0]!=0) res[0][7]=a16;
    a16=(a7/a14);
    a17=(a0*a16);
    if (res[0]!=0) res[0][8]=a17;
    a17=(a8/a14);
    a18=2000.;
    a18=(a5/a18);
    a18=(a17-a18);
    a19=(a0*a18);
    if (res[0]!=0) res[0][9]=a19;
    a19=0.;
    if (res[0]!=0) res[0][10]=a19;
    if (res[1]!=0) res[1][0]=a0;
    if (res[1]!=0) res[1][1]=a0;
    if (res[1]!=0) res[1][2]=a0;
    if (res[2]!=0) res[2][0]=a1;
    if (res[2]!=0) res[2][1]=a2;
    if (res[2]!=0) res[2][2]=a3;
    a5=(a5/a6);
    a5=(a4*a5);
    a5=(a0*a5);
    if (res[2]!=0) res[2][3]=a5;
    a7=(a7/a6);
    a7=(a4*a7);
    a7=(a0*a7);
    if (res[2]!=0) res[2][4]=a7;
    a8=(a8/a6);
    a4=(a4*a8);
    a4=(a0*a4);
    if (res[2]!=0) res[2][5]=a4;
    if (res[2]!=0) res[2][6]=a9;
    if (res[2]!=0) res[2][7]=a0;
    if (res[2]!=0) res[2][8]=a10;
    if (res[2]!=0) res[2][9]=a0;
    if (res[2]!=0) res[2][10]=a11;
    if (res[2]!=0) res[2][11]=a0;
    if (res[2]!=0) res[2][12]=a12;
    a12=(a0/a14);
    if (res[2]!=0) res[2][13]=a12;
    a15=(a15/a14);
    a15=(a0*a15);
    a15=(-a15);
    if (res[2]!=0) res[2][14]=a15;
    if (res[2]!=0) res[2][15]=a13;
    a13=(a0/a14);
    if (res[2]!=0) res[2][16]=a13;
    a13=(a16/a14);
    a13=(a0*a13);
    a13=(-a13);
    if (res[2]!=0) res[2][17]=a13;
    if (res[2]!=0) res[2][18]=a16;
    a16=-5.0000000000000001e-004;
    a16=(a16*a0);
    if (res[2]!=0) res[2][19]=a16;
    a16=(a0/a14);
    if (res[2]!=0) res[2][20]=a16;
    a17=(a17/a14);
    a0=(a0*a17);
    a0=(-a0);
    if (res[2]!=0) res[2][21]=a0;
    if (res[2]!=0) res[2][22]=a18;
    return 0;
}

int nlp3minError_DTVs_d42f_dynamics_0(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
    return casadi_f3(arg, res, iw, w, mem);
}

const casadi_int* nlp3minError_DTVs_d42f_dynamics_0_sparsity_out(casadi_int i) {
    switch (i) {
        case 0: return casadi_s6;
        case 1: return casadi_s8;
        case 2: return casadi_s9;
        default: return 0;
    }
}

/* nlp3minError_DTVs_d42f_objective_2:(i0[15],i1[2],i2[],i3[])->(o0,o1[1x15,5nz]) */
static int casadi_f4(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a10, a11, a12, a2, a3, a4, a5, a6, a7, a8, a9;
    a0=125000.;
    a1=arg[0]? arg[0][0] : 0;
    a2=casadi_sq(a1);
    a2=(a0*a2);
    a3=1.0000000000000001e-005;
    a4=arg[0]? arg[0][14] : 0;
    a4=(a3*a4);
    a5=arg[0]? arg[0][1] : 0;
    a6=(a4*a5);
    a7=(a6*a5);
    a8=arg[0]? arg[0][2] : 0;
    a9=(a4*a8);
    a10=(a9*a8);
    a7=(a7+a10);
    a10=arg[0]? arg[0][3] : 0;
    a11=(a4*a10);
    a12=(a11*a10);
    a7=(a7+a12);
    a2=(a2+a7);
    if (res[0]!=0) res[0][0]=a2;
    a1=(a1+a1);
    a0=(a0*a1);
    if (res[1]!=0) res[1][0]=a0;
    a0=(a4*a5);
    a6=(a6+a0);
    if (res[1]!=0) res[1][1]=a6;
    a6=(a4*a8);
    a9=(a9+a6);
    if (res[1]!=0) res[1][2]=a9;
    a4=(a4*a10);
    a11=(a11+a4);
    if (res[1]!=0) res[1][3]=a11;
    a10=casadi_sq(a10);
    a8=casadi_sq(a8);
    a10=(a10+a8);
    a5=casadi_sq(a5);
    a10=(a10+a5);
    a3=(a3*a10);
    if (res[1]!=0) res[1][4]=a3;
    return 0;
}

int nlp3minError_DTVs_d42f_objective_2(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
    return casadi_f4(arg, res, iw, w, mem);
}

const casadi_int* nlp3minError_DTVs_d42f_objective_2_sparsity_out(casadi_int i) {
    switch (i) {
        case 0: return casadi_s3;
        case 1: return casadi_s4;
        default: return 0;
    }
}

/* nlp3minError_DTVs_d42f_inequalities_2:(i0[15],i1[2],i2[],i3[])->(o0[3],o1[3x15,9nz]) */
static int casadi_f5(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a10, a11, a2, a3, a4, a5, a6, a7, a8, a9;
    a0=arg[0]? arg[0][11] : 0;
    a1=casadi_sq(a0);
    a2=arg[0]? arg[0][12] : 0;
    a3=casadi_sq(a2);
    a1=(a1+a3);
    a3=arg[0]? arg[0][13] : 0;
    a4=casadi_sq(a3);
    a1=(a1+a4);
    a1=sqrt(a1);
    a4=arg[0]? arg[0][0] : 0;
    a4=(a1-a4);
    if (res[0]!=0) res[0][0]=a4;
    a4=arg[0]? arg[0][4] : 0;
    a5=arg[1]? arg[1][1] : 0;
    a6=1.;
    a7=1.1000000000000000e-004;
    a8=arg[0]? arg[0][8] : 0;
    a7=(a7*a8);
    a7=(a6-a7);
    a7=(a5*a7);
    a7=(a4-a7);
    if (res[0]!=0) res[0][1]=a7;
    a7=arg[1]? arg[1][0] : 0;
    a8=casadi_sq(a4);
    a9=arg[0]? arg[0][5] : 0;
    a10=casadi_sq(a9);
    a8=(a8+a10);
    a10=arg[0]? arg[0][6] : 0;
    a11=casadi_sq(a10);
    a8=(a8+a11);
    a8=sqrt(a8);
    a11=(a7*a8);
    a11=(a11-a4);
    if (res[0]!=0) res[0][2]=a11;
    a11=-1.;
    if (res[1]!=0) res[1][0]=a11;
    if (res[1]!=0) res[1][1]=a6;
    a4=(a4/a8);
    a4=(a7*a4);
    a4=(a4+a11);
    if (res[1]!=0) res[1][2]=a4;
    a9=(a9/a8);
    a9=(a7*a9);
    if (res[1]!=0) res[1][3]=a9;
    a10=(a10/a8);
    a7=(a7*a10);
    if (res[1]!=0) res[1][4]=a7;
    a7=-1.1000000000000000e-004;
    a7=(a7*a5);
    a7=(-a7);
    if (res[1]!=0) res[1][5]=a7;
    a0=(a0/a1);
    if (res[1]!=0) res[1][6]=a0;
    a2=(a2/a1);
    if (res[1]!=0) res[1][7]=a2;
    a3=(a3/a1);
    if (res[1]!=0) res[1][8]=a3;
    return 0;
}

int nlp3minError_DTVs_d42f_inequalities_2(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
    return casadi_f5(arg, res, iw, w, mem);
}

const casadi_int* nlp3minError_DTVs_d42f_inequalities_2_sparsity_out(casadi_int i) {
    switch (i) {
        case 0: return casadi_s10;
        case 1: return casadi_s11;
        default: return 0;
    }
}

/* nlp3minError_DTVs_d42f_dynamics_0rd_1:(i0[11],i1[4],i2[2])->(o0[11]) */
static int casadi_f6(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a2, a3, a4, a5, a6;
    a0=arg[0]? arg[0][10] : 0;
    a1=arg[1]? arg[1][1] : 0;
    a1=(a0*a1);
    if (res[0]!=0) res[0][0]=a1;
    a1=arg[1]? arg[1][2] : 0;
    a1=(a0*a1);
    if (res[0]!=0) res[0][1]=a1;
    a1=arg[1]? arg[1][3] : 0;
    a1=(a0*a1);
    if (res[0]!=0) res[0][2]=a1;
    a1=-3.4166666666666666e-005;
    a2=arg[0]? arg[0][0] : 0;
    a3=casadi_sq(a2);
    a4=arg[0]? arg[0][1] : 0;
    a5=casadi_sq(a4);
    a3=(a3+a5);
    a5=arg[0]? arg[0][2] : 0;
    a6=casadi_sq(a5);
    a3=(a3+a6);
    a3=sqrt(a3);
    a1=(a1*a3);
    a1=(a0*a1);
    if (res[0]!=0) res[0][3]=a1;
    a1=arg[0]? arg[0][7] : 0;
    a1=(a0*a1);
    if (res[0]!=0) res[0][4]=a1;
    a1=arg[0]? arg[0][8] : 0;
    a1=(a0*a1);
    if (res[0]!=0) res[0][5]=a1;
    a1=arg[0]? arg[0][9] : 0;
    a1=(a0*a1);
    if (res[0]!=0) res[0][6]=a1;
    a1=-9.8066499999999994e+000;
    a3=arg[0]? arg[0][3] : 0;
    a6=(a2/a3);
    a1=(a1+a6);
    a1=(a0*a1);
    if (res[0]!=0) res[0][7]=a1;
    a4=(a4/a3);
    a4=(a0*a4);
    if (res[0]!=0) res[0][8]=a4;
    a5=(a5/a3);
    a3=2000.;
    a2=(a2/a3);
    a5=(a5-a2);
    a0=(a0*a5);
    if (res[0]!=0) res[0][9]=a0;
    a0=0.;
    if (res[0]!=0) res[0][10]=a0;
    return 0;
}

int nlp3minError_DTVs_d42f_dynamics_0rd_1(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
    return casadi_f6(arg, res, iw, w, mem);
}

const casadi_int* nlp3minError_DTVs_d42f_dynamics_0rd_1_sparsity_out(casadi_int i) {
    switch (i) {
        case 0: return casadi_s6;
        default: return 0;
    }
}

/* nlp3minError_DTVs_d42f_dynamics_1:(i0[11],i1[4],i2[2])->(o0[11],o1[4x11,3nz],o2[11x11,23nz]) */
static int casadi_f7(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a10, a11, a12, a13, a14, a15, a16, a17, a18, a19, a2, a3, a4, a5, a6, a7, a8, a9;
    a0=arg[0]? arg[0][10] : 0;
    a1=arg[1]? arg[1][1] : 0;
    a2=(a0*a1);
    if (res[0]!=0) res[0][0]=a2;
    a2=arg[1]? arg[1][2] : 0;
    a3=(a0*a2);
    if (res[0]!=0) res[0][1]=a3;
    a3=arg[1]? arg[1][3] : 0;
    a4=(a0*a3);
    if (res[0]!=0) res[0][2]=a4;
    a4=-3.4166666666666666e-005;
    a5=arg[0]? arg[0][0] : 0;
    a6=casadi_sq(a5);
    a7=arg[0]? arg[0][1] : 0;
    a8=casadi_sq(a7);
    a6=(a6+a8);
    a8=arg[0]? arg[0][2] : 0;
    a9=casadi_sq(a8);
    a6=(a6+a9);
    a6=sqrt(a6);
    a9=(a4*a6);
    a10=(a0*a9);
    if (res[0]!=0) res[0][3]=a10;
    a10=arg[0]? arg[0][7] : 0;
    a11=(a0*a10);
    if (res[0]!=0) res[0][4]=a11;
    a11=arg[0]? arg[0][8] : 0;
    a12=(a0*a11);
    if (res[0]!=0) res[0][5]=a12;
    a12=arg[0]? arg[0][9] : 0;
    a13=(a0*a12);
    if (res[0]!=0) res[0][6]=a13;
    a13=-9.8066499999999994e+000;
    a14=arg[0]? arg[0][3] : 0;
    a15=(a5/a14);
    a13=(a13+a15);
    a16=(a0*a13);
    if (res[0]!=0) res[0][7]=a16;
    a16=(a7/a14);
    a17=(a0*a16);
    if (res[0]!=0) res[0][8]=a17;
    a17=(a8/a14);
    a18=2000.;
    a18=(a5/a18);
    a18=(a17-a18);
    a19=(a0*a18);
    if (res[0]!=0) res[0][9]=a19;
    a19=0.;
    if (res[0]!=0) res[0][10]=a19;
    if (res[1]!=0) res[1][0]=a0;
    if (res[1]!=0) res[1][1]=a0;
    if (res[1]!=0) res[1][2]=a0;
    if (res[2]!=0) res[2][0]=a1;
    if (res[2]!=0) res[2][1]=a2;
    if (res[2]!=0) res[2][2]=a3;
    a5=(a5/a6);
    a5=(a4*a5);
    a5=(a0*a5);
    if (res[2]!=0) res[2][3]=a5;
    a7=(a7/a6);
    a7=(a4*a7);
    a7=(a0*a7);
    if (res[2]!=0) res[2][4]=a7;
    a8=(a8/a6);
    a4=(a4*a8);
    a4=(a0*a4);
    if (res[2]!=0) res[2][5]=a4;
    if (res[2]!=0) res[2][6]=a9;
    if (res[2]!=0) res[2][7]=a0;
    if (res[2]!=0) res[2][8]=a10;
    if (res[2]!=0) res[2][9]=a0;
    if (res[2]!=0) res[2][10]=a11;
    if (res[2]!=0) res[2][11]=a0;
    if (res[2]!=0) res[2][12]=a12;
    a12=(a0/a14);
    if (res[2]!=0) res[2][13]=a12;
    a15=(a15/a14);
    a15=(a0*a15);
    a15=(-a15);
    if (res[2]!=0) res[2][14]=a15;
    if (res[2]!=0) res[2][15]=a13;
    a13=(a0/a14);
    if (res[2]!=0) res[2][16]=a13;
    a13=(a16/a14);
    a13=(a0*a13);
    a13=(-a13);
    if (res[2]!=0) res[2][17]=a13;
    if (res[2]!=0) res[2][18]=a16;
    a16=-5.0000000000000001e-004;
    a16=(a16*a0);
    if (res[2]!=0) res[2][19]=a16;
    a16=(a0/a14);
    if (res[2]!=0) res[2][20]=a16;
    a17=(a17/a14);
    a0=(a0*a17);
    a0=(-a0);
    if (res[2]!=0) res[2][21]=a0;
    if (res[2]!=0) res[2][22]=a18;
    return 0;
}

int nlp3minError_DTVs_d42f_dynamics_1(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
    return casadi_f7(arg, res, iw, w, mem);
}

const casadi_int* nlp3minError_DTVs_d42f_dynamics_1_sparsity_out(casadi_int i) {
    switch (i) {
        case 0: return casadi_s6;
        case 1: return casadi_s8;
        case 2: return casadi_s9;
        default: return 0;
    }
}

/* nlp3minError_DTVs_d42f_objective_30:(i0[11],i1[6],i2[],i3[])->(o0,o1[1x11,2nz]) */
static int casadi_f8(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a2, a3;
    a0=arg[0]? arg[0][5] : 0;
    a1=arg[1]? arg[1][1] : 0;
    a0=(a0-a1);
    a1=casadi_sq(a0);
    a2=arg[0]? arg[0][6] : 0;
    a3=arg[1]? arg[1][2] : 0;
    a2=(a2-a3);
    a3=casadi_sq(a2);
    a1=(a1+a3);
    if (res[0]!=0) res[0][0]=a1;
    a0=(a0+a0);
    if (res[1]!=0) res[1][0]=a0;
    a2=(a2+a2);
    if (res[1]!=0) res[1][1]=a2;
    return 0;
}

int nlp3minError_DTVs_d42f_objective_30(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
    return casadi_f8(arg, res, iw, w, mem);
}

const casadi_int* nlp3minError_DTVs_d42f_objective_30_sparsity_out(casadi_int i) {
    switch (i) {
        case 0: return casadi_s3;
        case 1: return casadi_s13;
        default: return 0;
    }
}

/* nlp3minError_DTVs_d42f_inequalities_30:(i0[11],i1[6],i2[],i3[])->(o0[2],o1[2x11,4nz]) */
static int casadi_f9(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem) {
  casadi_real a0, a1, a2, a3, a4, a5;
    a0=arg[0]? arg[0][4] : 0;
    a1=arg[1]? arg[1][0] : 0;
    a0=(a0-a1);
    a1=casadi_sq(a0);
    if (res[0]!=0) res[0][0]=a1;
    a1=arg[0]? arg[0][7] : 0;
    a2=arg[1]? arg[1][3] : 0;
    a1=(a1-a2);
    a2=casadi_sq(a1);
    a3=arg[0]? arg[0][8] : 0;
    a4=arg[1]? arg[1][4] : 0;
    a3=(a3-a4);
    a4=casadi_sq(a3);
    a2=(a2+a4);
    a4=arg[0]? arg[0][9] : 0;
    a5=arg[1]? arg[1][5] : 0;
    a4=(a4-a5);
    a5=casadi_sq(a4);
    a2=(a2+a5);
    if (res[0]!=0) res[0][1]=a2;
    a0=(a0+a0);
    if (res[1]!=0) res[1][0]=a0;
    a1=(a1+a1);
    if (res[1]!=0) res[1][1]=a1;
    a3=(a3+a3);
    if (res[1]!=0) res[1][2]=a3;
    a4=(a4+a4);
    if (res[1]!=0) res[1][3]=a4;
    return 0;
}

int nlp3minError_DTVs_d42f_inequalities_30(const casadi_real** arg, casadi_real** res, casadi_int* iw, casadi_real* w, int mem){
    return casadi_f9(arg, res, iw, w, mem);
}

const casadi_int* nlp3minError_DTVs_d42f_inequalities_30_sparsity_out(casadi_int i) {
    switch (i) {
        case 0: return casadi_s1;
        case 1: return casadi_s14;
        default: return 0;
    }
}

#ifdef __cplusplus
} /* extern "C" */
#endif
