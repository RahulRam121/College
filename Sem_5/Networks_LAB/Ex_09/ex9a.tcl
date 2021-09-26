#Create a simulator object
set ns [new Simulator]

#Open the nam trace file
set nf [open outa.nam w]
$ns namtrace-all $nf

$ns color 0 blue
$ns color 1 red

set tr [open outa.tr w]
$ns trace-all $tr

#Define a 'finish' procedure
proc finish {} {
	global nf ns tr
	$ns flush-trace
 	close $tr
	exec nam outa.nam &
 	exit 0
}

#Creating Nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
set n5 [$ns node]
set n6 [$ns node]
set n7 [$ns node]
set n8 [$ns node]
set n9 [$ns node]
set n10 [$ns node]
set n11 [$ns node]

#Setting Links
$ns duplex-link $n0 $n8 1Mb 10ms DropTail
$ns duplex-link $n1 $n10 1Mb 10ms DropTail
$ns duplex-link $n0 $n9 1Mb 10ms DropTail
$ns duplex-link $n9 $n11 1Mb 10ms DropTail
$ns duplex-link $n10 $n11 1Mb 10ms DropTail
$ns duplex-link $n11 $n5 1Mb 10ms DropTail
$ns duplex-link $n7 $n6 1Mb 10ms DropTail

#Setting Topology
$ns duplex-link-op $n0 $n8 orient right
$ns duplex-link-op $n1 $n10 orient left-down
$ns duplex-link-op $n0 $n9 orient left-up
$ns duplex-link-op $n9 $n11 orient up
$ns duplex-link-op $n10 $n11 orient left
$ns duplex-link-op $n11 $n5 orient left-down
$ns duplex-link-op $n7 $n6 orient right


set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0
set cbr0 [new Application/Traffic/CBR]
$cbr0 attach-agent $udp0

set udp1 [new Agent/UDP]
$ns attach-agent $n1 $udp1
set cbr1 [new Application/Traffic/CBR]
$cbr1 attach-agent $udp1

set null0 [new Agent/Null]
$ns attach-agent $n5 $null0
set null1 [new Agent/Null]
$ns attach-agent $n5 $null1
$ns connect $udp0 $null0
$ns connect $udp1 $null1

$udp0 set class_ 0
$udp1 set class_ 1

$udp0 set fid_ 0
$udp0 set window_ 8000
$udp0 set packetSize_ 552
$udp1 set fid_ 1
$udp1 set window_ 8000
$udp1 set packetSize_ 552

$ns rtproto DV
$ns rtmodel-at 1.0 down $n11 $n5
$ns rtmodel-at 1.0 down $n7 $n6

$ns rtmodel-at 2.0 up $n11 $n5
$ns rtmodel-at 2.0 up $n7 $n6

$ns at 0.0 "$cbr0 start"
$ns at 0.0 "$cbr1 start"
$ns at 5.0 "$cbr0 stop"
$ns at 5.0 "$cbr1 stop"
$ns at 5.0 "finish"
$ns run
