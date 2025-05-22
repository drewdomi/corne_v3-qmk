/*
 * Clover (crkbd) Corne Split - Hardware Configuration
 * ----------------------------------------------
 * This file contains all hardware-specific configuration settings
 * including pin definitions, encoder setup, and various QMK features.
 *
 * File: config.h
 * Version: 1.0
 * Last updated: May 22, 2025
 */

#pragma once

// === SPLIT KEYBOARD CONFIGURATION ===
#define MASTER_LEFT                     // Force left side as master regardless of USB connection
#define SPLIT_USB_DETECT               // Detect USB connection for split communication

// === ENCODER CONFIGURATION ===
#define ENCODER_A_PINS { D4 }          // Encoder A pin for left side
#define ENCODER_B_PINS { C6 }          // Encoder B pin for left side
#define ENCODER_A_PINS_RIGHT { F4 }    // Encoder A pin for right side
#define ENCODER_B_PINS_RIGHT { F5 }    // Encoder B pin for right side
#define ENCODER_RESOLUTION 4           // Encoder sensitivity (steps per detent)

// === TAPPING AND TIMING CONFIGURATION ===
#define TAPPING_TERM 230               // Base tapping term (ms) for mod-tap keys
#define TAPPING_TERM_PER_KEY           // Enable per-key tapping term customization
#define QUICK_TAP_TERM 190             // Quick tap term (ms) for rapid typing
#define TAPPING_TOGGLE 2               // Number of taps to toggle layer
#define DEBOUNCE 5                     // Switch debounce time (ms)
#define TAP_FLOW_ENABLE                // Enable Tap Flow feature
#define TAP_FLOW_TERM 150              // Time window (ms) to disable holds during fast typing

// // === TAP-HOLD BEHAVIOR ===
#define HOLD_ON_OTHER_KEY_PRESS        // Trigger hold on other key press
#define TAPPING_FORCE_HOLD             // Force hold behavior for repeated keys


// === RGB MATRIX CONFIGURATION ===
#ifdef RGB_MATRIX_ENABLE
    #define RGB_MATRIX_LED_COUNT 54            // Total LEDs (27 per side)
    #define RGB_MATRIX_SPLIT { 27, 27 }        // LED distribution
    #define RGB_MATRIX_MAXIMUM_BRIGHTNESS 120  // Brightness limit (0-255)
    #define RGB_MATRIX_DEFAULT_VAL 80          // Default brightness
    #define RGB_MATRIX_DEFAULT_HUE 128         // Default color (0-255)
    #define RGB_MATRIX_DEFAULT_SAT 255         // Default saturation
    #define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_OUT_IN // Default effect

    // Enable EEPROM storage for RGB settings
    #define RGB_MATRIX_FRAMEBUFFER_EFFECTS     // Enable framebuffer effects
    #define RGB_MATRIX_KEYPRESSES              // Enable keypress effects
    
    #define ENABLE_RGB_MATRIX_SOLID_COLOR           // Static color
    #define ENABLE_RGB_MATRIX_BREATHING             // Breathing effect
    #define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL       // Spiral effect
    #define ENABLE_RGB_MATRIX_CYCLE_ALL             // Color cycle
    #define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON // Rainbow chevron
    #define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT      // Left-right cycle
    #define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN         // Up-down cycle
    #define ENABLE_RGB_MATRIX_CYCLE_OUT_IN          // Outside-in cycle
    #define ENABLE_RGB_MATRIX_TYPING_HEATMAP        // Heatmap on keypress
    #define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE // React to keypresses
    
    #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_SOLID_COLOR
    #define RGB_MATRIX_STARTUP_HUE 128
    #define RGB_MATRIX_STARTUP_SAT 255
    #define RGB_MATRIX_STARTUP_VAL 80
#endif


// === OLED CONFIGURATION ===
#ifdef OLED_ENABLE
    #define OLED_DISPLAY_128X32            // OLED display resolution
    #define OLED_TIMEOUT 60000             // OLED timeout in milliseconds (60 seconds)
    #define OLED_BRIGHTNESS 128            // Default OLED brightness
    #define OLED_SCROLL_TIMEOUT 0          // Disable scroll timeout
#endif
