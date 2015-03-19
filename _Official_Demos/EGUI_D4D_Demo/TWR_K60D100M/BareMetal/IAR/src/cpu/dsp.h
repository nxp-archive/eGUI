#ifndef __DSP_H__
#define __DSP_H__

#ifdef __cplusplus
extern "C" {
#endif

#ifndef	s8
#define s8		char
#endif
#ifndef	u8
#define u8		unsigned char
#endif
#ifndef	s16
#define s16		short
#endif
#ifndef	u16
#define u16		unsigned short
#endif
#ifndef	s32
#define s32		long
#endif
#ifndef	u32
#define u32		unsigned long
#endif
#ifndef	sint
#define sint		int
#endif
#ifndef	uint
#define uint		unsigned int
#endif
#ifndef	s64
#define s64		long long
#endif
#ifndef	u64
#define u64		unsigned long long
#endif

/* Function prototyp */
#pragma inline=forced
#pragma language=save
#pragma language=extended

//extern inline s64 __smlal(s64 acc, s32 x, s32 y);
__intrinsic extern s64 __smlal(s64 acc, s32 x, s32 y);
extern inline s64 __smull(s64 retval, s32 x, s32 y);

extern inline s32 __smlabb(s32 retval, s32 x, s32 y, s32 acc);
extern inline s32 __smlabt(s32 retval, s32 x, s32 y, s32 acc);
extern inline s32 __smlatb(s32 retval, s32 x, s32 y, s32 acc);
extern inline s32 __smlatt(s32 retval, s32 x, s32 y, s32 acc);

extern inline s32 __smlad(s32 retval, s32 x, s32 y, s32 acc);
extern inline s32 __smladx(s32 retval, s32 x, s32 y, s32 acc);

extern inline s64 __smlalbb(s64 acc, s32 x, s32 y);
extern inline s64 __smlalbt(s64 acc, s32 x, s32 y);
extern inline s64 __smlaltb(s64 acc, s32 x, s32 y);
extern inline s64 __smlaltt(s64 acc, s32 x, s32 y);

extern inline s64 __smlald(s64 acc, s32 x, s32 y);
extern inline s64 __smlaldx(s64 acc, s32 x, s32 y);

extern inline s32 __smlawb(s32 retval, s32 x, s32 y, s32 acc);
extern inline s32 __smlawt(s32 retval, s32 x, s32 y, s32 acc);

extern inline s32 __smlsd(s32 retval, s32 x, s32 y, s32 acc);
extern inline s32 __smlsdx(s32 retval, s32 x, s32 y, s32 acc);

extern inline s64 __smlsld(s64 sub, s32 x, s32 y);
extern inline s64 __smlsldx(s64 sub, s32 x, s32 y);

extern inline s32 __smmla(s32 retval, s32 x, s32 y, s32 acc);
extern inline s32 __smmlar(s32 retval, s32 x, s32 y, s32 acc);

extern inline s32 __smmls(s32 retval, s32 x, s32 y, s32 sub);
extern inline s32 __smmlsr(s32 retval, s32 x, s32 y, s32 sub);

extern inline s32 __smmul(s32 retval, s32 x, s32 y);
extern inline s32 __smmulr(s32 retval, s32 x, s32 y);

extern inline s32 __smuad(s32 retval, s32 x, s32 y);
extern inline s32 __smuadx(s32 retval, s32 x, s32 y);

extern inline s32 __smulbb(s32 retval, s32 x, s32 y);
extern inline s32 __smulbt(s32 retval, s32 x, s32 y);
extern inline s32 __smultb(s32 retval, s32 x, s32 y);
extern inline s32 __smultt(s32 retval, s32 x, s32 y);

extern inline s32 __smulwb(s32 retval, s32 x, s32 y);
extern inline s32 __smulwt(s32 retval, s32 x, s32 y);

extern inline s32 __smusd(s32 retval, s32 x, s32 y);
extern inline s32 __smusdx(s32 retval, s32 x, s32 y);

extern inline u64 __umlal(u64 uacc64, u32 x, u32 y);
extern inline u64 __umull(u64 retval64, u32 x, u32 y);

extern inline u64 __umaal(u64 retval64, u32 x, u32 y);

extern inline u32 __ssat01L00(s32 retval32, s32 x);
extern inline u32 __ssat01L01(s32 retval32, s32 x);
extern inline u32 __ssat01L02(s32 retval32, s32 x);
extern inline u32 __ssat01L03(s32 retval32, s32 x);
extern inline u32 __ssat01L04(s32 retval32, s32 x);
extern inline u32 __ssat01L05(s32 retval32, s32 x);
extern inline u32 __ssat01L06(s32 retval32, s32 x);
extern inline u32 __ssat01L07(s32 retval32, s32 x);
extern inline u32 __ssat01L08(s32 retval32, s32 x);
extern inline u32 __ssat01L09(s32 retval32, s32 x);
extern inline u32 __ssat01L10(s32 retval32, s32 x);
extern inline u32 __ssat01L11(s32 retval32, s32 x);
extern inline u32 __ssat01L12(s32 retval32, s32 x);
extern inline u32 __ssat01L13(s32 retval32, s32 x);
extern inline u32 __ssat01L14(s32 retval32, s32 x);
extern inline u32 __ssat01L15(s32 retval32, s32 x);
extern inline u32 __ssat01L16(s32 retval32, s32 x);
extern inline u32 __ssat01L17(s32 retval32, s32 x);
extern inline u32 __ssat01L18(s32 retval32, s32 x);
extern inline u32 __ssat01L19(s32 retval32, s32 x);
extern inline u32 __ssat01L20(s32 retval32, s32 x);
extern inline u32 __ssat01L21(s32 retval32, s32 x);
extern inline u32 __ssat01L22(s32 retval32, s32 x);
extern inline u32 __ssat01L23(s32 retval32, s32 x);
extern inline u32 __ssat01L24(s32 retval32, s32 x);
extern inline u32 __ssat01L25(s32 retval32, s32 x);
extern inline u32 __ssat01L26(s32 retval32, s32 x);
extern inline u32 __ssat01L27(s32 retval32, s32 x);
extern inline u32 __ssat01L28(s32 retval32, s32 x);
extern inline u32 __ssat01L29(s32 retval32, s32 x);
extern inline u32 __ssat01L30(s32 retval32, s32 x);
extern inline u32 __ssat01L31(s32 retval32, s32 x);
extern inline u32 __ssat01A01(s32 retval32, s32 x);
extern inline u32 __ssat01A02(s32 retval32, s32 x);
extern inline u32 __ssat01A03(s32 retval32, s32 x);
extern inline u32 __ssat01A04(s32 retval32, s32 x);
extern inline u32 __ssat01A05(s32 retval32, s32 x);
extern inline u32 __ssat01A06(s32 retval32, s32 x);
extern inline u32 __ssat01A07(s32 retval32, s32 x);
extern inline u32 __ssat01A08(s32 retval32, s32 x);
extern inline u32 __ssat01A09(s32 retval32, s32 x);
extern inline u32 __ssat01A10(s32 retval32, s32 x);
extern inline u32 __ssat01A11(s32 retval32, s32 x);
extern inline u32 __ssat01A12(s32 retval32, s32 x);
extern inline u32 __ssat01A13(s32 retval32, s32 x);
extern inline u32 __ssat01A14(s32 retval32, s32 x);
extern inline u32 __ssat01A15(s32 retval32, s32 x);
extern inline u32 __ssat01A16(s32 retval32, s32 x);
extern inline u32 __ssat01A17(s32 retval32, s32 x);
extern inline u32 __ssat01A18(s32 retval32, s32 x);
extern inline u32 __ssat01A19(s32 retval32, s32 x);
extern inline u32 __ssat01A20(s32 retval32, s32 x);
extern inline u32 __ssat01A21(s32 retval32, s32 x);
extern inline u32 __ssat01A22(s32 retval32, s32 x);
extern inline u32 __ssat01A23(s32 retval32, s32 x);
extern inline u32 __ssat01A24(s32 retval32, s32 x);
extern inline u32 __ssat01A25(s32 retval32, s32 x);
extern inline u32 __ssat01A26(s32 retval32, s32 x);
extern inline u32 __ssat01A27(s32 retval32, s32 x);
extern inline u32 __ssat01A28(s32 retval32, s32 x);
extern inline u32 __ssat01A29(s32 retval32, s32 x);
extern inline u32 __ssat01A30(s32 retval32, s32 x);
extern inline u32 __ssat01A31(s32 retval32, s32 x);
extern inline u32 __ssat01A32(s32 retval32, s32 x);

u32 rand(void);

#define RAND_MAXS16	0x7FFF
#define RAND_MAXU16	0xFFFF
#define RAND_MAXS32	0x7FFFFFFF
#define RAND_MAXU32	0xFFFFFFFF
#define RAND_MAX	RAND_MAXU32

#define	RAND_S16	(s16)(rand() & RAND_MAXS16)
#define	RAND_U16	(u16)(rand() & RAND_MAXU16)
#define	RAND_S32	(s32)(rand() & RAND_MAXS32)
#define	RAND_U32	(u32)(rand() & RAND_MAXU32)

#pragma language=restore

#ifdef __cplusplus 
} 
#endif 

#endif	/* __DSP_H__ */