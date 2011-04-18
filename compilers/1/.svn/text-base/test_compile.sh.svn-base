usages=("sim -i 1024 1 1"
"sim "
"sim -i 1024 1 1" 
"sim -i 1024 1 1 "
"sim -i 1024 0 1 "
"sim -i 1024 0 1 "
"sim -i 4000 0 10 20 30 40 50 60 70 80 90 "
"sim -i 1024 0 1 "
"sim -i 1024 0 1 "
"sim -i 1024 0 1 2 "
"sim -i 1024 1 "
"sim -i 1024 0 1" )

files=( "block1.i"
"block2.i"
"block3.i"
"block4.i"
"block5.i"
"block6.i"
"report1.i"
"report2.i"
"report3.i"
"report4.i"
"report5.i"
"report6.i")

if [ $# -ne 1 ]; then

	index=0

	count=13

	echo "Count = $count"

	while [ "$index" -lt "$count" ]
	do    # List all the elements in the array.
	  echo "../ILOC_Simulator/${usages[$index]} < ${blocks[$index]}"
	  let "index = $index + 1"
	done

	if 'a' = 'a'; then
		echo "Hello"
	fi
	
	count=${#usages[@]}
	i=0
	while [ $i -lt $count ]; do
		echo "File: ${files[$i]} command: ../ILOC_Simulator/${usages[$i]} < blocks/${files[$i]}"
		result=`../ILOC_Simulator/${usages[$i]} < blocks/${files[$i]}`
		naive_result=`python parse_iloc.py blocks/${files[$i]} 0 $num > naive-output && ../ILOC_Simulator/${usages[$i]} < naive-output`
		smart_result=`python parse_iloc.py blocks/${files[$i]} 1 $num > smart-output && ../ILOC_Simulator/${usages[$i]} < smart-output`
		bottom_up_result=`python parse_iloc.py blocks/${files[$i]} 2 $num > bottomup-output && ../ILOC_Simulator/${usages[$i]} < bottomup-output`

		if [ `echo $result | sed '$d'` = `echo $naive_result | sed '$d'` ] && 
			[ `echo $result | sed '$d'` =`echo $smart_result | sed '$d'` ] && 
			[ `echo $bottom_up_result | sed '$d'` = `echo $smart_result | sed '$d'` ] ; then
			echo "Correct, naive, and smart are the same."
		else
			echo "Correct Output:"
			echo -e $result
			echo "Naive Output:"
			echo -e $naive_result
			echo "Smart Output:"
			echo -e $smart_result
			echo "Bottom Up Output:"
			echo -e $smart_result
		fi


		let i=i+1
		
	done
else
	echo 'Correct Output'
	correct_output=`../ILOC_Simulator/sim < $1`
	echo $correct_output
	echo 'Your Naive Output'
	naive_output=`python parse_iloc.py $1 0  > naive-output && ../ILOC_Simulator/sim < naive-output`
	echo $naive_output
	echo 'Your Smart Output'
	smart_output=`python parse_iloc.py $1 1  > smart-output && ../ILOC_Simulator/sim < smart-output`
	echo $smart_output
	echo 'Your Bottom Up Output'
	smart_output=`python parse_iloc.py $1 2  > bottomup-output && ../ILOC_Simulator/sim < bottomup-output`
	echo $smart_output

fi
