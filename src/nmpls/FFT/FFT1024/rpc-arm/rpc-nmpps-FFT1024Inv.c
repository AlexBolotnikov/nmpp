	#include "fft2.h"
	#include "rpc-host.h"	

	void nmppsFFT1024Inv(nm32sc* src, nm32sc* dst, NmppsFFTSpec* spec)
	{
		int ret;	
		int size=1024;
		int k=8;
		struct aura_buffer *iobuf_src = aura_buffer_request(n, size*k);	
		struct aura_buffer *iobuf_dst = aura_buffer_request(n, size*k);	
		memcpy(iobuf_src->data,src,size*k);	
		struct aura_buffer *retbuf; 
		ret = aura_call(n, "nmppsFFT1024Inv", &retbuf,  iobuf_src, iobuf_dst, spec); 
		if (ret != 0) {
			slog(0, SLOG_ERROR, "call nmppsFFT1024Inv  failed, reason: %d\n", ret);
			BUG(n, "Call nmppsFFT1024Inv failed!"); 
		}
		memcpy(dst,iobuf_dst->data,size*k);
		aura_buffer_release( iobuf_dst); 
		aura_buffer_release( iobuf_src); 
		aura_buffer_release( retbuf); 
		slog(0, SLOG_INFO, "ARM: Call nmppsFFT1024Inv -ok"); 
	}


	int nmppsFFT1024InvInitAlloc( NmppsFFTSpec** spec, void* src, void* dst, int settings)
	{
		struct aura_buffer *iobuf_src = aura_buffer_request(n, 1024*8);	
		struct aura_buffer *iobuf_dst = aura_buffer_request(n, 1024*8);	
		struct aura_buffer *retbuf; 
		int ret =  aura_call(n, "nmppsFFT1024InvInitAlloc", &retbuf,  iobuf_src, iobuf_dst, settings); 
		if (ret != 0) {
			slog(0, SLOG_ERROR, "call failed, reason: %d\n", ret);
			BUG(n, "Call nmppsFFT1024InvInitAlloc failed!"); 
		}
		*spec = (NmppsFFTSpec*) aura_buffer_get_u32(retbuf);
		ret   = aura_buffer_get_u32(retbuf);
		aura_buffer_release( iobuf_src); 
		aura_buffer_release( iobuf_dst); 
		aura_buffer_release( retbuf); 
		slog(0, SLOG_INFO, "ARM: Call nmppsFFT1024InvInitAlloc -ok"); 
		return ret;
	}