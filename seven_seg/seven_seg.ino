/*
 * Pin mappings:
 * a (T):  1
 * b (TR): 2
 * c (BR): 3
 * d (B):  4
 * e (BL): 5
 * f (TL): 6
 * g (M):  7
 */

/* Bit masks for numbers 0-F: the index is the number
 * - Pin 0 (LSB) should always be zero
 * - g is the MSB
 */
const uint8_t masks[16] = {0x7E, 0x0C, 0xB6, 0x9E,
						   0xCC, 0xDA, 0xFA, 0x0E,
						   0xFE, 0xDE, 0xEE, 0xF8,
						   0x71, 0xCB, 0xF2, 0xE2};
void setup()
{
  // Set pins 1-7 to output
  DDRD |= 0xFE;
}

void loop()
{
  for (size_t i = 0; i < 16; ++i)
  {
    // Clear all LEDs, but leave pin 0 alone
    PORTD &= 0x01;
    // Send number to seven-segment display
    PORTD |= masks[i];
    delay(250);
  }

}
