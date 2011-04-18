// CS 415, Project 1, block "report5.i"
//
// a little work with powers of two
//
//** Usage sim -i 1024 1 < report5.i

	loadI	1024	=> r1
	load	r1	=> r2
	loadI	4	=> r54
	loadI	1024	=> r50
// generate 1 to 2^16
	lshift	r2, r2	=> r55
	lshift	r55, r2	=> r3
	lshift	r3, r2	=> r4
	lshift	r4, r2	=> r5
	lshift	r5, r2	=> r6
	lshift	r6, r2	=> r7
	lshift	r7, r2	=> r8
	lshift	r8, r2	=> r9
	lshift	r9, r2	=> r10
	lshift	r10, r2	=> r11
	lshift	r11, r2	=> r12
	lshift	r12, r2	=> r13
	lshift	r13, r2	=> r14
	lshift	r14, r2	=> r15
	lshift	r15, r2	=> r16
	lshift	r16, r2	=> r17
// now sum them  spending registers to
// save adds
	add	r2, r55	=> r20
	add	r3, r4	=> r21
	add	r5, r6	=> r22
	add	r7, r8	=> r23
	add	r9, r10	=> r24
	add	r11, r12	=> r25
	add	r13, r14	=> r26
	add	r15, r16	=> r27
	add	r20, r21	=> r30
	add	r22, r23	=> r31
	add	r24, r25	=> r32
	add	r26, r27	=> r33
	add	r30, r31	=> r34
	add	r32, r33	=> r35
	add	r35, r34	=> r36
	add	r36, r17	=> r37
// whew. Now  store the results where we can
// check them for correctness
	store	r37	=> r50
//
// sum i=1 to 16 (2^^i) should be 2^17 -1
//
	add	r5, r2	=> r40
	lshift	r2, r40	=> r41
	sub	r41, r2	=> r42
	add	r50, r54	=> r51
	store	r42	=> r51
//
	output	1024
	output	1028
//
