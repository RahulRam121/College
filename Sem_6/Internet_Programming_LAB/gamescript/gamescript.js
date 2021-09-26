let list = [1, 2, 3, 4, 5, 1, 2, 3, 4, 5]
var select=[-1,-1];
var tc=0;
var counter,ttime;
var match=0;
var cover=[1,1,1,1,1,1,1,1,1,1];
var score=0;
var level;
document.getElementById("1").addEventListener("click", function(){cal(1);});
document.getElementById("2").addEventListener("click", function(){cal(2);});
document.getElementById("3").addEventListener("click", function(){cal(3);});
document.getElementById("4").addEventListener("click", function(){cal(4);});
document.getElementById("5").addEventListener("click", function(){cal(5);});
document.getElementById("6").addEventListener("click", function(){cal(6);});
document.getElementById("7").addEventListener("click", function(){cal(7);});
document.getElementById("8").addEventListener("click", function(){cal(8);});
document.getElementById("9").addEventListener("click", function(){cal(9);});
document.getElementById("10").addEventListener("click", function(){cal(10);});
function setlevel(x)
{
 list = list.sort(() => Math.random() - 0.5);
 select=[-1,-1];
 tc=0;
 if(x==1){
 ttime=60;
 }
 else if(x==2){
 ttime=45;
 }
 else if(x==3){
 ttime=30;
 }
 match=0;
 var i;
 cover=[1,1,1,1,1,1,1,1,1,1];
 level=x;
 for(i=1;i<=10;i++)
 {
 document.getElementById("img"+i).src="cover.jpg";
 document.getElementById("img"+i).style.display="block";
 }
}
function cal(x){
if(cover[x-1]==1){
 if(select[0]==-1)
 {
 select[0]=x;
 document.getElementById("img"+x).src= "img"+list[x-1]+".jpg";
 cover[x-1]=0;
 }
 else if(select[1]==-1)
 {
 select[1]=x;
 document.getElementById("img"+x).src= "img"+list[x-1]+".jpg";
 cover[x-1]=0;
 setTimeout(eval,1000);

 }
}
}
function eval()
{

if(document.getElementById("img"+select[0]).src==document.getElementById("img"+select[1]).src){
 score+=20;
 document.getElementById("img"+select[0]).style.display="none";
 document.getElementById("img"+select[1]).style.display="none";
 select[0]=-1;
 select[1]=-1;
 match+=1;
 }
 else
 {
 score-=5;
 document.getElementById("img"+select[0]).src="cover.jpg";
 document.getElementById("img"+select[1]).src="cover.jpg";
 cover[select[0]-1]=1;
 cover[select[1]-1]=1;
 select[0]=-1;
 select[1]=-1;
 }
}
function initiate(x)
{
 alert('Welcome\nFind all possible pairs within given time\n correct match :+20 points wrong match : -5 points\nEarly finish would give extra time points to the score \nlevel='+x);
 setlevel(x);
 counter=setInterval(countdown,1000);
}
function countdown()
{
 tc++;
 document.getElementById("counter").innerHTML=ttime-tc;
 document.getElementById("score").innerHTML=score;

 if(ttime-tc==0)
 {
 clearInterval(counter);

 if(level==3)
 alert("GameOver:\n Game Score:"+score);
 else
 initiate(level+1);
 }
 else if(match==5)
 {
 clearInterval(counter);
 score+=ttime-tc;
 var tl=ttime-tc;
 document.getElementById("score").innerHTML=score;

 if(level==3)
 alert("GameOver:\n Game Score:"+score);
 else
 initiate(level+1);
 }
}