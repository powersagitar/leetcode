package solution

import "math"

func minimumDistance(nums []int) int {
	occurrences := make(map[int][]int)

	for idx, num := range nums {
		occurrences[num] = append(occurrences[num], idx)
	}

	doesNotExist := true

	minDistance := math.MaxInt

	for _, indices := range occurrences {
		if len(indices) < 3 {
			continue
		}

		doesNotExist = false

		for i := range len(indices) - 2 {
			j, k := i+1, i+2
			distance := calcDistance(indices[i], indices[j], indices[k])
			minDistance = min(minDistance, distance)
		}
	}

	if doesNotExist {
		return -1
	} else {
		return minDistance
	}
}

func min(a int, b int) int {
	if a < b {
		return a
	} else {
		return b
	}
}

func abs(x int) int {
	if x < 0 {
		return -x
	} else {
		return x
	}
}

func calcDistance(i int, j int, k int) int {
	return abs(i-j) + abs(j-k) + abs(k-i)
}
