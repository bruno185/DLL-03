
.data
mydata	QWORD  0

.code
_DllMainCRTStartup proc h:QWORD, r:DWORD, u:QWORD		; nécessaire pas défaut pour le CRT (C runtime)
	;mov rax, 1
	mov mydata,098765h		; init variable locale (au lancement de l'application)
	ret
_DllMainCRTStartup endp

mafonction proc 
	;mov rax,rcx
	mov rax,mydata			; renvoie la variable locale
	ret  
mafonction endp


DoMul proc
	mov eax,ecx
	imul eax,edx
	ret
DoMul endp


end