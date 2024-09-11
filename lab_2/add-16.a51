ORG 0H
LJMP MAIN
ORG 100H
MAIN:
CALL ADD16
HERE: SJMP HERE
ORG 130H
// *****************
ADD16:
CLR c
mov 74h,#00h            //clear 74h everytime the function calls 
mov a,71h              
add a,73h               //adding first 8 bit of both the numbers
mov 76h,a
mov a,70h
addc a,72h               //adding second 8 bits with carry 
mov 75h,a                 
jnc skip                   
inc 74h                 //if there is carry then increase the value of 74h to 1
skip:
RET

END