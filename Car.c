// Pin declarations

const int sonarPin1 = 2;
const int sonarPin2 = 3;

const int motorLeft1 = 4;
const int motorLeft2 = 5;
const int motorRight1 = 6;
const int motorRight2 = 7;

// Constant declarations

const int carMovement = 100;
const int carForwards = 1000;
const int carTurn = 1500;

// Variable declarations

unsigned long rawSonar;
int prevSonar = 0;
int testSonar = 0;
int currSonar = 0;
int i = 0;
int x = 0;
string moveInstruct[];

// Function declarations


// This function performs the sonar reading
int sonarCar() {

  pinMode(sonarPin1, OUTPUT);
  digitalWrite(sonarPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(sonarPin1, HIGH);
  delayMicroseconds(5);
  digitalWrite(sonarPin1, LOW);

  pinMode(sonarPin2, INPUT);
  rawSonar = pulseIn(sonarPin2, HIGH);

  Serial.print("rawSonar: " + rawSonar);

  return rawSonar / 29 / 2;

}


// This function check if the sonar readings are accurate
bool dataCheck(checking, index) {

  if (prevSonar + carMove < checking || prevSonar - carMove > checking) {

     // If the current sonar reading is within the expected range

  } else if (moveInstruct[x] == "Left" || moveInstruct[x] == "Right") {

      // If the last instructions given to the motors were good

    }

}


// This function tells the motors to move in a particualr direction for a specified time
void moveCar(direction) {

  if (direction == "up") {

    digitalWrite(motorLeft1, HIGH);
    digitalWrite(motorLeft2, LOW);
    digitalWrite(motorRight1, HIGH);
    digitalWrite(motorRight2, LOW);

    delay(carForwards);

    breakCar();

  } else if (direction == "down") {

    digitalWrite(motorLeft1, LOW);
    digitalWrite(motorLeft2, HIGH);
    digitalWrite(motorRight1, LOW);
    digitalWrite(motorRight2, HIGH);

    delay(carForwards);

    breakCar();

  } else if (direction == "left") {

    digitalWrite(motorLeft1, HIGH);
    digitalWrite(motorLeft2, LOW);
    digitalWrite(motorRight1, LOW);
    digitalWrite(motorRight2, HIGH);

    delay(carTurn);

    breakCar();

  } else if (direction == "right") {

    digitalWrite(motorLeft1, LOW);
    digitalWrite(motorLeft2, HIGH);
    digitalWrite(motorRight1, HIGH);
    digitalWrite(motorRight2, LOW);

    delay(carTurn);

    breakCar();

  }

}


// This function tells the motors to stop running
void breakCar() {

  digitalWrite(motorLeft1, HIGH);
  digitalWrite(motorLeft2, HIGH);
  digitalWrite(motorRight1, HIGH);
  digitalWrite(motorRight2, HIGH);

}


// This function uses the sonar readings to decide what to do next
void thinkCar(sonar, index) {

  //  thinkCarResult -> temporary value to represent the output of this function

  motorInstructions[index] = thinkCarResult;

  moveCar(thinkCarResult);

}



// Core Arduino Functions

void setup() {

  // Need to initialise certain values and variables here

}

void loop() {

  testSonar = sonarCar();

  if (dataCheck(testSonar, x) === true) {

    prevSonar == currSonar;
    currSonar == testSonar;

    x++;

    // This is where thinkCar function is called and chooses what to do based off the currSonar variable

    thinkCar(currSonar, x);

  }

}
