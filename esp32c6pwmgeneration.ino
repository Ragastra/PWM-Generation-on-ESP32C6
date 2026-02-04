const int pwmPinA = 18;
const int pwmPinB = 19;
const int pwmPinC = 21;

const int pwmFreq = 1000;   // 1 kHz
const int pwmRes  = 8;      // 8-bit (0–255)

#define N 36

uint8_t sine_table[N] = {
  128,150,171,191,209,225,238,248,254,
  255,254,248,238,225,209,191,171,150,
  128,105,84,64,46,30,17,7,1,
  0,1,7,17,30,46,64,84,105
};

void setup() {
  ledcAttach(pwmPinA, pwmFreq, pwmRes);
  ledcAttach(pwmPinB, pwmFreq, pwmRes);
  ledcAttach(pwmPinC, pwmFreq, pwmRes);
}

void loop() {

  int i = 0;

  while (1)   // continuous sine generation
  {
    // 3-phase sine PWM (120° phase shift)
    ledcWrite(pwmPinA, sine_table[i]);
    ledcWrite(pwmPinB, sine_table[(i + 12) % N]);  // +120°
    ledcWrite(pwmPinC, sine_table[(i + 24) % N]);  // +240°

    i = (i + 1) % N;   // move to next sine point
    delay(10);         // controls sine frequency
  }
}
