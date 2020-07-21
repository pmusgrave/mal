const readline = require('readline');
let r = require('./reader')
let p = require('./printer')

repl_env = {
    '+': (...args) => args.reduce((a,c) => a+c),
    '-': (...args) => args.reduce((a,c) => a-c),
    '*': (...args) => args.reduce((a,c) => a*c),
    '/': (...args) => args.reduce((a,c) => a/c),
};

function rep(input) {
    output = READ(input);
    output = EVAL(output);
    output = PRINT(output);
    return output;
}

function READ(input) {
    let form = r.read_str(input);
    return form;
}

function EVAL(input) {
    if (input.type === "list") {
        if (input.value && input.value.length === 0 || input.value.length === 2) {
            return input;
        }
        else {
            let new_list = eval(eval_ast(input));
            let f = eval_ast(new_list.value[0]);
            //console.log("nl:",new_list);
            //console.log("f:",f);
            //console.log("args:", new_list.value.slice(1,new_list.value.length).map((item) => (item.value)))
            let args =  new_list.value.slice(1,new_list.value.length).map((item) => (item.value));
            let result = f.apply(null, args);
            //console.log(result);
            return { type: "symbol", value: result };
        }
    }
    else {
        return input;
    }
}

function eval_ast(ast) {
    switch(ast.type) {
    case "symbol":
        if (repl_env[ast.value] != undefined) {
            return repl_env[ast.value];
        }
        else {
            return () => { console.log("error: symbol not found:", ast.value) }
        }
        break;
    case "list":
        let f = ast.value[1];
        let args = ast.value.slice(2,ast.value.length-1);
        args = args.map((elem) => EVAL(elem))
        let new_list = [];
        return {
            "type": "list",
            "value": new_list.concat(f).concat(args),
        }
    default:
        return ast;
    }
}

function PRINT(input) {
    return (p.pr_str(input));
}

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
    prompt: 'user> '
});

rl.prompt();

rl.on('line', (line) => {
    console.log(rep(line))
    r.Reader.position = 0;
    rl.prompt();
}).on('close', () => {
    console.log("\n");
    process.exit(0);
});
