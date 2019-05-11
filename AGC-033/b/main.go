package main

import (
	"fmt"
)

func main() {
	var h, w, n, sr, sc int
	var s, t string
	fmt.Scan(&h)
	fmt.Scan(&w)
	fmt.Scan(&n)
	fmt.Scan(&sr)
	fmt.Scan(&sc)
	fmt.Scan(&s)
	fmt.Scan(&t)

	dpxmin := make([]int, n+1)
	dpxmax := make([]int, n+1)
	dpymin := make([]int, n+1)
	dpymax := make([]int, n+1)
	dpxmin[n] = 1
	dpxmax[n] = w
	dpymin[n] = 1
	dpymax[n] = h

	for i := 1; i <= n; i++ {
		dpxmin[n-i] = dpxmin[n-i+1]
		dpxmax[n-i] = dpxmax[n-i+1]
		dpymin[n-i] = dpymin[n-i+1]
		dpymax[n-i] = dpymax[n-i+1]

		switch t[n-i] {
		case 'L':
			if dpxmax[n-i+1] < w {
				dpxmax[n-i]++
			}
		case 'R':
			if dpxmin[n-i+1] > 1 {
				dpxmin[n-i]--
			}
		case 'U':
			if dpymax[n-i+1] < h {
				dpymax[n-i]++
			}
		case 'D':
			if dpymin[n-i+1] > 1 {
				dpymin[n-i]--
			}
		}

		switch s[n-i] {
		case 'L':
			dpxmin[n-i]++
		case 'R':
			dpxmax[n-i]--
		case 'U':
			dpymin[n-i]++
		case 'D':
			dpymax[n-i]--
		}

		if dpxmin[n-i] > dpxmax[n-i] || dpymin[n-i] > dpymax[n-i] {
			fmt.Println("NO")
			return
		}
	}

	if dpxmin[0] <= sc && sc <= dpxmax[0] && dpymin[0] <= sr && sr <= dpymax[0] {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
