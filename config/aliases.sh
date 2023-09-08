#!/bin/bash

alias compilerun='gcc adivinhacao.c -o adivinhacao -lm; ./adivinhacao'

exec "$@"