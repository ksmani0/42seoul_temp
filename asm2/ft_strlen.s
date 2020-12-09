section .text
	global _ft_strlen

_ft_strlen:
	xor		rax, rax	; Set all the bits of rax to 0
	or		rcx, -1		; Set all the bits of rcx to 1 (max value)
	cld					; DF = 0
	repne	scasb		; Compare al, which is 0, with each byte of rdi until rcx becomes 0 or the value of al is found
	sub		rax, rcx	; rcx = -len -2. Therefore, rax = 0 - (-len -2) = len + 2
	sub		rax, 2		; rax = len + 2 - 2 = len
	ret					; return (return value is rax, which is the len of the string)
