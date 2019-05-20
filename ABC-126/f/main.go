package main

import (
	"fmt"
	"math"
	"strconv"
	"strings"
)

func main() {
	var m, k int
	fmt.Scan(&m)
	fmt.Scan(&k)

	n := int(math.Pow(2.0, float64(m+1)))
	max := int(math.Pow(2.0, float64(m))) - 1
	if max == 0 {
		if k == 0 {
			fmt.Println("0 0")
		} else {
			fmt.Println("-1")
		}
	} else if max == 1 {
		if k == 0 {
			fmt.Println("0 1 1 0")
		} else {
			fmt.Println("-1")
		}
	} else {
		if k <= max {
			ret := make([]string, n)
			if k == 0 {
				for i := 0; i <= max; i++ {
					ret[i*2] = strconv.Itoa(i)
					ret[i*2+1] = strconv.Itoa(i)
				}
			} else {
				ret[0] = "0"
				ret[1] = strconv.Itoa(k)
				ret[2] = "0"
				index := 3
				for i := 1; i <= max; i++ {
					if i == k {
						continue
					}
					ret[index] = strconv.Itoa(i)
					index++
				}
				ret[index] = strconv.Itoa(k)
				index++
				for i := max; i > 0; i-- {
					if i == k {
						continue
					}
					ret[index] = strconv.Itoa(i)
					index++
				}
			}
			r := strings.Join(ret, " ")
			fmt.Println(r)
		} else {
			fmt.Println("-1")
		}
	}
}
