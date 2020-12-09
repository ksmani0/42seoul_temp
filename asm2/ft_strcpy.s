section .text
	global _ft_strcpy
	extern _ft_strlen

_ft_strcpy:
	push	rdi			; Push rdi in stack
	mov		rdi, rsi	; Put the source string's first address into rdi
	call	_ft_strlen	; Call _ft_strlen to get the length of rdi(currently source address)
	mov		rcx, rax	; Put rax into rcx. rax here is the return value of _ft_strlen. rcx will be used in rep later
	pop		rdi			; Retrieve rdi back
	mov		rax, rdi	; Put the dest string's first address in rax to return it later
	cld					; Set DF to 0. This sets rep to incrementing rep
	rep		movsb		; Copy the source sting to the dest string for rcx times byte after byte
	mov		BYTE [rdi], 0	; The dest string should be null terminated
	ret					; return (return value is rax, the dest string's first address)
