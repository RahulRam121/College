import React, { useState } from "react"
import './App.css';
import Question from "./components/QuestionTypes.js"
import Score from "./components/Scores.js"
import {
	BrowserRouter as Router,
	NavLink,
	Link,
	Switch,
	Route
} from "react-router-dom";


function Nav(props) {
	const nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]

	function handleClick(num) {
		props.set(num)
		props.visited[num - 1] = true
		if (!props.answered[num - 1]) {
			document.getElementById("q" + (num - 1)).style.backgroundColor = "red";
			document.getElementById("q" + (num - 1)).style.color = "white";
		}
	}

	return (
		<div className="nav" >
			{nums.map((num, i) => <button key={i} id={"q" + i} style={{ width: '50px', fontSize: '30px', margin: '5px' }} onClick={() => handleClick(num)}>{num}</button>)}
		</div>
	)
}
function App() {

	const [curQues, setCurQuestion] = useState(-1)
	const [visited, setVisited] = useState(Array(10).fill(false))
	const [answered, setAnswered] = useState(Array(10).fill(false))
	const [answers, setAnswers] = useState(Array(10).fill([]))
	const [scores, setScores] = useState(Array(10).fill(0));

	//console.log(answers)
	return (
		<Router>
			<Switch>
				<Route exact path="/">
					<div className="App">
						<h1 style={{ textAlign: 'center' }} >EXAM SYSTEM</h1>
						<br />

						<Nav set={setCurQuestion}
							visited={visited}
							answered={answered}
						/>
						<Question cur={curQues}
							answered={answered}
							answers={answers}
							scores={scores}
						/>
					</div>
				</Route>
				<Route path="/score">
					<Score answers={answers} scores={scores} />
				</Route>
			</Switch>


		</Router>
	);
}


export default App;
