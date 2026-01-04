;
; Created by IRVM
; Owner: Codeleaded
;
bits 64

global _start


main:
	mov	rbx,68
	mov	rax,rbx
	ret	

_start:
	call	main
	mov	rdi,rax
	mov	rax,60
	syscall	
