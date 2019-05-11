package main

import (
	"bufio"
	"fmt"
	"os"
)

type point struct {
	h    int
	w    int
	step int
}

func main() {
	var h, w int
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	fmt.Sscanf(scanner.Text(), "%d %d", &h, &w)

	queues := make([]point, 0, h*w)
	blackPoints := make(map[int]map[int]bool)
	white := h * w
	for i := 0; i < h; i++ {
		scanner.Scan()
		s := scanner.Text()
		blackPoints[i] = make(map[int]bool)
		for j, c := range s {
			if c == '#' {
				if _, ok := blackPoints[i]; !ok {
					blackPoints[i] = make(map[int]bool)
				}
				blackPoints[i][j] = true
				queues = append(queues, point{
					h:    i,
					w:    j,
					step: 0,
				})
				white--
			}
		}
	}

	if white == 0 {
		fmt.Println(0)
		return
	}

	var cur point
	for white > 0 {
		cur, queues = queues[0], queues[1:]
		i, j, step := cur.h, cur.w, cur.step

		if i > 0 && !blackPoints[i-1][j] {
			blackPoints[i-1][j] = true
			queues = append(queues, point{
				h:    i - 1,
				w:    j,
				step: step + 1,
			})
			white--
		}
		if i < h-1 && !blackPoints[i+1][j] {
			blackPoints[i+1][j] = true
			queues = append(queues, point{
				h:    i + 1,
				w:    j,
				step: step + 1,
			})
			white--
		}
		if j > 0 && !blackPoints[i][j-1] {
			blackPoints[i][j-1] = true
			queues = append(queues, point{
				h:    i,
				w:    j - 1,
				step: step + 1,
			})
			white--
		}
		if j < w-1 && !blackPoints[i][j+1] {
			blackPoints[i][j+1] = true
			queues = append(queues, point{
				h:    i,
				w:    j + 1,
				step: step + 1,
			})
			white--
		}
	}

	fmt.Println(cur.step + 1)
}
