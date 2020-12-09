section .text
	global _ft_strdup
	extern _malloc
	extern _ft_strlen
	extern _ft_strcpy

_ft_strdup:
	push	rdi			; Save rdi(the source string) in stack
	call	_ft_strlen	; Get the length of the source string
	inc		rax			; Add 1 to the length for null termination
	mov		rdi, rax	; Put the length of the source string + 1 into rdi to malloc that amount of bytes
	call	_malloc
	cmp		rax, 0
	jl 		err
	mov		rdi, rax	; Put the allocated memory address into rdi
	pop 	rsi			; Put rdi into rsi ('cause it's going to be the source string of ft_strcpy)
	call	_ft_strcpy	; Copy the source string to the allocated memory
	ret					; Return (return value is rax, the newly copied string)

err:
	or rax, -1
	ret
