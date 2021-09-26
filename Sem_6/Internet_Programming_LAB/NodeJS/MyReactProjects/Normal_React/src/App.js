import React, {Component} from "react";
import './App.css';

var images = ['assets/idli.jpg', 'assets/dosa.jpg', 'assets/puri.jpg', 'assets/upma.jpg', 'assets/pongal.jpg', 'assets/chicken_fry.jpg', 'assets/mutton_fry.jpg', 'assets/chicken_biriyani.jpg', 'assets/hyderabadi_biriyani.jpg', 'assets/chicken_roll.jpg'];
var prices = [30, 40, 50, 60, 80, 120, 150, 250, 300, 170];

var imageId = "";
var priceId = "";

var i;


class App extends Component {
  constructor(props) {
    super(props);
  }

  displayDetails(e) {
	if(e.current < 5) {
		imageId = "vegimage";
		priceId = "vegprice";
		for(i = 0; i < 5; i++) {
			document.getElementById(i).style.color = "black";
		}
	}
	else {
		imageId = "nonvegimage";
		priceId = "nonvegprice";
		for(i = 5; i < 10; i++) {
			document.getElementById(i).style.color = "black";
		}
	}
	var image = document.getElementById(imageId);
	var price = document.getElementById(priceId);

	image.src = images[index];
	price.innerHTML = "Rs: " +  prices[index];

	image.style.display = "block";
	price.style.display = "block";

	
	document.getElementById(index).style.color = "pink";

	}

  render() {
    return (
		<div>
		  <center>
			<h1 style={{color: 'black'}}>SSN Hotel</h1>
		  </center>
		  <div className="split veg">
			<center>
			  <h3>Vegetarian Menu</h3>
			</center>
			<ul style={{paddingLeft: '70px', paddingBottom: '50px'}}>
			  <li data-id="0" onclick={this.displayDetails.bind(this)} style={{color: 'pink'}}>Idli</li>
			  <li data-id="1" onclick={this.displayDetails.bind(this)}>Dosa</li>
			  <li data-id="2" onclick={this.displayDetails.bind(this)}>Puri</li>
			  <li data-id="3" onclick={this.displayDetails.bind(this)}>Upma</li>
			  <li data-id="4" onclick={this.displayDetails.bind(this)}>Pongal</li>
			</ul>
			<center>
			  <div className="info">
				<img id="vegimage" src="assets/idli.jpg" width={300} height={230} />
				<h4 id="vegprice">Rs: 30</h4>
			  </div>
			</center>
		  </div>
		  <div className="split nonveg">
			<center>
			  <h3>Non-Vegetarian Menu</h3>
			</center>
			<ul style={{paddingLeft: '70px', paddingBottom: '100px'}}>
			  <li id={5} onclick={this.displayDetails(5)} style={{color: 'pink'}}>Chicken Fry</li>
			  <li id={6} onclick={this.displayDetails(6)}>Mutton Fry</li>
			  <li id={7} onclick={this.displayDetails(7)}>Chicken Biriyani</li>
			  <li id={8} onclick={this.displayDetails(8)}>Hyderabadi Biriyani</li>
			  <li id={9} onclick={this.displayDetails(9)}>Chicken Roll</li>
			</ul>
			<center>
			  <div className="info">
				<img id="nonvegimage" src="assets/chicken_fry.jpg" width={300} height={230} />
				<h4 id="nonvegprice">Rs: 120</h4>
			  </div>
			</center>
		  </div>
		</div>
	  );
  }
}

export default App;
