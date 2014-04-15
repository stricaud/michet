mov eax, 1 			; exit syscall
mov ebx, 42			; Return a code of zero
int 80H				; Make the syscall to terminate to program
