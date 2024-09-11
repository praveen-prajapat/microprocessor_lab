ORG 0H
LJMP MAIN
ORG 100H
MAIN:
mov 50h,#00h  
CALL MAC
HERE: SJMP HERE
ORG 130H

MAC:
mov a,70h
mov b,73h
mul ab
mov 70h,a
mov 73h,b

mov a,71h
mov b,74h
mul ab
mov 71h,a
mov 74h,b

lcall add16

mov a,72h
mov b,75h
mul ab
mov 70h,a
mov 73h,b

mov 71h,52h
mov 74h,51h
lcall add16

RET

ADD16:
CLR c          //clear 74h everytime the function calls 
mov a,70h              
add a,71h               //adding first 8 bit of both the numbers
mov 52h,a
mov a,73h
addc a,74h               //adding second 8 bits with carry 
mov 51h,a                 
jnc skip                   
inc 50h                 //if there is carry then increase the value of 74h to 1
skip:
RET

END