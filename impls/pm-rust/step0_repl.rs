use std::io;

fn main() {
    loop {
        println!("user> ");
        let input = read();
        println!("{}", input);
    }
}

fn read() -> String {
    let mut input: String = "".to_string();
    io::stdin().read_line(&mut input)
        .expect("Failed to read line");
    input
}
