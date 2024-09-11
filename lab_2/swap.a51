// -- DO NOT CHANGE ANYTHING UNTIL THE **** LINE--//
ORG 0H
LJMP MAIN
ORG 100H
MAIN:
CALL XORSWAP
HERE: SJMP HERE
ORG 130H
// *****************
XORSWAP:
xrl a,60h         //using this method we don't have to use 2 registers. we can swap number with one accumulator only
xrl a,61h         // using the logic that a xor b xor a = b and vice versa
mov 60h,a
xrl a,61h
mov 61h,a
xrl a,60h
mov 60h,a
RET
END
