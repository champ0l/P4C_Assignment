section .data
msg1 : db "input : "        ;8bit
enter : db 0xa              ;8bit
x : db " x "                ;8bit
eq : db " = "               ;8bit
cnt : dq 0x1                ;64bit


section .bss
input resq 1
ten resq 1              ;10의 자리 8byte
one resq 1              ;1의 자리 8byte


section .text
        global _start
_start :
	mov rsi, msg1             ;rsi==0
	mov rdx, 0x08             ;rdx==8
	call print                ;input :
	call read

	mov rsi, input            ;rsi==input
	mov rdx, 0x01             ;rdx==1
	call print ; print input
	mov rsi, x                ;rsi=="x"
	mov rdx, 0x03             ;rdx==3
	call print ; print x

	add qword [cnt], 0x30     ;to chr (0x30 == '0') 
	mov rsi, cnt              ;rsi==cnt (첫 시도 cnt는 1)
	mov rdx, 0x01             ;rdx==1
	call print                ;cnt 출력(1~9)
	mov rsi, eq               ;rsi=="="
	mov rdx, 0x03             ;rdx==3
	call print                ;"=" 출력
	sub qword [cnt], 0x30     ;to int
	mov rax, qword [input]    ;rax==input값
	sub rax, 0x30             
	mul qword [cnt]
	mov rbx, 0xa              ;rbx==10
	div rbx                   ;rax을 10으로 나눠서 rax에 몫, rdx에 나머지 저장
	mov qword [ten], rax      ;몫은 10의 자리
	mov qword [one], rdx      ;나머지는 1의 자리
	add qword [ten], 0x30
	add qword [one], 0x30
	cmp rax, 0x00             ;rax가 0이면 zf=1
	je 24                     ;result is under 10 (직전 비교한 두 연산자가 같으면 다시 input받으러 이동)
	mov rsi, ten              ;rsi==ten
	mov rdx, 0x01             ;rdx==1
	call print
	mov rsi, one              ;rsi==one
	mov rdx, 0x01             ;rdx==1
	call print
	mov rsi, enter            ;rsi==10
	mov rdx, 0x01             ;rdx==1
	call print
	inc qword [cnt]           ;cnt=cnt+1
	cmp qword [cnt], 0x0a     ;cnt가 10이면 zf=1
	jl 0xFFFFFFFFFFFFFF07     ;10보다 작으면 loop
	call exit                 ;끝
	

read :
	xor rax, rax             ;rax==0
	xor rdi, rdi             ;rdi==0
	lea rsi,[input]          ;rsi에 입력값 대입
	mov rdx, 1               ;rdi==1
	syscall                  ;read(1, 0, 1) 
	ret                      ;탈출

print :                         ;self argument -> rsi에 저장된 값을 길이 rdx만큼 출력
	mov rax, 1              ;rax==1
	mov rdi, 1              ;rdi==1
	syscall                 ;write(1h, 0, 8h) -> 0에 저장된 길이 8h만큼 stdout -> "input: " (1)
	ret                     ;탈출

exit :
	mov rax, 60             ;rax==60(0x3c)
	xor rdi, rdi            ;rdi==0
	syscall                 ;exit(0)
	ret                     ;탈출
