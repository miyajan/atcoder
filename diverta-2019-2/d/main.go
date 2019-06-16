package main

import (
	"fmt"
)

func main() {
	var n, ga, sa, ba, gb, sb, bb int
	fmt.Scan(&n)
	fmt.Scan(&ga)
	fmt.Scan(&sa)
	fmt.Scan(&ba)
	fmt.Scan(&gb)
	fmt.Scan(&sb)
	fmt.Scan(&bb)

	dp1 := make([]int, n+1)
	for i := 0; i <= n; i++ {
		max := i
		if i >= ga {
			x := gb + dp1[i-ga]
			if x > max {
				max = x
			}
		}
		if i >= sa {
			x := sb + dp1[i-sa]
			if x > max {
				max = x
			}
		}
		if i >= ba {
			x := bb + dp1[i-ba]
			if x > max {
				max = x
			}
		}
		dp1[i] = max
	}
	m := dp1[n]

	dp2 := make([]int, m+1)
	for i := 0; i <= m; i++ {
		max := i
		if i >= gb {
			x := ga + dp2[i-gb]
			if x > max {
				max = x
			}
		}
		if i >= sb {
			x := sa + dp2[i-sb]
			if x > max {
				max = x
			}
		}
		if i >= bb {
			x := ba + dp2[i-bb]
			if x > max {
				max = x
			}
		}
		dp2[i] = max
	}

	fmt.Println(dp2[m])
}
