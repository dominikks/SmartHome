#pragma once

const unsigned char gate_open[] PROGMEM = {
    0x00, 0x00, 0x1f, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xff,
    0xf0, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x70,
    0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x18, 0x00, 0x00,
    0x00, 0x60, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x1c,
    0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0xe0, 0x00,
    0x00, 0x1c, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x00, 0x03,
    0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x03, 0x03, 0xc0, 0x0f, 0x03, 0x00,
    0x00, 0x02, 0x03, 0xff, 0xff, 0x01, 0x00, 0x00, 0x02, 0x03, 0xff, 0xff,
    0x01, 0x00, 0x00, 0x03, 0x07, 0x80, 0x07, 0x83, 0x00, 0x00, 0x03, 0xff,
    0xff, 0xff, 0xff, 0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00,
    0x03, 0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0xfe,
    0x00, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x01, 0xf8, 0x00,
    0x00, 0x7c, 0x00, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00,
    0xf0, 0x00, 0x00, 0x7c, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x1c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x80, 0xff, 0xf8, 0x00,
    0x00, 0x00, 0x00, 0xc0, 0xff, 0x38, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xdf,
    0x18, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xdf, 0x18, 0x00, 0x00, 0x00, 0x00,
    0xc0, 0xdf, 0x18, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xdf, 0x18, 0x00, 0x00,
    0x00, 0x00, 0xc0, 0xdf, 0x18, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xdf, 0x18,
    0x00, 0x00, 0x00, 0x00, 0xc0, 0xdf, 0x18, 0x00, 0x00, 0x00, 0x00, 0xc0,
    0xdf, 0x18, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xdf, 0x18, 0x00, 0x00, 0x00,
    0x00, 0xc0, 0xdf, 0x18, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xdf, 0x18, 0x00,
    0x00, 0x00, 0x00, 0xc0, 0xdf, 0x18, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xdf,
    0x18, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xdf, 0x18, 0x00, 0x00, 0x00, 0x00,
    0xc0, 0xdf, 0x18, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xdf, 0x18, 0x00, 0x00,
    0x00, 0x00, 0xc0, 0xdf, 0x18, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xf8,
    0x00, 0x00, 0x00, 0x00, 0xc0, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0xc0,
    0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x1f, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xc0};

const unsigned char gate_closed[] PROGMEM = {
    0x00, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x01, 0xff, 0xff, 0xff, 0x80,
    0x00, 0x03, 0x80, 0x00, 0x01, 0xc0, 0x00, 0x03, 0x80, 0x00, 0x01, 0xc0,
    0x00, 0x03, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x03, 0x00, 0x00, 0x00, 0xc0,
    0x00, 0x07, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x07, 0x00, 0x00, 0x00, 0xe0,
    0x00, 0x07, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x07, 0xff, 0xff, 0xff, 0xe0,
    0x00, 0x0f, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x18, 0x1e, 0x00, 0x78, 0x18,
    0x00, 0x10, 0x1f, 0xff, 0xf8, 0x08, 0x00, 0x10, 0x1f, 0xff, 0xf8, 0x08,
    0x00, 0x18, 0x3c, 0x00, 0x3c, 0x18, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xf8,
    0x00, 0x1f, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x1f, 0xff, 0xff, 0xff, 0xf8,
    0x00, 0x0f, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x0f, 0xc0, 0x00, 0x03, 0xe0,
    0x00, 0x0f, 0xc0, 0x00, 0x03, 0xe0, 0x00, 0x0f, 0xc0, 0x00, 0x03, 0xe0,
    0x00, 0x07, 0x80, 0x00, 0x03, 0xe0, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xe7, 0xff, 0xff, 0xff, 0xff, 0xf4, 0xef, 0xff, 0xff, 0xff, 0xff, 0xf6,
    0xee, 0x71, 0xce, 0x71, 0xce, 0x76, 0xec, 0x31, 0x8e, 0x31, 0x8e, 0x36,
    0xec, 0x31, 0x8e, 0x31, 0x8e, 0x36, 0xec, 0x31, 0x8e, 0x31, 0x8e, 0x36,
    0xec, 0x31, 0x8e, 0x31, 0x8e, 0x36, 0xec, 0x31, 0x8e, 0x31, 0x8e, 0x36,
    0xec, 0x31, 0x8e, 0x31, 0x8e, 0x36, 0xec, 0x31, 0x8e, 0x31, 0x8e, 0x36,
    0xec, 0x31, 0x8e, 0x31, 0x8e, 0x36, 0xec, 0x31, 0x8e, 0x31, 0x8e, 0x36,
    0xec, 0x31, 0x8e, 0x31, 0x8e, 0x36, 0xec, 0x31, 0x8e, 0x31, 0x8e, 0x36,
    0xec, 0x31, 0x8e, 0x31, 0x8e, 0x36, 0xec, 0x31, 0x8e, 0x31, 0x8e, 0x36,
    0xec, 0x31, 0x8e, 0x31, 0x8e, 0x36, 0xec, 0x31, 0x8e, 0x31, 0x8e, 0x36,
    0xec, 0x31, 0x8e, 0x31, 0x8e, 0x36, 0xec, 0x31, 0x8e, 0x31, 0x8e, 0x36,
    0xef, 0xff, 0xff, 0xff, 0xff, 0xf6, 0xef, 0xff, 0xff, 0xff, 0xff, 0xf6,
    0xe7, 0xff, 0xff, 0xff, 0xff, 0xf6, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfe};

const unsigned char light_off[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x7e, 0x1f, 0x80, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x03, 0xc0,
    0x00, 0x00, 0x00, 0x01, 0xe0, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x03, 0xc0,
    0x00, 0xf0, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x70, 0x00, 0x00, 0x00,
    0x07, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x38, 0x00,
    0x00, 0x00, 0x07, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00,
    0x38, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x07,
    0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x38, 0x00, 0x00,
    0x00, 0x07, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x38,
    0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x70, 0x00, 0x00, 0x00, 0x03, 0x80,
    0x00, 0x70, 0x00, 0x00, 0x00, 0x01, 0xc0, 0x00, 0xe0, 0x00, 0x00, 0x00,
    0x01, 0xc0, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x01, 0xc0, 0x00,
    0x00, 0x00, 0x00, 0xf0, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x70, 0x03,
    0x80, 0x00, 0x00, 0x00, 0x00, 0x38, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x38, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x07, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1c, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x0e, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x08, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xfc,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00,
    0x00, 0x00};

const unsigned char light_on[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00,
    0xe0, 0x30, 0x00, 0x00, 0x00, 0x03, 0x80, 0xe0, 0x70, 0x00, 0x00, 0x00,
    0x03, 0x80, 0xe0, 0x70, 0x00, 0x00, 0x00, 0x01, 0xc0, 0x00, 0xe0, 0x00,
    0x00, 0x00, 0x01, 0xc0, 0x00, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x03, 0xc0,
    0x0f, 0xfc, 0x00, 0xf0, 0x00, 0x03, 0xe0, 0x3f, 0xff, 0x01, 0xf0, 0x00,
    0x01, 0xf0, 0xff, 0x3f, 0xc3, 0xe0, 0x00, 0x00, 0x61, 0xf0, 0x03, 0xe1,
    0x80, 0x00, 0x00, 0x01, 0xe0, 0x01, 0xe0, 0x00, 0x00, 0x00, 0x03, 0xc0,
    0x00, 0xf0, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x70, 0x00, 0x00, 0x00,
    0x07, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x38, 0x00,
    0x00, 0x08, 0x87, 0x00, 0x00, 0x38, 0x44, 0x00, 0x1f, 0x87, 0x00, 0x00,
    0x38, 0x7e, 0x00, 0x1f, 0x87, 0x00, 0x00, 0x38, 0x7e, 0x00, 0x00, 0x07,
    0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x38, 0x00, 0x00,
    0x00, 0x07, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x38,
    0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x70, 0x00, 0x00, 0x00, 0x03, 0x80,
    0x00, 0x70, 0x00, 0x00, 0x00, 0xe1, 0xc0, 0x00, 0xe1, 0x80, 0x00, 0x03,
    0xe1, 0xe0, 0x01, 0xe1, 0xf0, 0x00, 0x07, 0xe0, 0xe0, 0x01, 0xc1, 0xf8,
    0x00, 0x03, 0x80, 0xf0, 0x03, 0xc0, 0x70, 0x00, 0x00, 0x00, 0x70, 0x03,
    0x80, 0x00, 0x00, 0x00, 0x00, 0x78, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x38, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x07, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x1c, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c, 0x0e, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x18, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xfc,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x03, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xc0, 0x00,
    0x00, 0x00};

const unsigned char moon_0_8[] PROGMEM = {
    0x00, 0x3c, 0x00, 0x01, 0xff, 0x80, 0x07, 0xff, 0xe0, 0x0f, 0xff, 0xf0,
    0x1f, 0xff, 0xf8, 0x3f, 0xff, 0xfc, 0x3f, 0xff, 0xfc, 0x7f, 0xff, 0xfe,
    0x7f, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7f, 0xff, 0xfe,
    0x7f, 0xff, 0xfe, 0x3f, 0xff, 0xfc, 0x3f, 0xff, 0xfc, 0x1f, 0xff, 0xf8,
    0x0f, 0xff, 0xf0, 0x07, 0xff, 0xe0, 0x01, 0xff, 0x80, 0x00, 0x3c, 0x00};

const unsigned char moon_1[] PROGMEM = {
    0x00, 0x3c, 0x00, 0x01, 0xff, 0x80, 0x07, 0xff, 0xe0, 0x0f, 0xff, 0xf0,
    0x1f, 0xe1, 0xf8, 0x3f, 0xf0, 0x7c, 0x3f, 0xfc, 0x3c, 0x7f, 0xfc, 0x1e,
    0x7f, 0xfe, 0x1e, 0xff, 0xfe, 0x0f, 0xff, 0xff, 0x0f, 0xff, 0xff, 0x0f,
    0xff, 0xff, 0x0f, 0xff, 0xff, 0x0f, 0xff, 0xfe, 0x0f, 0x7f, 0xfe, 0x1e,
    0x7f, 0xfc, 0x1e, 0x3f, 0xfc, 0x3c, 0x3f, 0xf0, 0x7c, 0x1f, 0xe1, 0xf8,
    0x0f, 0xff, 0xf0, 0x07, 0xff, 0xe0, 0x01, 0xff, 0x80, 0x00, 0x3c, 0x00};

const unsigned char moon_2[] PROGMEM = {
    0x00, 0x3c, 0x00, 0x01, 0xff, 0x80, 0x07, 0xff, 0xe0, 0x0f, 0xff, 0xf0,
    0x1f, 0xe1, 0xf8, 0x3f, 0xf0, 0x7c, 0x3f, 0xfc, 0x3c, 0x7f, 0xfc, 0x1e,
    0x7f, 0xfe, 0x1e, 0xff, 0xfe, 0x0f, 0xff, 0xff, 0x0f, 0xff, 0xff, 0x0f,
    0xff, 0xff, 0x0f, 0xff, 0xff, 0x0f, 0xff, 0xfe, 0x0f, 0x7f, 0xfe, 0x1e,
    0x7f, 0xfc, 0x1e, 0x3f, 0xfc, 0x3c, 0x3f, 0xf0, 0x7c, 0x1f, 0xe1, 0xf8,
    0x0f, 0xff, 0xf0, 0x07, 0xff, 0xe0, 0x01, 0xff, 0x80, 0x00, 0x3c, 0x00};

const unsigned char moon_3[] PROGMEM = {
    0x00, 0x3c, 0x00, 0x01, 0xff, 0x80, 0x07, 0xff, 0xe0, 0x0f, 0xff, 0xf0,
    0x1f, 0xf1, 0xf8, 0x3f, 0xf0, 0x7c, 0x3f, 0xf0, 0x3c, 0x7f, 0xf0, 0x1e,
    0x7f, 0xf0, 0x1e, 0xff, 0xf0, 0x0f, 0xff, 0xf0, 0x0f, 0xff, 0xf0, 0x0f,
    0xff, 0xf0, 0x0f, 0xff, 0xf0, 0x0f, 0xff, 0xf0, 0x0f, 0x7f, 0xf0, 0x1e,
    0x7f, 0xf0, 0x1e, 0x3f, 0xf0, 0x3c, 0x3f, 0xf0, 0x7c, 0x1f, 0xf1, 0xf8,
    0x0f, 0xff, 0xf0, 0x07, 0xff, 0xe0, 0x01, 0xff, 0x80, 0x00, 0x3c, 0x00};

const unsigned char moon_4[] PROGMEM = {
    0x00, 0x3c, 0x00, 0x01, 0xff, 0x80, 0x07, 0xff, 0xe0, 0x0f, 0xff, 0xf0,
    0x1f, 0xc1, 0xf8, 0x3f, 0xc0, 0x7c, 0x3f, 0x80, 0x3c, 0x7f, 0x00, 0x1e,
    0x7f, 0x00, 0x1e, 0xff, 0x00, 0x0f, 0xff, 0x00, 0x0f, 0xff, 0x00, 0x0f,
    0xff, 0x00, 0x0f, 0xff, 0x00, 0x0f, 0xff, 0x00, 0x0f, 0x7f, 0x00, 0x1e,
    0x7f, 0x00, 0x1e, 0x3f, 0x80, 0x3c, 0x3f, 0xc0, 0x7c, 0x1f, 0xc1, 0xf8,
    0x0f, 0xff, 0xf0, 0x07, 0xff, 0xe0, 0x01, 0xff, 0x80, 0x00, 0x3c, 0x00};

const unsigned char moon_5[] PROGMEM = {
    0x00, 0x3c, 0x00, 0x01, 0xff, 0x80, 0x07, 0xff, 0xe0, 0x0f, 0xff, 0xf0,
    0x1f, 0x81, 0xf8, 0x3e, 0x00, 0x7c, 0x3c, 0x00, 0x3c, 0x78, 0x00, 0x1e,
    0x78, 0x00, 0x1e, 0xf0, 0x00, 0x0f, 0xf0, 0x00, 0x0f, 0xf0, 0x00, 0x0f,
    0xf0, 0x00, 0x0f, 0xf0, 0x00, 0x0f, 0xf0, 0x00, 0x0f, 0x78, 0x00, 0x1e,
    0x78, 0x00, 0x1e, 0x3c, 0x00, 0x3c, 0x3e, 0x00, 0x7c, 0x1f, 0x81, 0xf8,
    0x0f, 0xff, 0xf0, 0x07, 0xff, 0xe0, 0x01, 0xff, 0x80, 0x00, 0x3c, 0x00};

const unsigned char moon_6[] PROGMEM = {
    0x00, 0x3c, 0x00, 0x01, 0xff, 0x80, 0x07, 0xff, 0xe0, 0x0f, 0xff, 0xf0,
    0x1f, 0x8f, 0xf8, 0x3e, 0x0f, 0xfc, 0x3c, 0x0f, 0xfc, 0x78, 0x0f, 0xfe,
    0x78, 0x0f, 0xfe, 0xf0, 0x0f, 0xff, 0xf0, 0x0f, 0xff, 0xf0, 0x0f, 0xff,
    0xf0, 0x0f, 0xff, 0xf0, 0x0f, 0xff, 0xf0, 0x0f, 0xff, 0x78, 0x0f, 0xfe,
    0x78, 0x0f, 0xfe, 0x3c, 0x0f, 0xfc, 0x3e, 0x0f, 0xfc, 0x1f, 0x8f, 0xf8,
    0x0f, 0xff, 0xf0, 0x07, 0xff, 0xe0, 0x01, 0xff, 0x80, 0x00, 0x3c, 0x00};

const unsigned char moon_7[] PROGMEM = {
    0x00, 0x3c, 0x00, 0x01, 0xff, 0x80, 0x07, 0xff, 0xe0, 0x0f, 0xff, 0xf0,
    0x1f, 0x87, 0xf8, 0x3e, 0x0f, 0xfc, 0x3c, 0x3f, 0xfc, 0x78, 0x3f, 0xfe,
    0x78, 0x7f, 0xfe, 0xf0, 0x7f, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff,
    0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0x7f, 0xff, 0x78, 0x7f, 0xfe,
    0x78, 0x3f, 0xfe, 0x3c, 0x3f, 0xfc, 0x3e, 0x0f, 0xfc, 0x1f, 0x87, 0xf8,
    0x0f, 0xff, 0xf0, 0x07, 0xff, 0xe0, 0x01, 0xff, 0x80, 0x00, 0x3c, 0x00};

const unsigned char moon_8[] PROGMEM = {
    0x00, 0x3c, 0x00, 0x01, 0xff, 0x80, 0x07, 0xff, 0xe0, 0x0f, 0xff, 0xf0,
    0x1f, 0x87, 0xf8, 0x3e, 0x0f, 0xfc, 0x3c, 0x3f, 0xfc, 0x78, 0x3f, 0xfe,
    0x78, 0x7f, 0xfe, 0xf0, 0x7f, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff,
    0xf0, 0xff, 0xff, 0xf0, 0xff, 0xff, 0xf0, 0x7f, 0xff, 0x78, 0x7f, 0xfe,
    0x78, 0x3f, 0xfe, 0x3c, 0x3f, 0xfc, 0x3e, 0x0f, 0xfc, 0x1f, 0x87, 0xf8,
    0x0f, 0xff, 0xf0, 0x07, 0xff, 0xe0, 0x01, 0xff, 0x80, 0x00, 0x3c, 0x00};

const unsigned char pressure[] PROGMEM = {
    0x00, 0x00, 0x84, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84,
    0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x84, 0x44, 0x40, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xc4, 0x44, 0x44, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x4c, 0x88, 0x8c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40,
    0x88, 0x88, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x88, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x01, 0x11, 0x08, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x01, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x31, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x30, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x60, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x08, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10,
    0x84, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x30, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0e, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1c,
    0x03, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3c, 0x04, 0x18, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x60, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x03, 0xe0, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xe0,
    0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0xff, 0xc0, 0x00, 0x18, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x05, 0x80, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x0b, 0x80,
    0x00, 0x0e, 0x00, 0x00, 0x00, 0x00, 0x00, 0x33, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x61, 0x80, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
    0x00, 0xc1, 0x80, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
    0x00, 0x1c, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00,
    0x08, 0x00, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x01, 0xf0, 0x00, 0x00, 0x07,
    0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xc0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x01, 0xf8, 0x00, 0x00, 0x18,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00,
    0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf8, 0x00, 0x01, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x08, 0x00, 0x00, 0x03, 0x80, 0x3f, 0x80, 0x00, 0x00, 0x10, 0x00,
    0x00, 0x03, 0x80, 0x3f, 0xe0, 0x00, 0x00, 0x20, 0x00, 0x00, 0x03, 0x80,
    0x30, 0xe0, 0x00, 0x3c, 0xc0, 0x00, 0x00, 0x03, 0xfc, 0x30, 0xe7, 0xf0,
    0xff, 0x80, 0x00, 0x00, 0x03, 0xfc, 0x30, 0xe3, 0xf0, 0xe3, 0x80, 0x00,
    0x00, 0x03, 0x8e, 0x3b, 0xe0, 0x38, 0x01, 0x80, 0x00, 0x00, 0x03, 0x8e,
    0x3f, 0xc1, 0xf8, 0x01, 0x80, 0x00, 0x00, 0x03, 0x8e, 0x3f, 0x07, 0xf8,
    0x01, 0x80, 0x00, 0x00, 0x03, 0x8e, 0x30, 0x0e, 0x38, 0x01, 0x80, 0x00,
    0x00, 0x03, 0x8e, 0x30, 0x0e, 0x38, 0x03, 0x80, 0x00, 0x00, 0x03, 0x8e,
    0x30, 0x07, 0xf8, 0x01, 0x00, 0x00, 0x00, 0x01, 0x8e, 0x30, 0x03, 0xf0};

const unsigned char sunrise_sunset[] PROGMEM = {
    0x00, 0x00, 0x01, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00,
    0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00,
    0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00,
    0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x01, 0xc0, 0x01, 0x80, 0x03, 0x80,
    0x01, 0xe0, 0x00, 0x00, 0x07, 0x80, 0x01, 0xf0, 0x00, 0x00, 0x0f, 0x80,
    0x00, 0xf8, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x78, 0x00, 0x00, 0x1e, 0x00,
    0x00, 0x38, 0x03, 0xc0, 0x1c, 0x00, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00,
    0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00,
    0x00, 0x01, 0xf8, 0x1f, 0x80, 0x00, 0x00, 0x03, 0xe0, 0x07, 0xc0, 0x00,
    0x00, 0x03, 0xc0, 0x03, 0xc0, 0x00, 0x00, 0x07, 0x80, 0x01, 0xe0, 0x00,
    0x00, 0x07, 0x80, 0x01, 0xe0, 0x00, 0x00, 0x0f, 0x00, 0x00, 0xf0, 0x00,
    0x7e, 0x0f, 0x00, 0x00, 0xf0, 0x7e, 0xff, 0x0f, 0x00, 0x00, 0xf0, 0xff,
    0xff, 0x0f, 0x00, 0x00, 0xf0, 0xff, 0x7e, 0x0f, 0x00, 0x00, 0xf0, 0x7e,
    0x00, 0x07, 0x00, 0x00, 0xe0, 0x00, 0x00, 0x07, 0x80, 0x01, 0xe0, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x07, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00,
    0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x07, 0xff, 0xff, 0xe0, 0x00};

const unsigned char clear_day[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x38, 0x00, 0x30,
    0x00, 0x70, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00, 0x3e,
    0x00, 0x00, 0x01, 0xf0, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x03, 0xe0, 0x00,
    0x00, 0x0f, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x00, 0x07, 0x00, 0x78, 0x03,
    0x80, 0x00, 0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f,
    0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xe0, 0x00, 0x00, 0x00,
    0x00, 0x3f, 0x03, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x00, 0xf8, 0x00,
    0x00, 0x00, 0x00, 0x78, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00,
    0x3c, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x01,
    0xe0, 0x00, 0x1e, 0x00, 0x00, 0x0f, 0xc1, 0xe0, 0x00, 0x1e, 0x0f, 0xc0,
    0x1f, 0xe1, 0xe0, 0x00, 0x1e, 0x1f, 0xe0, 0x1f, 0xe1, 0xe0, 0x00, 0x1e,
    0x1f, 0xe0, 0x0f, 0xc1, 0xe0, 0x00, 0x1e, 0x0f, 0xc0, 0x00, 0x01, 0xe0,
    0x00, 0x1e, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x3c, 0x00, 0x00, 0x00,
    0x00, 0xf0, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x78, 0x00,
    0x00, 0x00, 0x00, 0x7c, 0x00, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x3f, 0x03,
    0xf0, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00,
    0x0f, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0x00,
    0x00, 0x07, 0x00, 0x78, 0x03, 0x80, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x03,
    0xc0, 0x00, 0x00, 0x1f, 0x00, 0x00, 0x03, 0xe0, 0x00, 0x00, 0x3e, 0x00,
    0x00, 0x01, 0xf0, 0x00, 0x00, 0x3c, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x00,
    0x38, 0x00, 0x30, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00};

const unsigned char temperature[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xfe,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x03, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xcf, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x07, 0x87, 0x80, 0x00, 0x00, 0x00, 0x00, 0x07, 0x87, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x07, 0x87, 0x80, 0x00, 0x00, 0x00, 0x00, 0x07,
    0x87, 0x80, 0x00, 0x00, 0x00, 0x00, 0x07, 0x87, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x07, 0x87, 0x80, 0x00, 0x00, 0x00, 0x00, 0x07, 0x87, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x07, 0x87, 0x80, 0x00, 0x00, 0x00, 0x00, 0x07, 0x87,
    0x80, 0x00, 0x00, 0x00, 0x00, 0x07, 0x87, 0x80, 0x00, 0x00, 0x00, 0x00,
    0x07, 0xb7, 0x80, 0x00, 0x00, 0x00, 0x00, 0x07, 0xb7, 0x80, 0x00, 0x00,
    0x00, 0x00, 0x07, 0xb7, 0x80, 0x00, 0x00, 0x00, 0x00, 0x07, 0xb7, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x07, 0xb7, 0x80, 0x00, 0x00, 0x00, 0x00, 0x07,
    0xb7, 0x80, 0x00, 0x00, 0x00, 0x00, 0x07, 0xb7, 0x80, 0x00, 0x00, 0x00,
    0x00, 0x07, 0xb7, 0x80, 0x00, 0x00, 0x00, 0x00, 0x07, 0xb7, 0x80, 0x00,
    0x00, 0x00, 0x00, 0x0f, 0xb7, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x33,
    0xc0, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x79, 0xe0, 0x00, 0x00, 0x00, 0x00,
    0x1e, 0xfd, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x1e, 0xfd, 0xe0, 0x00, 0x00,
    0x00, 0x00, 0x1e, 0x79, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x33, 0xc0,
    0x00, 0x00, 0x00, 0x00, 0x0f, 0x87, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x07,
    0xff, 0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0xff, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00};

const unsigned char prob_rain[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07,
    0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xff, 0xf0, 0x00, 0x00, 0x00,
    0x00, 0x7f, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0xfe, 0x00,
    0x00, 0x00, 0x03, 0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff,
    0xff, 0x80, 0x00, 0x00, 0x07, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x00, 0x0f,
    0xff, 0xff, 0xff, 0xe0, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xff, 0xe0, 0x00,
    0x00, 0x00, 0x30, 0x30, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x40, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x38, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0xe0, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x1f, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x80,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00};

const unsigned char barometer[] PROGMEM = {
    0x00, 0x1f, 0xe0, 0x00, 0x00, 0x7f, 0xf8, 0x00, 0x01, 0xff, 0xfe, 0x00,
    0x03, 0xf0, 0x3f, 0x00, 0x0f, 0x80, 0x07, 0xc0, 0x0f, 0x00, 0x03, 0xc0,
    0x1e, 0x00, 0x01, 0xe0, 0x3c, 0x00, 0x00, 0xf0, 0x38, 0x00, 0x3c, 0x70,
    0x70, 0x00, 0x3c, 0x38, 0x70, 0x00, 0x7c, 0x38, 0xf0, 0x00, 0xfc, 0x3c,
    0xe0, 0x07, 0xf0, 0x1c, 0xe0, 0x0f, 0xe0, 0x1c, 0xe0, 0x0f, 0xc0, 0x1c,
    0xe0, 0x0f, 0xc0, 0x1c, 0xe0, 0x1f, 0x80, 0x1c, 0xe0, 0x3f, 0x80, 0x1c,
    0xf3, 0xfc, 0x00, 0x3c, 0x71, 0xf8, 0x00, 0x38, 0x70, 0xf0, 0x00, 0x38,
    0x38, 0x70, 0x00, 0x70, 0x3c, 0x30, 0x00, 0xf0, 0x1e, 0x10, 0x01, 0xe0,
    0x0f, 0x00, 0x03, 0xc0, 0x0f, 0x80, 0x07, 0xc0, 0x03, 0xf0, 0x3f, 0x00,
    0x01, 0xff, 0xfe, 0x00, 0x00, 0x7f, 0xf8, 0x00, 0x00, 0x1f, 0xe0, 0x00};

const unsigned char wind_speed[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x01, 0xfc, 0x00, 0x00, 0x03, 0x3f, 0xf0, 0x00,
    0x85, 0x3e, 0x1f, 0x80, 0xd9, 0x3e, 0x1f, 0x38, 0xf1, 0x3e, 0x0f, 0x0c,
    0xc1, 0x3e, 0x0f, 0x0c, 0xc1, 0x3e, 0x0f, 0x0c, 0xf1, 0x3e, 0x0f, 0x0c,
    0xd9, 0x3e, 0x0f, 0x18, 0xc5, 0x3e, 0x1f, 0xc0, 0xc3, 0x3f, 0xf0, 0x00,
    0xc1, 0xfe, 0x00, 0x00, 0xc0, 0x80, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00,
    0xc0, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00,
    0xc0, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00,
    0xc0, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00,
    0xc0, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00,
    0xc0, 0x00, 0x00, 0x00, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const unsigned char rain[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0c,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xe0, 0x00, 0x00, 0x00, 0x00,
    0x07, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xfc, 0x00, 0x00,
    0x00, 0x00, 0x3f, 0x80, 0x7f, 0x00, 0x00, 0x00, 0x00, 0x7e, 0x00, 0x1f,
    0x80, 0x00, 0x00, 0x00, 0x78, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0xf0,
    0x00, 0x03, 0xc0, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x01, 0xec, 0x00, 0x00,
    0x01, 0xe0, 0x00, 0x01, 0xff, 0xc0, 0x00, 0x03, 0xc0, 0x00, 0x00, 0xff,
    0xf0, 0x00, 0x03, 0xc0, 0x00, 0x00, 0xff, 0xf8, 0x00, 0x03, 0x80, 0x00,
    0x00, 0x40, 0x7c, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x3e, 0x00, 0x07,
    0x80, 0x00, 0x00, 0x00, 0x1e, 0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x0f,
    0x00, 0x07, 0x80, 0x00, 0x00, 0x00, 0x07, 0x00, 0x07, 0x80, 0x00, 0x00,
    0x00, 0x07, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x07, 0x80, 0x03, 0x80,
    0x00, 0x00, 0x00, 0x07, 0x80, 0x03, 0xc0, 0x00, 0x00, 0x00, 0x07, 0x80,
    0x03, 0xc0, 0x78, 0x00, 0x78, 0x07, 0x80, 0x01, 0xe0, 0x78, 0x00, 0x78,
    0x07, 0x00, 0x01, 0xe0, 0x78, 0x00, 0x78, 0x0f, 0x00, 0x00, 0xf0, 0x78,
    0x00, 0x78, 0x0f, 0x00, 0x00, 0x78, 0x78, 0x78, 0x78, 0x1e, 0x00, 0x00,
    0x78, 0x78, 0x78, 0x78, 0x3e, 0x00, 0x00, 0x38, 0x30, 0x78, 0x30, 0x7c,
    0x00, 0x00, 0x08, 0x00, 0x78, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x78,
    0x00, 0x70, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x40, 0x00, 0x00, 0x00,
    0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x78, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x78,
    0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x78,
    0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x78, 0x78, 0x78, 0x00, 0x00, 0x00,
    0x00, 0x78, 0x78, 0x78, 0x00, 0x00, 0x00, 0x00, 0x30, 0x78, 0x30, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x30, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00};

const unsigned char partly_cloudy_day[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x0f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f,
    0x00, 0x00, 0x00, 0x00, 0x07, 0x00, 0x06, 0x00, 0x0e, 0x00, 0x00, 0x07,
    0x80, 0x00, 0x00, 0x1e, 0x00, 0x00, 0x07, 0xc0, 0x00, 0x00, 0x3e, 0x00,
    0x00, 0x03, 0xe0, 0x00, 0x00, 0x7c, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x00,
    0x78, 0x00, 0x00, 0x00, 0xe0, 0x0f, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00,
    0x7f, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xf8, 0x00, 0x00, 0x00,
    0x00, 0x03, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x07, 0xe7, 0xe0, 0x7e, 0x00,
    0x00, 0x00, 0x3f, 0xff, 0x80, 0x1f, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00,
    0x0f, 0x00, 0x00, 0x03, 0xff, 0xff, 0x80, 0x07, 0x80, 0x00, 0x07, 0xf0,
    0x0f, 0xe0, 0x07, 0x80, 0x00, 0x0f, 0xc0, 0x03, 0xf0, 0x03, 0xc0, 0x00,
    0x1f, 0x00, 0x00, 0xf8, 0x03, 0xc1, 0xf8, 0x1e, 0x00, 0x00, 0x78, 0x03,
    0xc3, 0xfc, 0x3c, 0x00, 0x00, 0x3f, 0xc3, 0xc3, 0xfc, 0x3c, 0x00, 0x00,
    0x3f, 0xfb, 0xc1, 0xf8, 0x78, 0x00, 0x00, 0x1f, 0xff, 0x80, 0x00, 0x78,
    0x00, 0x00, 0x1f, 0xff, 0x80, 0x00, 0x70, 0x00, 0x00, 0x08, 0x1f, 0x80,
    0x00, 0xf0, 0x00, 0x00, 0x00, 0x07, 0xc0, 0x00, 0xf0, 0x00, 0x00, 0x00,
    0x03, 0xc0, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x01, 0xe0, 0x00, 0xf0, 0x00,
    0x00, 0x00, 0x01, 0xe0, 0x00, 0xf0, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00,
    0xf0, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x70, 0x00, 0x00, 0x00, 0x00,
    0xf0, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x78, 0x00, 0x00,
    0x00, 0x00, 0xf0, 0x00, 0x3c, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x00, 0x3c,
    0x00, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x1e, 0x00, 0x00, 0x00, 0x01, 0xe0,
    0x00, 0x1f, 0x00, 0x00, 0x00, 0x03, 0xc0, 0x00, 0x0f, 0xc0, 0x00, 0x00,
    0x07, 0xc0, 0x00, 0x07, 0xf0, 0x00, 0x00, 0x1f, 0x80, 0x00, 0x03, 0xff,
    0xff, 0xff, 0xff, 0x00, 0x00, 0x00, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00,
    0x00, 0x3f, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xc0,
    0x00, 0x00};

const unsigned char electricity[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xf0, 0x00, 0x00, 0xff, 0xfc, 0x00,
    0x03, 0xe0, 0x1f, 0x00, 0x07, 0x80, 0x07, 0x80, 0x0e, 0x00, 0x03, 0xc0,
    0x1c, 0x0f, 0xf8, 0xe0, 0x38, 0x1f, 0xf8, 0x60, 0x38, 0x1f, 0xf0, 0x70,
    0x70, 0x1f, 0xf0, 0x30, 0x60, 0x3f, 0xe0, 0x38, 0x60, 0x3f, 0xe0, 0x18,
    0x60, 0x3f, 0xc0, 0x18, 0xe0, 0x7f, 0xc0, 0x18, 0xc0, 0x7f, 0xf0, 0x1c,
    0xc0, 0x7f, 0xf0, 0x1c, 0xe0, 0x7f, 0xe0, 0x18, 0x60, 0x1f, 0xc0, 0x18,
    0x60, 0x1f, 0x80, 0x18, 0x60, 0x1f, 0x00, 0x18, 0x70, 0x3e, 0x00, 0x38,
    0x30, 0x3c, 0x00, 0x30, 0x38, 0x78, 0x00, 0x70, 0x1c, 0x70, 0x00, 0xe0,
    0x1e, 0x00, 0x01, 0xc0, 0x0f, 0x00, 0x03, 0xc0, 0x07, 0xc0, 0x0f, 0x00,
    0x01, 0xf0, 0x7e, 0x00, 0x00, 0xff, 0xf8, 0x00, 0x00, 0x1f, 0xe0, 0x00};

const unsigned char window_open[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0xff, 0xff, 0xe0,
    0x7f, 0xff, 0xff, 0xfe, 0x7f, 0x00, 0x00, 0xfe, 0x7f, 0xff, 0xff, 0xfe,
    0x61, 0xff, 0xff, 0x86, 0x61, 0x80, 0x01, 0x86, 0x61, 0x80, 0x01, 0x86,
    0x61, 0x80, 0x01, 0x86, 0x61, 0x80, 0x01, 0x86, 0x61, 0x80, 0x01, 0x86,
    0x7f, 0x80, 0x01, 0xfe, 0x7f, 0x80, 0x01, 0xfe, 0x61, 0x80, 0x01, 0x86,
    0x61, 0x80, 0x01, 0x86, 0x61, 0x80, 0x01, 0x86, 0x61, 0x80, 0x01, 0x86,
    0x61, 0x80, 0x01, 0x86, 0x61, 0x80, 0x01, 0x86, 0x61, 0x80, 0x01, 0x86,
    0x61, 0x80, 0x01, 0x86, 0x61, 0x80, 0x01, 0x86, 0x61, 0x80, 0x01, 0x86,
    0x61, 0x80, 0x01, 0x86, 0x61, 0xff, 0xff, 0x86, 0x7f, 0xff, 0xff, 0xfe,
    0x7f, 0x00, 0x00, 0xfe, 0x7f, 0xff, 0xff, 0xfe, 0x07, 0xff, 0xff, 0xe0,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

const unsigned char window_closed[] PROGMEM = {
    0x00, 0x00, 0x00, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x1f, 0xff, 0xff, 0xf8,
    0x1f, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xf8,
    0x1f, 0x01, 0x80, 0xf8, 0x1f, 0x01, 0x80, 0xf8, 0x1f, 0x01, 0x80, 0xf8,
    0x1f, 0x01, 0x80, 0xf8, 0x1f, 0x01, 0x80, 0xf8, 0x1f, 0x01, 0x80, 0xf8,
    0x1f, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xf8,
    0x1f, 0x01, 0x80, 0xf8, 0x1f, 0x01, 0x80, 0xf8, 0x1f, 0x01, 0x80, 0xf8,
    0x1f, 0x01, 0x80, 0xf8, 0x1f, 0x01, 0x80, 0xf8, 0x1f, 0x01, 0x80, 0xf8,
    0x1f, 0x01, 0x80, 0xf8, 0x1f, 0x01, 0x80, 0xf8, 0x1f, 0x01, 0x80, 0xf8,
    0x1f, 0x01, 0x80, 0xf8, 0x1f, 0x01, 0x80, 0xf8, 0x1f, 0xff, 0xff, 0xf8,
    0x1f, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xff, 0xf8,
    0x0f, 0xff, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00};