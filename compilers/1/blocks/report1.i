// CS 415, Project 1, block "report1.i"
//
// ** Usage: sim -i 4000 0 10 20 30 40 50 60 70 80 90 < report1.i

	loadI	4000	=> r0
	loadI	4	=> r1
	loadI	1	=> r25
//
	load	r0	=> r10
	add	r0, r1	=> r26
	load	r26	=> r11
	add	r26, r1	=> r27
	load	r27	=> r12
	add	r27, r1	=> r28
	load	r28	=> r13
	add	r28, r1	=> r29
	load	r29	=> r14
	add	r29, r1	=> r30
	load	r30	=> r15
	add	r30, r1	=> r31
	load	r31	=> r16
	add	r31, r1	=> r32
	load	r32	=> r17
	add	r32, r1	=> r33
	load	r33	=> r18
	add	r33, r1	=> r34
	load	r34	=> r19
	add	r34, r1	=> r35
//
	loadI	0	=> r2
//
	add	r10, r11	=> r36
	mult	r25, r11	=> r3
	sub	r19, r10	=> r4
//
	add	r36, r12	=> r37
	mult	r3, r12	=> r38
	add	r4, r18	=> r39
//
	add	r37, r13	=> r40
	mult	r38, r13	=> r41
	sub	r39, r17	=> r42
//
	add	r40, r14	=> r43
	mult	r41, r14	=> r44
	add	r42, r16	=> r45
//
	add	r43, r15	=> r46
	mult	r44, r15	=> r47
	sub	r45, r15	=> r48
//
	add	r46, r16	=> r49
	mult	r47, r16	=> r50
	add	r45, r14	=> r51
//
	loadI	16	=> r20
	rshift	r50, r20	=> r52
//
	add	r49, r17	=> r53
	mult	r52, r17	=> r54
	sub	r51, r13	=> r55
//
	add	r53, r18	=> r56
	mult	r54, r18	=> r57
	add	r55, r12	=> r58
//
	add	r56, r19	=> r59
	mult	r57, r19	=> r60
	sub	r58, r11	=> r61
//
	loadI	1024	=> r62
	store	r59	=> r62
	loadI	1028	=> r21
	store	r60	=> r21
	loadI	1032	=> r22
	store	r61	=> r22
//
	output	1024
	output	1028
	output	1032
//






