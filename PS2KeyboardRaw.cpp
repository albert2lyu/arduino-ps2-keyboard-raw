/*
  PS2KeyboardRaw.cpp - PS2KeyboardRaw library
  Copyright (c) 2007 Free Software Foundation.  All right reserved.
  Written by Christian Weichel <info@32leaves.net>

  ** Mostly rewritten Paul Stoffregen <paul@pjrc.com> 2010, 2011
  ** Modified for use beginning with Arduino 13 by L. Abraham Smith, <n3bah@microcompdesign.com> * 
  ** Modified for easy interrup pin assignement on method begin(datapin,irq_pin). Cuningan <cuninganreset@gmail.com> **
  
  ** 8bit packed keycodes by Athos Bacchiocchi <athos.bacchiocchi@gmail.com>, September 2015
     This version is a radical modification of the original code, with
     custom, 8-bit packed values for the keycodes (see OptimizedKeyCodes.h),
     key release coded in the msb, code repetitions filtered out. 

  for more information on the original version (non "raw") go to:
  at http://www.arduino.cc/playground/Main/PS2Keyboard
  or http://www.pjrc.com/teensy/td_libs_PS2Keyboard.html

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include "PS2KeyboardRaw.h"

const PROGMEM uint8_t optcodes[2][256] = {

/* 0 */	{	// 0:
		0, KEY_F9, 0, KEY_F5, KEY_F3, KEY_F1, KEY_F2, KEY_F12, 0, KEY_F10,
		KEY_F8, KEY_F6, KEY_F4, KEY_TAB, AN_ROW_3, 0, 0, KEY_ALT_L, KEY_SHIFT_L, 0,
		KEY_CTRL_L, AN_ROW_2, AN_ROW_3+1, 0, 0, 0, AN_ROW_0+1, AN_ROW_1+1, AN_ROW_1, AN_ROW_2+1,
		AN_ROW_3+2, 0, 0, AN_ROW_0+3, AN_ROW_0+2, AN_ROW_1+2, AN_ROW_2+2, AN_ROW_3+4, AN_ROW_3+3, 0,
		0, SPACEBAR, AN_ROW_0+4, AN_ROW_1+3, AN_ROW_2+4, AN_ROW_2+3, AN_ROW_3+5, 0, 0, AN_ROW_0+6,
		AN_ROW_0+5, AN_ROW_1+5, AN_ROW_1+4, AN_ROW_2+5, AN_ROW_3+6, 0, 0, 0, AN_ROW_0+7, AN_ROW_1+6,
		AN_ROW_2+6, AN_ROW_3+7, AN_ROW_3+8, 0, 0, AN_ROW_0+8, AN_ROW_1+7, AN_ROW_2+7, AN_ROW_2+8, AN_ROW_3+10,
		AN_ROW_3+9, 0, 0, AN_ROW_0+9, AN_ROW_0+10, AN_ROW_1+8, AN_ROW_1+9, AN_ROW_2+9, AN_ROW_3+11, 0,
		0, 0, AN_ROW_1+10, 0, AN_ROW_2+10, AN_ROW_3+12, 0, 0, KEY_CAPSLOCK, KEY_SHIFT_R,
		KEY_ENTER, AN_ROW_2+11, 0, AN_ROW_1+11, 0, 0, 0, AN_ROW_0, 0, 0,
		// 100:
		0, 0, KEY_BACKSPACE, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, KEY_ESC, 0,
		KEY_F11, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, KEY_F7, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		// 200:
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0
	},

/* 1 */	{	// 0:
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, KEY_ALT_GR, 0, 0,
		KEY_CTRL_R, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, KEY_SUPER_L, 0, 0, 0, 0, 0, 0, 0, KEY_SUPER_R,
		0, 0, 0, 0, 0, 0, 0, KEY_MENU, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		// 100:
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		// 200:
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0
	}
};

#define BUFFER_SIZE 45

static volatile uint8_t head, tail;
static uint8_t DataPin;
static volatile uint16_t bufferRaw[BUFFER_SIZE];
static uint16_t lastPressed = 0;

// The ISR for the external interrupt
void ps2interrupt_raw(void)
{
	static uint8_t bitcount=0;
	static uint8_t incoming=0;
	static uint16_t current=0;
	static uint32_t prev_ms=0;
	static uint32_t optCodeRow = 0;
	uint32_t now_ms;
	uint8_t n, val;

	val = digitalRead(DataPin);
	now_ms = millis();
	if (now_ms - prev_ms > 250) {
		bitcount = 0;
		incoming = 0;
	}
	prev_ms = now_ms;
	n = bitcount - 1;
	if (n <= 7) {
		incoming |= (val << n);
	}
	bitcount++;
	if (bitcount == 11) {
		uint8_t i = head + 1;
		if (i >= BUFFER_SIZE) i = 0;
		if (i != tail) {
			
			switch (incoming)
			{
				case 0x00: current=0;	     break; // issue an error code?
				case 0xF0: current |= 1<<15; break;
				case 0xE1: current |= 1<<9;  optCodeRow=1; break;
				case 0xE0: current |= 1<<8;  optCodeRow=1; break;
				default:
					//current |= incoming;
					current |= pgm_read_byte(optcodes[optCodeRow]+incoming);
					
					if (current&(1<<15)) { // is a release event
						bufferRaw[i]=current;
						head = i;
						if (lastPressed==(current&(~(1<<15))))
							lastPressed=0;

					} 
					else if (lastPressed!=current) {
						bufferRaw[i]=current;
						head = i;
						lastPressed=current;
					}
					current=0;
					optCodeRow=0;
			}

		}
		bitcount = 0;
		incoming = 0;
	}
}

static inline uint16_t get_scan_code_raw(void)
{
	uint8_t i;
	uint16_t c;

	i = tail;
	if (i == head) return 0;
	i++;
	if (i >= BUFFER_SIZE) i = 0;
	c = bufferRaw[i];
	tail = i;
	return c;
}

#define BREAK     0x01
#define MODIFIER  0x02
#define SHIFT_L   0x04
#define SHIFT_R   0x08
#define ALTGR     0x10
#define CTRL      0x20

PS2KeyboardRaw::PS2KeyboardRaw() {
  // nothing to do here, begin() does it all
}

bool PS2KeyboardRaw::available()
{
	return head!=tail;
}

uint16_t PS2KeyboardRaw::read()
{
	return get_scan_code_raw();
}

void PS2KeyboardRaw::begin(uint8_t data_pin, uint8_t irq_pin)
{
  uint8_t irq_num=0;
  DataPin = data_pin;
 
  // initialize the pins
#ifdef INPUT_PULLUP
  pinMode(irq_pin, INPUT_PULLUP);
  pinMode(data_pin, INPUT_PULLUP);
#else
  pinMode(irq_pin, INPUT);
  digitalWrite(irq_pin, HIGH);
  pinMode(data_pin, INPUT);
  digitalWrite(data_pin, HIGH);
#endif
  
  switch(irq_pin) {
    #ifdef CORE_INT0_PIN
    case CORE_INT0_PIN:
      irq_num = 0;
      break;
    #endif
    #ifdef CORE_INT1_PIN
    case CORE_INT1_PIN:
      irq_num = 1;
      break;
    #endif
    #ifdef CORE_INT2_PIN
    case CORE_INT2_PIN:
      irq_num = 2;
      break;
    #endif
    #ifdef CORE_INT3_PIN
    case CORE_INT3_PIN:
      irq_num = 3;
      break;
    #endif
    #ifdef CORE_INT4_PIN
    case CORE_INT4_PIN:
      irq_num = 4;
      break;
    #endif
    #ifdef CORE_INT5_PIN
    case CORE_INT5_PIN:
      irq_num = 5;
      break;
    #endif
    #ifdef CORE_INT6_PIN
    case CORE_INT6_PIN:
      irq_num = 6;
      break;
    #endif
    #ifdef CORE_INT7_PIN
    case CORE_INT7_PIN:
      irq_num = 7;
      break;
    #endif
    default:
      irq_num = 0;
      break;
  }
  head = 0;
  tail = 0;
  attachInterrupt(irq_num, ps2interrupt_raw, FALLING);
}


