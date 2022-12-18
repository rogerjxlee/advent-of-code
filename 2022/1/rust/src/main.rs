use std::env;
use std::fs::File;
use std::io::{BufRead, BufReader};

fn main() {
  let filepath = env::args().nth(1).expect("no filepath given");
  let file = File::open(filepath).expect("failed to read file");
  let reader = BufReader::new(file);
  let mut elf_to_calories : Vec<i32> = Vec::new();
  let mut calories = 0;
  for line in reader.lines() {
    let line = line.expect("");
    if line == "" {
      elf_to_calories.push(calories);
      calories = 0;
    } else {
      calories += line.parse::<i32>().expect("failed to parse line");
    }
  }
  println!("{}", &elf_to_calories.iter().max().unwrap());
}
