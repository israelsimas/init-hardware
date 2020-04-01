/**************************************************************************
 * init-hardware.h
 *
 *  Create on: 22/08/2017
 *     Author: Intelbras SIP team
 *
 *  Header File to Plataform SIP Intelbras
 *
 * Copyrights Intelbras, 2020
 *
 **************************************************************************/
#ifndef __INIT_HARDWARE_H__
#define __INIT_HARDWARE_H__

/**************************************************************************
 * INCLUDES
 **************************************************************************/
#include <utils.h>

/**************************************************************************
 * DEFINITIONS
 **************************************************************************/

/* Devices path */
#define DEV_LCD_DATA			"/dev/lcd_data"
#define DEV_LCD_CMD 			"/dev/lcd_command"
#define DEV_LEDS          "/dev/leds"
#define DEV_BACKLIGHT		  "/dev/backlight"

#define PORTUGUESE        "pt_BR"
#define SPANISH				    "es"
#define ENGLISH				    "en"

#define ERROR_LCD_CMD	    -1
#define ERROR_LCD_DATA	  -2
#define ERROR_LED			    -3
#define ERROR_BACKLIGHT	  -4

#define INVALID_FILE_DESCRIPTOR -1

#define BUFFER_LENGHT		   128
#define NUM_CMDS           3

#define NUM_LINES_128x32   4
#define NUM_LINES_128x64   8
#define SIZE_WORD          8
#define MAX_HEIGHT         64  

#define SLEEP_TIME_CLEAN		(200 * 1000)
#define SLEEP_BEFORE_CLOSE	60	// waiting time before closing the application

#define TURN_ON_BACKLIGHT	 0x01

/* LCD CMD */
#define START_LINE_0		  0x40
#define PAGE_ADDR_0			  0xB0
#define COL_ADDR_0			  0x10
#define BOOSTER_6X			  0x04

#define NUM_BLINK_LEDS		  600
#define SLEEP_BEFORE_BLINK	(100 * 1000)

#define CFG_LED_ID              "led:Init1"
#define CFG_BACKLIGHT_SUPPORT   "handset0:backlightSupport"
#define CFG_DISPLAY_SIZE        "handset0:displaySize"
#define CFG_DISPLAY_SUPPORT     "handset0:displaySupport"

/**************************************************************************
 * TYPEDEFS
 **************************************************************************/

/*
 * @enum E_LANGUAGE
 *
 * Product Types ID 
 */
typedef enum {
  LANG_PORTUGUESE = 0,
  LANG_SPANISH,
  LANG_ENGLISH
} E_LANGUAGE;

/**************************************************************************
 * INTERNAL CALL FUNCTIONS
 **************************************************************************/

/*
 * Inverts the value of the Byte.
 *
 * @return inverted byte.
 */
unsigned char reverseByte(unsigned char b);

/*
 * Writing a command on the LCD.
 *
 * @param Command to be written.
 */
int writeCommandLCD(unsigned char command);

/*
 * Writing data on the LCD.
 *
 * @param buff Buffer of data to be written on the LCD.
 * @param size
 */
int writeDataLCD(unsigned char *buff, int size);

/*
 * Fills the screen with all the pixels in a template.
 *
 * @return command execution status.
 */
int writeTemplateLCD();

/*
 * Writes the value to the LED driver.
 */
int led_write_data(unsigned char *data, unsigned char size);

/*
 * Turns a specific LED on or off.
 *
 * @param bOn Indicates whether or not to turn on the Led.
 * @param off Led indexer.
 *
 * @return LED operation status.
 */
int ledOnOff(bool bOn, unsigned char off);

/*
 * Blinks the leds
 */
void *blinkLeds();

/*
 * Handle blink leds
 */
void ctrlLeds();

/*
 * Opens the LCD data driver.
 *
 * @return driver open status.
 */
int open_data_conection(void);

/*
 * Opens the LCD command driver.
 *
 * @return driver open status.
 */
int open_command_conection(void);

/*
 * Opens the LED driver.
 *
 * @return driver open status.
 */
int openDriverLed();

/*
 * Opens the backlight driver.
 *
 * @return driver open status.
 */
int open_backlight(void);

/*
 * Opens the LCD Data and Command Driver and LED Drivers.
 *
 * @return status of the opening of the communication drivers.
 */
int openDrivers();

/* 
 * Retrieves the system language
 */
int getLanguage();

/* 
 * Retrieves product settings
 */
void getConfig();

/* 
 * Configures the Display backlight
 */
void turnOnBacklight();

#endif
