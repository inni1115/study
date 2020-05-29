#!/bin/bash
ls -l $1 | sed -e '/^-/s/$/*/' -e '/^d/s/$/\//' -e '/^l/s/$/@/' 
