const readline = require('readline');

function rep(input) {
    output = READ(input);
    output = EVAL(output);
    output = PRINT(output);
    return output;
}

function READ(input) {
    return input;
}

function EVAL(input) {
    return input;
}

function PRINT(input) {
    return input;
}

const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout,
    prompt: 'user> '
});

rl.prompt();

rl.on('line', (line) => {
    console.log(line);
    rl.prompt();
}).on('close', () => {
    process.exit(0);
});
