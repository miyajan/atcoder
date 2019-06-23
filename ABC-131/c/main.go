package main

import (
	"fmt"
)

func main() {
	var a, b, c, d int64
	fmt.Scan(&a)
	fmt.Scan(&b)
	fmt.Scan(&c)
	fmt.Scan(&d)

	dividableC := dividable(a, b, c)
	dividableD := dividable(a, b, d)
	cd := lcm(c, d)
	dividableCD := dividable(a, b, cd)

	ret := b - a + 1 - dividableC - dividableD + dividableCD
	fmt.Println(ret)
}

func dividable(a int64, b int64, x int64) int64 {
	d := (b / x) - (a / x)
	if a%x == 0 {
		d++
	}
	return d
}

func gcd(c int64, d int64) int64 {
	for c%d != 0 {
		tmp := d
		d = c % d
		c = tmp

	}
	return d
}

func lcm(c int64, d int64) int64 {
	return c * d / gcd(c, d)
}
