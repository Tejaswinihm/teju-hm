# This script is created by NSG2 beta1
# <http://wushoupong.googlepages.com/nsg>

#===================================
#     Simulation parameters setup
#===================================
set val(stop)   10.0                         ;# time of simulation end

#===================================
#        Initialization        
#===================================
#Create a ns simulator
set ns [new Simulator -multicast on];

#Open the NS trace file
set tracefile [open out.tr w]
$ns trace-all $tracefile

#Open the NAM trace file
set namfile [open out.nam w]
$ns namtrace-all $namfile

set group [Node allocaddr]
#===================================
#        Nodes Definition        
#===================================
#Create 5 nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]

#===================================
#        Links Definition        
#===================================
#Createlinks between nodes
$ns duplex-link $n0 $n4 100.0Mb 10ms DropTail
$ns queue-limit $n0 $n4 50
$ns duplex-link $n1 $n0 100.0Mb 10ms DropTail
$ns queue-limit $n1 $n0 50
$ns duplex-link $n2 $n0 100.0Mb 10ms DropTail
$ns queue-limit $n2 $n0 50
$ns duplex-link $n3 $n0 100.0Mb 10ms DropTail
$ns queue-limit $n3 $n0 50

set mproto DM
set mrthandle [$ns mrtproto $mproto]

#Give node position (for NAM)
$ns duplex-link-op $n0 $n4 orient left

$ns duplex-link-op $n1 $n0 orient left-down
$ns duplex-link-op $n2 $n0 orient left

$ns duplex-link-op $n3 $n0 orient left-up

#===================================
#        Agents Definition
#===================================

set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0

#===================================
#        Applications Definition        
#===================================
#Setup a CBR Application over UDP connection
set cbr0 [new Application/Traffic/CBR]
$cbr0 attach-agent $udp0

$udp0 set dst_addr_ $group
$udp0 set dst_port_ 0

set revr [new Agent/LossMonitor]
$ns attach-agent $n1 $revr
$ns at 1.9 "$n1 join-group $revr $group"

set revr2 [new Agent/LossMonitor]
$ns attach-agent $n2 $revr2
$ns at 1.12 "$n2 join-group $revr2 $group"

set revr3 [new Agent/LossMonitor]
$ns attach-agent $n3 $revr3
$ns at 1.15 "$n3 join-group $revr3 $group"

set revr4 [new Agent/LossMonitor]
$ns attach-agent $n4 $revr
$ns at 0.3 "$n4 join-group $revr4 $group"
$ns at 3.5 "$n4 leave-group $revr4 $group"





$cbr0 set packetSize_ 1000
$cbr0 set rate_ 1.0Mb
$cbr0 set random_ null
$ns at 1.0 "$cbr0 start"
$ns at 2.0 "$cbr0 stop"


#===================================
#        Termination        
#===================================
#Define a 'finish' procedure
proc finish {} {
    global ns tracefile namfile
    $ns flush-trace
    close $tracefile
    close $namfile
    exec nam out.nam &
    exit 0
}
$ns at $val(stop) "$ns nam-end-wireless $val(stop)"
$ns at $val(stop) "finish"
$ns at $val(stop) "puts \"done\" ; $ns halt"
$ns run
