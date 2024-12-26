use std::collections::HashMap;

fn main() {}

#[allow(dead_code)]
fn majority_element(nums: Vec<i32>) -> i32 {
    let mut frequencies: HashMap<&i32, usize> = HashMap::new();

    for x in nums.iter() {
        frequencies
            .entry(x)
            .and_modify(|x| {
                *x += 1;
            })
            .or_insert(1);
    }

    let (&&elem, &max_freq) = frequencies.get_key_value(&nums[0]).unwrap();
    let mut elem = elem;
    let mut max_freq = max_freq;

    for x in nums.iter().skip(1) {
        let freq = frequencies.get(x).unwrap();
        if freq > &max_freq {
            elem = *x;
            max_freq = *freq;
        }
    }

    elem
}
