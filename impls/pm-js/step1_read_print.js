const readline = require('readline');
let r = require('./reader')
let p = require('./printer')

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
    return input;
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
