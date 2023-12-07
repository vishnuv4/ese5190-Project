#include "speaker.h"

#include<stdint.h>

uint8_t _packet[10] = {0x7E, 0xFF, 0x06, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEF};

void uint16ToArray(uint16_t value, uint8_t *array)
{
  *array = (uint8_t)(value>>8);
  *(array+1) = (uint8_t)(value);
}

uint16_t calculateCheckSum(uint8_t *buffer)
{
  uint16_t sum = 0;
  for (int i=PKT_VERSION; i<PKT_CHECKSUM; i++) {
    sum += buffer[i];
  }
  return -sum;
}

char str[25];
void sendPacket(uint8_t cmd, uint16_t data)
{
    _packet[PKT_CMD] = cmd;
    uint16ToArray(data, (_packet + PKT_PARAM));
    uint16ToArray(calculateCheckSum(_packet), _packet + PKT_CHECKSUM);
    for(int i=0; i<10; i++){
        UART_send(_packet[i]);
    }
    _delay_ms(10);
}

void speaker_reset()
{
    sendPacket((uint8_t)0x0C, (uint8_t)0);
}

void speaker_setVolume(uint8_t vol)
{
    sendPacket((uint8_t)0x06, (uint8_t)vol);
}

void speaker_setEQ()
{
    sendPacket((uint8_t)0x07, (uint8_t)0);
}

void speaker_outputDevice()
{
    sendPacket((uint8_t)0x09, (uint8_t)DFPLAYER_DEVICE_SD);
    _delay_ms(200);
}

void speaker_play(uint8_t file)
{
    sendPacket((uint8_t)0x03, file);
}

void speaker_begin()
{
    speaker_reset();
    _delay_ms(2000);

    speaker_setVolume(20);
    speaker_setEQ();
    speaker_outputDevice();
}
