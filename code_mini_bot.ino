#define MOTOR_RIGHT_A 14
#define MOTOR_RIGHT_B 27
#define MOTOR_LEFT_A 26
#define MOTOR_LEFT_B 25

#define PWM_CHANNEL_MR_A 0
#define PWM_CHANNEL_ML_A 1
#define PWM_FREQ 5000
#define PWM_RES 8
#define SPEED 200

#define TIME_1 637
#define TIME_2 8366
#define TIME_3 1753
#define TIME_4 2706
#define TIME_TURN 500

void moveForward(int timeMs);
void turnLeft(int timeMs);
void turnRight(int timeMs);
void stopMotors();

void setup() {
  ledcSetup(PWM_CHANNEL_MR_A, PWM_FREQ, PWM_RES);
  ledcAttachPin(MOTOR_RIGHT_A, PWM_CHANNEL_MR_A);

  ledcSetup(PWM_CHANNEL_ML_A, PWM_FREQ, PWM_RES);
  ledcAttachPin(MOTOR_LEFT_A, PWM_CHANNEL_ML_A);

  pinMode(MOTOR_RIGHT_B, OUTPUT);
  pinMode(MOTOR_LEFT_B, OUTPUT);
}

void loop() {
  moveForward(TIME_1);
  turnLeft(TIME_TURN);
  moveForward(TIME_2);
  turnRight(TIME_TURN);
  moveForward(TIME_3);
  turnRight(TIME_TURN);
  moveForward(TIME_4);
  stopMotors();
  while (1);
}

void moveForward(int timeMs) {
  digitalWrite(MOTOR_RIGHT_B, LOW);
  digitalWrite(MOTOR_LEFT_B, LOW);
  ledcWrite(PWM_CHANNEL_MR_A, SPEED);
  ledcWrite(PWM_CHANNEL_ML_A, SPEED);
  delay(timeMs);
  stopMotors();
}

void turnLeft(int timeMs) {
  digitalWrite(MOTOR_RIGHT_B, LOW);
  digitalWrite(MOTOR_LEFT_B, HIGH);
  ledcWrite(PWM_CHANNEL_MR_A, SPEED);
  ledcWrite(PWM_CHANNEL_ML_A, SPEED);
  delay(timeMs);
  stopMotors();
}

void turnRight(int timeMs) {
  digitalWrite(MOTOR_RIGHT_B, HIGH);
  digitalWrite(MOTOR_LEFT_B, LOW);
  ledcWrite(PWM_CHANNEL_MR_A, SPEED);
  ledcWrite(PWM_CHANNEL_ML_A, SPEED);
  delay(timeMs);
  stopMotors();
}

void stopMotors() {
  ledcWrite(PWM_CHANNEL_MR_A, 0);
  ledcWrite(PWM_CHANNEL_ML_A, 0);
}
