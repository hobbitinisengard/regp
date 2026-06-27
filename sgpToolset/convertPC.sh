#!/bin/bash
for f in ./*.pc; do echo -n "$f "; ./pcconvert.out "$f" ; done 
