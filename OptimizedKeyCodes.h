/*
  PS2KeyboardRaw.cpp - PS2KeyboardRaw library
  Copyright (c) 2007 Free Software Foundation.  All right reserved.

  This header is not present in the original version by C. Weichel.
  It's written by Athos Bacchiocchi for use with the modified 
  "PS2KeyboardRaw" library.

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



#ifndef PS2_KEYBOARD_OPTIMIZED_KEY_CODES
#define PS2_KEYBOARD_OPTIMIZED_KEY_CODES

#define KEY_INVALID	0
// Alphanumeric:
#define GROUP_AN_BASE	1		
#define	AN_ROW_0	GROUP_AN_BASE	// 1st alphanumeric row (starting with "<")
#define AN_ROW_0_LEN	11
#define AN_ROW_1	(AN_ROW_0 + AN_ROW_0_LEN)	// 2nd AN row (starting with "A")
#define AN_ROW_1_LEN	12
#define AN_ROW_2	(AN_ROW_1 + AN_ROW_1_LEN)	// 3rd AN row (starting with "Q")
#define AN_ROW_2_LEN	12
#define AN_ROW_3	(AN_ROW_2 + AN_ROW_2_LEN)	// 4th AN row (starting with "\")
#define AN_ROW_3_LEN	13
#define SPACEBAR	(AN_ROW_3 + AN_ROW_3_LEN)
#define GROUP_AN_LEN	(SPACEBAR - (GROUP_AN_BASE) + 1)
// Modifiers:
#define GROUP_MOD_BASE	(GROUP_AN_BASE + GROUP_AN_LEN)
#define KEY_ESC		GROUP_MOD_BASE
#define KEY_TAB		KEY_ESC + 1
#define KEY_CAPSLOCK	KEY_TAB + 1
#define KEY_SHIFT_L	KEY_CAPSLOCK + 1
#define KEY_CTRL_L	KEY_SHIFT_L + 1
#define KEY_SUPER_L	KEY_CTRL_L + 1		
#define KEY_ALT_L	KEY_SUPER_L + 1
#define KEY_ALT_GR	KEY_ALT_L + 1
#define KEY_SUPER_R	KEY_ALT_GR + 1
#define KEY_MENU	KEY_SUPER_R + 1
#define KEY_CTRL_R	KEY_MENU + 1
#define KEY_SHIFT_R	KEY_CTRL_R + 1
#define KEY_ENTER	KEY_SHIFT_R + 1
#define KEY_BACKSPACE	KEY_ENTER + 1
#define GROUP_MOD_LEN	(KEY_BACKSPACE - (GROUP_MOD_BASE) + 1)
// Function keys:
#define GROUP_FN_BASE	(GROUP_MOD_BASE + GROUP_MOD_LEN)
#define KEY_F1		GROUP_FN_BASE
#define KEY_F2		GROUP_FN_BASE + 1
#define KEY_F3		GROUP_FN_BASE + 2
#define KEY_F4		GROUP_FN_BASE + 3
#define KEY_F5		GROUP_FN_BASE + 4
#define KEY_F6		GROUP_FN_BASE + 5
#define KEY_F7		GROUP_FN_BASE + 6
#define KEY_F8		GROUP_FN_BASE + 7
#define KEY_F9		GROUP_FN_BASE + 8
#define KEY_F10		GROUP_FN_BASE + 9
#define KEY_F11		GROUP_FN_BASE + 10
#define KEY_F12		GROUP_FN_BASE + 11
#define GROUP_FN_LEN	12
// Commands:
#define GROUP_CMD_BASE	(GROUP_FN_BASE + GROUP_FN_LEN)
#define KEY_PRT_SCR	GROUP_CMD_BASE
#define KEY_SCRL_LOCK	KEY_PRT_SCR + 1
#define KEY_PAUSE	KEY_SCRL_LOCK + 1
#define KEY_INS		KEY_PAUSE + 1
#define KEY_CANC	KEY_INS + 1
#define KEY_HOME	KEY_CANC + 1
#define KEY_END		KEY_HOME + 1
#define KEY_PGUP	KEY_END + 1
#define KEY_PGDOWN	KEY_PGUP + 1
#define GROUP_CMD_LEN	(KEY_PGDOWN - (GROUP_CMD_BASE) + 1)
// Cursors:
#define GROUP_CURSORS_BASE	(GROUP_CMD_BASE + GROUP_CMD_LEN)
#define KEY_UP			GROUP_CURSORS_BASE
#define KEY_DOWN		KEY_UP + 1
#define KEY_LEFT		KEY_DOWN + 1
#define KEY_RIGHT		KEY_LEFT + 1
#define GROUP_CURSORS_LEN	(KEY_RIGHT - (GROUP_CURSORS_BASE) + 1)
// Numpad:
#define GROUP_NUMPAD_BASE	(GROUP_CURSORS_BASE + GROUP_CURSORS_LEN) 
#define NUM_ROW_0		GROUP_NUMPAD_BASE
#define NUM_ROW_1		NUM_ROW_0 + 2
#define NUM_ROW_2		NUM_ROW_1 + 3
#define NUM_ROW_3		NUM_ROW_2 + 3
#define NUM_ROW_4		NUM_ROW_3 + 3
#define NUM_PLUS		NUM_ROW_4 + 4
#define NUM_ENTER		NUM_PLUS + 1
#define GROUP_NUMPAD_LEN	(NUM_ENTER - (GROUP_NUMPAD_BASE) + 1)

#endif
