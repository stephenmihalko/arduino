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

// Bit masks for numbers 0-9: the index is the number
const uint8_t masks[10] = {0x7E, 0x0C, 0xB6, 0x9E, 0xCC, 0xDA, 0xFA, 0x0E, 0xFE, 0xDE};
void setup()
{
  // Set pins 1-7 to output
  DDRD |= 0xFE;
}

void loop()
{
  for (size_t i = 0; i < 10; ++i)
  {
    PORTD &= 0x00;
    PORTD |= masks[i];
    delay(250);
  }

}
