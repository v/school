// CS 415, Project 1, block "report2.i"
//
// a simple summation of some initialized data
//
// **** Usage: sim -i 1024 0 1 <report2.i

	loadI	1024	=> r0
	loadI	1028	=> r1
	load	r0	=> r2
	load	r1	=> r3
	loadI	4	=> r25
	loadI	1024	=> r10
	store	r2	=> r10
	add	r2, r3	=> r26
	add	r10, r25	=> r27
	store	r26	=> r27
	add	r26, r3	=> r28
	add	r27, r25	=> r29
	store	r28	=> r29
	add	r28, r3	=> r30
	add	r29, r25	=> r31
	store	r30	=> r31
	add	r30, r3	=> r32
	add	r31, r25	=> r33
	store	r32	=> r33
	add	r32, r3	=> r34
	add	r33, r25	=> r35
	store	r34	=> r35
	add	r34, r3	=> r36
	add	r35, r25	=> r37
	store	r36	=> r37
	add	r36, r3	=> r38
	add	r37, r25	=> r39
	store	r38	=> r39
	add	r38, r3	=> r40
	add	r39, r25	=> r41
	store	r40	=> r41
	add	r40, r3	=> r42
	add	r41, r25	=> r43
	store	r42	=> r43
	add	r42, r3	=> r44
	add	r43, r25	=> r45
	store	r44	=> r45
//
	loadI	1024	=> r46
	load	r46	=> r47
	add	r46, r25	=> r48
	load	r48	=> r4
	add	r48, r25	=> r49
	load	r49	=> r5
	add	r47, r4	=> r20
	load	r49	=> r6
	add	r6, r6	=> r21
	mult	r20, r21	=> r22
	loadI	2048	=> r7
	store	r22	=> r7
	output	2048
//
