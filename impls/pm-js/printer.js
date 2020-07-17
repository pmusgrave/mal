function pr_str(input) {
    //console.log("i:",input)
    //if (input.type === undefined) {
    //    return input.toString().trim();
    //}

    switch (input.type) {
    case "number":
        return input.value.toString();
    case "paren":
        return input.value
    case "symbol":
        return input.value;
    case "list":
        //let out_str = input.value
        //    .map((li) => (pr_str(li.value)))
        //    .join(" ");
        let out_str = "";
        let i = 0;
        for (i = 0; i < input.value.length; i++) {
            out_str = out_str.concat(pr_str(input.value[i])) + " ";
        }
        return out_str
            .replace(/\s+\(/g, ' (')
            .replace(/^\s+\(/g, '( ')
            .replace(/\s+\)/g, ')')
            .replace(/\)\s+/g, ') ')
            .replace(/\(\s+/g, '(')
    case "EOF":
        return "EOF";
    default:
        return input.value;
    }
}

module.exports = { pr_str };
