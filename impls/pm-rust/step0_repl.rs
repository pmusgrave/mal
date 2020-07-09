use std::io;

fn read(input: &str) -> String {
    input.to_string()
}

fn eval(input: &str) -> String {
    input.to_string()
}

fn print(input: &str) -> String {
    input.to_string()
}

fn rep(input: &str) -> String {
    let buffer = read(&input);
    let buffer = eval(&buffer);
    let buffer = print(&buffer);
    return buffer;
}

fn main() {
    loop {
        println!("user> ");
        let mut input: String = "".to_string();
        io::stdin().read_line(&mut input)
            .expect("Failed to read line");
        input = rep(&input);
        println!("{}", input);
    }
}
