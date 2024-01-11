# Design and Development of an Embedded System Applied to Table Football Game
The present document has been drafted with the aim of designing and implementing an embedded system 
for detecting impacts caused by a ball on the rods of a foosball table and distinguishing them during a game.
Indeed, foosball is a game that requires skill, reflexes, and a good amount of concentration.
However, players' decisions and actions can often be based on subjective observations and feelings,
leading to discussions about which shots were actually made during a game. 
Specifically, a microcontroller, Arduino Due, is used, which manages 
several ADXL345 accelerometers placed on the rods of a foosball table. 
The code for detecting ball impacts has been written in C++ using the popular Arduino IDE.

## Quick Start
To setup the embedded system, the following steps need to be followed:
<ul>
  <li>Install Arduino IDE.</li>
  <li>Inside the IDE settings, add the Arduino Due board.</li>
  <li>Install the SparkFun_ADXL345 library.</li>
  <li>Set up the connectios between the Arduino Due and the sensors the following way: </li>
</ul>

![Connections' Diagram](images/figure1.jpg?raw=true "Connections' Diagram")


