ORG 0H
LJMP MAIN
ORG 100H
MAIN:
    CALL TAKE_INP
	CALL QUANT_ENC
	CALL LED_DISP
HERE: SJMP HERE
ORG 130H

TAKE_INP:
	mov r0,#01h
	mov r1,#50h
input:
	mov a,r0
	swap a
	mov p1,a
	acall delay_4s
	mov p1,#0Fh
	mov b,p1

	inc r0
	mov a,r0
	swap a
	mov p1,a
	acall delay_4s
	mov p1,#0Fh
	mov a,p1
	swap a

	add a,b
	mov @r1,a

	inc r0
	inc r1
	cjne r0,#09h,input
ret

QUANT_ENC:
    mov r1,#50h
start:
	mov b,@r1
first:
	mov a,#191
	subb a,b
	jnc second
	mov @r1,#08h
    jmp next
second:
	mov a,#127
	subb a,b
	jnc third
	mov @r1,#04h
    jmp next
third:
	mov a,#63
	subb a,b
	jnc last
	mov @r1,#02h
	jmp next
last:
	mov @r1,#01h
next:
	inc r1
	cjne r1,#54h,start
ret

LED_DISP:
	mov p1,#00h
initial:
	mov r1,#50h
	dis_start:
	mov a,@r1

	mov p1,a
	inc r1
	acall delay_4s
	cjne r1,#54h,dis_start
	acall initial
RET

DELAY_4s:
	push 00h
	mov r0,#100
	h4: acall delay_40ms
	djnz r0,h4
	pop 00h
RET
delay_40ms:
	push 00h
	mov r0, #160
	h2: acall delay_250us
	djnz r0, h2
	pop 00h
ret
delay_250us:
	push 00h                //2cycles
	mov r0, #244            //1cycle
	h1: djnz r0, h1         //2cycles
	pop 00h                 //2cycles
ret 

END