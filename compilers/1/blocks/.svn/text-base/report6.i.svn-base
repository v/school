// CS 415, Project 1, block "report6.i"
//
// example 5, worked with fewer registers 
//
// Usage sim -i 1024 0 1 < report6.i

	loadI	1024	=> r0
	loadI	1028	=> r1
	load	r0	=> r2
	load	r1	=> r3
	loadI	4	=> r54
	loadI	1024	=> r50
// generate 1 to 2^16
	add	r2, r3	=> r55
	lshift	r3, r3	=> r56
	add	r55, r56	=> r57
	lshift	r56, r3	=> r58
	add	r57, r58	=> r59
	lshift	r58, r3	=> r60
	add	r59, r60	=> r61
	lshift	r60, r3	=> r62
	add	r61, r62	=> r63
	lshift	r62, r3	=> r64
	add	r63, r64	=> r65
	lshift	r64, r3	=> r66
	add	r65, r66	=> r67
	lshift	r66, r3	=> r68
	add	r67, r68	=> r69
	lshift	r68, r3	=> r70
	add	r69, r70	=> r71
	lshift	r70, r3	=> r72
	add	r71, r72	=> r73
	lshift	r72, r3	=> r74
	add	r73, r74	=> r75
	lshift	r74, r3	=> r76
	add	r75, r76	=> r77
	lshift	r76, r3	=> r78
	add	r77, r78	=> r79
	lshift	r78, r3	=> r80
	add	r79, r80	=> r81
	lshift	r80, r3	=> r82
	add	r81, r82	=> r83
	lshift	r82, r3	=> r84
	add	r83, r84	=> r85
	lshift	r84, r3	=> r86
	add	r85, r86	=> r87
// whew. Now, store the results where we can
// check them for correctness
	store	r87	=> r50
//
// sum i=0 to 16 (2^^i) should be 2^17 -1
//
// since we didn't save the results, this
// part is a little harder, but still easy
	loadI	17	=> r17
	lshift	r3, r17	=> r18
	sub	r18, r3	=> r19
	add	r50, r54	=> r51
	store	r19	=> r51
//
	output	1024
	output	1028
//









