import React, { useEffect } from "react";
import questions from './Questions.js';
import { Link } from "react-router-dom";
function eqSet(as, bs) {
	if (as.size !== bs.size) return false;
	for (var a of as) if (!bs.has(a)) return false;
	return true;
}


function Question(props) {

	useEffect(() => {
		const checkType = [1, 2, 5, 6]
		const btnType = [3, 4]
		const textType = [7, 8, 9, 10]

		if (checkType.includes(props.cur)) {
			if (!props.answered[props.cur - 1])
				for (var i = 0; i < 4; ++i) {
					document.getElementById("" + props.cur + i).checked = false;
				}
			else {
				for ( i = 0; i < 4; ++i) {
					document.getElementById("" + props.cur + i).checked = false;
				}
				for ( i = 0; i < props.answers[props.cur - 1].length; ++i) {
					document.querySelector('[val="' + props.answers[props.cur - 1][i] + '"]').checked = true;
				}

			}
		} 
		else if (textType.includes(props.cur)){
			if( !props.answered[props.cur - 1]) {
				document.getElementById("t" + props.cur).value = "";
			}
			else{
				document.getElementById("t" + props.cur).value = props.answers[props.cur-1];
			}
		}
	}, [props.cur, props.answered, props.answers])

	if (props.cur === -1) {
		return (
			<div className="main">
				<h2>Rules</h2>
				<div className="rules">
					<p>1. Find Navigation links on the left</p>
					<p>2. Click on the links to answer the questions</p>
					<p>3. Submit test Button appears at the end of the test</p>
					<p>4. Each question is either MCQ type or Fill in the blanks type</p>
					<p>5. All The Best !</p>
				</div><br />
			</div>
		)
	} else if (props.cur === 1 || props.cur === 2) {
		return (
			<Radio cur={props.cur}
				answered={props.answered}
				answers={props.answers}
				scores={props.scores}
			/>
		)
	} else if (props.cur === 3 || props.cur === 4) {
		return (
			<Button cur={props.cur}
				answered={props.answered}
				answers={props.answers}
				scores={props.scores}
			/>
		)
	} else if (props.cur === 5 || props.cur === 6) {
		return (
			<Checkbox cur={props.cur}
				answered={props.answered}
				answers={props.answers}
				scores={props.scores}
			/>
		)
	} else if (props.cur === 10) {
		return (
			<div>
				<Text cur={props.cur}
					answered={props.answered}
					answers={props.answers}
					scores={props.scores}
				/>
				<Link to="/score">
					<button id="submitbtn">Submit Test</button>
				</Link>
			</div>
		)
	} else {
		return (
			<Text cur={props.cur}
				answered={props.answered}
				answers={props.answers}
				scores={props.scores}
			/>
		)
	}

}

function Radio(props) {

	function handleClick(tex) {
		console.log("Clicked " + tex);
		document.getElementById("q" + (props.cur - 1)).style.backgroundColor = "green";
		document.getElementById("q" + (props.cur - 1)).style.color = "white";
		props.answered[props.cur - 1] = true
		props.answers[props.cur - 1] = [tex];
		if (tex === questions[props.cur - 1].ans) {
			props.scores[props.cur - 1] = 5;
		}
		else {
			props.scores[props.cur - 1] = 0;
		}
	}

	return (
		<div className="main">
			<div className="question">
				<h3>{props.cur}. {questions[props.cur - 1].ques || questions[props.cur - 1].part1}</h3>
				<form id={"f" + props.cur}>
					{questions[props.cur - 1].options.map((option, i) => (<div key={i} className="options">
						<input type="radio" id={"" + props.cur + i} onClick={() => handleClick(option.text)} name={props.cur} val={option.text} />
						<label htmlFor={"" + props.cur + i}>{option.text}</label><br /></div>))}
				</form>
			</div><br />

		</div>
	)
}
function Button(props) {
	function colorChange(){
		var x = document.getElementById("" + props.cur + 0)
		if (!props.answered[props.cur - 1]) {
			for (var i = 0; i < 4; ++i) {
				document.getElementById("" + props.cur + i).style.backgroundColor = "#e7e7e7";
			}
		} else {
			for ( i = 0; i < 4; ++i) {
				document.getElementById("" + props.cur + i).style.backgroundColor ="#e7e7e7";
			}
			if (props.answers[props.cur - 1].length !== 0) {
				document.querySelector('[val="' + props.answers[props.cur - 1] + '"]').style.backgroundColor = "#FFD514";
			}
		}
	}
	useEffect(()=>{
		colorChange()
	})

	function handleClick(e, tex, i) {
		e.preventDefault();
		console.log("Clicked " + tex);
		document.getElementById("q" + (props.cur - 1)).style.backgroundColor = "green";
		document.getElementById("q" + (props.cur - 1)).style.color = "white";
		props.answered[props.cur - 1] = true
		let current_ans = props.answers[props.cur - 1];
		if (current_ans === tex) {
			current_ans = "";
		}
		else {
			current_ans = tex;
		}
		if (current_ans === questions[props.cur - 1].ans) {
			props.scores[props.cur - 1] = 5;
		}
		else {
			props.scores[props.cur - 1] = 0;
		}
		props.answers[props.cur - 1] = tex;
		colorChange()

	}
	return (
		<div className="main">
			<div className="question">
				<h3>{props.cur}. {questions[props.cur - 1].ques || questions[props.cur - 1].part1}</h3>
				<form id={"f" + props.cur}>
					{questions[props.cur - 1].options.map((option, i) => (<div key={i} className="options">
						<button onClick={(e) => handleClick(e, option.text, i)} val={option.text} id={"" + props.cur + i} >{option.text}</button><br /></div>))}
				</form>
			</div><br />
		</div>
	)
}
function Checkbox(props) {
	function handleClick(e, tex) {

		const index = props.answers[props.cur - 1].indexOf(tex);
		if (index > -1) {
			props.answers[props.cur - 1].splice(index, 1);
			console.log("removed")
		} else {
			props.answers[props.cur - 1] = props.answers[props.cur - 1].concat([tex])
			console.log("added")
			let current_ans_set = new Set(props.answers[props.cur - 1]);
			let correct_ans_set = new Set(questions[props.cur - 1].ans);
			if (eqSet(current_ans_set, correct_ans_set)) {
				console.log('Correct ans: ' + Array.from(correct_ans_set))
				console.log('Current ans: ' + Array.from(current_ans_set))

				props.scores[props.cur - 1] = 5;
			}
			else {
				props.scores[props.cur - 1] = 0;

			}
		}

		if (props.answers[props.cur - 1].length !== 0) {
			props.answered[props.cur - 1] = true
			document.getElementById("q" + (props.cur - 1)).style.backgroundColor = "green";
			document.getElementById("q" + (props.cur - 1)).style.color = "white";
		}
		else {
			console.log("empty")
			props.answered[props.cur - 1] = false
			document.getElementById("q" + (props.cur - 1)).style.backgroundColor = "red";
			document.getElementById("q" + (props.cur - 1)).style.color = "white";
		}


	}

	return (
		<div className="main">
			<div className="question">
				<h3>{props.cur}. {questions[props.cur - 1].ques || questions[props.cur - 1].part1}</h3>
				<form id={"f" + props.cur}>
					{questions[props.cur - 1].options.map((option, i) => (<div key={i} className="options">
						<input type="checkbox" id={"" + props.cur + i} onClick={(e) => handleClick(e, option.text)} val={option.text} name={props.cur} />
						<label htmlFor={"" + props.cur + i}>{option.text}</label><br /></div>))}
				</form>
			</div><br />
		</div>
	)
}
function Text(props) {
	function handleClick(e, i) {
		console.log("Clicked " + e.target.value);
		if (!e.target.value) {
			props.answered[props.cur - 1] = false
			props.answers[props.cur - 1] = e.target.value
			document.getElementById("q" + (props.cur - 1)).style.backgroundColor = "red";
		}else{
			document.getElementById("q" + (props.cur - 1)).style.backgroundColor = "green";
			document.getElementById("q" + (props.cur - 1)).style.color = "white";
			props.answered[props.cur - 1] = true
			props.answers[props.cur - 1] = document.getElementById("t" + i).value;
			if (props.answers[props.cur - 1] === questions[props.cur - 1].ans) {
				props.scores[props.cur - 1] = 5;
			}
			else {
				props.scores[props.cur - 1] = 0;
			}
		}
		
	}

	return (
		<div className="main">
			<br /><div className="question">
				{props.cur}. {questions[props.cur - 1].part1}
				<form id={"f" + props.cur}>
					{<input type="text" id={"t" + props.cur} onKeyUp={(e) => handleClick(e, props.cur)} style={{ width: "100px", margin: "10px", fontSize: "20px" }} />}
				</form>
				{questions[props.cur - 1].part2}
			</div><br />
		</div>
	)
}

export default Question;