fn main() {}

#[allow(dead_code)]
fn plus_one(mut digits: Vec<i32>) -> Vec<i32> {
    let len = digits.len();
    digits[len - 1] += 1;

    for i in (1..digits.len()).rev() {
        if digits[i] > 9 {
            digits[i] = 0;
            digits[i - 1] += 1;
        }
    }

    if digits[0] > 9 {
        digits[0] = 0;
        digits.insert(0, 1);
    }

    digits
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test() {
        assert_eq!(plus_one(vec![9]), vec![1, 0]);
        assert_eq!(plus_one(vec![1, 9]), vec![2, 0]);
        assert_eq!(plus_one(vec![9, 9]), vec![1, 0, 0]);
    }
}
