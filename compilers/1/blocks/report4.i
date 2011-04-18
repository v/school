// CS 415, Project 1, block "report4.i"
//
//
// ** Usage sim -i 1024 0 1 2 <report4.i
	loadI	1024	=> r0
	loadI	1028	=> r1
	loadI	1032	=> r3
	load	r0	=> r4
	load	r1	=> r5
	load	r3	=> r6
	loadI	40	=> r2
	loadI	1024	=> r10
//
	store	r6	=> r10
	add	r4, r4	=> r11
	add	r4, r5	=> r12
//
	add	r11, r12	=> r13
	add	r12, r5	=> r14
	add	r13, r14	=> r15
	add	r14, r5	=> r16
	add	r15, r16	=> r17
	add	r16, r5	=> r18
	add	r17, r18	=> r19
	add	r18, r5	=> r20
	add	r19, r20	=> r21
	add	r20, r5	=> r22
	add	r21, r22	=> r23
	add	r22, r5	=> r24
	add	r23, r24	=> r25
	add	r24, r5	=> r26
	add	r25, r26	=> r27
	add	r26, r5	=> r28
	add	r27, r28	=> r29
	add	r28, r5	=> r30
	add	r29, r30	=> r31
	load	r10	=> r32
	mult	r31, r32	=> r33
	add	r10, r2	=> r34
	store	r33	=> r34
	output	1024
	output	1064
//










