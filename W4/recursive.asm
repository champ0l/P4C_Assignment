section .bss
one resq 1

section	.text
   global _start       
	
_start:                 
   
    mov rbx, 10             ;10의 팩토리얼을 구할 것이다.
    call factorial          ;호출

    mov rbx, 0xa            ;rbx==10
    call again              
    pop rdx                 ;처음에 저장한 rdx값 pop(repeat함수와 동일)
    add rdx, 0x30           
    mov qword [one], rdx    
    mov rsi, one
    call print          
    call exit               ;끝
    
again :
    mov rdx, 0              ;rdx==0
    div rbx                 ;rax을 10으로 나눠서 rax에 몫, rdx에 나머지 저장
    pop rcx                 ;again을 호출하면서 stack에 쌓인 주소값을 잠시 pop
    push rdx                ;역순으로 꺼내야 하므로 일단 rdx를 push
    push rcx                ;잠시 꺼냈던 주소값을 다시 push
    cmp rax, 0              ;rax를 0과 비교
    jg repeat               ;rax>0 이면 repeat로 jmp
    ret                     ;rax=0이면 return

repeat :
    call again              ;직전 함수 재호출
    pop rdx                 ;차곡차곡 쌓았던 rdx값을 pop
    add rdx, 0x30           ;rdx에 0x30('0')을 add(아스키코드)
    mov qword [one], rdx    ;rdx를 one에 저장
    mov rsi, one            ;one을 rsi에 저장
    call print            ;rsi에 저장된 값 출력
    ret                     ;repeat함수 반복하다가 마지막에 _start로 ret

print :
    mov rdx, 1
    mov rax, 1
    mov rdi, 1
    syscall
    ret

factorial:
    cmp rbx, 1              ;rbx와 1을 비교
    jg calculation          ;rbx가 1보다 크면 calculation으로 jmp
    mov rax, 1              ;rbx가 1보다 작거나 같으면 rax==1
    ret
	
calculation:
    dec rbx                 ;rbx-=1
    call factorial          
    inc rbx
    mul rbx                 ;rax*rbx의 값을 rax에 저장
    ret

exit :
	mov rax, 60             ;rax==60(0x3c)
	xor rdi, rdi            ;rdi==0
	syscall                 ;exit(0)
	ret                     ;탈출
