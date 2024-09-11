// -- DO NOT CHANGE ANYTHING UNTIL THE **** LINE--//
ORG 0H
LJMP MAIN
ORG 100H
MAIN:
CALL MAX
HERE: SJMP HERE
ORG 130H
// *****************
MAX:
mov r0,#60h       //store initial address in r0
mov r1,#07h       //store counter in r1
mov 70h,@r0       //take first value of array as largest number

loop:
clr c             //clear the carry everytime loop runs
mov a,70h         //store largest no in accumulator
inc r0            //increment memory address
subb a,@r0        //subtract current and next value 
jnc move          //check for carry 
mov 70h,@r0       //if there is carry then move this array element to 70h
move:
djnz r1,loop      //loop
RET
END