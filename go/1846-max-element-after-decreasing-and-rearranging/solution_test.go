package solution

import "testing"

type Test struct {
	input []int
	want  int
}

func TestMaximumElement(t *testing.T) {
	tests := []Test{{[]int{73, 98, 9}, 3}}

	for _, tt := range tests {
		got := maximumElementAfterDecrementingAndRearranging(tt.input)
		if got != tt.want {
			t.Error("Test failed for input:", tt.input)
			t.Error("Expected:", tt.want)
			t.Error("Got:", got)
		}
	}
}
