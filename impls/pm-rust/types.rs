#[derive(Clone)]
pub enum MalType {
    List,
    Number,
    Symbol,
}

pub trait DataType {
    fn get_data(&self) -> Self;
}

pub mod Types {
    #[derive(Clone)]
    pub struct List {
        list: std::vec::Vec<MalType>,
    }

    pub struct Number {
        val: f64,
    }
}

impl DataType for Types::List {
    fn get_data(&self) -> std::vec::Vec<MalType> {
        self.list
    }
}
impl DataType for Types::Number {
    fn get_data(&self) -> f64 {
        self.list
    }
}
