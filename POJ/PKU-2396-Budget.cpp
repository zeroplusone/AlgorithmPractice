/******************
Judge   : POJ
Problem : 2396-Budget
Course  : Course11
discribe: find an assignment of cows to barns such that no barn's capacity is exceeded and the size of the range
Input   :
			2	//case

			2 3 //matrix size m*n
			8 10 	//row sum
			5 6 7 	//col sum
			4 		//restriction num
			0 2 > 2 	//restriction
			2 1 = 3
			2 3 > 2
			2 3 < 5

			2 2
			4 5
			6 7
			1
			1 1 > 10
Output  :
			2 3 3
			3 3 4

			IMPOSSIBLE
Solve   : maximun flow +binary search
*****************************/
