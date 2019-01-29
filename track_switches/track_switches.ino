// There are 2 relays (one normal, one reversed) per turnout.

// There are 2 cards of 8 relays, so we can have a max of 8 relays

// and we need 16 output pins: 90-105.

#define RELAY_PIN_1 90

#define TURNOUT_N    8

#define RELAY_N     (2 * TURNOUT_N)

#define RELAY_NORMAL( T) (2 * (T))

#define RELAY_REVERSE(T) ((2 * (T)) + 1)

 

#define RELAY_TIME_MS   100

 

#define TURNOUT_NORMAL  'N'

#define TURNOUT_REVERSE 'R'

 

unsigned char _turnouts[TURNOUT_N];

 

void trip_relay(int);

 

void setup_relays() {

    // initialize digital pin 90+ as an output.

    for (int i = 0; i < RELAY_N; i++) {

        pinMode(RELAY_PIN_1 + i, OUTPUT);

        digitalWrite(RELAY_PIN_1 + i, LOW);

    }

   

    for (int i = 0; i < TURNOUT_N; i++) {

        _turnouts[i] = TURNOUT_NORMAL;

        trip_relay(RELAY_NORMAL(i));

    }

}

 

void setup() {

    setup_relays();

    // etc

}

void loop() {
  
}

void trip_relay(int index /* 0..RELAY_N-1 */) {

    digitalWrite(RELAY_PIN_1 + index, HIGH);

    delay(RELAY_TIME_MS);

    digitalWrite(RELAY_PIN_1 + index, LOW);

}

 

void set_turnout(int turnout /* 0..TURNOUT_N-1 */, int direction) {

    if (_turnouts[turnout] != direction) {

        trip_relay(direction == TURNOUT_NORMAL ? RELAY_NORMAL(turnout)

                                               : RELAY_REVERSE(turnout));

        _turnouts[turnout] = direction;

    }

}
