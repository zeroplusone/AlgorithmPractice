/******************
Judge   : POJ
Problem : 2112-Optimal Milking
Course  : Course11
discribe:  find an assignment for each cow to some milking machine so that the distance the furthest-walking cow travels is minimized
Input   :
			2 3 2		//K(#machine~30) C(#cow~200) M(#max cow in the station~15)
			0 3 2 1 1   //dis(MAX:200   0=disconnect)
			3 0 3 2 0
			2 3 0 1 0
			1 2 1 0 2
			1 0 0 2 0
Output  :
			2	// minimum possible total distance for the furthest walking cow.
Solve   : maximun flow
*******************/
