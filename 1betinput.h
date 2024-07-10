#pragma once
#include <iostream>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <termios.h>

static struct termios stored_settings;

void set_keypress(void);

void reset_keypress(void);