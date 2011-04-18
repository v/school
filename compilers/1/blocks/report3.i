// CS 415, Project 1, block "report3.i"
//
// Fibonacci numbers, using a heap of registers (25)
//
// ** Usage sim -i 1024 0 1 < report3.i

	loadI	1024	=> r2
	loadI	1028	=> r3
	loadI	0	=> r0
	loadI	4	=> r1
	load	r2	=> r4
	load	r3	=> r5

	loadI	2000	=> r20
// f1
	add	r4, r5	=> r21
// f2
	add	r21, r4	=> r22
// f3
	add	r22, r21	=> r6
// f4
	add	r6, r22	=> r7
// f5
	add	r7, r6	=> r8
// f6
	add	r8, r7	=> r9
// f7
	add	r9, r8	=> r10
// f8
	add	r10, r9	=> r11
// f9
	add	r11, r10	=> r12
// f10
	add	r12, r11	=> r13
// 
	store	r4	=> r20
	add	r20, r1	=> r23
	store	r21	=> r23
	add	r23, r1	=> r24
	store	r22	=> r24
	add	r24, r1	=> r25
	store	r6	=> r25
	add	r25, r1	=> r26
	store	r7	=> r26
	add	r26, r1	=> r27
	store	r8	=> r27
	add	r27, r1	=> r28
	store	r9	=> r28
	add	r28, r1	=> r29
	store	r10	=> r29
	add	r29, r1	=> r30
	store	r11	=> r30
	add	r30, r1	=> r31
	store	r12	=> r31
	add	r31, r1	=> r32
	store	r13	=> r32
//
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
// end of block


