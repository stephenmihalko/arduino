const uint8_t data = 12,  // the data pin in Arduino
              clk = 13,   // the clock pin in Arduino
              dp = 0x80;  // OR number bitmask with this for dp

/*
 * Bit layout
 * REGISTER: 7-SEG
 *       Qh: dp  <-- MSB
 *       Qk: k
 */

const uint8_t masks[16] = {0x3F, 0x06, 0x5B, 0x4F,
                           0x66, 0x6D, 0x7D, 0x07,
                           0x7F, 0x6F, 0x77, 0x7C,
                           0x39, 0x5E, 0x79, 0x71};

void setup()
{
  // Set pins 12 and 13 to output
  DDRB |= 0x30;
}

void loop()
{
  for (size_t i = 0; i < 16; ++i)
  {
    shiftOut(data, clk, MSBFIRST, masks[i]);
    delay(500);
  }
}
