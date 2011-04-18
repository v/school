//
//   Simple example program 
//
// Assign STATIC_AREA_ADDRESS to register "r0"
         loadI 1024     => r0
// Store value 6 into variable a with @a = 0;
         loadI 1 => r1  // true
         storeAI r1 => r0, 0 
// Store value 10 into variable b with @b = 4;
         loadI 1 => r2 // false
         storeAI r2 => r0, 4
// Compute a + b 
         loadAI r0, 0 => r3
         loadAI r0, 4 => r4
         and  r3, r4 => r5
         or  r3, r4 => r6
         xor  r3, r4 => r7
// Print the result using the fixed memory address 1020
         loadI 1020 => r8
         store r5 => r8
         output 1020
         store r6 => r8
         output 1020
         store r7 => r8
         output 1020
