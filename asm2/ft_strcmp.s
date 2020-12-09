section .text
	global _ft_strcmp
	extern _ft_strlen

_ft_strcmp:
	push	rdi
	call	_ft_strlen
	lea		rcx, [rax + 1]
	pop		rdi
	cld
	repe	cmpsb
	movzx	rax, BYTE [rdi - 1]
	movzx	rcx, BYTE [rsi - 1]
	sub		rax, rcx
	ret
