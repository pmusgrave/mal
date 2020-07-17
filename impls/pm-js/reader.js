let Reader = {
    tokens: [],
    position: 0,
};

function next() {
    return Reader.tokens[Reader.position++];
}

function peek() {
    return Reader.tokens[Reader.position];
}

function read_str(str) {
    Reader.tokens = tokenize(str);
    return read_form(Reader);
}

function tokenize(str) {
    let re = /[\s,]*(~@|[\[\]{}()'`~^@]|"(?:\\.|[^\\"])*"?|;.*|[^\s\[\]{}('"`,;)]*)/g;
    let tokens = str.match(re);
    return tokens;
}

function read_form(reader) {
    let token = peek();

    if (token == undefined) return undefined;
    switch (token.trim()) {
    case '(':
        return read_list(reader);
        break;
    default:
        return read_atom(reader);
    }
}

function read_list(reader) {
    let list = {
        type: "list",
        value: [],
        balanced: false,
    };
    let token = next();

    list.value.push({type:"paren",value:token});

    while (token != ")" && token != undefined) {
        let form = read_form(reader);
        if (form == undefined) break;
        token = form.value;
        if (token == ")")
            list.balanced = true;
        list.value.push(form)
    }

    if (!list.balanced) {
        list.value.push({ type: "EOF", value: "EOF" });
    }
    //console.log(list)
    return list;
}

function read_atom(reader) {
    let token = next().replace(/,+/g, '');
    if (is_numeric(token)) {
        return {
            type: "number",
            value: parseInt(token.trim()),
        }
    }
    else {
        return {
            type: "symbol",
            value: token.trim(),
        }
    }
}

function is_numeric(num){
    return num && !isNaN(num)
}

module.exports = {
    Reader: Reader,
    read_str: read_str,
};
