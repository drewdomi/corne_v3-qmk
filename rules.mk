# Clover (crkbd) Corne Split - Build Configuration
# -------------------------------------------
# This file defines which QMK features are enabled for the firmware build
# Including RGB, OLED, encoders, and other custom functionality.
#
# File: rules.mk
# Version: 1.0
# Last updated: May 21, 2025

# Bootloader Configuration
BOOTLOADER = caterina

# Core Features
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration

# Lighting Features
BACKLIGHT_ENABLE = no       # Disable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Disable RGB underglow (old system)
RGB_MATRIX_ENABLE = yes     # Enable RGB matrix (modern system)
RGB_MATRIX_DRIVER = ws2812  # RGB driver type

# Audio Features
AUDIO_ENABLE = no           # Audio output

# Split Keyboard Features
SPLIT_KEYBOARD = yes        # Enable split keyboard support

# Input Features
ENCODER_ENABLE = yes        # Enable rotary encoder support
ENCODER_MAP_ENABLE = yes    # Enable encoder mapping
TAP_DANCE_ENABLE = yes      # Enable tap dance functionality

# Display Features
OLED_ENABLE = yes           # Enable OLED displays
OLED_DRIVER = ssd1306       # OLED driver type
OLED_TRANSPORT = i2c        # OLED communication protocol

# Additional Features
WPM_ENABLE = yes            # Enable words per minute calculation
QMK_SETTINGS = yes          # Enable QMK settings

# Build Optimizations
LTO_ENABLE = yes            # Link Time Optimization (reduces firmware size)

# Optional Features (currently disabled)
# KEY_OVERRIDE_ENABLE = yes
# AUTO_SHIFT_ENABLE = yes
# SERIAL_DRIVER = vendor
# WS2812_DRIVER = vendor