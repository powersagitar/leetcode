package solution

import "testing"

type TestCase struct {
	input []int
	want  int
}

func TestMinimumDistance(t *testing.T) {
	tests := []TestCase{{[]int{1, 2, 1, 1, 3}, 6}}

	for _, tt := range tests {
		got := minimumDistance(tt.input)
		if got != tt.want {
			t.Error("Assertion failed for:", tt.input)
			t.Error("Got:", got)
			t.Error("Expected:", tt.want)
		}
	}
}
