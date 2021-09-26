import React from "react"
import questions from './Questions.js';
function Scores(props) {
    let entries = []
    for (var i = 0; i < 10; i++) {
        entries.push(
            <tr id={"test" + i}>
                <th>{i + 1}</th>
                <th>{props.answers[i]}</th>
                <th>{questions[i].ans}</th>
                <th>{props.scores[i]}</th>
            </tr>
        );

    }
    return (
        <>
            <div className="App">
                <h1 style={{ textAlign: 'center' }} >EXAM SYSTEM SCORES</h1>
                <br />
                <table>
                    <thead>

                        <tr>
                            <th>SNO</th>
                            <th>Answer Entered</th>
                            <th>Correct Ans</th>
                            <th>Scores Obtained</th>
                        </tr>
                    </thead>
                    <tbody>

                        {entries}
                    </tbody>
                </table>
            </div>
        </>
    )
}

export default Scores;