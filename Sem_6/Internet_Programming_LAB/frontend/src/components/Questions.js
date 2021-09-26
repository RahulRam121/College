const questions = [{
        ques: "Which of the following is an example of non-volatile memory?",
        options: [
            { text: "Cache memory", isCorrect: false },
            { text: "RAM", isCorrect: false },
            { text: "ROM", isCorrect: true },
            { text: "None of the Above", isCorrect: false }
        ],
        ans: "ROM"
    },
    {
        ques: "How many buses are connected as part of the 8085 microprocessor?",
        options: [
            { text: "2", isCorrect: false },
            { text: "3", isCorrect: false },
            { text: "5", isCorrect: false },
            { text: "8", isCorrect: true }
        ],
        ans: "8"
    },
    {
        ques: "The term ‘page traffic’ describes",
        options: [
            { text: "Number of pages in memory at a given instant", isCorrect: false },
            { text: "Number of papers required to be brought in at a given page request", isCorrect: false },
            { text: "Number of pages of executing programs loaded in memory", isCorrect: false },
            { text: "The movement of pages in and out of memory", isCorrect: true }
        ],
        ans: "The movement of pages in and out of memory"
    }, {
        ques: "An assembler is",
        options: [
            { text: "Syntax dependant", isCorrect: false },
            { text: "Machine dependant", isCorrect: true },
            { text: "Data dependant", isCorrect: false },
            { text: "Programming language-dependent", isCorrect: false }
        ],
        ans: "Machine dependant"
    },

    {
        ques: "Concepts of OOPS include : ",
        options: [
            { text: "Data encapsulation", isCorrect: true },
            { text: "Data authentication", isCorrect: false },
            { text: "Inheritance", isCorrect: true },
            { text: "Compilation", isCorrect: false }
        ],
        ans: ["Inheritance", "Data encapsulation"]
    },
    {
        ques: "Which of the following is true ?",
        options: [
            { text: "Ajax is a programming language", isCorrect: false },
            { text: "Node.js is a runtime environment", isCorrect: true },
            { text: "React is a front-end JS library", isCorrect: true },
            { text: "Express is a front-end JS framework", isCorrect: false }
        ],
        ans: ["Node.js is a runtime environment", "React is a front-end JS library"]
    },
    {
        part1: "The first part of a machine language instruction that specifies the operation to be performed is called a(n)",
        part2: "Note: one word, lower case letters only",
        ans: "opcode"
    },
    {
        part1: "When the Lagrangian multiplier value is not zero then the vector is called",
        part2: "vector. Note: one word, lower case letters only",
        ans: "support"
    },
    {
        part1: "Solve: In data set S, if the no. of samples n=4,P+=1,p−=3, then the Entropy(S) is",
        part2: "note: real number, after decimal point two digits only, no space before and after decimal point",
        ans: "0.81"
    },
    {
        part1: "Solve: The value of  information gain of the following data set is",
        part2: "S={s1, s2, s3, s4} where s1=false, s2=true, s3=false, s4=true F={f1, f2} where f1 = s1, s2 and f2 = s3, s4 Note: only number.",
        ans: "0"
    }

]

export default questions;