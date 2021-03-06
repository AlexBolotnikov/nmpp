#ifndef _FFT_32FC_H_INCLUDED_
#define _FFT_32FC_H_INCLUDED_

#ifdef __cplusplus
		extern "C" {
#endif

#include "nmtype.h"


#define		NUMBUFF1		21
#define		NUMBUFF2		4

typedef struct
{   
    nm32fcr *Buffers[NUMBUFF1];
    nm32fcr *Buffs[NUMBUFF2];
    int order;
} NmppsFFTSpec_32fc;

void nmppsDFT8Fwd_32fc(nm32fcr *x8, nm32fcr *X8, NmppsFFTSpec_32fc *spec8);
void nmppsFFT16Fwd_32fc(nm32fcr *x16, nm32fcr *X16, NmppsFFTSpec_32fc *spec16);
void nmppsFFT32Fwd_32fc(nm32fcr *x32, nm32fcr *X32, NmppsFFTSpec_32fc *spec32);
void nmppsFFT64Fwd_32fc(nm32fcr *x64, nm32fcr *X64, NmppsFFTSpec_32fc *spec64);
void nmppsFFT128Fwd_32fc(nm32fcr *x128, nm32fcr *X128, NmppsFFTSpec_32fc *spec128);
void nmppsFFT256Fwd_32fc(nm32fcr *x256, nm32fcr *X256, NmppsFFTSpec_32fc *spec256);
void nmppsFFT512Fwd_32fc(nm32fcr *x512, nm32fcr *X512, NmppsFFTSpec_32fc *spec512);
void nmppsFFT1024Fwd_32fc(nm32fcr *x1024, nm32fcr *X1024, NmppsFFTSpec_32fc *spec1024);
void nmppsFFT2048Fwd_32fc(nm32fcr *x2048, nm32fcr *X2048, NmppsFFTSpec_32fc *spec2048);

int nmppsFFTFwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *Spc);

int nmppsFFT16FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr16);
int nmppsFFT32FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr32);
int nmppsFFT64FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr64);
int nmppsFFT128FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr128);
int nmppsFFT256FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr256);
int nmppsFFT512FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr512);
int nmppsFFT1024FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr1024);
int nmppsFFT2048FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr2048);

int nmppsFFTFwdInitAlloc_32fc(NmppsFFTSpec_32fc **Spec, int Order);

int nmppsFFTFree_32fc(NmppsFFTSpec_32fc *specN);

#ifdef __cplusplus
		};
#endif

#endif // _FFT_32FC_H_INCLUDED_