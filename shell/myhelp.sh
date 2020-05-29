#!/bin/bash
help $1 | sed -n '/^ *Options:/,/^ *$/p' | sed '$d'

