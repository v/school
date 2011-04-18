// CS 415 Project #1 - block5.i
//
// Fibonacci numbers, using few registers (6)
// Takes as input the first two numbers in the series at memory 
// locations 1024 and 1028.  Thes would usually be 0 and 1.
//
// Example usage: sim -i 1024 0 1 < block5.i
//                sim -i 1024 3 5 < block5.i

	loadI	0	=> r0
	loadI	4	=> r1
	loadI	1024	=> r2
	load	r2	=> r3
	loadI	1028	=> r4
	load	r4	=> r5
	loadI	2000	=> r6
// f0
	store	r3	=> r6
// f1
	add	r3, r5	=> r7
	add	r5, r0	=> r8
	add	r7, r0	=> r9
	add	r6, r1	=> r10
	store	r8	=> r10
// f2
	add	r8, r9	=> r11
	add	r9, r0	=> r12
	add	r11, r0	=> r13
	add	r10, r1	=> r14
	store	r12	=> r14
// f3
	add	r12, r13	=> r15
	add	r13, r0	=> r16
	add	r15, r0	=> r17
	add	r14, r1	=> r18
	store	r16	=> r18
// f4
	add	r16, r17	=> r19
	add	r17, r0	=> r20
	add	r19, r0	=> r21
	add	r18, r1	=> r22
	store	r20	=> r22
// f5
	add	r20, r21	=> r23
	add	r21, r0	=> r24
	add	r23, r0	=> r25
	add	r22, r1	=> r26
	store	r24	=> r26
// f6
	add	r24, r25	=> r27
	add	r25, r0	=> r28
	add	r27, r0	=> r29
	add	r26, r1	=> r30
	store	r28	=> r30
// f7
	add	r28, r29	=> r31
	add	r29, r0	=> r32
	add	r31, r0	=> r33
	add	r30, r1	=> r34
	store	r32	=> r34
// f8
	add	r32, r33	=> r35
	add	r33, r0	=> r36
	add	r35, r0	=> r37
	add	r34, r1	=> r38
	store	r36	=> r38
// f9
	add	r36, r37	=> r39
	add	r37, r0	=> r40
	add	r39, r0	=> r41
	add	r38, r1	=> r42
	store	r40	=> r42
// f10
	add	r40, r41	=> r43
	add	r41, r0	=> r44
	add	r43, r0	=> r45
	add	r42, r1	=> r46
	store	r44	=> r46
// f11
	add	r46, r1	=> r47
	store	r45	=> r47

	output	2000
	output	2004
	output	2008
	output	2012
	output	2016
	output	2020
	output	2024
	output	2028
	output	2032
	output	2036
	output	2040
	output	2044
// end of block
