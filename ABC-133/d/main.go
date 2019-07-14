package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func main() {
	var n int
	fmt.Scan(&n)

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Split(bufio.ScanWords)

	a := make([]int, n)
	oddSum := make([]int, n)
	evenSum := make([]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		a[i], _ = strconv.Atoi(scanner.Text())
		if i == 0 {
			oddSum[i] = 0
			evenSum[i] = a[i]
		} else if i%2 == 0 {
			oddSum[i] = oddSum[i-1]
			evenSum[i] = evenSum[i-1] + a[i]
		} else {
			oddSum[i] = oddSum[i-1] + a[i]
			evenSum[i] = evenSum[i-1]
		}
	}

	for i := 0; i < n; i++ {
		if i > 0 {
			fmt.Print(" ")
		}
		var b int
		if i == 0 {
			b = evenSum[n-1] - oddSum[n-1]
		} else if i%2 == 0 {
			b = (evenSum[n-1] - evenSum[i-1]) + (oddSum[i-1]) - ((oddSum[n-1] - oddSum[i-1]) + evenSum[i-1])
		} else {
			b = (oddSum[n-1] - oddSum[i-1]) + (evenSum[i-1]) - ((evenSum[n-1] - evenSum[i-1]) + oddSum[i-1])
		}
		fmt.Print(b)
	}

	fmt.Println("")
}
