use std::io;
use regex::Regex;
use crate::types;

struct Reader<'a> {
    tokens: std::vec::Vec<&'a str>,
    position: usize,
}

impl Reader<'_> {
    fn next(&mut self) -> Option<&str> {
        let next_val = self.tokens[self.position];
        self.position += 1;
        Some(next_val)
    }

    fn peek(&mut self) -> Option<&str> {
        match self.tokens.get(self.position) {
            Some(x) => Some(x),
            None => None,
        }
    }
}

fn read_str(buffer: &str) -> Reader {
    let mut reader = Reader {
        tokens: vec![],
        position: 0,
    };
    reader.tokens = tokenize(&buffer);
    read_form(&mut reader);
    reader
}

fn tokenize(subject: &str) -> std::vec::Vec<&str> {
    let re = Regex::new(r#"[\s,]*(~@|[\[\]{}()'`~^@]|"(?:\\.|[^\\"])*"?|;.*|[^\s\[\]{}('"`,;)]*)"#).unwrap();
    let tokens = re.split(subject).collect();
    tokens
}

fn read_form(reader: &mut Reader) -> std::vec::Vec<types::MalType> {
    let token = reader.peek();
    match token.unwrap().chars().next() {
        Some('(') => read_list(&mut reader),
        _ => read_atom(&reader),
    }
}

fn read_list(reader: &mut Reader) -> std::vec::Vec<types::MalType>{
    let token = reader.next();
    let mut list: std::vec::Vec<types::MalType>;
    while token.unwrap().chars().next().unwrap() != ')' {
        for elem in read_form(&mut reader).clone() {
            list.push(elem);
        }
        let token = reader.next();
    }
    list
}

fn read_atom(reader: &Reader) -> Box<types::DataType> {
    let token = reader.next();
    match token.unwrap().parse::<f64>().is_ok() {
        Ok(ok_val) => return Some(types::Types::Number{ val: ok_val }),
        Err(err) => return Err(err),
    }
}
