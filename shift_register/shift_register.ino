const uint8_t data = 12, clk = 13;

/*
 * Bit layout
 * REGISTER: 7-SEG
 *       Qh: dp  <-- MSB
 *       Qk: k
 */

const uint8_t masks[16] = { };

void setup()
{
  // Set pins 12 and 13 to output
  DDRB |= 0x30
}

void loop()
{
  
}
