  SECTION .noinit : CODE

	EXPORT	__smlal
	EXPORT	__smull

	EXPORT	__smlabb
	EXPORT	__smlabt
	EXPORT	__smlatb
	EXPORT	__smlatt

	EXPORT	__smlad
	EXPORT	__smladx

	EXPORT	__smlalbb
	EXPORT	__smlalbt
	EXPORT	__smlaltb
	EXPORT	__smlaltt

	EXPORT	__smlald
	EXPORT	__smlaldx

	EXPORT	__smlawb
	EXPORT	__smlawt

	EXPORT	__smlsd
	EXPORT	__smlsdx

	EXPORT	__smlsld
	EXPORT	__smlsldx

	EXPORT	__smmla
	EXPORT	__smmlar

	EXPORT	__smmls
	EXPORT	__smmlsr

	EXPORT	__smmul
	EXPORT	__smmulr

	EXPORT	__smuad
	EXPORT	__smuadx

	EXPORT	__smulbb
	EXPORT	__smulbt
	EXPORT	__smultb
	EXPORT	__smultt

	EXPORT	__smulwb
	EXPORT	__smulwt

	EXPORT	__smusd
	EXPORT	__smusdx

	EXPORT	__umlal
	EXPORT	__umull

	EXPORT	__umaal

	EXPORT	__ssat01L00
	EXPORT	__ssat01L01
	EXPORT	__ssat01L02
	EXPORT	__ssat01L03
	EXPORT	__ssat01L04
	EXPORT	__ssat01L05
	EXPORT	__ssat01L06
	EXPORT	__ssat01L07
	EXPORT	__ssat01L08
	EXPORT	__ssat01L09
	EXPORT	__ssat01L10
	EXPORT	__ssat01L11
	EXPORT	__ssat01L12
	EXPORT	__ssat01L13
	EXPORT	__ssat01L14
	EXPORT	__ssat01L15
	EXPORT	__ssat01L16
	EXPORT	__ssat01L17
	EXPORT	__ssat01L18
	EXPORT	__ssat01L19
	EXPORT	__ssat01L20
	EXPORT	__ssat01L21
	EXPORT	__ssat01L22
	EXPORT	__ssat01L23
	EXPORT	__ssat01L24
	EXPORT	__ssat01L25
	EXPORT	__ssat01L26
	EXPORT	__ssat01L27
	EXPORT	__ssat01L28
	EXPORT	__ssat01L29
	EXPORT	__ssat01L30
	EXPORT	__ssat01L31
	EXPORT	__ssat01A01
	EXPORT	__ssat01A02
	EXPORT	__ssat01A03
	EXPORT	__ssat01A04
	EXPORT	__ssat01A05
	EXPORT	__ssat01A06
	EXPORT	__ssat01A07
	EXPORT	__ssat01A08
	EXPORT	__ssat01A09
	EXPORT	__ssat01A10
	EXPORT	__ssat01A11
	EXPORT	__ssat01A12
	EXPORT	__ssat01A13
	EXPORT	__ssat01A14
	EXPORT	__ssat01A15
	EXPORT	__ssat01A16
	EXPORT	__ssat01A17
	EXPORT	__ssat01A18
	EXPORT	__ssat01A19
	EXPORT	__ssat01A20
	EXPORT	__ssat01A21
	EXPORT	__ssat01A22
	EXPORT	__ssat01A23
	EXPORT	__ssat01A24
	EXPORT	__ssat01A25
	EXPORT	__ssat01A26
	EXPORT	__ssat01A27
	EXPORT	__ssat01A28
	EXPORT	__ssat01A29
	EXPORT	__ssat01A30
	EXPORT	__ssat01A31
	EXPORT	__ssat01A32

;	EXPORT	__sml

; Signed Multiply Accumulate Long
; r0 - lower 32 bits accumulate and return result
; r1 - upper 32 bits accumulate and return result
; r2 - x
; r3 - y
__smlal:
	smlal	r0, r1, r2, r3
	bx	lr

; Signed Multiply Long
; r0 - lower 32 bits return result
; r1 - upper 32 bits return result
; r2 - x
; r3 - y
__smull:
	smull	r0, r1, r2, r3
	bx	lr

; Signed Multiply Accumulate, halfwords
; r0 - return result
; r1 - x
; r2 - y
; r3 - accumulate
__smlabb:
	smlabb	r0, r1, r2, r3
	bx	lr

__smlabt:
	smlabt	r0, r1, r2, r3
	bx	lr

__smlatb:
	smlatb	r0, r1, r2, r3
	bx	lr

__smlatt:
	smlatt	r0, r1, r2, r3
	bx	lr

; Signed Multiply Accumulate Dual
; r0 - return result
; r1 - x
; r2 - y
; r3 - accumulate
__smlad:
	smlad	r0, r1, r2, r3
	bx	lr

__smladx:
	smladx	r0, r1, r2, r3
	bx	lr

; Signed Multiply Accumulate long, halfwords
; r0 - lower 32 bits of accumulate value
; r1 - upper 32 bits of accumulate value
; r2 - x
; r3 - y
__smlalbb:
	smlalbb	r0, r1, r2, r3
	bx	lr

__smlalbt:
	smlalbt	r0, r1, r2, r3
	bx	lr

__smlaltb:
	smlaltb	r0, r1, r2, r3
	bx	lr

__smlaltt:
	smlaltt	r0, r1, r2, r3
	bx	lr

; Signed Multiply Accumulate Long Dual
; r0 - lower 32 bits accumulate and return result
; r1 - upper 32 bits accumulate and return result
; r2 - x
; r3 - y
__smlald:
	smlald	r0, r1, r2, r3
	bx	lr

__smlaldx:
	smlaldx	r0, r1, r2, r3
	bx	lr

; signed Multipl Accumulate, word by halfword
; r0 - return result
; r1 - x
; r2 - y
; r3 - accumulate
__smlawb:
	smlawb	r0, r1, r2, r3
	bx	lr

__smlawt:
	smlawt	r0, r1, r2, r3
	bx	lr

; Signed Multiply Subtract Dual
; r0 - 32 bits return result
; r1 - x
; r2 - y
; r3 - accumulate
__smlsd:
	smlsd	r0, r1, r2, r3
	bx	lr

__smlsdx:
	smlsdx	r0, r1, r2, r3
	bx	lr

; Signed Multiply Subtract Long Dual
; r0 - lower 32 bits accumulate and return result
; r1 - upper 32 bits accumulate and return result
; r2 - x
; r3 - y
__smlsld:
	smlsld	r0, r1, r2, r3
	bx	lr

__smlsldx:
	smlsldx	r0, r1, r2, r3
	bx	lr

; Signed Most Significant Word Multiply Accumulate
; r0 - 32 bits return result
; r1 - x
; r2 - y
; r3 - accumulate
__smmla:
	smmla	r0, r1, r2, r3
	bx	lr

__smmlar:
	smmlar	r0, r1, r2, r3
	bx	lr

; Signed Most Significant Word Multiply Subtract
; r0 - 32 bits return result
; r1 - x
; r2 - y
; r3 - accumulate
__smmls:
	smmls	r0, r1, r2, r3
	bx	lr

__smmlsr:
	smmlsr	r0, r1, r2, r3
	bx	lr

; Signed Most Significant Word Multiply
; r0 - 32 bits Accumulate and return result
; r1 - x
; r2 - y
__smmul:
	smmul	r0, r1, r2
	bx	lr

__smmulr:
	smmulr	r0, r1, r2
	bx	lr

; Signed Dual Multiply Add
; r0 - Return result
; r1 - x
; r2 - y
__smuad:
	smuad	r0, r1, r2
	bx	lr

__smuadx:
	smuadx	r0, r1, r2
	bx	lr

; Signed Multiply, halfwords
; r0 - return result
; r1 - x
; r2 - y
__smulbb:
	smulbb	r0, r1, r2
	bx	lr

__smulbt:
	smulbt	r0, r1, r2
	bx	lr

__smultb:
	smultb	r0, r1, r2
	bx	lr

__smultt:
	smultt	r0, r1, r2
	bx	lr

; Signed Multiply, word by halfwords
; r0 - return result
; r1 - x
; r2 - y
__smulwb:
	smulwb	r0, r1, r2
	bx	lr

__smulwt:
	smulwt	r0, r1, r2
	bx	lr

; Signed Dual Multiply Subtract
; r0 - return result
; r1 - x
; r2 - y
__smusd:
	smusd	r0, r1, r2
	bx	lr

__smusdx:
	smusdx	r0, r1, r2
	bx	lr

; Unsigned Multiply Accumulate Long
; r0 - lower 32 bits Accumulate and return result
; r1 - upper 32 bits Accumulate and return result
; r2 - x
; r3 - y
__umlal:
	umlal	r0, r1, r2, r3
	bx	lr

; Unsigned Multiply Long
; r0 - lower 32 bits return result
; r1 - upper 32 bits return result
; r2 - x
; r3 - y
__umull:
	umull	r0, r1, r2, r3
	bx	lr

; Unsigned Multiply Accumulate Accumulate Long
; r0 - lower 32 bits return result
; r1 - upper 32 bits return result
; r2 - x
; r3 - y
__umaal:
	umaal	r0, r1, r2, r3
	bx	lr

; signed saturate
; r0 - return result
; r1 - x
__ssat01L00
	ssat	r0, #1, r1, LSL #0
	bx	lr
__ssat01L01
	ssat	r0, #1, r1, LSL #1
	bx	lr
__ssat01L02
	ssat	r0, #1, r1, LSL #2
	bx	lr
__ssat01L03
	ssat	r0, #1, r1, LSL #3
	bx	lr
__ssat01L04
	ssat	r0, #1, r1, LSL #4
	bx	lr
__ssat01L05
	ssat	r0, #1, r1, LSL #5
	bx	lr
__ssat01L06
	ssat	r0, #1, r1, LSL #6
	bx	lr
__ssat01L07
	ssat	r0, #1, r1, LSL #7
	bx	lr
__ssat01L08
	ssat	r0, #1, r1, LSL #8
	bx	lr
__ssat01L09
	ssat	r0, #1, r1, LSL #9
	bx	lr
__ssat01L10
	ssat	r0, #1, r1, LSL #10
	bx	lr
__ssat01L11
	ssat	r0, #1, r1, LSL #11
	bx	lr
__ssat01L12
	ssat	r0, #1, r1, LSL #12
	bx	lr
__ssat01L13
	ssat	r0, #1, r1, LSL #13
	bx	lr
__ssat01L14
	ssat	r0, #1, r1, LSL #14
	bx	lr
__ssat01L15
	ssat	r0, #1, r1, LSL #15
	bx	lr
__ssat01L16
	ssat	r0, #1, r1, LSL #16
	bx	lr
__ssat01L17
	ssat	r0, #1, r1, LSL #17
	bx	lr
__ssat01L18
	ssat	r0, #1, r1, LSL #18
	bx	lr
__ssat01L19
	ssat	r0, #1, r1, LSL #19
	bx	lr
__ssat01L20
	ssat	r0, #1, r1, LSL #20
	bx	lr
__ssat01L21
	ssat	r0, #1, r1, LSL #21
	bx	lr
__ssat01L22
	ssat	r0, #1, r1, LSL #22
	bx	lr
__ssat01L23
	ssat	r0, #1, r1, LSL #23
	bx	lr
__ssat01L24
	ssat	r0, #1, r1, LSL #24
	bx	lr
__ssat01L25
	ssat	r0, #1, r1, LSL #25
	bx	lr
__ssat01L26
	ssat	r0, #1, r1, LSL #26
	bx	lr
__ssat01L27
	ssat	r0, #1, r1, LSL #27
	bx	lr
__ssat01L28
	ssat	r0, #1, r1, LSL #28
	bx	lr
__ssat01L29
	ssat	r0, #1, r1, LSL #29
	bx	lr
__ssat01L30
	ssat	r0, #1, r1, LSL #30
	bx	lr
__ssat01L31
	ssat	r0, #1, r1, LSL #31
	bx	lr
__ssat01A01
	ssat	r0, #1, r1, ASR #1
	bx	lr
__ssat01A02
	ssat	r0, #1, r1, ASR #2
	bx	lr
__ssat01A03
	ssat	r0, #1, r1, ASR #3
	bx	lr
__ssat01A04
	ssat	r0, #1, r1, ASR #4
	bx	lr
__ssat01A05
	ssat	r0, #1, r1, ASR #5
	bx	lr
__ssat01A06
	ssat	r0, #1, r1, ASR #6
	bx	lr
__ssat01A07
	ssat	r0, #1, r1, ASR #7
	bx	lr
__ssat01A08
	ssat	r0, #1, r1, ASR #8
	bx	lr
__ssat01A09
	ssat	r0, #1, r1, ASR #9
	bx	lr
__ssat01A10
	ssat	r0, #1, r1, ASR #10
	bx	lr
__ssat01A11
	ssat	r0, #1, r1, ASR #11
	bx	lr
__ssat01A12
	ssat	r0, #1, r1, ASR #12
	bx	lr
__ssat01A13
	ssat	r0, #1, r1, ASR #13
	bx	lr
__ssat01A14
	ssat	r0, #1, r1, ASR #14
	bx	lr
__ssat01A15
	ssat	r0, #1, r1, ASR #15
	bx	lr
__ssat01A16
	ssat	r0, #1, r1, ASR #16
	bx	lr
__ssat01A17
	ssat	r0, #1, r1, ASR #17
	bx	lr
__ssat01A18
	ssat	r0, #1, r1, ASR #18
	bx	lr
__ssat01A19
	ssat	r0, #1, r1, ASR #19
	bx	lr
__ssat01A20
	ssat	r0, #1, r1, ASR #20
	bx	lr
__ssat01A21
	ssat	r0, #1, r1, ASR #21
	bx	lr
__ssat01A22
	ssat	r0, #1, r1, ASR #22
	bx	lr
__ssat01A23
	ssat	r0, #1, r1, ASR #23
	bx	lr
__ssat01A24
	ssat	r0, #1, r1, ASR #24
	bx	lr
__ssat01A25
	ssat	r0, #1, r1, ASR #25
	bx	lr
__ssat01A26
	ssat	r0, #1, r1, ASR #26
	bx	lr
__ssat01A27
	ssat	r0, #1, r1, ASR #27
	bx	lr
__ssat01A28
	ssat	r0, #1, r1, ASR #28
	bx	lr
__ssat01A29
	ssat	r0, #1, r1, ASR #29
	bx	lr
__ssat01A30
	ssat	r0, #1, r1, ASR #30
	bx	lr
__ssat01A31
	ssat	r0, #1, r1, ASR #31
	bx	lr
__ssat01A32
	ssat	r0, #1, r1, ASR #32
	bx	lr


        END
