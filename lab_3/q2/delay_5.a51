ORG 0H
LJMP MAIN
ORG 100H
MAIN:
setb p1.4
aCALL DELAY_5s
clr p1.4
HERE: SJMP HERE
ORG 130H

DELAY_5s:
push 00h
mov r0,#50
h4: acall delay_100ms
djnz r0,h4
pop 00h
RET

delay_100ms:
push 00h
mov r0,#100
h3: acall delay_1ms
djnz r0,h3
pop 00h
ret

delay_1ms:
push 00h
mov r0, #4
h2: acall delay_250us
djnz r0, h2
pop 00h
ret

delay_250us:
push 00h                //2cycles
mov r0, #244            //1cycle
h1: djnz r0, h1         //2cycles
pop 00h                 //2cycles
ret                     //2cycles

END















proceed:
		adjoint:
		mov a,64h
		mov 50h,a
		mov a,68h
		mov 51h,a
		mov a,65h
		mov 52h,a
		mov a,67h
		mov 53h,a
		acall det2x2
		mov a,51h
		mov 70h,a
		
		mov a,65h
		mov 50h,a
		mov a,66h
		mov 51h,a
		mov a,63h
		mov 52h,a
		mov a,68h
		mov 53h,a
		acall det2x2
		mov a,51h
		mov 71h,a
		
		mov a,63h
		mov 50h,a
		mov a,67h
		mov 51h,a
		mov a,64h
		mov 52h,a
		mov a,66h
		mov 53h,a
		acall det2x2
		mov a,51h
		mov 72h,a
		
		mov a,62h
		mov 50h,a
		mov a,67h
		mov 51h,a
		mov a,61h
		mov 52h,a
		mov a,68h
		mov 53h,a
		acall det2x2
		mov a,51h
		mov 73h,a
		
		mov a,60h
		mov 50h,a
		mov a,68h
		mov 51h,a
		mov a,62h
		mov 52h,a
		mov a,66h
		mov 53h,a
		acall det2x2
		mov a,51h
		mov 74h,a
		
		mov a,61h
		mov 50h,a
		mov a,66h
		mov 51h,a
		mov a,60h
		mov 52h,a
		mov a,67h
		mov 53h,a
		acall det2x2
		mov a,51h
		mov 75,a
		
		mov a,61h
		mov 50h,a
		mov a,65h
		mov 51h,a
		mov a,62h
		mov 52h,a
		mov a,64h
		mov 53h,a
		acall det2x2
		mov a,51h
		mov 76h,a
		
		mov a,63h
		mov 50h,a
		mov a,62h
		mov 51h,a
		mov a,65h
		mov 52h,a
		mov a,60h
		mov 53h,a
		acall det2x2
		mov a,51h
		mov 77h,a
		
		mov a,60h
		mov 50h,a
		mov a,64h
		mov 51h,a
		mov a,61h
		mov 52h,a
		mov a,63h
		mov 53h,a
		acall det2x2
		mov a,51h
		mov 78h,a
	